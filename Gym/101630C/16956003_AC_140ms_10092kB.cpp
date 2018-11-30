#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int MAX_N=1e5+10;
vector <int> G[MAX_N],rG[MAX_N];
map<pii,bool> m;
bool used[MAX_N];
int N,M,x,y;
void add_edge(int x,int y){
    G[x].emplace_back(y),rG[y].emplace_back(x);
}
void dfs(int v){
    used[v]=true;
    for(auto x:G[v]){
        if(!used[x]){
            m.erase(pii{v,x});
            dfs(x);
        }
    }
}
void rdfs(int v){
    used[v]=true;
    for(auto x:rG[v]){
        if(!used[x]){
            m.erase(pii{x,v});
            rdfs(x);
        }
    }
}
void init(){
    for(int i=1;i<=N;i++){
        G[i].clear();
        rG[i].clear();
        used[i]=false;
    }
    m.clear();
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&x,&y);
            add_edge(x,y);
            m[pii{x,y}]=true;
        }
        dfs(1);
        for(int i=1;i<=N;i++){
            used[i]=false;
        }
        rdfs(1);
        int cnt=M-2*N;
        for(auto x:m){
            if(cnt){
                pii tmp=x.first;
                printf("%d %d\n",tmp.first,tmp.second);
                cnt--;
            }else{
                break;
            }
        }
    }
    return 0;
}




