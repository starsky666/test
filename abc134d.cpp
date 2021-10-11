#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MOD 1000000007
char s[MAXN];
int n, dp[MAXN][13];
int main(){
    scanf("%s", s);
    int len = strlen(s);
    if(s[0] == '?') 
    for(int i = 0; i <= 9; i++){
        dp[0][i] = 1;
        }
    else dp[0][s[0] - '0'] = 1;
    for(int i = 1; i < len; i++){
        if(s[i] == '?'){
            for(int j = 0; j <= 9; j++) 
                for(int k = 0; k <= 12; k++){
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    dp[i][(k * 10 + j) % 13] %= MOD;
                }
        }
        else{
            for(int k = 0; k <= 12; k++){
                dp[i][(k * 10 + s[i] - '0') % 13] += dp[i - 1][k];
                dp[i][(k * 10 + s[i] - '0') % 13] %= MOD;
            }
        }
    }
    printf("%d\n", dp[len - 1][5]);
    return 0;
}