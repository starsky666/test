#include <bits/stdc++.h>
#define w f[i][j][k][l]
using namespace std;
int len, ans, a[18], p[18], gt[21], vs, lp[4] = { 0, 5, 3, 2 }, f[18][18][18][18];
char s[20];
void dfs(int pl) {
    int i = 0, j = 0, k = 0, l = 0, re[18];
    for (int o = 3; o <= 17; o++) {
        if (p[o] == 1)
            ++i;
        else if (p[o] == 2)
            ++j;
        else if (p[o] == 3)
            ++k;
        else if (p[o] == 4)
            ++l;
    }
    for (int o = 2; o <= 10; o++) {
        for (int u = 1; u <= gt[o]; u++) {
            if (i < o)
                break;
            i -= o;
        }
    }
    ans = min(ans, w + pl);
    if (p[16] && p[17])
        ans = min(ans, w + pl - 1);
    if (i + j + k + l == 0)
        return;
    for (i = 1; i <= 3; i++) {
        j = 3;
        while (j <= 14) {
            while (p[j] < i && j <= 14) ++j;
            if (j > 14)
                break;
            for (k = j + 1; k <= 14; k++) {
                if (p[k] < i)
                    break;
                if (k - j + 1 >= lp[i]) {
                    for (l = j; l <= k; l++) {
                        p[l] -= i;
                    }
                    if (i == 3)
                        ++gt[k - j + 1];
                    dfs(pl + 1);
                    if (i == 3)
                        --gt[k - j + 1];
                    for (l = j; l <= k; l++) {
                        p[l] += i;
                    }
                }
            }
            ++j;
        }
    }
}
int main() {
    memset(f, 10, sizeof(f));
    f[0][0][0][0] = 0;
    for (int i = 0; i <= 17; i++) {
        for (int j = 0; j <= 17; j++) {
            for (int k = 0; k <= 17; k++) {
                for (int l = 0; l <= 17; l++) {
                    if (i)
                        w = min(w, f[i - 1][j][k][l] + 1);
                    if (j)
                        w = min(w, f[i][j - 1][k][l] + 1);
                    if (i && k)
                        w = min(w, f[i - 1][j][k - 1][l] + 1);
                    if (j && k)
                        w = min(w, f[i][j - 1][k - 1][l] + 1);
                    else if (k)
                        w = min(w, f[i][j][k - 1][l] + 1);
                    if (l)
                        w = min(w, f[i][j][k][l - 1] + 1);
                }
            }
        }
    }
    while (scanf("%s", s) != EOF) {
        len = strlen(s);
        memset(p, 0, sizeof(p));
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                ++p[s[i] - '0'];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] == 'A')
                    ++p[14];
                if (s[i] == 'K')
                    ++p[13];
                if (s[i] == 'Q')
                    ++p[12];
                if (s[i] == 'J')
                    ++p[11];
            } else if (s[i] == '#')
                ++p[16];
            else
                ++p[17];
        }
        swap(p[0], p[10]);
        swap(p[2], p[15]);
        vs = p[16] | p[17];
        p[16] = p[17] = 0;
        ans = 21474836;
        dfs(0);
        printf("%d\n", ans + vs);
    }
}