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

  //  for(int i=0;i<=len;i++)
  //      cout<<nxt[i];

    if(nxt[len]==0)
        printf("%d\n",len);
    else{
        int jie=len-nxt[len];

            if(len%jie==0){
                printf("%d\n",0);
            }
            else{
                printf("%d\n",jie+(jie-(len-nxt[len]/jie*jie)));
            }

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
            j=0;
        }
    }
    return ans;
}


char a[1000050];//原始串
char b[1000050];//模式串
int nxt[1000050];
int N,M;

int main(){

int t;
scanf("%d",&t);
    while(t--){

        scanf("%s",a);
        N=strlen(a);


        getNext(a,N,nxt);

    }

    return 0;
}
