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
#define INF (1<<30)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long int ll;
string str;
int len;
struct point{
    int x;
    int y;
    point(int a=0,int b=0){
        x=a;
        y=b;
    }
};



point func(int num,int zoom,point p){

    if(num==0){
        ;
    }

    if(num==1){
        p.x+=(1<<(len-zoom));
    }
    if(num==2){
        p.y+=(1<<(len-zoom));
    }
    if(num==3){
        p.x+=(1<<(len-zoom));
        p.y+=(1<<(len-zoom));
    }

    return p;
}



int main()
{

    cin>>str;
    cout<<str.length()<<" ";
    len=str.length();

    int i=len;
    point p;
    while(i--){
        p=func(str[len-i-1]-'0',len-i,p);
    }

    cout<<p.x<<" "<<p.y<<endl;


    return 0;
}







