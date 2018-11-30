#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;

const int MAXN=200005;

int nxt[MAXN][2];
int sta[MAXN];
int tot=1;
int root=1;
int mask;

void insert(uint x){
    int cur=root;
    for(int i=31;i>=31-mask+1;i--){

        uint c=((x>>i)&1);
        if(nxt[cur][c]==0)
            nxt[cur][c]=++tot;
        cur=nxt[cur][c];

    }
    sta[cur]=1;
}

vector<pair<uint,int> > ans;
void dfs(int u,int dep,uint sum){
    if(u==0){
        ans.push_back({sum,dep});
        return;
    }

    if(sta[u]==1){
        return;
    }

    dfs(nxt[u][0],dep+1,sum<<1);
    dfs(nxt[u][1],dep+1,(sum<<1)+1);
}


int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        tot=1;
        root=1;
        memset(nxt,0,sizeof(nxt));
        memset(sta,0,sizeof(sta));
        int N;
        scanf("%d",&N);
        if(N==0){

            printf("Case #%d:\n",qqq);
            printf("%d\n",1);
            printf("%d.%d.%d.%d/%d\n",0,0,0,0,0);
continue;
        }
        int a,b,c,d;
        ans.clear();
        for(int i=0;i<N;i++){
            scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&mask);

            uint sum=a;
            sum<<=8;
            sum+=b;
            sum<<=8;
            sum+=c;
            sum<<=8;
            sum+=d;
           // bitset<32> s(sum);
            //cout<<s<<endl;
            insert(sum);
        }

        dfs(root,0,0);

        printf("Case #%d:\n",qqq);
        printf("%d\n",ans.size());

        for(int i=0;i<ans.size();i++){

            uint s=ans[i].first;
            int dd=ans[i].second;

            s<<=(32-dd);

            a=(s>>24);
            b=(s>>16)%(1<<8);
            c=(s>>8)%(1<<8);
            d=s%(1<<8);
            printf("%d.%d.%d.%d/%d\n",a,b,c,d,dd);



        }


    }


    return 0;
}









