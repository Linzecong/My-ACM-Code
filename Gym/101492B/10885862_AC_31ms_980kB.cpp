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
#define MAXV 400005
using namespace std;
typedef long long int ll;



int main()
{



    long long int N;
    cin>>N;


    if(((1+N)*N/2)%2==1){
        cout<<-1<<endl;
    }
    else{

        long long int num=((1+N)*N/2)/2;

        string ans;
        ans.resize(N,'0');

        for(int i=N;i>=0;i--){
            num-=i;
            ans[i-1]='-';
            if(num>=i)
                continue;
            else{
                if(num==0)
                    break;
                ans[num-1]='-';
                break;
            }
        }

        for(int i=0;i<N;i++){
            if(ans[i]!='-')
                ans[i]='+';
        }
        cout<<ans<<endl;

    }




    return 0;
}
