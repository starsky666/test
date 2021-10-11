#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int fir[MAXN], w[MAXN];
#define LL long long int 
struct edge{
    int v, nxt;
}eds[MAXN << 1];
LL f[MAXN], g[MAXN], sum, ans;
int que[MAXN],sz[MAXN], fa[MAXN], head, tail, n;
bool vis[MAXN];
int ecnt;
void adde(int a, int b){
    eds[++ecnt].v = b, eds[ecnt].nxt = fir[a], fir[a] = ecnt;
    eds[++ecnt].v = a, eds[ecnt].nxt = fir[b], fir[b] = ecnt;
}

void bfs(int root){
    int tmp;
    head = tail = 0;
    que[tail++] = root;
    vis[root] = 1;
    while(head < tail){
        root = que[head++];
         sz[root] = w[root];
        for(int i = fir[root]; i; i = eds[i].nxt){
            tmp = eds[i].v;
            if(vis[tmp] == 0){
                fa[tmp] = root;
                vis[tmp] = 1;
                que[tail++] = tmp;
            }
        }
    }
    tmp = tail;
    while(tail--){
        sz[fa[que[tail]]] += sz[que[tail]];
        f[fa[que[tail]]] += f[que[tail]] + sz[que[tail]];
    }
    tail = tmp;
}

void bfs2(int root){
    g[1] = f[1];
    sum = sz[1];
    for(int i = 1; i < tail; i++){
        g[que[i]] = g[fa[que[i]]] + sum - sz[que[i]] - sz[que[i]];
    }
}
int main(){
    scanf("%d", &n);
    ans = 0x7f7f7f7f7f7f7f7f;
    int a, b;
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &w[i], &a, &b);
        if(a > 0) adde(i, a);
        if(b > 0) adde(i, b);
    }
    bfs(1);
    bfs2(1);
    for(int i = 1; i <= n; i++){
        if(g[i] < ans)
            ans = g[i];
    }
    printf("%lld\n", ans);
    return 0;
}