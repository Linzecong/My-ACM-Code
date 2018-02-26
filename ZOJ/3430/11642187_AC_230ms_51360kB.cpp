#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int kind = 256; //the maximum number of letter
const int N = 50010;
struct Node
{
    int next[kind];
    int fail;
    int cnt;
    void build_node() {
        for(int i = 0; i < kind; i++)
            next[i] = 0;
        fail = 0;
        cnt = 0;
    }
} node[N];
int digit[N], code[N], Size, vis[N];
char file[N], vir[N];

int fun(char ch)  //convert char to int
{
    if(ch >= 'A' && ch <= 'Z') return ch - 'A';
    if(ch >= 'a' && ch <= 'z') return ch - 'a' + 26;
    if(ch >= '0' && ch <= '9') return ch - '0' + 52;
    if(ch == '+') return 62;
    return 63;
}

void change(char *str)
{
    int i, j, len, t;
    vector<int> v;
    memset(digit, 0, sizeof(digit));
    for(len = strlen(str); str[len-1] == '='; len--) ;
    str[len] = '\0';
    for(i = 0; i < len; i++)
        v.push_back(fun(str[i]));
    for(i = 0; i < v.size(); i++) {
        for(j = 6 * (i + 1) - 1; j >= 6 * i; j--) {
            if(v[i]&1)
                digit[j] = 1;
            v[i] >>= 1;
        }
    }
    int k = v.size() * 6 / 8; //the number of letter before encode
    for(i = 0; i < k; i++) {
        for(t = 0, j = 8 * i; j < 8 * (i + 1); j++)
            t = (t << 1) + digit[j];
        code[i] = t;
    }
    code[i] = -1;
}

void Insert()
{
    int cur, index, i;
    for(cur = i = 0; code[i] >= 0; i++) {
        index = code[i];
        if(node[cur].next[index] == 0) {
            node[++Size].build_node();
            node[cur].next[index] = Size;
        }
        cur = node[cur].next[index];
    }
    node[cur].cnt++;
}
void build_ac_automation(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < kind; i++) {
            if(node[cur].next[i]) {
                int p = node[cur].next[i];
                if(cur)
                    node[p].fail = node[node[cur].fail].next[i];
                q.push(p);
            }
            else
                node[cur].next[i] = node[node[cur].fail].next[i];
        }
    }
}
int Query()
{
    int ans = 0;
    for(int i = 0, cur = 0; code[i] >= 0; i++) {
        int index = code[i];
        cur = node[cur].next[index];
        for(int j = cur; j; j = node[j].fail) {
            if(!vis[j]) {
                ans += node[j].cnt;
                vis[j] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    while(~scanf("%d",&n)) {
        node[0].build_node();
        Size = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s",vir);
            change(vir);
            Insert();
        }
        build_ac_automation(0);
        scanf("%d",&m);
        while(m--) {
            memset(vis, 0, sizeof(vis));
            scanf("%s", file);
            change(file);
            printf("%d\n", Query());
        }
        printf("\n");
    }
    return 0;
}