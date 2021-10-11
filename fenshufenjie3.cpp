#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define INF 2000000000
#define min(a, b) (a < b ? (a) : (b))
#define max(a, b) (a > b ? (a) : (b))
int n, m, ans;
LL fac[40];
LL gcd(LL a, LL b){
    LL t;
    while(b){t = b, b =  a % b, a = t;}
    return a;
}
void dfs(int k, LL la, LL lb){
    if(k <= n && la == 0)return;
    if(k == n && lb % la == 0 && lb / la >= fac[k - 1]) {
        ans++;
        return;
    }
    if(k >= n)return;
    if(lb > INF ){
    LL gd = gcd(la, lb);
    la /= gd, lb /= gd;
    }
    //if(1.0 * la / lb<= 1.0 * (n - k) / m ) return;
    //if(1.0 * la / lb > 1.0 * (n - k + 1)/ fac[k - 1]) return;
    double tmp =  (1.0 * la / lb - 1.0 * (n - k - 1) / m);
    tmp = 1.0 / tmp;
    LL minz = (int) tmp;
    tmp = (1.0 * lb / la * (n - k + 1));
    LL maxz =(LL) tmp;
    for(int i = max(fac[k - 1] ,minz); i <= min(m, maxz); i++){
        fac[k] = i;
        dfs(k + 1, la * i - lb, lb * i);
    }
}
int main(){
    fac[0] = 2;
    scanf("%d %d", &n, &m);
    dfs(1, 1,  1);
    printf("%d\n", ans);
    return 0;
}