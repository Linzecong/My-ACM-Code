#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
int ans[100005];

int tree[100005 << 2];
int lazy[100005 << 2];

void pushup(int rt)
{
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int rt, int ln, int rn)
{
    if (lazy[rt])
    {
        tree[rt << 1] += lazy[rt] * ln;
        tree[rt << 1 | 1] += lazy[rt] * rn;
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return tree[rt];

    int m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m);

    int ANS = 0;
    if (L <= m)
        ANS += query(L, R, l, m, rt << 1);
    if (R > m)
        ANS += query(L, R, m + 1, r, rt << 1 | 1);
    return ANS;
}

void update(int L, int R, int C, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        tree[rt] += C * (r - l + 1);
        lazy[rt] += C;
        return;
    }
    int m = (l + r) >> 1;

    pushdown(rt, m - l + 1, r - m);
    if (L <= m)
        update(L, R, C, l, m, rt << 1);
    if (R > m)
        update(L, R, C, m + 1, r, rt << 1 | 1);
    pushup(rt);
}

int shang[100005];
int zuo[100005];

vector<string> maze;

int main()
{

    ios::sync_with_stdio(false);
    cin >> N >> M;
    int len = max(N, M);
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        maze.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == '.')
            {
                update(1, ++shang[j], 1, 1, len, 1);
                update(1, ++zuo[i], 1, 1, len, 1);
            //    cout << shang[j] << " " << zuo[i] << endl;
            }
            else
            {
                shang[j] = 0;
                zuo[i] = 0;
            }
        }
    }

    printf("%d ", query(1, 1, 1, len, 1)/2);
    for (int i = 2; i <= len; i++)
        if (i != len)
            printf("%d ", query(i, i, 1, len, 1));
        else
            printf("%d\n", query(i, i, 1, len, 1));
}