#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, k, ans = 0, pt[51], gt[51], mx[51], f[10001];
void dp(int t) {
    int now = t - 1;
    while (f[now] <= n) {
        f[++now] = 21474836;
        for (int p = 1; p <= t; p++) {
            if (gt[p] > now)
                break;
            f[now] = min(f[now], f[now - gt[p]] + 1);
        }
    }
    mx[t] = max(mx[t], now - 1);
}
void dfs(int t) {
    if (t == k + 1) {
        if (mx[t - 1] > ans) {
            ans = mx[t - 1];
            for (int i = 1; i <= k; i++) {
                pt[i] = gt[i];
            }
        }
        return;
    }
    for (int i = gt[t - 1] + 1; i <= mx[t - 1] + 1; i++) {
        gt[t] = i;
        dp(t);
        dfs(t + 1);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    gt[1] = 1;
    mx[1] = n;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    dfs(2);
    for (int i = 1; i <= k; i++) {
        printf("%d ", pt[i]);
    }
    printf("\nMAX=%d", ans);
}