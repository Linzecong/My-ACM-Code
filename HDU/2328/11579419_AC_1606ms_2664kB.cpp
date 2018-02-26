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
using namespace std;
typedef long long int ll;

void getNext(char a[],int len,int nxt[]){
    nxt[0]=nxt[1]=0;
    for(int i=1;i<len;i++){
        int j=nxt[i];
        while(j&&a[i]!=a[j])
            j=nxt[j];
        nxt[i+1]=(a[i]==a[j])?j+1:0;
    }
}

int KMP(char a[],char b[],int N,int M,int nxt[]){
    int j=0;
    int ans=0;
    for(int i=0;i<N;i++){
        while(j&&a[i]!=b[j])
            j=nxt[j];
        if(a[i]==b[j])
            j++;
        if(j==M){
            ans++;
        }
    }
    return ans;
}

char a[4005][205];//原始串
char b[1000050];//模式串
int nxt[1000050];

int N,M;

int main(){

    int num;
    while(~scanf("%d",&num)){

        vector<string> ans;
        map<string,bool> vis;
        if(num==0)
            break;

        for(int i=0;i<num;i++)
            scanf("%s",a[i]);

        N=strlen(a[0]);
        int len;
        for(len=N;len>=1;len--){
            for(int i=0;i+len<=N;i++){

                for(int j=0;j<len;j++){
                    b[j]=a[0][j+i];
                }
                b[len]='\0';
                if(vis[b]==1)
                    continue;
                vis[b]=1;

                getNext(b,len,nxt);

                bool have=1;
                for(int k=1;k<num;k++){
                    bool flag=0;
                    if(KMP(a[k],b,N,len,nxt)){
                        flag=1;
                    }

                    if(flag==0){
                        have=0;
                        break;
                    }
                }

                if(have){
                    ans.push_back(b);
                   // printf("%s\n",b);

                }
            }
            if(ans.size()){
                sort(ans.begin(),ans.end());
                cout<<ans.front()<<endl;
                len=0;
            }
        }

        if(len==0)
            printf("IDENTITY LOST\n");



    }

    return 0;
}






