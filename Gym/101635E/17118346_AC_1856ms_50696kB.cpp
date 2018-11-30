#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=51000;

int C[MAXN];
int V[MAXN];
int deg[MAXN];

char s1[35],s2[35],s3[35];
map<string,int> mp;
int cnt=0;
vector<int> G[MAXN];

struct edge{
    int u,v,C,V,next;
}e[2000005];
int head[MAXN],edge_num=0;

void insert_edge(int u,int v,int C,int V){
    e[edge_num].u=u;
    e[edge_num].v=v;
    e[edge_num].C=C;
    e[edge_num].V=V;
    e[edge_num].next=head[u];
    head[u]=edge_num++;
}

int dp[100005];
int W;

void zero_one_pack(int w,int v){

    for(int i=W;i>=w;i--)
        dp[i]=max(dp[i-w]+v,dp[i]);
}



int main()
{
    memset(head,-1,sizeof(head));

    scanf("%d",&W);

    int N;
    scanf("%d",&N);

    int CC,VV;
    for(int i=0;i<N;i++){
        scanf("%s%s%s",s1,s2,s3);
        scanf("%d%d",&CC,&VV);

        if(mp[s1]==0)
            mp[s1]=++cnt;

        if(mp[s2]==0)
            mp[s2]=++cnt;

        int u=mp[s2];
        int v=mp[s1];
        insert_edge(v,u,CC,VV);
        G[u].push_back(v);
        deg[v]++;
    }

    queue<int> que;
    for(int i=1;i<=cnt;i++){
        if(deg[i]==0)
            que.push(i);
    }

    while(!que.empty()){
        int u=que.front();
        que.pop();

        CC=0x3f3f3f3f;
        VV=0;

        for(int i=head[u];~i;i=e[i].next){
            int CCC=e[i].C+C[e[i].v];
            int VVV=e[i].V+V[e[i].v];
            if(CCC<CC){
                VV=VVV;
                CC=CCC;
            }
            else if(CCC==CC)
                VV=max(VV,VVV);
        }

        if(CC==0x3f3f3f3f)
            CC=0;
        C[u]=CC;
        V[u]=VV;

        for(auto &t:G[u]){
            deg[t]--;
            if(deg[t]==0)
                que.push(t);
        }

    }



    for(int i=1;i<=cnt;i++){
     //   cout<<C[i]<<" "<<V[i]<<endl;
        zero_one_pack(C[i],V[i]);
    }

    int ans1=0;
    int ans2=0;

    for(int i=0;i<=W;i++)
        if(dp[i]>ans1){
            ans1=dp[i];
            ans2=i;
        }

    printf("%d\n%d\n",ans1,ans2);


    return 0;
}









