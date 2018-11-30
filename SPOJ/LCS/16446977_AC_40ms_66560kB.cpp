#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
typedef long long ll;

int step[MAXN];
int SZ=1;
int ch[MAXN][30];
int fa[MAXN];
int last=1;

void extend(int x){
    int np=++SZ;
    int p=last;
    step[np]=step[last]+1;
    last=np;
    while(!ch[p][x]&&p)
        ch[p][x]=np,p=fa[p];
    if(!p)
        fa[np]=1;
    else{
        int q=ch[p][x];
        if(step[q]==step[p]+1)
            fa[np]=q;
        else{
            int nq=++SZ;
            step[nq]=step[p]+1;
            for(int i=0;i<26;i++)
                ch[nq][i]=ch[q][i];
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            while(p&&ch[p][x]==q)
                ch[p][x]=nq,p=fa[p];
        }
    }
}


char s1[MAXN],s2[MAXN];

int main(){
    scanf("%s%s",s1+1,s2+1);

    int len1=strlen(s1+1);
    int len2=strlen(s2+1);

    for(int i=1;i<=len1;i++)
        extend(s1[i]-'a');
    int p=1,l=0;
    int ans=0;
    for(int i=1;i<=len2;i++){
        int x=s2[i]-'a';

        if(ch[p][x]){
            l++;
            p=ch[p][x];
        }
        else{
            while(p&&!ch[p][x])
                p=fa[p];

            if(!p)
                l=0,p=1;
            else
                l=step[p]+1,p=ch[p][x];
        }


        ans=max(ans,l);

    }
    cout<<ans<<endl;




    return 0;
}
