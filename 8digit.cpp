#include <bits/stdc++.h>
using namespace std;
#define MAXN 12
#define MAXT 400000
char s[MAXN], t[MAXN], sta[MAXN];
bool haveans;
int head, tail, que[MAXT], step[MAXT], flg[MAXT]; 
int bitw[10] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1}; //{1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int encode(char *s){
    int res = 0;
    for(int i = 0; i < 9; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            if(s[j] < s[i]) tmp++;
        }
        res = res + (s[i] -'0' - tmp) * bitw[i];
    }
    return res;
}
void decode(int x, char *s){
    bool vis[10] ={};
    for(int i = 0; i < 9; i++){
        s[i] = x / bitw[i];
        for(int j = 0, t = 0; j < 9; j++){
            if(vis[j] == 0) t++;
            if(t - 1 == s[i]){
                s[i] = j + '0';
                vis[j] = 1;
                break;
            }
        }
        x = x % bitw[i]; 
    }
}
bool check(int num, int newnum){
    if(flg[newnum] > 0 && flg[num] > 0 && flg[newnum] != flg[num]){
        printf("%d", step[newnum] + step[num] + 1);
        return 1;
    }
    return 0;
}
int main(){
    for(int i = 0;i < 9;)if((s[i]=getchar())>='0' && s[i] <= '9')i++;
    for(int i = 0;i < 9;)if((t[i]=getchar())>='0' && t[i] <= '9')i++;
    int sx = encode(s), ex = encode(t);
    memset(step, 0x3f, sizeof step);
    step[sx] = 0;
    step[ex] = 0;
    que[tail++] = sx;
    que[tail++] = ex;
    flg[sx] = 1, flg[ex] = 2;
    while(head < tail){
        int num = que[head++];
        decode(num, sta);
        int pos0, newnum;
        for(int j = 0; j < 9; j++){
            if(sta[j] == '0') {
                pos0 = j;
                break;
            }
        }
        if(pos0 % 3 != 0) {
            swap(sta[pos0 - 1], sta[pos0]);
            newnum = encode(sta);
            if(flg[newnum] > 0 && flg[newnum] != flg[num]){
                printf("%d", step[newnum] + step[num] + 1);
                return 0;
            }
            flg[newnum] = flg[num];
            if(step[newnum] > step[num] + 1){step[newnum] = step[num] + 1;
            que[tail++] = newnum;
            }
            swap(sta[pos0 - 1], sta[pos0]);
        }
        if(pos0 %3 != 2){
            swap(sta[pos0 + 1], sta[pos0]);
            newnum = encode(sta);
            if(flg[newnum] > 0 && flg[newnum] != flg[num]){
                printf("%d", step[newnum] + step[num] + 1);
                return 0;
            }
            flg[newnum] = flg[num];
            if(step[newnum] > step[num] + 1){step[newnum] = step[num] + 1;
            que[tail++] = newnum;
            }
            swap(sta[pos0 + 1], sta[pos0]);
        }
        if(pos0 / 3 != 0){
            swap(sta[pos0 - 3], sta[pos0]);
            newnum = encode(sta);
            if(flg[newnum] > 0 && flg[newnum] != flg[num]){
                printf("%d", step[newnum] + step[num] + 1);
                return 0;
            }
            flg[newnum] = flg[num];
            if(step[newnum] > step[num] + 1){step[newnum] = step[num] + 1;
            que[tail++] = newnum;
            }
            swap(sta[pos0 - 3], sta[pos0]);
        }
        if(pos0 / 3 != 2){
            swap(sta[pos0 + 3], sta[pos0]);
            newnum = encode(sta);
            if(flg[newnum] > 0 && flg[newnum] != flg[num]){
                printf("%d", step[newnum] + step[num] + 1);
                return 0;
            }
            flg[newnum] = flg[num];
            if(step[newnum] > step[num] + 1){step[newnum] = step[num] + 1;
            que[tail++] = newnum;
            }
            swap(sta[pos0 + 3], sta[pos0]);
        }
    }
    printf("-1\n");
    return 0;
}