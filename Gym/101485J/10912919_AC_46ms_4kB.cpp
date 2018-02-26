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



int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        unsigned char b=a;
       // cout<<int(b)<<endl;

      //  cout<<(b^(unsigned char)(b<<1))<<endl;

        for(int j=0;j<=255;j++){
            if(((unsigned char)j^(unsigned char)(j<<1))==b){
                if(i!=n-1)
                    cout<<int(j)<<" ";
                else
                    cout<<int(j)<<endl;
            }
        }

    }



    return 0;
}







