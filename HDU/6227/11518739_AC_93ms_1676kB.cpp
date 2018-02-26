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

bool a[10005];
bool b[10005];

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n;
        scanf("%d",&n);
        int temp;
        int minn=1000000;
        int maxnn=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            a[temp]=1;
            b[temp]=1;
            minn=min(minn,temp);
            maxnn=max(maxnn,temp);
        }

        int ans1=0;
        if(a[minn+1]==1){
            for(int i=minn;i<=maxnn;i++)
                if(a[i]==0)
                    ans1++;
        }
        else{
            bool flag=0;
            for(int i=minn+1;i<=maxnn;i++)
                if(a[i]==0&&flag)
                    ans1++;
                else{
                    if(a[i]==1)
                        flag=1;
                }
        }

        int ans2=0;
        if(a[maxnn-1]==1){
            for(int i=maxnn;i>=minn;i--)
                if(a[i]==0)
                    ans2++;
        }
        else{
            bool flag=0;
            for(int i=maxnn-1;i>=minn;i--)
                if(a[i]==0&&flag)
                    ans2++;
                else{
                    if(a[i]==1)
                        flag=1;
                }
        }


//        int ans1=0;
//        for(int i=minn;i<=maxnn;i++){
//            bool flag=0;
//            for(int j=i+1;j<=maxnn;j++){
//                if(a[j]==1){
//                    if(flag==0){
//                        i=j-1;
//                        flag=1;
//                    }
//                }
//                else{
//                    if(flag){
//                        a[j]=1;
//                        ans1++;
//                        break;
//                    }
//                }
//            }
//        }


//        int ans2=0;
//        for(int i=maxnn;i>=minn;i--){
//            bool flag=0;
//            for(int j=i-1;j>=minn;j--){
//                if(a[j]==1){
//                    if(flag==0){
//                        i=j+1;
//                        flag=1;
//                    }
//                }
//                else{
//                    if(flag){
//                        a[j]=1;
//                        ans2++;
//                        break;
//                    }
//                }
//            }
//        }

        printf("%d\n",ans1>ans2?ans1:ans2);



    }

    return 0;
}






