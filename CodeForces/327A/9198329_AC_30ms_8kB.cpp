#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<memory>
#include<math.h>
using namespace std;
typedef long long int ll;

int a[200];



int main ()
{
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
        cin>>a[i];

    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++)
               a[k]=1-a[k];

            int tmp=0;
            for(int q=0;q<n;q++)
                if(a[q]==1)
                    tmp++;
            ans=max(ans,tmp);

            for(int k=i;k<=j;k++)
               a[k]=1-a[k];
        }

     cout<<ans<<endl;





    return 0;
}
