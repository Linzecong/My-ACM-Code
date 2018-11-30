#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;



int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        int N;
        scanf("%d",&N);
        int a;
        bool flag=0;
        for(int i=0;i<N;i++){
            scanf("%d",&a);
            if(a%3!=0){
                flag=1;
            }
        }
        if(!flag){
            printf("Case #%d: Yes\n",qqq);
        }
        else
             printf("Case #%d: No\n",qqq);

    }


    return 0;
}









