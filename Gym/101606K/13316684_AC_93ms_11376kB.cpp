#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int cnt = 1; //点的总个数，下标从1开始

typedef struct
{
    int flow;     //流量
    int capacity; //最大容量值
} maps;
maps G[MAXN][MAXN];

int layer[MAXN];              //保存标号所属层
bool countLayer(int s, int e) //宽搜
{
    int v, i;
    queue<int> q;
    memset(layer, 0, sizeof(layer));

    q.push(s);
    layer[s] = 1;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (i = 1; i <= cnt; i++)
            if (!layer[i] && G[v][i].capacity > G[v][i].flow)
            {
                q.push(i);
                layer[i] = layer[v] + 1;
            }
        if (v == e)
            return 1;
    }
    return 0;
}
int dfs(int cur, int cp, int e)
{
    if (cur == e)
        return cp;

    int tmp = cp, t;
    for (int i = 1; i <= cnt; i++)
        if (layer[i] == layer[cur] + 1 && tmp && G[cur][i].capacity > G[cur][i].flow)
        {
            t = dfs(i, min(G[cur][i].capacity - G[cur][i].flow, tmp), e);
            G[cur][i].flow += t;
            G[i][cur].flow -= t;
            tmp -= t;
        }
    return cp - tmp;
}
int Max_Flow_Dinic(int s, int e)
{
    int maxflow = 0;
    while (countLayer(s, e))
        maxflow += dfs(s, INF, e);
    return maxflow;
}

struct Ji
{
    int w;
    int l;
    int id;
} qzj[1005];
map<int,int> mp;

struct fj
{
    int w;
    int id;
} zd[1005];

int main()
{

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &qzj[i].w, &qzj[i].l);
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &zd[i].w);

    int S = cnt++;
    for (int i = 0; i < N; i++){
        qzj[i].id = cnt++;
        qzj[N+i].id=cnt++;
        G[qzj[i].id][qzj[N+i].id].capacity=1;
        mp[qzj[N+i].id]=i+1;
        mp[qzj[i].id]=i+1;
    }
        

    for (int i = 0; i < M; i++)
        zd[i].id = cnt++;

    int T = cnt;

    for (int i = 0; i < N; i++)
        if (qzj[i].w == 0)
            G[S][qzj[i].id].capacity = 1;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
            {
                if (qzj[i].l >= qzj[j].w)
                    G[qzj[N+i].id][qzj[j].id].capacity = 1;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (qzj[i].l >= zd[j].w)
                G[qzj[N+i].id][zd[j].id].capacity = 1;

    for (int j = 0; j < M; j++)
        G[zd[j].id][T].capacity = 1;

    int flow = Max_Flow_Dinic(S, T);
   // cout<<flow<<endl;
    if (flow != M)
        printf("impossible\n");
    else
    {

        for (int i = 0; i < M; i++)
        {
            int cur = zd[i].id;
            vector<int> ans;
            while (cur != 1)
            {
                for (int j = 1; j <= cnt; j++)
                {
                    if (G[j][cur].flow == 1)
                    {
                        //G[j][cur].flow=0;

                        ans.push_back(mp[j]);
                        //cout<<j-1<<" ";
                        cur = j;
                        break;
                    }
                }
            }

            ans.pop_back();
            while (!ans.empty())
            {
                cout << ans.back() << " ";
                ans.pop_back();
                ans.pop_back();
            }
            cout << endl;
        }
    }

    return 0;
}