#include<iostream>
#include<deque>
#include<memory.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#define inf 1<<29
#define MAXV 4005
using namespace std;


#define MAX 0x3f3f3f3f
struct node
{
    double x, y;
} ls[210];
double map[250][250];
int n;
double dis[210];
int bj[250];
int kk = 0;
void Dijk()
{
    int pos = 0;
    memset(bj,0,sizeof(bj));
    memset(dis,0,sizeof(dis));
    for(int i = 0; i < n; i++)
        dis[i] = map[pos][i];
    bj[pos] = 1;
    double ans=0;
    for(int i = 0; i < n-1; i++)
    {
        double min = MAX;
        for(int j = 0; j < n; j++)
        {
            if(min > dis[j] && !bj[j])
            {
                min = dis[pos = j];
            }
        }
        bj[pos] = 1;
        if(min>ans)
            ans=min;
        if(pos == 1)
            break;
        for(int j = 0; j < n; j++)
        {
            if(dis[j] > map[pos][j]&& !bj[j])
            {
                dis[j] = map[pos][j];
            }
        }
    }
    printf("Scenario #%d\n",++kk);
    printf("Frog Distance = %.3lf\n",ans);
    printf("\n");
}
int main()
{
    kk = 0;
    while(~scanf("%d",&n)&&n)
    {
        int i,j;
        for(i = 0; i < n; i++)
            scanf("%lf%lf",&ls[i].x,&ls[i].y);
        for(i = 0; i < n; i++)
            for(j = i; j < n; j++)
            {
                map[i][j] = sqrt(pow((ls[i].x - ls[j].x),2)+pow((ls[i].y -ls[j].y),2));
                map[j][i] = sqrt(pow((ls[i].x - ls[j].x),2)+pow((ls[i].y -ls[j].y),2));
            }

        Dijk();
    }
    return 0;
}



