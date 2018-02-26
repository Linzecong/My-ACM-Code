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

struct Node{
    int have;
    int ch[10];
}node[100005];
int cnt=1;

void insert(string a){
    int cur=0;
    for(int i=0;i<a.length();i++){
        if(node[cur].ch[a[i]-'0']==-1)
            node[cur].ch[a[i]-'0']=cnt++;
        cur=node[cur].ch[a[i]-'0'];
    }
    node[cur].have=1;
}

bool search(string a){
    bool have=0;
    int cur=0;
    for(int i=0;i<a.length();i++){
        cur=node[cur].ch[a[i]-'0'];
        if(node[cur].have==1&&i!=a.length()-1)
            have=1;
    }
    return have;
}

int main(){


    int t;
    scanf("%d",&t);
    while(t--){
        cnt=1;
        memset(node,-1,sizeof(node));
        int n;
        scanf("%d",&n);
        string temp;
        vector<string> list;
        bool flag=0;

        for(int i=0;i<n;i++){
            cin>>temp;
            insert(temp);
            list.push_back(temp);
        }

        for(int i=0;i<n;i++){
            flag|=search(list[i]);
        }


        if(!flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}







