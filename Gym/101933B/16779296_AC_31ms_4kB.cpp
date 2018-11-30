#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int N;
    scanf("%d",&N);

    int cur=0;
    bool flag=1;
    string a;

    bool fir=0;

    for(int i=0;i<N;i++){
        cin>>a;

        if(a[0]=='m'){
            cur++;
        }
        else{
            int c=stoi(a);

            if(c==cur+1){
                cur++;
            }
            else
                flag=0;

        }

    }


    if(flag)
        cout<<"makes sense"<<endl;
    else
        cout<<"something is fishy"<<endl;


    return 0;
}






