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

int no[1000][1000];


int main()
{



    scanf("%d%d%d%d%d",&r,&s,&m,&d,&n);
    ll temp;
    for(int i=1;i<=r;i++){
        scanf("%lld",&brand[i]);
    }

    int k;
    int rrr;
    for(int i=1;i<=s+m+d;i++){

        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&rrr);
            ingre[i].push_back(rrr);
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
    long double aaa=0;
    for(int i=1;i<=s;i++){
        for(int j=s+1;j<=s+m;j++){
            for(int k=s+m+1;k<=s+m+d;k++){

                if(no[i][k])
                    continue;
                if(no[j][k])
                    continue;
                if(no[i][j])
                    continue;

                set<int> ss;
                for(int q=0;q<ingre[i].size();q++)
                    ss.insert(ingre[i][q]);

                for(int p=0;p<ingre[j].size();p++)
                    ss.insert(ingre[j][p]);

                for(int l=0;l<ingre[k].size();l++)
                    ss.insert(ingre[k][l]);


                ll tt=1;
                long double ttt=1;
                for(set<int>::iterator it=ss.begin();it!=ss.end();it++){
                    tt*=brand[(*it)];
                    ttt*=brand[(*it)];

                    if(ttt>1000000000000000000LL)
                        flag=1;
                }
                aaa+=tt;
                ans+=tt;

                if(aaa>1000000000000000000LL||aaa<0)
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







