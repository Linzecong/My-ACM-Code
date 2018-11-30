#include<bits/stdc++.h>
using namespace std;



map<string,int> mp;

vector<int> G[305];

bool flag,vis[305];

void dfs(int u,int v){
    vis[u]=1;
    if(u==v){
        flag=1;
        return;
    }
    for(auto &t:G[u])
        if(vis[t]==0){
            dfs(t,v);
            if(flag)
                return;
        }
}

int main()
{

    ios::sync_with_stdio(false);

    int N,M;
    cin>>N>>M;
    int cnt=0;
    string a,b,c,d,e;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c>>d>>e;
        if(mp[a]==0)
            mp[a]=++cnt;
        if(mp[e]==0)
            mp[e]=++cnt;

        G[mp[e]].push_back(mp[a]);
    }


    for(int i=0;i<M;i++){
        cin>>a>>b>>c>>d>>e;

        int u=mp[e];
        int v=mp[a];

        if(u==0||v==0||u==v){
            cout<<"Pants on Fire"<<endl;
            continue;
        }

        memset(vis,0,sizeof(vis));
        flag=0;
        dfs(u,v);

        if(flag==1){
            cout<<"Fact"<<endl;
        }
        else{
            memset(vis,0,sizeof(vis));
            flag=0;
            dfs(v,u);
            if(flag==1){
                cout<<"Alternative Fact"<<endl;
            }
            else
                cout<<"Pants on Fire"<<endl;
        }

    }



    return 0;
}
