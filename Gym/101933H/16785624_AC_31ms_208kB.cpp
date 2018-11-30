#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN=1005;


struct mac{
    string name;
    ll p,c,t,r;
    int id;
}M[MAXN];

bool cmpp(mac a,mac b){
    return a.p<b.p;
}

bool cmpi(mac a,mac b){
    return a.id<b.id;
}

int main()
{
    ll L;
    int N;
    scanf("%lld%d",&L,&N);

    for(int i=0;i<N;i++){

        char c;
        scanf("%c",&c);
        while(1){
            scanf("%c",&c);
            if(c==','){
                scanf("%lld,%lld,%lld,%lld",&M[i].p,&M[i].c,&M[i].t,&M[i].r);
                M[i].id=i;
                break;
            }
            else{
                M[i].name.push_back(c);
            }
        }
        // cout<<M[i].name<<" "<<M[i].p<<" "<<M[i].c<<" "<<M[i].t<<" "<<M[i].r<<endl;
    }

    vector<mac> ans;
    sort(M,M+N,cmpp);

    for(int i=0;i<N;i++){

        ll t=M[i].t+M[i].r;

        ll num=10080ll*998244353ll/t;

        ll yu=10080ll*998244353ll%t;

        if(yu>=M[i].t)
            yu=M[i].t;

        ll c=M[i].t*M[i].c*num;
        c+=yu*M[i].c;

        if(c>=L*998244353ll){

            if(ans.empty()||ans.back().p==M[i].p)
                ans.push_back(M[i]);
            else
                break;
        }

        

    }

    sort(ans.begin(),ans.end(),cmpi);

    for(auto i:ans)
        cout<<i.name<<endl;

    if(ans.empty())
        cout<<"no such mower"<<endl;


    return 0;
}









