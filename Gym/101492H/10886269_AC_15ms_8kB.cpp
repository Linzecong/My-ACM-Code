#include <iostream>
#include <vector>
using namespace std;

int sx,sy,dx,dy,cnt=0;
int cur=0;

int getNum(char c)
{
    if(c=='E')return 0;
    else if(c=='S')return 1;
    else if(c=='O')return 2;
    else return 3;
}

int main()
{
    char c;
    cin>>sx>>sy;
    cin>>c;
    cin>>dx>>dy;
    cur=getNum(c);
    vector<int> ans;
    while(sx!=dx||sy!=dy)
    {
        if(cur==0)
        {
            if(dx>sx){
                cnt++;
                ans.push_back(dx-sx);
                sx=dx;
            }
            else{
                cnt++;
                ans.push_back(-1);
                cur=(cur+1)%4;
            }
        }
        else if(cur==1)
        {
            if(dy<sy){
                cnt++;
                ans.push_back(sy-dy);
                sy=dy;
            }
            else{
                cnt++;
                ans.push_back(-1);
                cur=(cur+1)%4;
            }
        }
        else if(cur==2){
            if(dx<sx){
                cnt++;
                ans.push_back(sx-dx);
                sx=dx;
            }
            else{
                cnt++;
                ans.push_back(-1);
                cur=(cur+1)%4;
            }
        }
        else{
            if(dy>sy){
                cnt++;
                ans.push_back(dy-sy);
                sy=dy;
            }
            else{
                cnt++;
                ans.push_back(-1);
                cur=(cur+1)%4;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        if(ans[i]==-1)cout<<"D"<<endl;
        else cout<<"A "<<ans[i]<<endl;
    }
    return 0;
}
