#include<bits/stdc++.h>
using namespace std;

struct node{
    string name;
    int s;
}P[100005];

bool cmp(node &a,node &b){
    return a.s>b.s;
}

int main()
{

    ios::sync_with_stdio(false);

    int N,D,K;
    cin>>N>>D>>K;
    for(int i=0;i<N;i++){
        cin>>P[i].name>>P[i].s;
    }

    sort(P,P+N,cmp);

    vector<string> ans;

    int sum=0;
    for(int i=0;i<N;i++){
        sum+=P[i].s;
        ans.push_back(P[i].name);
        K--;
        if(sum>=D){
            break;
        }
    }

    if(K>=0&&sum>=D){
        cout<<ans.size()<<endl;
        for(auto t:ans){
            cout<<t<<", YOU ARE FIRED!"<<endl;
        }
    }
    else{
        cout<<"impossible"<<endl;
    }

    return 0;
}
