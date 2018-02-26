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

struct building{
    double p;
    int index;
}list[1000];

bool cmp(building a,building b){
    return a.p<b.p;
}

bool cmp2(building a,building b){
    return a.index<b.index;
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        double R,r;
        scanf("%d%lf%lf",&n,&R,&r);

        vector<building> ans;
        vector<building> others;
        double x,y;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&x,&y);
            list[i].index=i;
            if(x*x+y*y<=(R-2*r)*(R-2*r)){
                ans.push_back(list[i]);
            }
            else{
                list[i].p=x*x+y*y;
                others.push_back(list[i]);
            }

        }

        if(ans.empty()){
            sort(others.begin(),others.end(),cmp);
            double last=others[0].p;
            for(int i=0;i<others.size();i++){
                if(others[i].p==last)
                    ans.push_back(others[i]);
            }
            sort(ans.begin(),ans.end(),cmp2);

            printf("%d\n",ans.size());
            for(int i=0;i<ans.size()-1;i++)
                printf("%d ",ans[i].index);
            printf("%d\n",ans[ans.size()-1].index);
        }
        else{
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size()-1;i++)
                printf("%d ",ans[i].index);
            printf("%d\n",ans[ans.size()-1].index);
        }

    }


    return 0;
}
