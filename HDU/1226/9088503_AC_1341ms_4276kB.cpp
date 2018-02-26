#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N,C,M;
vector<char>  cl;

bool vis[5005];

int quickpow(int a,int b)
{
    int ans=1;
    a%=N;
    while (b)
    {
        if (b&1) ans=ans*a%N;
        b>>=1;
        a=a*a%N;
    }
    return ans;
}

int isStr(string a){
    int sum=0;

    for(int i=0;i<a.size();i++){
        int x=a[a.size()-1-i]-'0';
        if(a[a.size()-1-i]=='A')x=10;
        if(a[a.size()-1-i]=='B')x=11;
        if(a[a.size()-1-i]=='C')x=12;
        if(a[a.size()-1-i]=='D')x=13;
        if(a[a.size()-1-i]=='E')x=14;
        if(a[a.size()-1-i]=='F')x=15;

        sum=(sum+(x*(quickpow(C,i))%N)%N)%N;

    }

        return sum;
}


deque<string> que;
string bfs(){

    que.clear();
    for(int i=0;i<M;i++){
        string a;
        if(cl[i]!='0'){
        a.push_back(cl[i]);
        que.push_back(a);
        }
    }

    while(!que.empty()){
        string tp=que.front();
        que.pop_front();

        if(tp.length()>500)
            return "";

        int vv=isStr(tp);
        if(vv==0)
            return tp;
        else{
            if(!vis[vv]){
                vis[vv]=1;
                for(int i=0;i<M;i++){
                    string aa=tp;
                    aa.push_back(cl[i]);
                    que.push_back(aa);
                }
            }
        }




    }

    return "";
}


int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        cl.clear();
        scanf("%d%d%d",&N,&C,&M);
        char c;
        getchar();
        for(int i=0;i<M;i++){
            scanf("%c",&c);
            getchar();
            cl.push_back(c);
        }

        sort(cl.begin(),cl.end());

        if(N==0){
            if(cl[0]=='0'){
            cout<<0<<endl;
            continue;
            }
            else{
                printf("give me the bomb please\n");
                continue;
            }
        }


        string ans=bfs();
        if(ans=="")
            printf("give me the bomb please\n");
        else
            printf("%s\n",ans.c_str());


    }


    return 0;
}
