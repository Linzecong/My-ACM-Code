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
    int ch[26];
}node[200005];
int cnt=1;

void insert(string a){
    int cur=0;
    for(int i=0;i<a.length();i++){
        if(node[cur].ch[a[i]-'a']==-1)
            node[cur].ch[a[i]-'a']=cnt++;
        cur=node[cur].ch[a[i]-'a'];
    }
    node[cur].have=1;
}

bool search(string a){
    bool have=0;
    int cur=0;
    for(int i=0;i<a.length();i++){
        if(node[cur].ch[a[i]-'a']==-1)
            return false;
        cur=node[cur].ch[a[i]-'a'];
    }
    if(node[cur].have==1)
        have=1;
    return have;
}

int main(){


    cnt=1;
    memset(node,-1,sizeof(node));

    string temp;
    vector<string> list;


    while(cin>>temp){
        insert(temp);
        list.push_back(temp);
    }

    for(int i=0;i<list.size();i++){

        for(int k=1;k<list[i].length();k++)
        {
            string a,b;
            for(int j=0;j<k;j++)
                a.push_back(list[i][j]);
            for(int j=k;j<list[i].length();j++)
                b.push_back(list[i][j]);


            if(search(a)&&search(b)){
             //   cout<<a<<" "<<b<<endl;
                cout<<list[i]<<endl;
                break;
            }
        }

    }



    return 0;
}







