#include <bits/stdc++.h>
using namespace std;
#define MAXN 52
#define MAXK 2505
int arr[MAXN], dp[MAXN][MAXN][MAXK];
#define MOD 1000000007
int n, k;
int main(){
    scanf("%d %d", &n, &k);
    //dp[i][j][k] 前i位，有j个数未匹配，当前的美观度为k时的方案数。
    //dp[i][j][k] 
    dp[1][0][0] = 1;
    dp[1][1][2] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <=i && j <= n - i; j++){
            for(int k = 2 * j; k <= n * n; k++){
                dp[i][j][k] = (1ll * dp[i - 1][j][k - 2 * j] * (2 * j + 1) + 1ll * dp[i - 1][j + 1][k - 2 * j] * (j + 1) * (j + 1) + dp [i - 1][j - 1][k - 2 * j]) % MOD;
            }
        }
    }
    printf("%d\n", dp[n][0][k]);
    return 0;
}