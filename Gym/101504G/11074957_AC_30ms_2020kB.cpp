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
#include<bitset>
#include<list>
#define INF 1<<29
using namespace std;
typedef long long int ll;

vector<int> fris[55];


int main(){

    int N,x;
    scanf("%d%d",&N,&x);

    for(int i=1;i<=N;i++){
        int d;
        scanf("%d",&d);
        int temp;
        for(int j=0;j<d;j++){
            scanf("%d",&temp);
            fris[i].push_back(temp);
        }
    }
    fris[x].push_back(x);

    vector<int> ans;

    for(int i=0;i<fris[x].size();i++){
        for(int j=0;j<fris[fris[x][i]].size();j++){

            bool have=0;
            for(int k=0;k<fris[x].size();k++)
                if(fris[x][k]==fris[fris[x][i]][j])
                    have=1;

            if(have)
                continue;

            ans.push_back(fris[fris[x][i]][j]);
        }
    }

    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){

        if(i==ans.size()-1)
            cout<<ans[i];
        else
        cout<<ans[i]<<" ";
    }


    return 0;
}




