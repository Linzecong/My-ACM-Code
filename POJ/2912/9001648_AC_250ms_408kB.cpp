#include<stdio.h>
#include<string.h>
const int maxm=505;

int fa[maxm],num[maxm],wa[maxm];
struct ques{
    int a,b,c;
}q[2005];

void init(int n){
    for(int i=0;i<=n;++i){
        fa[i]=i;
        num[i]=0;
    }
}

int find(int x){
    int r=x,t1,t2,c=0;
    while(r!=fa[r]){
        c+=num[r];
        r=fa[r];
    }
    while(x!=r){
        t1=fa[x];
        t2=c-num[x];
        num[x]=c%3;
        fa[x]=r;
        c=t2;
        x=t1;
    }
    return r;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=m;++i){
            char c;
            scanf("%d",&q[i].a);
            c=getchar();
            while(c!='='&&c!='<'&&c!='>')c=getchar();
            if(c=='=')q[i].c=0;
            else if(c=='<')q[i].c=1;
            else if(c=='>')q[i].c=2;
            scanf("%d",&q[i].b);
        }
        memset(wa,-1,sizeof(wa));
        for(int i=0;i<n;++i){
            init(n);
            for(int j=1;j<=m;++j){
                if(q[j].a==i||q[j].b==i)continue;
                int x=find(q[j].a),y=find(q[j].b);
                if(x!=y){
                    fa[x]=y;
                    num[x]=((num[q[j].b]+q[j].c-num[q[j].a])%3+3)%3;
                }
                else{
                    if((num[q[j].b]+q[j].c)%3!=num[q[j].a]){wa[i]=j;break;}
                }
            }
        }
        int cnt=0,ans1,ans2=0;
        for(int i=0;i<n;++i){
            if(wa[i]==-1){
                cnt++;
                ans1=i;
            }
            if(wa[i]>ans2)ans2=wa[i];
        }
        if(!cnt)printf("Impossible\n");
        else if(cnt>1)printf("Can not determine\n");
        else printf("Player %d can be determined to be the judge after %d lines\n",ans1,ans2);
    }
    return 0;
}