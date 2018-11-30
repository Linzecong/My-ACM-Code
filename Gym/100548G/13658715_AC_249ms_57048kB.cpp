#include<bits/stdc++.h>  
using namespace std;  
const int maxn = 2e5+100;  

struct PAM{  
    int nxt[maxn][26],len[maxn],cnt[maxn],fail[maxn];  
    int S[maxn];  
    int last,p,now;  
    int newnode(int l){  
        memset(nxt[p],0,sizeof nxt[p]);  
        cnt[p]=0;  
        len[p]=l;  
        return p++;  
    }  
    void init(){  
        p =0;  
        newnode(0);  
        newnode(-1);  
        last =0;  
        now =0;  
        S[now++] =-1;  
        fail[0]=1;  
    }  
    inline int get_fail(int x){  
        int tx =x;  
        while (S[now-len[tx]-2]!=S[now-1]) tx = fail[tx];  
        return tx;  
    }   
    void add(int c){  
        S[now++] =c;  
        int cur = get_fail(last);  
        if (!nxt[cur][c]){  
            int tt = newnode(len[cur]+2);  
            fail[tt] = nxt[get_fail(fail[cur])][c];  
            nxt[cur][c] =tt;  
        }  
        last = nxt[cur][c];  
        cnt[last]++;  
    }  
    void count(){  
        for (int i=p-1;i>=0;i--){  
            cnt[fail[i]]+=cnt[i];  
        }  
        cnt[0]=cnt[1]=0;  
    }  
  
}pam1,pam2;  

long long dfs(int u,int v){  
    long long res =0;  
    for (int i=0;i<26;i++){  
        int uu = pam1.nxt[u][i];  
        int vv = pam2.nxt[v][i];  
        if (uu&&vv){  
            res +=1LL*pam1.cnt[uu]*pam2.cnt[vv];  
            res+=dfs(uu,vv);  
        }  
    }  
    return res;  
}  
int T;  
int Cas=1;   
int len1,len2;  
char s1[maxn],s2[maxn];  
int main(){  
    scanf("%d",&T);  
    while (T--){  
        pam1.init();  
        pam2.init();  
        scanf("%s%s",s1,s2);  
        len1 = strlen(s1);  
        len2 = strlen(s2);  
        for (int i=0;i<len1;i++){  
            pam1.add(s1[i]-'a');  
        }  
        for (int i=0;i<len2;i++){  
            pam2.add(s2[i]-'a');  
        }  
        pam1.count();  
        pam2.count();  
        printf("Case #%d: %I64d\n",Cas++,dfs(0,0)+dfs(1,1));  
    }  
    return 0;  
} 