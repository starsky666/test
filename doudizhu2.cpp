#include <bits/stdc++.h>
using namespace std;
#define MAXN 18
char s[MAXN];
int ans, pai[17];
void dfs(int pairs, int id, int leave, int step){//p表示三带对带的对数，id表示当前考虑第几种牌，leave表示剩下的牌数，step表示当前的步数
    if(id >= 15 || step > ans) return;
    int duizi = 0;
        for(int i = 0; i < 13; i++)if(pai[i] == 2 ||pai[i] == 4) duizi += pai[i] / 2;
    if(leave == 0 && pairs <= duizi) { 
        if(step < ans) ans = step; 
        return;
    }
    int tmp3 = 0;
    for(int i = id; i < 15; i++){ 
        if(i < 13 && pai[i] > 2){
            int k = i;
            while(k < 12 && pai[k] > 2 ) k++;
            if(k > i + 1) {  
                for(int x = i + 2; x <= k; x++){
                for(int j = i; j < x; j++)pai[j] -= 3;
                dfs(pairs, i, leave - (x - i) * 3, step + 1); //连三不带
                if(leave >= (x - i) * 4)dfs(pairs, i, leave - (x - i) * 4, step + 1); //连三带一
                for(int j = i; j < x; j++)pai[j] +=3;
                }
            }
            pai[i] -= 3;  
            dfs(pairs, i, leave - 3, step + 1);//三不带
            dfs(pairs, i, leave - 4, step + 1); //三带1
            dfs(pairs + 1, i, leave - 5, step + 1); //三带对
            pai[i] +=3;
        }
        if(pai[i] > 1){
            int k = i;
            while(k < 12 && pai[k] > 1) k++;
            if(k > i + 2) { //连对子必须三个。
                for(int x = i + 3; x <= k; x++){
                for(int j = i; j < x; j++) pai[j] -= 2;
                dfs(pairs, i, leave - (x - i) * 2, step + 1);
                for(int j = i; j < x; j++) pai[j] += 2;
                }
            }
            pai[i] -= 2; //对子
            dfs(pairs , i, leave - 2, step + 1);
            pai[i] += 2;
        }
        if(pai[i] > 0){
            int k = i;
            while(k < 12 && pai[k] > 0) k++;
            if(k > i + 4){ //连单张
                for(int x = i + 5; x <= k; x++){
                for(int j = i; j < x; j++) pai[j]--;
                dfs(pairs, i, leave - (x - i), step + 1);
                for(int j = i; j < x; j++) pai[j]++;
                }
            }
            if(i == 13 && pai[14] == 1){
                pai[i]--;
                pai[i + 1]--;
                dfs(pairs, i, leave - 2, step + 1);
                pai[i]++;
                pai[i + 1]++;
            }
            pai[i]--; // 单张
            dfs(pairs, i, leave - 1, step + 1);
            pai[i]++;
        }
    }
}
int main(){
    while(scanf("%s", s) != -1){
        memset(pai, 0, sizeof pai);
        ans = 100;
        int len = strlen(s);
        for(int i = 0; i < len; i++){
            if(s[i] == '0') pai[7]++;
            else if(s[i] == 'J') pai[8]++;
            else if(s[i] == 'Q') pai[9]++;
            else if(s[i] == 'K') pai[10]++;
            else if(s[i] == 'A') pai[11]++;
            else if(s[i] == '2') pai[12]++;
            else if(s[i] == '*') pai[13]++;
            else if(s[i] == '#') pai[14]++;
            else pai[s[i] - '3']++;
        }
        dfs(0, 0, 17, 0);
        printf("%d\n", ans);
    }
    return 0;
}