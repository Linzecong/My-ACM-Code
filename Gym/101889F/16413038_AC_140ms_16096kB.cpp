#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long ll;


struct node{
    int A,B;
    ll C;
}P[MAXN];
bool cmp(node a,node b){
    if(a.A==b.A)
        return a.B<b.B;
    return a.A<b.A;
}

int s[MAXN*2];

vector<int> li[MAXN*2];

bool cmp2(int a,int b){
    return a>b;
}

map<pair<int,int> ,ll> C;

long long tree[MAXN];

int lowbit(int t)
{
    return t&(-t);
}

void Update(int index,long long value)
{
    for(int i=index ; i<=MAXN ; i+=lowbit(i))
    {
        tree[i] = max(tree[i],value);
    }
}

long long Query(int index)//区间查询最大值
{
    long long sum = 0;
    for(int i=index ; i>0 ; i-=lowbit(i))
    {
        sum = max(sum,tree[i]);
    }
    return sum;
}


int main(){

    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d%lld",&P[i].A,&P[i].B,&P[i].C);
        s[i]=P[i].A;
        s[N+i]=P[i].B;
    }

    sort(s,s+2*N);
    int cnt=unique(s,s+2*N)-s;

    for(int i=0;i<N;i++){
        int a=lower_bound(s,s+cnt,P[i].A)-s+1;
        int b=lower_bound(s,s+cnt,P[i].B)-s+1;
        C[make_pair(a,b)]+=P[i].C;

        li[a].push_back(b);

    }

    //	cout<<cnt<<endl;

    for(int a=1;a<=cnt;a++){
        sort(li[a].begin(),li[a].end(),cmp2);


        for(int i=0;i<li[a].size();i++){
            auto b=li[a][i];

            ll tmp=Query(b-1);
            ll ans=tmp+C[make_pair(a,b)];

            Update(b,ans);
        }
    }


    cout<<Query(cnt)<<endl;

    return 0;
}
