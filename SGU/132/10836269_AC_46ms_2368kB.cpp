#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define S (1 << 8)
#define N 10
#define INF 0x3f3f3f3f

int g[80];
int dp[2][S][S];
int row, col, x, state_I, state_J;
char str[N];
int shift_l[N] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

void init() {
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= row; i++) {
        scanf ("%s", str);
        for (int j = 0; j < col; j++)
                g[i] = g[i] << 1 | (str[j] == '*');
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][shift_l[col] - 1][g[1]] = 0;
    x = 1;
}

void dfs(int r, int s1, int s2, int cnt) {

    if (r > 0 && (state_I & shift_l[r - 1]) == 0 && (s1 & shift_l[r - 1]) == 0)
        return ;
    if (r > 1 && (s1 & shift_l[r - 1]) == 0 && (s1 & shift_l[r - 2]) == 0)
        return ;
    if (r == col) {
        if (dp[x^1][state_I][state_J] != INF) 
            dp[x][s1][s2] = min(dp[x][s1][s2], dp[x ^ 1][state_I][state_J] + cnt);

        return ;
    }

    dfs(r + 1, s1, s2, cnt);
    if((s1 & shift_l[r]) == 0 && (s2 & shift_l[r]) == 0)
        dfs(r + 1, s1 | shift_l[r], s2 | shift_l[r], cnt + 1);

    if(r < (col - 1) && (s1 & shift_l[r]) == 0 && (s1 & shift_l[r + 1]) == 0)
        dfs(r + 1, s1 | shift_l[r] | shift_l[r + 1], s2, cnt + 1);
}

void solve() {
    for (int r = 1; r <= row; r++) {
        for (int i = 0; i < shift_l[col]; i++) 
            for (int j = 0; j < shift_l[col]; j++)  {
                if (dp[x ^ 1][i][j] != INF) {
                    state_I = i;
                    state_J = j;
                    dfs(0, j, g[r + 1], 0);
                }
            }
            memset(dp[x ^ 1], 0x3f, sizeof(dp[x ^ 1]));
            x ^= 1;
        }
    x ^= 1;
    int ans = INF;
    for(int i = 0; i < shift_l[col]; i++) {
        ans = min(ans, dp[x][i][0]);
    }

    printf("%d\n", ans);
}

int main() {
    scanf("%d%d", &row, &col);
    init();
    solve();
    return 0;
}