#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int fir[MAXN], w[MAXN];
struct edge{
    int v, nxt;
}eds[MAXN << 1];
int ecnt;
void adde(int a, int b){
    eds[++ecnt].v = b, eds[ecnt].nxt = fir[a], fir[a] = ecnt;
    eds[++ecnt].v = a, eds[ecnt].nxt = fir[b], fir[b] = ecnt;
}
int main(){

}