#include<iostream>  
#include<string>  
#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<map>  
#include<cmath>  
#include<stack>  
#include<set>  
#include<vector>  
#include<algorithm>  
#define LL long long  
#define inf 1<<30  
using namespace std;  
const int N=2005;  
int n;  
double y[N];  
struct LINE  
{  
    double x;  
    double y_down,y_up;  
    int flag;  
}line[N];  
struct node  
{  
    double l,r;  
    double x;  
    int cover;  
    bool flag;  
}node[N<<2];  
bool cmp(LINE a,LINE b)  
{  
    return a.x<b.x;  
}  
void build(int rt,int l,int r)  
{  
    node[rt].l=y[l];  
    node[rt].r=y[r];  
    node[rt].x=-1;  
    node[rt].flag=false;  
    node[rt].cover=0;  
    if(l+1==r){  
        node[rt].flag=true;  
        return;  
    }  
    int mid=(l+r)>>1;  
    build(rt<<1,l,mid);  
    build(rt<<1|1,mid,r);  
}  
double Insert_query(int rt,double x,double l,double r,int flag)  
{  
    if(l>=node[rt].r||r<=node[rt].l) return 0;  
    if(node[rt].flag){  
        if(node[rt].cover>1){  
            double pre=node[rt].x;  
            double ans=(x-pre)*(node[rt].r-node[rt].l);  
            node[rt].x=x;  
            node[rt].cover+=flag;  
            return ans;  
        }else{  
            node[rt].x=x;  
            node[rt].cover+=flag;  
            return 0;  
        }  
    }  
    double ans1,ans2;  
    ans1=Insert_query(rt<<1,x,l,r,flag);  
    ans2=Insert_query(rt<<1|1,x,l,r,flag);  
    return ans1+ans2;  
}  
int main()  
{  
    int t;  
    double x1,x2,y1,y2;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        int cnt=-1;  
        for(int i=0;i<n;i++){  
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);  
            y[++cnt]=y1;  
            line[cnt].x=x1;  
            line[cnt].y_down=y1;  
            line[cnt].y_up=y2;  
            line[cnt].flag=1;  
            y[++cnt]=y2;  
            line[cnt].x=x2;  
            line[cnt].y_down=y1;  
            line[cnt].y_up=y2;  
            line[cnt].flag=-1;  
        }  
        sort(y,y+cnt+1);  
        sort(line,line+cnt+1,cmp);  
        build(1,0,cnt);  
        double area=0;  
        for(int i=0;i<=cnt;i++){  
            area+=Insert_query(1,line[i].x,line[i].y_down,line[i].y_up,line[i].flag);  
        }  
        printf("%.2lf\n",area);  
    }  
    return 0;  
}  