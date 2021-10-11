#include <bits/stdc++.h>
using namespace std;
#define MAXN 8
#define MAXL 7000005
char s[MAXN], t[MAXN];
int bit[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};
#define MOD 1000000
int head ,tail, que[MAXL], step[MAXL];
int encode(char *s, int pos){ //left:1, right:6
    int xcode = pos;
    for(int i = 0; i < 6; i++){
        xcode = xcode * 10 + s[i] - '0';
    }
    return xcode;
}
int swap0(int x){
    int pos = x / bit[0];
    int bit1 = x / bit[pos] % 10;
    int bit2 = x / bit[1] % 10;
    x -= bit1 * bit[pos] + bit2 * bit[1];
    x += bit1 * bit[1] + bit2 * bit[pos];
    return x;
}

int swap1(int x){
    int pos = x / bit[0];
    int bit1 = x / bit[pos] % 10;
    int bit2 = x % 10;
    x -= bit2 + bit1 * bit[pos];
    x += bit2 * bit[pos] + bit1;
    return x;
}
int up(int x){
    int pos = x / 1000000;
    int tmp = 0, tmpbit = 1;
    while(tmp < 7 - pos)tmpbit = tmpbit * 10, tmp++;
    if(x % tmpbit /(tmpbit / 10) != 9) x += tmpbit / 10;
    return x;
}

int down(int x){
    int pos = x / 1000000;
    int tmp = 0, tmpbit = 1;
    while(tmp < 7 - pos)tmpbit = tmpbit * 10, tmp++;
    if(x % tmpbit /(tmpbit / 10)!= 0) x -= tmpbit/10;
    return x;
}

int left(int x){
    int pos = x / 1000000;
    if(pos > 1) x -= 1000000;
    return x;
}

int right(int x){
    int pos = x / 1000000;
    if(pos < 6) x += 1000000;
    return x;
}

int main(){
    scanf("%s %s", s, t);
    que[tail++] = encode(s, 1);
    int target = encode(t, 1);
    target %= 1000000;
    memset(step, 0x3f ,sizeof step);
    step[que[tail - 1]] = 0;
    while(head < tail){
        int tmp = que[head++];
        if(tmp % MOD == target){
            printf("%d\n", step[tmp]);
            return 0;
        }
        int state = up(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
        state = down(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
        state = swap0(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
        state = swap1(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
        state = left(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
        state = right(tmp);
        if(step[state] > step[tmp] + 1) step[state] = step[tmp] + 1, que[tail++] = state;
    }
    return 0;
}