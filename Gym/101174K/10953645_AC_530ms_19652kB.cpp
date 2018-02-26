#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int bcj[200005];

int find(int x)
{
    if(bcj[x]==0)
    {
        bcj[x]=x;
    }
    if(bcj[x]==x)
    {
        return x;
    }
    bcj[x]=find(bcj[x]);
    return bcj[x];
}

void merge(int x,int y)
{
    if(find(x)==find(y))
    {
        return ;
    }
    bcj[find(x)]=y;
}

struct node{
    int x,y,z;
    bool operator< (const node & right)const
    {
        if(x!=right.x)
        {
            return x<right.x;
        }
        if(y!=right.y)
        {
            return y<right.y;
        }
        return z<right.z;
    }
}be,ed;

map<node,int>mp;
map<int,int>con[200005];

int beg=1;

int main()
{
    int n;
    cin>>n;
    int tmp;
    int a,b;
    int rcir=0,dcir=0;
    for(int i=0;i<n;i++)
    {
        cin>>be.x>>be.y>>be.z;
        cin>>ed.x>>ed.y>>ed.z;
        if(mp.find(be)!=mp.end())
        {
            a=mp[be];
        }
        else
        {
            mp[be]=beg;
            a=beg;
            beg++;
        }
        if(mp.find(ed)!=mp.end())
        {
            b=mp[ed];
        }
        else
        {
            mp[ed]=beg;
            b=beg;
            beg++;
        }
        if(find(a)==find(b)&&a != b && con[a].find(b)==con[a].end())
        {
            rcir=1;
        }
        if(a!=b)
        {
            con[a][b]=1;
            con[b][a]=1;
        }
        merge(a,b);
        be.z=0;
        ed.z=0;
        if(mp.find(be)!=mp.end())
        {
            a=mp[be];
        }
        else
        {
            mp[be]=beg;
            a=beg;
            beg++;
        }
        if(mp.find(ed)!=mp.end())
        {
            b=mp[ed];
        }
        else
        {
            mp[ed]=beg;
            b=beg;
            beg++;
        }
        if(find(a)==find(b)&& a != b&&con[a].find(b)==con[a].end())
        {
            dcir=1;
        }
        if(a!=b)
        {
            con[a][b]=1;
            con[b][a]=1;
        }
        merge(a,b);
    }
    if(rcir)
    {
        cout<<"True closed chains\n";
    }
    else
    {
        cout<<"No true closed chains\n";
    }
    if(dcir)
    {
        cout<<"Floor closed chains\n";
    }
    else
    {
        cout<<"No floor closed chains\n";
    }
    return 0;
}