#include <cstdio>  
#include <cmath>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <map>  
#include <set>  
#include <vector>  
using namespace std;  
struct node  
{  
    int hx,hy;  
    int body[8]; //1 2 3 4 分别代表上下左右   
    int step;  
};  
int len;  
int n,m,l;  
queue<node> qq;  
int dirx[]={0,0,1,-1}; //you  zuo xia shang  
int diry[]={1,-1,0,0};  
int mp[22][22];  
bool state[22][22][1<<14];  
int trans(int x,int y)          //计算del_x,del_y代表的方位  
{  
    if (x==-1&&y==0)  
        return 1;  //shang   
    if (x==1&&y==0)   
        return 2; //下  
    if (x==0&&y==-1)  
        return 3 ;      //左  
    if (x==0&&y==1)  
        return 4;   //右  
}  
node move_to(node t,int x,int y)        //蛇移动到[X,Y]后整体坐标的变化  
{  
    node res;  
    int i;  
    for (i=len;i>1;i--)  
    {  
        res.body[i]=t.body[i-1];  
    }  
    int dir=trans(t.hx-x,t.hy-y);  
   
        res.body[1]=dir;    
    res.step=t.step+1;  
    res.hx=x;  
    res.hy=y;  
    return res;  
      
}  
inline void get_xy(int &tx,int &ty,int dir,int x,int y)     //得到坐标值  
{  
    if (dir==1)//上  
    {  
        tx=x-1;ty=y;  
    }  
    if (dir==2)//xia  
    {  
        tx=x+1;ty=y;  
    }  
    if (dir==3)//zuo  
    {  
        tx=x;ty=y-1;  
    }  
    if (dir==4)//you  
    {  
        tx=x;ty=y+1;  
    }  
 return ;  
  
}  
void deal_map(node t)       //把蛇身标记为障碍  
{  
    int i;  
    int lastx,lasty;  
    for (i=1;i<=len;i++)  
    {  
        int tx,ty;  
        if (i==1)  
        {  
            get_xy(tx,ty,t.body[i],t.hx,t.hy);  
        }  
        else  
        {  
            get_xy(tx,ty,t.body[i],lastx,lasty);  
        }  
            lastx=tx;  
            lasty=ty;  
        if (mp[tx][ty]==0)  
            mp[tx][ty]=2;      
    }  
          
}  
void un_deal_map(node t)        //去掉 蛇身记号  
{  
int i;  
    int lastx,lasty;  
    for (i=1;i<=len;i++)  
    {  
        int tx,ty;  
        if (i==1)  
        {  
            get_xy(tx,ty,t.body[i],t.hx,t.hy);    
        }  
        else  
        {  
            get_xy(tx,ty,t.body[i],lastx,lasty);  
        }  
            lastx=tx;  
            lasty=ty;  
        if (mp[tx][ty]==2)  
            mp[tx][ty]=0;      
    }  
}  
int get_body_num(node &y)  //计算该状态特征值  
{  
    int i;  
    int ret=0;  
    for (i=1;i<=len;i++)  
    {  
    //  ret+=(y.body[i]-1)*  int(pow(4.0,i-1)); 下一行与本行等价  
        ret+=(y.body[i]-1)*  1<<(2*(i-1)) ;  //位运算加速  
    }  
    return ret;  
}  
  
int main()  
{  
    int cnt=1;  
    while(scanf("%d%d%d",&n,&m,&l)!=EOF)  
    {  
        if (!n&&!m&&!l) break;  
        while(!qq.empty())  
            qq.pop();  
        node tm;  
        memset(mp,0,sizeof(mp));   
         memset(state,0,sizeof(state));  
        int i;   
        scanf("%d%d",&tm.hx,&tm.hy);  
        for (i=0;i<=m+1;i++)   //lock the board 边界设置为障碍  
            mp[0][i]=1;  
        for (i=0;i<=m+1;i++)  
            mp[n+1][i]=1;  
        for (i=0;i<=n+1;i++)  
            mp[i][0]=1;  
        for (i=0;i<=n+1;i++)  
            mp[i][m+1]=1;    
            int xx,yy;  
           
        int lastx,lasty;  
        int delx,dely;  
        for (i=1;i<=l-1;i++)  
        {  
            scanf("%d%d",&xx,&yy);  
            if (i==1)   
            {  
                delx=xx-tm.hx;  
                dely=yy-tm.hy;  
            }  
            else  
            {  
                delx=xx-lastx;  
                dely=yy-lasty;  
            }  
            tm.body[i]=trans(delx,dely);        //记录每个部分是在前一部分的什么方向  
            lastx=xx;  
            lasty=yy;  
        }  
        len=l-1;  
        int num;      
      
        scanf("%d",&num);  
        for (i=1;i<=num;i++)   
        {  
            scanf("%d%d",&xx,&yy);  
            mp[xx][yy]=1;           //屏蔽障碍  
        }  
////  
  
       
        tm.step=0;  
        int ret=get_body_num(tm);  
        state[tm.hx][tm.hy][ret]=true;    
        qq.push(tm);   
        int ans=-1;  
        while(!qq.empty())  
        {  
            node t=qq.front();  
            qq.pop();  
            if (t.hx==1&&t.hy==1)       //结束条件  
            {  
                ans=t.step;  
                break;  
            }  
            deal_map(t);        //设蛇身为障碍  
            for (i=0;i<4;i++)  
            {  
                int x=t.hx+dirx[i];  
                int y=t.hy+diry[i];  
                if (mp[x][y]) continue;         //如果不可行   
                node res=move_to(t,x,y);        //移动后得到的新状态res  
                int ret=get_body_num(res);      //计算是否出现过当前状态  
                if (state[res.hx][res.hy][ret]==true)         
                    continue;  
                state[res.hx][res.hy][ret]=true;  
                qq.push(res);                 
  
            }  
            un_deal_map(t);     //恢复地图  
        }  
          
        printf("Case %d: %d\n",cnt++,ans);  
    }  
    return 0;  
      
}  