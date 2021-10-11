#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int n, k, ans;
int stamp_tmp[41], stamp[41];
int flg[41][MAXN];
void init(){
    memset(flg, 0x3f, sizeof flg);
    flg[0][0] = 0;
}
void dfs(int id, int lastmax){ 
    if(id > k){
        if(lastmax > ans){
            ans = lastmax;
            for(int i = 1; i < id; i++){
                stamp[i] = stamp_tmp[i];
            }
        }
        return;
    }
    lastmax++;
    for(int i = stamp_tmp[id - 1] + 1; i <= lastmax; i++){
        int tmpmax = 0;
        stamp_tmp[id] = i;
        tmpmax =lastmax;
        memcpy(flg[id], flg[id - 1],sizeof flg[id]); 
        for(int j = 0; j < MAXN; j++){
            if(j >= i && flg[id][j - i] < n) flg[id][j] = min(flg[id][j - i] + 1, flg[id][j]); 
        }
        for(int j = 0; ; j++){
            if(flg[id][j] > n) {
                tmpmax = j - 1;
                break;
            }
        }
        dfs(id + 1, tmpmax);
    }
}
int main(){
    scanf("%d %d", &n, &k);
    init();
    dfs(1, n);
    for(int i = 1; i <= k; i++)printf("%d ", stamp[i]);
    printf("\nMAX=%d\n", ans);
    return 0;
}