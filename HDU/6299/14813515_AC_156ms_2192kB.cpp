#include <bits/stdc++.h>
using namespace std;
const int MAXN=100505;
typedef long long int ll;


pair<int,int> li[MAXN];

bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.first>b.first;
}

char str[MAXN];
int main()
{

    int T;
    scanf("%d",&T);

    for(int qqq=0;qqq<T;qqq++){

        int N;
        scanf("%d",&N);
        int ans=0;
        for(int i=0;i<N;i++){
            scanf("%s",str);
            li[i].first=li[i].second=0;
            for(int j=0;str[j]!='\0';j++){

                if(str[j]=='(')
                    li[i].second++;
                else{
                    if(li[i].second)
                        li[i].second--,++ans;
                    else
                        li[i].first++;
                }
            }
        }
        sort(li,li+N,cmp);

        int l=0,r=0;
        for(int i=0;i<N;i++){
            int ln=min(l,li[i].second);
            int rn=min(r,li[i].first);
            if(ln>rn){
                ans+=ln;
                l-=ln;
                li[i].second-=ln;
            }
            else{
                ans+=rn;
                r-=rn;
                li[i].first-=rn;
            }

            l+=li[i].first;
            r+=li[i].second;
        }
        printf("%d\n",ans*2);



    }


    return 0;
}








