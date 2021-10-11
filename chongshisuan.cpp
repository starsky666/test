#include <bits/stdc++.h>
using namespace std;
#define MAXN 30
char as[MAXN], bs[MAXN],cs[MAXN], ss[MAXN];
int tot, ans[MAXN], jinwei[MAXN];
bool haveans, vis[MAXN], used[MAXN]; 
int n;
bool check(){
    memset(jinwei, -1 ,sizeof jinwei);
    jinwei[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        int a = ans[as[i] - 'A'], b = ans[bs[i] - 'A'], c = ans[cs[i] - 'A']; //第i位的三个值
        if(a != -1 && b != -1 && c != -1){ //如果第i为的三个值都确定
            if(jinwei[i + 1] != -1){ //如果进位也确定
                if((a + b + jinwei[i + 1]) %n != c){ //不相等，则不合法，返回0
                    return 0;
                }
                else jinwei[i] = (a + b + jinwei[i + 1] >= n);
            }
            else { //如果进位不确定，只有两种可能：进位为0，进位为1.
                if((a + b) % n != c && (a + b + 1) % n != c)return 0; //两种进位都不能相等，则不合法。
                else if(a + b == n - 1) jinwei[i] = -1;
                else jinwei[i] = ((a + b) > n - 1);
            }
        }
    }
    return 1; //其他情况都暂且认为合法，返回1.
}
void dfs(int k){
    if(k == n){ // 找到解，将haveans标记为1，并输出该解。
        haveans = 1; 
        for(int i = 0; i < n; i++) 
        printf("%d ",ans[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++){
        if(used[i] == 0){
            ans[ss[k] - 'A'] = i;
            used[i] = 1;
            if(check() == 1)
            dfs(k + 1);
            if(haveans == 1) break;
            used[i] = 0;
            ans[ss[k] - 'A'] = -1;
        }
    }
}
int main(){
    memset(ans, -1, sizeof ans);
    scanf("%d %s %s %s", &n, as, bs, cs);
    for(int i = n - 1; i >= 0; i--){ //按照加式中从右到左首次出现的顺序来把字母存放到ss数组中。
        if(vis[as[i] - 'A'] == 0){
            ss[tot++] = as[i];
            vis[as[i] - 'A'] = 1;
        }
        if(vis[bs[i] - 'A'] == 0){
            ss[tot++] = bs[i];
            vis[bs[i] - 'A'] = 1;
        }
        if(vis[cs[i] - 'A'] == 0){
            ss[tot++] = cs[i];
            vis[cs[i] - 'A'] = 1;
        }
    }
    dfs(0);
}