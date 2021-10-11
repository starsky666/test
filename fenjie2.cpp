#include <bits/stdc++.h>
using namespace std;
const long long LIM = 2000000000;
const int MAXN = 201;
long long a[MAXN];
long long n, m, ans;
bool check(long long t1, long long t2)
{
  bool f = false;
  if (t1<t2 && t2 % (t2-t1)==0 && t2 / (t2-t1) >= a[n-1])
  {
    f = true;
    a[n] = t2 / (t2-t1);
  }
  return f;
}
void reduce(long long x, long long y)
{
  long long r, i, j;
  i = x;
  j = y;
  while (j != 0)
  {
     r = i % j;
     i = j;
     j = r;
  }
  x = x / i;
  y = y / i;
}
  
void dfs(long long i,long long t1, long long t2)
{
  long long j, k;
  bool flag;
  if (i == n)
  {
    flag = check(t1,t2);
    if (flag)
    {
        ans++;
        /*
        for(k = 1; k <= n; k++)
          cout << a[k] << ' ';
        cout << endl;
        */
    }
    return;
  }
  reduce(t1,t2);  //分子太大时，约分
  if ((n-i+1)/(double)a[i-1]+t1/(double)t2 < 1) return;  //剪枝1
  if ((n-i)/(double)m + t1/(double)t2 > 1) return;       //剪枝2
  for (j = a[i-1]; j <= m; j++)
  {
    a[i] = j;
    dfs(i+1,t2+t1*j,t2*j);
  }
}
int main()
{
  cin >>n >>m;
  a[0] = 2;
  dfs(1,0,1);
  cout << ans << endl;
  return 0;
}