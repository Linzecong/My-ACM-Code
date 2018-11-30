#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int MAXN = 300500;
const int INF = 0x3f3f3f3f;

map<int,int> vis;

int main()
{
    int N;
    scanf("%d",&N);

    int tmp;
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        for(int j=1;j*j<=tmp;j++){
            if(tmp%j==0){
                vis[j]++;
                if(j*j!=tmp)
                vis[tmp/j]++;
            }
        }
    }
    int ans=1;
    for(auto &i:vis){
       // cout<<i.second<<" "<<i.first<<endl;
        if(i.second>=2)
            ans=max(i.first,ans);
    }
    cout<<ans<<endl;



    return 0;
}



