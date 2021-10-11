#include <bits/stdc++.h>
#include "gendata.h"
using namespace std;
char infile[100], outfile[100], exestring[100];
int que[MAXN], head, tail;
bool myvis[200005];
int bfs(int root, int n){
    memset(myvis, 0, sizeof myvis);
    head = tail = 0;
    que[tail++] = root;
    int pcnt = 0;
    myvis[root] = 1;
    while(head < tail){
        pcnt++;
        int tmp = que[head++];
        if(childcnt[tmp][0]){
            if(childcnt[tmp][1]){
                assert(myvis[childcnt[tmp][1]] == 0);
                vis[childcnt[tmp][1]] = 1;
                que[tail++] = childcnt[tmp][1];
                
            }
            if(childcnt[tmp][2]){
                assert(myvis[childcnt[tmp][2]] ==0);
                vis[childcnt[tmp][2]] = 1;
                que[tail++] = childcnt[tmp][2];
            }
        }
    }
    cerr << n << ' ' << pcnt << endl;
    assert(pcnt == n);
}
int main(){
    my_srand();
    int n;
    for(int cas = 11; cas <= 20; cas++){
        genfilename(infile, "hospital", cas, ".in");
        genfilename(outfile, "hospital", cas, ".out");
        freopen(infile, "w", stdout);
        if(cas <= 13){
            n = my_random(3000,10000);
        }
        else {
            n = my_random(10000, 100000);
        }
        gen_binary_tree(0, n, 1, 10000);
        printf("%d\n", n);  
        for(int i = 1; i <= n; i++){
            printf("%d %d %d\n",childcnt[i][3], childcnt[i][1], childcnt[i][2]);
        }
        bfs(1, n);
        cerr << infile << endl;
        sprintf(exestring, "./hospital < %s > %s", infile, outfile);
        cerr << exestring << endl;
        system(exestring);
        cerr << outfile << " isdone\n" << endl;
        fclose(stdout);
    }
    return 0;
}