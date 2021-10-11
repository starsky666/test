#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long int
#define MOD 1000000007
int n, k;
LL ans;
LL fac[MAXN],recfac[MAXN];
LL qpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1)
        res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void init(){
    fac[0] = 1;
    recfac[0] = 1;
    for(int i = 1; i <= n; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    recfac[n] = qpow(fac[n], MOD - 2);
    for(int i = n - 1; i > 0; i--){
        recfac[i] = recfac[i + 1] * (i + 1) % MOD;
    }
}
 
LL getc(int tn, int tk) //C(tn, tk)
{
    if(tn == tk) return 1;
    if(tn < tk) return 0;
    return fac[tn] * recfac[tk] % MOD * recfac[tn - tk] % MOD;
}
int main(){
    scanf("%d %d", &n, &k);
    init();
    LL tmp;
    for(int i = 1; i <= k; i++){
        tmp = getc(k - 1, i - 1) * ((2 * getc(n - k - 1, i - 1) + getc(n - k - 1, i) + getc(n - k - 1, i - 2) ) % MOD) % MOD;
        printf("%lld\n", tmp % MOD);
    }
}