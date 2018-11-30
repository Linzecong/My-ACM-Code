#include<iostream>
#include<string.h>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=20005;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edge{
    int u;
    string v;
    int next;
}e[MAXN];
int edge_num=0;
int head[MAXN];
void insert_edge(int u,string v){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

map<string,int> mp,ans;
bool vis[MAXN];

int main(){

    int N;
    scanf("%d",&N);
    string a,b,c;
    int cnt=0;
    memset(head,-1,sizeof(head));
    bool have=0;
    for(int i=1;i<=N;i++){
        cin>>a>>b>>c;
        if(mp[a]==0)mp[a]=++cnt;
        if(mp[b]==0)mp[b]=++cnt;
        if(mp[c]==0)mp[c]=++cnt;
        ans[a]=-1;
        ans[b]=-1;
        ans[c]=-1;
        insert_edge(mp[a],b);
        insert_edge(mp[a],c);

        insert_edge(mp[b],c);
        insert_edge(mp[b],a);

        insert_edge(mp[c],a);
        insert_edge(mp[c],b);
        if(a=="Isenbaev"||b=="Isenbaev"||c=="Isenbaev")
            have=1;
    }

    if(have==1){
    queue<pair<string,int> > que;
    que.push(make_pair("Isenbaev",0));
    vis[mp["Isenbaev"]]=1;
    while(!que.empty()){
        pair<string,int> tp=que.front();
        ans[tp.first]=tp.second;

        que.pop();

        int u=mp[tp.first];
        for(int i=head[u];~i;i=e[i].next){
            string v=e[i].v;
            if(vis[mp[v]])
                continue;
            vis[mp[v]]=1;
            que.push(make_pair(v,tp.second+1));
        }
    }
    }

    for(auto &a:ans){
        if(a.second==-1)
            cout<<a.first<<" "<<"undefined"<<endl;
            else

        cout<<a.first<<" "<<a.second<<endl;
    }





    return 0;
}





