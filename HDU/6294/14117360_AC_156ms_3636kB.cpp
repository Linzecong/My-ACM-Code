#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char str[1000005];
char ans[1000005];

int main(){

    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        memset(ans,0,sizeof(ans));
        int N;
        scanf("%d",&N);
        scanf("%s",str);

        for(int i=0;i<N;i++){

            if(str[i]<str[i+1]){
                ans[i]='<';
            }
            else{
                if(str[i]>str[i+1]){
                    ans[i]='>';
                }
            }
        }


        char cur=ans[N-1];
        for(int i=N-2;i>=0;i--){
            if(ans[i]==0)
                ans[i]=cur;
            else{
                cur=ans[i];
            }

        }
        ans[N-1]='\0';
        printf("%s\n",ans);

    }

    return 0;
}








