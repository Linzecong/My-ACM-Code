#include <cstring>  
#include <cstdio>  
int z[10001],a,b,c,k=0;  
char h[6][11]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};  
struct node  
{  
    int x,y,dis,z,pre;  
}q[50000];  
int vis[101][101];  
int bfs()  
{  
    int in=0,out=0,i;  
    q[in].pre=-1;  
    q[in].z=0;  
    q[in].dis=0;  
    q[in].x=0;  
    q[in++].y=0;  
    vis[0][0]=1;  
    while(in>out)  
    {  
        int j=out;  
        int x=q[out].x;  
        int y=q[out].y;  
        int di=q[out++].dis;  
        if(x==c||y==c)  
        {  
            while(q[j].pre!=-1)  
            {  
                z[k++]=q[j].z;  
                j=q[j].pre;  
            }  
            return di;  
        }  
        for(i=0;i<6;i++)  
        {  
            int sx=x,sy=y;  
            switch(i)  
            {  
                case 0:sx=a;break;  
                case 1:sy=b;break;  
                case 2:sx=0;break;  
                case 3:sy=0;break;  
                case 4:sx=x+y-b>=0?x+y-b:0;  
                    sy=y+x>=b?b:y+x;break;  
                case 5:sy=x+y-a>=0?x+y-a:0;  
                    sx=x+y>=a?a:x+y;break;  
            }  
            if(!vis[sx][sy])  
            {  
                q[in].pre=out-1;  
                q[in].z=i;  
                vis[sx][sy]=1;  
                q[in].dis=di+1;  
                q[in].x=sx;  
                q[in++].y=sy;  
            }  
        }  
    }  
    return 0;  
}  
int main()  
{  
    scanf("%d%d%d",&a,&b,&c);  
    int di=bfs();  
    if(di)  
    {  
        printf("%d\n",di);  
        for(int i=k-1;i>=0;i--)  
            puts(h[z[i]]);  
    }  
    else  
        printf("impossible\n");  
}  