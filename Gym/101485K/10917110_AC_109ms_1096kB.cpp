#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define MAXV 2000005
#define INF (1LL<<62)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;

int r,s,m,d,n;

ll brand[105000];
vector<int> ingre[10000];

int no[100][100];


int main()
{

    // cout<<1000000000000000000LL<<endl;
    memset(no,0,sizeof(no));
    scanf("%d%d%d%d%d",&r,&s,&m,&d,&n);
    int temp;
    for(int i=1;i<=r;i++){
        scanf("%lld",&temp);
        brand[i]=temp;
    }

    int k;
    for(int i=1;i<=s+m+d;i++){

        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&temp);
            ingre[i].push_back(temp);
        }

    }
    int a,b;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        no[a][b]=1;
        no[b][a]=1;
    }

    bool flag=0;
    ll ans=0;
    for(int i=1;i<=s;i++){
        for(int j=s+1;j<=s+m;j++){

            if(no[i][j])
                continue;

            for(int k=s+m+1;k<=s+m+d;k++){
                if(no[j][k])
                    continue;
                if(no[i][k])
                    continue;

                set<int> ss;
                for(int q=0;q<ingre[i].size();q++)
                    ss.insert(ingre[i][q]);

                for(int p=0;p<ingre[j].size();p++)
                    ss.insert(ingre[j][p]);

                for(int l=0;l<ingre[k].size();l++)
                    ss.insert(ingre[k][l]);

                ll tt=1;
                for(set<int>::iterator it=ss.begin();it!=ss.end();it++){
                    if(tt>9223372036854775807/brand[(*it)])flag=1;
                    tt*=brand[(*it)];
                    if(tt>1000000000000000000LL||tt<0)flag=1;
                }

                ans+=tt;
                if(ans>1000000000000000000LL||ans<0)
                    flag=1;


            }
        }
    }


    if(!flag)
        cout<<ans<<endl;
    else
        cout<<"too many"<<endl;



    return 0;
}
