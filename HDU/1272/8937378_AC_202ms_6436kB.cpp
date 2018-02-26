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
const int MAXN=100005;

int pre[MAXN];


int find(int x){
    if(x!=pre[x]){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}



int main()
{
    for(int i=0;i<MAXN;i++)
        pre[i]=i;
    int a,b;

    map<int,int> m;
    int count=1;
    bool is=false;
    int merge=1;
    while(~scanf("%d%d",&a,&b)){
        if(a==-1&&b==-1)
            break;

        if(a==0&&b==0){
            if(merge==1)
            {
                for(int i=0;i<=count;i++)
                    pre[i]=i;
                m.clear();
                is=false;
                count=1;
                merge=1;
                printf("Yes\n");
                continue;
            }

            if(merge!=count-1)
                is=true;

            if(is)
                printf("No\n");
            else
                printf("Yes\n");

            for(int i=0;i<=count;i++)
                pre[i]=i;

            m.clear();
            is=false;
            count=1;
            merge=1;
            continue;
        }

        if(!m[a])
            m[a]=count++;
        if(!m[b])
            m[b]=count++;

        int ar=find(m[a]);
        int br=find(m[b]);
        if(ar==br)
            is=true;
        else{
            pre[ar]=br;
            merge++;
        }

    }
    return 0;
}
