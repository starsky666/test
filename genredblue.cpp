#include <bits/stdc++.h>
#include "gendata.h"
using namespace std;
char infile[100], outfile[100], exestring[100];
int main(){
    int n, k;
    my_srand();
    for(int cas = 11; cas <= 20; cas++){
        genfilename(infile, "redblue", cas, ".in");
        genfilename(outfile, "redblue", cas, ".out");
        n = my_random(10000, 100000);
        k = my_random(1000, n);
        freopen(infile, "w", stdout);
        printf("%d %d\n", n, k);
        sprintf(exestring, "./redblue < %s > %s", infile, outfile);
        cerr << exestring << endl;
        system(exestring);
        cerr << outfile << " is done\n";
        fclose(stdout);
    }
    return 0;
}