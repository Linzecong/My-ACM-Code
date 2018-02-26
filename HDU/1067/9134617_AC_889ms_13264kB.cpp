#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;




string layout[10][10];

map<string,int> vis;

struct point{
    string str;
    int step;
};

string makestr(){
    string res="";
    for(int i=1;i<=4;i++)
        for(int j=1;j<=8;j++)
            res+=layout[i][j];
    return res;

}

int bfs(point start){
    queue<point> que;
    que.push(start);

    vis[start.str]=1;


    while(!que.empty()){

        point tp=que.front();
        que.pop();

        int t=tp.step;
        string str=tp.str;

    

        if(str=="1112131415161700212223242526270031323334353637004142434445464700")
            return t;


            for(int i=0;i<str.length();i+=2){
                if(str[i]=='0'){
                    char need1=str[i-2];
                    char need2=str[i-1];
                    if(need2!='7')
                        need2++;
                    else
                        continue;

                    if(need1=='0')
                        continue;

                    for(int j=0;j<str.length();j+=2)
                        if(str[j]==need1&&str[j+1]==need2){
                            point temp;
                            temp.str=str;
                            temp.str[i]=need1;
                            temp.str[i+1]=need2;
                            temp.str[j]='0';
                            temp.str[j+1]='0';
                            temp.step=t+1;
                            if(!vis[temp.str]){
                            vis[temp.str]=1;
                            que.push(temp);
                            }
                            break;
                        }
                }
            }



    }


    return -1;
}



int main(){


    int t;
    cin>>t;
    while(t--){
        vis.clear();
        layout[1][1]="11";
        layout[2][1]="21";
        layout[3][1]="31";
        layout[4][1]="41";

        for(int i=1;i<=4;i++)
            for(int j=2;j<=8;j++){
                cin>>layout[i][j];
                if(layout[i][j]=="11"||layout[i][j]=="21"||layout[i][j]=="31"||layout[i][j]=="41")
                    layout[i][j]="00";
            }


        point tt;
        tt.step=0;
        tt.str=makestr();

        cout<<bfs(tt)<<endl;




    }

    return 0;
}
