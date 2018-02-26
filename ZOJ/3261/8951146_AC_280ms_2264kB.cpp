#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10005;

int pre[MAXN];
int power[MAXN];//0同性，1不同姓

struct road{
    int x;
    int y;
    bool operator <(const road& a)const{
        return a.x<x;
    }
};

struct query{
    char str[10];
    int num1;
    int num2;
}ql[50005];




int find(int x){
    int r=pre[x];
    while(r!=pre[r])
        r=pre[r];

    int i=x,j;
    while(pre[i]!=r){
        j=pre[i];
        pre[i]=r;
        i=j;
    }

    return r;
}

int main()
{
    int n;
    bool first=true;
    while(~scanf("%d",&n)){

        if(first)first=false;
        else printf("\n");


        for(int i=0;i<n;i++){
            pre[i]=i;
            scanf("%d",&power[i]);
        }

        map<int,int> m;

        int r;
        scanf("%d",&r);
        for(int i=0;i<r;i++){
            road temp;
            scanf("%d%d",&temp.x,&temp.y);
            if(temp.x > temp.y) swap(temp.x, temp.y);

            m[temp.x*50000+temp.y]=1;
        }

        int q;
        scanf("%d",&q);

        for(int i=0;i<q;i++){
            scanf("%s",ql[i].str);
            if(ql[i].str[0]=='d'){
                road temp;
                scanf("%d%d",&temp.x,&temp.y);
                if(temp.x > temp.y) swap(temp.x, temp.y);

                ql[i].num1=temp.x;
                ql[i].num2=temp.y;
                m[temp.x*50000+temp.y]=0;
            }
            else{
                scanf("%d",&ql[i].num1);
            }
        }

        for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
            if(i->second==1){
                int ar=find(i->first/50000),br=find(i->first%50000);


                if(power[ar]>=power[br]){
                    if(power[ar]==power[br]){
                        if(ar<br)
                            pre[br]=ar;
                        else
                            pre[ar]=br;
                    }
                    else
                        pre[br]=ar;
                }
                else
                    pre[ar]=br;

            }
        }


        int ans[q];

        for(int i=q-1;i>=0;i--){
            ans[i]=-2;
            if(ql[i].str[0]=='q'){
                int fa=find(ql[i].num1);
                ans[i]=power[fa]>power[ql[i].num1]?fa:-1;
            }
            else{
                int ar=find(ql[i].num1),br=find(ql[i].num2);


                if(power[ar]>=power[br]){
                    if(power[ar]==power[br]){
                        if(ar<br)
                            pre[br]=ar;
                        else
                            pre[ar]=br;
                    }
                    else
                        pre[br]=ar;
                }
                else
                    pre[ar]=br;

            }

        }


        for(int i=0;i<q;i++)
            if(ans[i]!=-2)
                printf("%d\n",ans[i]);






    }



    return 0;
}
