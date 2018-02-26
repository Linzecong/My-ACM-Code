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
typedef long long int ll;

int a[500];

struct node{
    int l;
    int w;

}list[6000];

bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}

int main(){


    int t;
    cin>>t;

    for(int qqq=1;qqq<=t;qqq++){


        memset(list,0,sizeof(list));


        int n;
        cin>>n;


        for(int i=0;i<n;i++){
            cin>>list[i].l>>list[i].w;
        }

        sort(list,list+n,cmp);

        int ans=0;
        int count=0;

        while(count<n){
            ans++;

        int cur=-1;

        for(int i=0;i<n;i++){
            if(list[i].w!=-1)
            if(list[i].w>=cur){
                count++;
                cur=list[i].w;
                list[i].w=-1;
            }
        }
        }


        cout<<ans<<endl;



    }

    return 0;
}
