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
    int cnt=0;
    int ch[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
}node[500001];
int cnt=1;

void insert(string a){

    int cur=0;
    for(int i=0;i<a.length();i++){
        if(node[cur].ch[a[i]-'a']==0)
            node[cur].ch[a[i]-'a']=cnt++;
        cur=node[cur].ch[a[i]-'a'];
        node[cur].cnt++;
    }
}

int search(string a){
    int cur=0;
    for(int i=0;i<a.length();i++){
        if(node[cur].ch[a[i]-'a']==0)
            return 0;
        cur=node[cur].ch[a[i]-'a'];
    }
    return node[cur].cnt;
}


int main(){

    cnt=1;

    string temp;
    char c;
    while(1){
        c=getchar();
        if(c=='\n'){
            if(temp=="")
                break;
            insert(temp);

            temp="";
        }
        else{
            temp.push_back(c);
        }
    }

    while(1){
        c=getchar();
        if(c==-1)
            break;
        if(c=='\n'){

            printf("%d\n",search(temp));
            temp="";
        }
        else{
            temp.push_back(c);
        }
    }

    return 0;
}








