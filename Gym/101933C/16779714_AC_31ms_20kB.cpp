#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN=4000;


int A[MAXN];
int main()
{
    int N;
    scanf("%d",&N);

    vector<int> cur;
    int ans=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }


    for(int i=0;i<400;i++){

        for(int j=0;j<N;j++){
            if(A[j]==i)
                cur.push_back(A[j]);
        }


        int sum=0;
        for(auto p:cur){
            sum+=i-p;
        }
        if(sum>=19){
            ans++;
            cur.clear();
        }
        else{

            int sum2=0;
            for(auto p:cur){
                sum2+=i+1-p;
            }
            if(sum2>=20){
                ans++;
                cur.clear();
            }

        }

    }

    cout<<ans<<endl;






    return 0;
}






