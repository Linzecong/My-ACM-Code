#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5000;

int a[MAXN];
int b[MAXN];

int main()
{

    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=M;i++)
        scanf("%d",&b[i]);

    int ans=0;
    int num=0x3f3f3f3f;
    map<int,int> mp;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            if(b[j]>=a[i])
                mp[b[j]-a[i]]++;
        }


    for(auto &t:mp){
        if(t.second>ans){
            num=t.first;
            ans=t.second;
        }
        else if(t.second==ans){
            if(t.first<num)
                num=t.first;
        }
    }

    if(mp.size()==0)
        cout<<0<<endl;
    else
        cout<<num<<endl;


    return 0;
}
