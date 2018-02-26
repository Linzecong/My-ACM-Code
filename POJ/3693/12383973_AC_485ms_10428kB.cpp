#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100005;

struct Suffix_Arr {
    int n, s[maxn];
    int SA[maxn], rank[maxn], height[maxn];
    int tmp_one[maxn], tmp_two[maxn], c[305];

    int d[maxn][20];

    void init(char* str);
    void build(int m);
    void get_height();
    void rmq_init();
    int rmq_query(int x, int y);
    void solve();
}AC;

char str[maxn];

int main () {
    int cas = 0;
    while (scanf("%s", str) == 1 && strcmp(str, "#")) {
        AC.init(str);
        AC.build(27);
        AC.get_height();
        printf("Case %d: ", ++cas);
        AC.solve();
    }
    return 0;
}

void Suffix_Arr::init(char* str) {
    n = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        s[n++] = str[i] - 'a' + 1;
    s[n++] = 0;
}

void Suffix_Arr::solve() {

    /*
    for (int i = 0; i < n; i++)
        printf("%d ", SA[i]);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d ", height[i]);
    printf("\n");
    */

    rmq_init();

    int ans = 0;
    vector<int> vec;

    for (int l = 1; l < n; l++) {
        for (int i = 0; i + l < n; i += l) {
            int lcp = rmq_query(rank[i], rank[i + l]);
            int k = lcp / l + 1;
            int p = i - (l - lcp % l);

            if (p >= 0 && lcp % l && rmq_query(rank[p], rank[p + l]) >= lcp)
                k++;

            if (k > ans) {
                ans = k;
                vec.clear();
            }

            if (k == ans)
                vec.push_back(l);
        }
    }

    int pos, len;
    for (int i = 0; i < n; i++) {
        bool flag = false;

        for (int j = 0; j < vec.size(); j++) {

            if (SA[i] + vec[j] >= n)
                continue;

            if (rmq_query(i, rank[SA[i] + vec[j]]) >= (ans - 1) * vec[j]) {
                pos = SA[i];
                len = vec[j] * ans;
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    for (int i = 0; i < len; i++)
        printf("%c", s[pos + i] + 'a' - 1);
    printf("\n");
}

void Suffix_Arr::rmq_init() {
    for (int i = 0; i < n; i++) d[i][0] = height[i];

    for (int k = 1; (1<<k) <= n; k++) {
        for (int i = 0; i + (1<<k) - 1 < n; i++)
            d[i][k] = min(d[i][k-1], d[i+(1<<(k-1))][k-1]);
    }
}

int Suffix_Arr::rmq_query(int x, int y) {
    if (x == y)
        return d[x][0];

    if (x > y)
        swap(x, y);
    x++;

    int k = 0;
    while ((1<<(k+1) <= y - x + 1)) k++;
    return min(d[x][k], d[y - (1<<k) + 1][k]);
}

void Suffix_Arr::get_height() {
    for (int i = 0; i < n; i++)
        rank[SA[i]] = i;

    int mv = height[n-1] = 0;
    for (int i = 0; i < n - 1; i++) {
        if (mv) mv--;

        int j = SA[rank[i] - 1];
        while (s[i+mv] == s[j+mv])
            mv++;
        height[rank[i]] = mv;
    }
}

void Suffix_Arr::build (int m) {
    int *x = tmp_one, *y = tmp_two;

    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i-1];
    for (int i = n - 1; i >= 0; i--) SA[--c[x[i]]] = i;

    for (int k = 1; k <= n; k <<= 1) {

        int mv = 0;
        for (int i = n - k; i < n; i++) y[mv++] = i;
        for (int i = 0; i < n; i++) if (SA[i] >= k)
            y[mv++] = SA[i] - k;

        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i-1];
        for (int i = n - 1; i >= 0; i--) SA[--c[x[y[i]]]] = y[i];

        swap(x, y);
        mv = 1;
        x[SA[0]] = 0;

        for (int i = 1; i < n; i++)
            x[SA[i]] = (y[SA[i-1]] == y[SA[i]] && y[SA[i-1] + k] == y[SA[i] + k] ? mv - 1 : mv++);

        if (mv >= n)
            break;
        m = mv;
    }
}