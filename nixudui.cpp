#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LL long long int
LL ans;
int n, arr[MAXN], tmparr[MAXN];
void mergesort(int l, int r){
    if(l >= r)return;
    int mid = (l + r) >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int p1 = l, p2 = mid + 1, p3 =l;
    while(p1 <= mid && p2 <= r){
        if(arr[p1] <= arr[p2]){
            tmparr[p3++] = arr[p1++];
            ans += p2 - mid - 1;
        }
        else tmparr[p3++] = arr[p2++];
    }
    while(p1 <= mid) ans += p2 - mid - 1, tmparr[p3++]= arr[p1++];
    while(p2 <= r) tmparr[p3++] = arr[p2++];
    for(int i = l; i <= r; ++i) arr[i] = tmparr[i];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)scanf("%d", &arr[i]);
    mergesort(1, n);
    printf("%lld\n", ans);
    return 0;
}