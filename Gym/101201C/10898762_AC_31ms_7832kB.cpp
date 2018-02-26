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
#define MAXV 2000005
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;


inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int tree[1000005];

int n,k,r;
void add(int k,int num)
{
    while(k<=n)
    {
        tree[k]+=num;
        k+=k&-k;
    }
}

int read(int k)//1~k的区间和
{
    int sum=0;
    while(k)
    {
        sum+=tree[k];
        k-=k&-k;
    }
    return sum;
}

int have[1000000];


int main()
{

    while(cin>>n>>k>>r){

        memset(tree,0,sizeof(tree));
        memset(have,0,sizeof(have));
        int a;

        for(int i=0;i<k;i++){
            scanf("%d",&a);

            add(a,1);
            have[a]=1;

        }

        int ans=0;

        for(int i=1;i+r-1<=n;i++){
            int ll=i;
            int rr=i+r-1;
            int num=read(rr)-read(ll-1);
           // cout<<num<<endl;
            if(num<2){

                for(int j=rr;j>=ll;j--){
                    if(have[j]==0){
                        have[j]=1;
                        add(j,1);
                        num++;
                        ans++;
                        if(num==2)
                            break;
                    }
                }
            }
        }

        cout<<ans<<endl;

    }


    return 0;
}







