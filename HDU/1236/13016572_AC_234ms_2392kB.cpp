#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long int ll;
struct man{
    string name;
    int fen;
}p[10005];

bool cmp(man a,man b)
{
    if(a.fen==b.fen){
        return a.name<b.name;
    }
    return a.fen>b.fen;
}


int m[105];

int main(){
   
    int N,M;
    int G;
    while(~scanf("%d",&N)){
        if(N==0)
            break;
        scanf("%d%d",&M,&G);

        for(int i=1;i<=M;i++)
            scanf("%d",&m[i]);
        

        int nn;
        int temp;
        int num=0;
        for(int i=0;i<N;i++){
            cin>>p[i].name;
            scanf("%d",&nn);
            p[i].fen=0;
            for(int j=0;j<nn;j++){
                scanf("%d",&temp);
                p[i].fen+=m[temp];
            }
            if(p[i].fen>=G)
               num++;
        }

        sort(p,p+N,cmp);

        printf("%d\n",num);
        for(int i=0;i<num;i++){
            cout<<p[i].name;
            printf(" %d\n",p[i].fen);
        }

    }



    return 0;
}


