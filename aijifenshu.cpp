#include <bits/stdc++.h> 
using namespace std;
int a, b, depth;
#define MAXN 10005
#define LL long long int
LL gcd(LL a, LL b){
    return (!b)?a:gcd(b, a%b);
}
#define INF 999999999
int ans[MAXN], trueans[MAXN];
int res;
void dfs(int a, int b, int k){
    if(a == 0) {
        if(ans[k - 1] < trueans[k - 1] || trueans[k] == 0){
            for(int j = 1; j < k; j++)
            trueans[j] = ans[j];
            res = k - 1;
        }
        return;
    }
    if(k > res || k > depth)return;
    int beg = ((b - 1) / a) + 1;
    for(int i = max(beg, ans[k - 1] + 1); i <= 1ll * beg * (depth - k + 1); i++){
        if(res < INF && i >= trueans[res]) return;
        int ta = a, tb = b;
        LL xd = gcd(b, i);
        LL lcm = 1ll * b * i / xd;
        a *= i / xd;
        a -= 1 * (b / xd);
        ans[k] = i;
        if(res < INF && 1ll * trueans[res] * a < 1ll * lcm *(depth - k))
        {
            a = ta, b = tb;
            continue;
        }
        int d = gcd(a, lcm);
        a /= d, lcm /= d;
        dfs(a, lcm, k + 1);
        a = ta, b =tb;
    }
}
int main(){
    scanf("%d%d", &a, &b);
    res = INF;
    depth = 1;
    while(1){
        depth++;
        dfs(a, b, 1);
        if(res != INF)
        {
            for(int i = 1; i <= res; i++)
            printf("%d ", trueans[i]);
            return 0;
        }
    }
    
}

