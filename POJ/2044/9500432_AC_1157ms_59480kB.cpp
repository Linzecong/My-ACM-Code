#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int date[366][5][5];
int vis[366][10][8][8][8][8];


bool check(int day,int pos){
    if(pos==1){
        if(date[day][1][1]==1)return false;
        if(date[day][1][2]==1)return false;
        if(date[day][2][1]==1)return false;
        if(date[day][2][2]==1)return false;
    }

    if(pos==2){
        if(date[day][1][2]==1)return false;
        if(date[day][1][3]==1)return false;
        if(date[day][2][2]==1)return false;
        if(date[day][2][3]==1)return false;
    }

    if(pos==3){
        if(date[day][1][3]==1)return false;
        if(date[day][1][4]==1)return false;
        if(date[day][2][3]==1)return false;
        if(date[day][2][4]==1)return false;
    }

    if(pos==4){
        if(date[day][2][1]==1)return false;
        if(date[day][2][2]==1)return false;
        if(date[day][3][1]==1)return false;
        if(date[day][3][2]==1)return false;
    }

    if(pos==5){
        if(date[day][2][2]==1)return false;
        if(date[day][2][3]==1)return false;
        if(date[day][3][2]==1)return false;
        if(date[day][3][3]==1)return false;
    }

    if(pos==6){
        if(date[day][2][3]==1)return false;
        if(date[day][2][4]==1)return false;
        if(date[day][3][3]==1)return false;
        if(date[day][3][4]==1)return false;
    }

    if(pos==7){
        if(date[day][3][1]==1)return false;
        if(date[day][3][2]==1)return false;
        if(date[day][4][1]==1)return false;
        if(date[day][4][2]==1)return false;
    }

    if(pos==8){
        if(date[day][3][2]==1)return false;
        if(date[day][3][3]==1)return false;
        if(date[day][4][2]==1)return false;
        if(date[day][4][3]==1)return false;
    }

    if(pos==9){
        if(date[day][3][3]==1)return false;
        if(date[day][3][4]==1)return false;
        if(date[day][4][3]==1)return false;
        if(date[day][4][4]==1)return false;
    }



    return true;
}

bool ans=false;

bool ch(int c1,int c2,int c3,int c4){

    if(c1>=7||c2>=7||c3>=7||c4>=7)return false;

    return true;
}


void dfs(int day,int pos,int c1,int c2,int c3,int c4){

    //  cout<<day<<pos<<c1<<c2<<c3<<c4<<endl;

    if(!ch( c1, c2, c3, c4))
        return;

    if(day>N){
        ans=true;
        return;
    }

    if(vis[day][pos][c1][c2][c3][c4]==true)return;

    vis[day][pos][c1][c2][c3][c4]=1;


    if(check(day,pos)){

        if(pos==1){
            dfs(day+1,pos,0,c2+1,c3+1,c4+1);
            dfs(day+1,pos+1,0,c2+1,c3+1,c4+1);
            dfs(day+1,pos+2,0,c2+1,c3+1,c4+1);
            dfs(day+1,pos+3,0,c2+1,c3+1,c4+1);
            dfs(day+1,pos+6,0,c2+1,c3+1,c4+1);
        }
        if(pos==2){
            dfs(day+1,pos,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+6,c1+1,c2+1,c3+1,c4+1);
        }
        if(pos==3){
            dfs(day+1,pos,c1+1,0,c3+1,c4+1);
            dfs(day+1,pos-1,c1+1,0,c3+1,c4+1);
            dfs(day+1,pos-2,c1+1,0,c3+1,c4+1);
            dfs(day+1,pos+3,c1+1,0,c3+1,c4+1);
            dfs(day+1,pos+6,c1+1,0,c3+1,c4+1);
        }
        if(pos==4){
            dfs(day+1,pos,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+2,c1+1,c2+1,c3+1,c4+1);
        }
        if(pos==5){
            dfs(day+1,pos,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+3,c1+1,c2+1,c3+1,c4+1);
        }
        if(pos==6){
            dfs(day+1,pos,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-2,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+3,c1+1,c2+1,c3+1,c4+1);
        }
        if(pos==7){
            dfs(day+1,pos,c1+1,c2+1,0,c4+1);
            dfs(day+1,pos+1,c1+1,c2+1,0,c4+1);
            dfs(day+1,pos+2,c1+1,c2+1,0,c4+1);
            dfs(day+1,pos-3,c1+1,c2+1,0,c4+1);
            dfs(day+1,pos-6,c1+1,c2+1,0,c4+1);
        }
        if(pos==8){
            dfs(day+1,pos,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos+1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-1,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-3,c1+1,c2+1,c3+1,c4+1);
            dfs(day+1,pos-6,c1+1,c2+1,c3+1,c4+1);
        }
        if(pos==9){
            dfs(day+1,pos,c1+1,c2+1,c3+1,0);
            dfs(day+1,pos-1,c1+1,c2+1,c3+1,0);
            dfs(day+1,pos-2,c1+1,c2+1,c3+1,0);
            dfs(day+1,pos-3,c1+1,c2+1,c3+1,0);
            dfs(day+1,pos-6,c1+1,c2+1,c3+1,0);
        }
    }

}



int main()
{


    while(cin>>N){
        if(N==0)
            break;
        ans=false;
        memset(date,0,sizeof(date));
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=N;i++)
            for(int j=1;j<=4;j++)
                for(int k=1;k<=4;k++)
                    cin>>date[i][j][k];


        dfs(1,5,0,0,0,0);

        cout<<ans<<endl;



    }





}
