#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int node[100000*20][2];
int tot=0;
int root=0;

void insert(ll x){
    bitset<33> s(x);
    int cur=root;
    for(int i=32;i>=0;i--){
        if(node[cur][s[i]]==0)
            node[cur][s[i]]=++tot;
        cur=node[cur][s[i]];
    }
}

ll search(ll x){
    bitset<33> s(x);
    int cur=root;
    bitset<33> ans;
    for(int i=32;i>=0;i--){
        if(s[i]){
            if(node[cur][0]){
                ans[i]=0;
                cur=node[cur][0];
            }
            else{
                ans[i]=1;
                cur=node[cur][1];
            }
        }
        else{
            if(node[cur][1]){
                ans[i]=1;
                cur=node[cur][1];
            }
            else{
                cur=node[cur][0];
            }
        }
    }
    return ans.to_ullong();
}

int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        printf("Case #%d:\n",qqq);
        tot=0;
        memset(node,0,sizeof(node));
        int N,M;
        ll x;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            scanf("%lld",&x);
            insert(x);
        }
        while(M--){
            scanf("%lld",&x);
            cout<<search(x)<<endl;
        }
    }
    return 0;
}
