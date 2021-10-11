#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int beg, ed, n;
#define OFFSET 100001
struct node{
    int l, r, sum, add;
}tree[MAXN << 2];
void build(int rt, int l, int r){
    tree[rt].l = l, tree[rt].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void down(int rt){
    if(tree[rt].add == 0)return;
    if(tree[rt].l < tree[rt].r) tree[rt << 1].add = tree[rt << 1 | 1].add = tree[rt].add;
    tree[rt].sum = tree[rt].add * (tree[rt].r - tree[rt].l + 1);
    tree[rt].add = 0;
}

void update(int rt, int l, int r){
    if(l <= tree[rt].l && r >= tree[rt].r){
        tree[rt].add = 1;
        down(rt);
        return;
    }
    if(l > tree[rt].r || r < tree[rt].l) {down(rt);return;}
    down(rt);
    update(rt << 1, l, r);
    update(rt << 1 | 1, l ,r);
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum ;
}
int main(){
    int a, b;
    scanf("%d %d %d", &beg, &ed, &n);
    beg += OFFSET;
    ed += OFFSET;
    build(1, beg, ed);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        b--;
        update(1, a + OFFSET , b + OFFSET);
    }
    down(1);
    printf("%d\n", tree[1].sum);
    return 0;
    
}