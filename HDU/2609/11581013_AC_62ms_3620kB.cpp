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


int getMin(char a[],int len){
    int i=0,j=1,k=0;
    while(i+k<len&&j+k<len){
        if(a[i+k]==a[j+k])
            k++;
        else{
            if(a[i+k]>a[j+k])
                i=i+k+1;
            else
                j=j+k+1;
            k=0;
            if(i==j)
                j++;
        }
    }
    return min(i,j);
}



char a[205];//原始串

int nxt[1000050];

int N,M;

int main(){
    int num;

    while(~scanf("%d",&num)){

        int len;
        set<string> ans;
        for(int i=0;i<num;i++){
            scanf("%s",a);
            len=strlen(a);
            for(int i=0;i<len;i++)
                a[i+len]=a[i];
            a[len*2]='\0';
            int index=getMin(a,len*2);
            a[index+len]='\0';
            ans.insert(a+index);
        }
        printf("%d\n",ans.size());



    }

    return 0;
}






