#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;


int tu[25][3];

int start;
int time=1;

bool vis[25];


void dfs(int cur,vector<int> res){




    if(res.size()==21){
        if(res.back()==start){
        cout<<time++<<":  ";
        for(int i=0;i<20;i++)
            cout<<res[i]<<" ";
        cout<<start<<endl;
        }
        return;
    }




    for(int i=0;i<3;i++){
        if(vis[tu[cur][i]]==1){
            continue;
        }
        else{
            vis[tu[cur][i]]=1;
            res.push_back(tu[cur][i]);
            dfs(tu[cur][i],res);
            vis[tu[cur][i]]=0;
            res.pop_back();
        }
    }


}

int main(){


   for(int i=1;i<=20;i++){
       for(int j=0;j<3;j++)
           cin>>tu[i][j];
       sort(tu[i],tu[i]+3);
   }

   while(1){
       int n;
       cin>>n;

       if(n==0)
           break;

       time=1;
       start=n;
       vector<int> res;
       res.push_back(n);
       dfs(start,res);
   }








    return 0;
}
