#include<iostream>
#include<vector>
using namespace std;



int N,K;

char str[10];
vector<int> g[10];

int dp[10][1<<10];

int bitcount(int x){
    return x==0?0:bitcount(x>>1)+(x&1);
}


int main(){

    while(~scanf("%d%d",&N,&K)&&N!=-1){

        for(int i=1;i<=N;i++){
            g[i].clear();
            scanf("%s",str);
            for(int j=0;j<N;j++)
                if(str[j]=='#')
                    g[i].push_back(j);
        }

        dp[0][0]=1;

        int ans=0;

        for(int i=1;i<=N;i++){
            for(int j=0;j<(1<<N);j++){
                dp[i][j]=dp[i-1][j];

                for(int k=0;k<g[i].size();k++){
                    if(j&(1<<g[i][k]))
                            dp[i][j]+=dp[i-1][j^(1<<g[i][k])];
                }

                if(i==N&&bitcount(j)==K)
                    ans+=dp[i][j];

            }
        }

        printf("%d\n",ans);


    }




    return 0;
}
