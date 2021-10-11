#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
struct flower{
    int si, ci, mi, ans, cnt;
}arr[MAXN], arr2[MAXN];
int ans[MAXN], result[MAXN];
int n, maxm, tot;
bool cmp1(const flower &a, const flower &b){
    return a.si < b.si ||(a.si == b.si && a.ci < b.ci) || (a.si == b.si && a.ci == b.ci && a.mi < b.mi);
}
#define lowbit(a) (a & -(a))
int tree[MAXN], kinds[MAXN];
int getsum(int x){
    int sum = 0;
    for(int i = x; i > 0; i = i - lowbit(i)){
        sum += tree[i];
    }
    return sum;
}
void update(int x, int delta){
    while(x <= maxm){
        tree[x] += delta;
        x += lowbit(x);
    }
}
int st[MAXN], st2[MAXN], top;
void cdq(int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    int p1 = l, p2 = mid + 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    top = 0;
    for(int i = l; i <= r; i++){
        if(p2 > r || p1 <= mid && arr[p1].ci <= arr[p2].ci) {
            update(arr[p1].mi, arr[p1].cnt);
            st[top] = arr[p1].mi;
            st2[top++] = arr[p1].cnt;
            arr2[i] = arr[p1++];
        }
        else{
            arr[p2].ans += getsum(arr[p2].mi);
            arr2[i] = arr[p2++];
        }
    }
    while(top--){
        update(st[top], -st2[top]);
       
    }
    assert(getsum(maxm) == 0);
    for(int i = l; i <= r; i++){
        arr[i] = arr2[i];
    }
}
int main(){
    int cnt = 1;
    scanf("%d %d", &n, &maxm);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &arr[i].si, &arr[i].ci, &arr[i].mi);
    }
    sort(arr + 1, arr + n + 1, cmp1);
    for(int i = 1; i <= n; i++){
        if(arr[i].ci == arr[i + 1].ci && arr[i].si == arr[i + 1].si && arr[i].mi == arr[i + 1].mi){
            cnt++;
        }
        else
        {
            arr2[++tot] = arr[i];
            arr2[tot].cnt = cnt;
            cnt = 1;
        }
    }
    //for(int i = 1; i <= tot; ++i)
    //printf("%d %d %d %d\n", arr2[i].si, arr2[i].ci, arr2[i].mi, arr2[i].cnt);
    memset(arr, 0, sizeof arr);
    for(int i = 1; i <= tot; i++)arr[i] = arr2[i];
    cdq(1, tot);
    

   /*for(int i = n; i > 1; i--){
        if(arr[i].ci == arr[i - 1].ci && arr[i].si == arr[i - 1].si && arr[i].mi == arr[i - 1].mi){
            ans[arr[i - 1].id] = ans[arr[i].id];
        }
    }*/
    for(int i = 1; i <= tot; i++)arr[i].ans += arr[i].cnt - 1;
    for(int i = 1; i <= tot; i++)result[arr[i].ans] += arr[i].cnt;
    for(int i = 0; i < n; i++)
    printf("%d\n", result[i]);
    
    return 0;
}