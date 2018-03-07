#include <iostream>
#include <deque>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;

string a[1005];

vector<vector<string> > list(6);

int main(){

    int N;
    cin>>N;

    map<char,int> w;

    map<char,int> nozero;

    for(int i=0;i<N;i++){
        cin>>a[i];
        list[a[i].size()-1].push_back(a[i]);
        for(int j=0;j<a[i].size();j++)
            w[a[i][j]]+=pow(10,a[i].size()-j-1);
        nozero[a[i][0]]=1;
    }

    
    vector<pair<int,char> > s;
    for(int i=0;i<10;i++)
        if(w['a'+i]!=0)
            s.push_back(make_pair(w['a'+i],'a'+i));
    
    sort(s.begin(),s.end());

        
    map<char,int> r;

    bool setz=1;
    int num=1;
    for(int i=s.size()-1;i>=0;i--){
       // cout<<s[i].second<<" "<<nozero[s[i].second]<<endl;
        if(nozero[s[i].second]==0&&setz==1){
            r[s[i].second]=0;
            setz=0;
            continue;
        }
            
        r[s[i].second]=num;
        num++;    
    }
        
    
    int sum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<a[i].size();j++)
           a[i][j]='0'+r[a[i][j]];
    //    cout<<a[i]<<endl;
        sum+=stoi(a[i]);
    }

    cout<<sum<<endl;



    return 0;
}
