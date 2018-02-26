#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

const int maxn=20000;

int pre[maxn];
int sum[maxn];//0偶数1奇数

int find(int x){
    if(x!=pre[x]){
        int tmp=pre[x];
        pre[x]=find(pre[x]);

        sum[x]=(sum[tmp]+sum[x])%2;
    }
    return pre[x];
}




int main(){
    int n;
    scanf("%d",&n);

    map<int,int> m;



    for(int i=0;i<maxn;i++){
        pre[i]=i;
        sum[i]=0;
    }

    int k;
    scanf("%d",&k);
int count=1;
    int ans=k;
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;

        if(!m[a])
        m[a]=count++;
        if(!m[b])
        m[b]=count++;

        a=m[a];
        b=m[b];

        char c[10];
        scanf("%s",c);

        int eo=0;
        if(c[0]=='o')
            eo=1;


        if(ans!=k)
            continue;

        int ar=find(a);
        int br=find(b);



        if(ar!=br){
            pre[ar]=br;
            sum[ar]=(sum[a]+eo+sum[b])%2;
            find(a);
            find(b);
        }
        else{

            if((sum[a]+sum[b])%2!=eo)
                ans=i;
        }

    }
    printf("%d\n",ans);






    return 0;
}
