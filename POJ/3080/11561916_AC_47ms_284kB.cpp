#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
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

char a[15][100];//原始串

char b[1000050];//模式串

int nxt[1000050];
int N,M;
char str[100];
int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        int num;
        scanf("%d",&num);
        for(int i=0;i<num;i++)
            scanf("%s",a[i]);
        N=60;

        for(int len=60;len>=3;len--){
            vector<string> ans;
            for(int k=0;k<num;k++){
                for(int i=0;i+len<=60;i++){
                    getNext(a[k]+i,len,nxt);
                    bool flag=1;
                    for(int j=0;j<num;j++){
                        if(!KMP(a[j],a[k]+i,60,len,nxt)){
                            flag=0;
                            break;
                        }
                    }
                    if(flag){
                        string temp;
                        for(int q=0;q<len;q++)
                            temp.push_back(a[k][i+q]);
                        ans.push_back(temp);
                    }
                }
            }
            if(!ans.empty()){
                sort(ans.begin(),ans.end());
                cout<<ans.front()<<endl;
                break;
            }
            if(len==3)
                cout<<"no significant commonalities"<<endl;
        }


    }


    return 0;
}












