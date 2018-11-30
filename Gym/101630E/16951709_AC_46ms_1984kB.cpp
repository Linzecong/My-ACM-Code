#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500000;

int a[MAXN];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);

    map<int,int> num;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(a[i]>0){
            num[a[i]]++;
        }
        else if(a[i]==0){
            bool flag=0;
            map<int,int> mm=num;
            for(int j=i+1;j<=N;j++){
                if(a[j]<0){
                    if(mm[abs(a[j])]==0){
                        num[abs(a[j])]++;
                        ans.push_back(abs(a[j]));
                        flag=1;
                        break;
                    }
                    else
                        mm[abs(a[j])]--;
                }
                else if(a[j]>0){
                    mm[a[j]]++;
                }
            }
            if(!flag)
                ans.push_back(1);
        }
        else{
            if(num[abs(a[i])]==0){
                cout<<"No"<<endl;
                return 0;
            }
            else{
                num[abs(a[i])]--;
            }
        }
    }

    cout<<"Yes"<<endl;
    for(auto t:ans)
        cout<<t<<" ";


    return 0;
}



