#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long

using namespace std;

const int N=5000010;
int n,m,totx=0,tot=0;     //totx是操作的个数,tot询问的编号 

struct node{
    int type,id;
    ll val;
    bool operator < (const node &a) const   //重载运算符,优先时间排序 
    {
        if (id!=a.id) return id<a.id;
        else return type<a.type;
    }
};
node A[N],B[N];
ll ans[N];

void CDQ(int L,int R)
{
    if (L==R) return;
    int M=(L+R)>>1;
    CDQ(L,M);
    CDQ(M+1,R);
    int t1=L,t2=M+1;
    ll sum=0; 
    for (int i=L;i<=R;i++)
    {
        if ((t1<=M&&A[t1]<A[t2])||t2>R) //只修改左边区间内的修改值
        {
            if (A[t1].type==1) sum+=A[t1].val;   //sum是修改的总值
            B[i]=A[t1++]; 
        }
        else                         //只统计右边区间内的查询结果
        {
            if (A[t2].type==3) ans[A[t2].val]+=sum;
            else if (A[t2].type==2) ans[A[t2].val]-=sum;
            B[i]=A[t2++];
        }
    }
    for (int i=L;i<=R;i++) A[i]=B[i];
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        tot++;
        A[tot].type=1; A[tot].id=i;            //修改操作 
        scanf("%lld",&A[tot].val);
    }
    for (int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        tot++;
        A[tot].type=t; 
        if (t==1)
            scanf("%d%lld",&A[tot].id,&A[tot].val);
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            totx++; 
            A[tot].val=totx; A[tot].id=l-1;    //询问的前一个位置 
            tot++; A[tot].type=3; A[tot].val=totx; A[tot].id=r;  //询问的后端点 
        }
    }
    CDQ(1,tot);
    for (int i=1;i<=totx;i++) printf("%lld\n",ans[i]);
    return 0;
}
