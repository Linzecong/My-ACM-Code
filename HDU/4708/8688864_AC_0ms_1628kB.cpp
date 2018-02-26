//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <vector>
//#include <deque>
//using namespace std;

//long long int mat[10][10];

//struct node{
//    long long int max;
//    long long int time;
//};

//bool cmp(node a,node b){
//    if(a.max==b.max)
//        return a.time<b.time;
//    return a.max>b.max;
//}

//long long int sum(deque<long long int> quelist[],int N){

//   long long  int result=0;

//    for(int i=0;i<N;i++){
//        result+=quelist[i][0];
//        result+=quelist[i][(N-i)*2];
//        result+=quelist[i][(N-i)*4];
//        result+=quelist[i][(N-i)*6];
//    }

//    return result;
//}


//int main()
//{




//    int N;

//    while(1){
//        scanf("%d",&N);

//        if(N==0)
//            break;
//        else{
//            for(int i=0;i<N;i++)
//                for(int j=0;j<N;j++)
//                    cin>>mat[i][j];

//            deque<long long int> quelist[(N-1)/2];


//            for(int q=0;q<(N-1)/2;q++)
//            {
//                for(int i=q;i<N-q;i++)
//                    quelist[q].push_back(mat[q][i]);


//                for(int i=q+1;i<N-q-1;i++)
//                    quelist[q].push_back(mat[i][N-q-1]);

//                for(int i=N-1-q;i>=q;i--)
//                    quelist[q].push_back(mat[N-1-q][i]);

//                for(int i=N-2-q;i>=q+1;i--)
//                    quelist[q].push_back(mat[i][q]);

//            }

//            vector<node> templist;

//            if(N==3){
//                for(int i=0;i<quelist[0].size();i++)
//                {

//                    node tempnode;
//                    tempnode.time=i;
//                    tempnode.max=sum(quelist,(N-1)/2)+mat[(N-1)/2][(N-1)/2];
//                    templist.push_back(tempnode);

//                    quelist[0].push_back(quelist[0].front());
//                    quelist[0].pop_front();
//                }
//            }

//            if(N==5){
//                for(int i=0;i<quelist[0].size();i++)
//                {


//                    for(int j=0;j<quelist[1].size();j++)
//                    {


//                        node tempnode;
//                        tempnode.time=i+j;
//                        tempnode.max=sum(quelist,(N-1)/2)+mat[(N-1)/2][(N-1)/2];
//                        templist.push_back(tempnode);

//                        quelist[1].push_back(quelist[1].front());
//                        quelist[1].pop_front();
//                    }
//                    quelist[0].push_back(quelist[0].front());
//                    quelist[0].pop_front();
//                }
//            }

//            if(N==7){
//                for(int i=0;i<quelist[0].size();i++)
//                {


//                    for(int j=0;j<quelist[1].size();j++)
//                    {


//                        for(int k=0;k<quelist[2].size();k++)
//                        {
//                            node tempnode;
//                            tempnode.time=i+j+k;
//                            tempnode.max=sum(quelist,(N-1)/2)+mat[(N-1)/2][(N-1)/2];
//                            templist.push_back(tempnode);

//                            quelist[2].push_back(quelist[2].front());
//                            quelist[2].pop_front();
//                        }
//                        quelist[1].push_back(quelist[1].front());
//                        quelist[1].pop_front();
//                    }
//                    quelist[0].push_back(quelist[0].front());
//                    quelist[0].pop_front();
//                }


//            }

//            if(N==9){
//                for(int i=0;i<quelist[0].size();i++)
//                {


//                    for(int j=0;j<quelist[1].size();j++)
//                    {


//                        for(int k=0;k<quelist[2].size();k++)
//                        {
//                            for(int l=0;l<quelist[3].size();l++)
//                            {
//                                node tempnode;
//                                tempnode.time=i+j+k+l;
//                                tempnode.max=sum(quelist,(N-1)/2)+mat[(N-1)/2][(N-1)/2];
//                                templist.push_back(tempnode);

//                                quelist[3].push_back(quelist[3].front());
//                                quelist[3].pop_front();
//                            }
//                            quelist[2].push_back(quelist[2].front());
//                            quelist[2].pop_front();
//                        }
//                        quelist[1].push_back(quelist[1].front());
//                        quelist[1].pop_front();
//                    }
//                    quelist[0].push_back(quelist[0].front());
//                    quelist[0].pop_front();
//                }
//            }




//            sort(templist.begin(),templist.end(),cmp);


//            cout<<templist[0].max<<" "<<templist[0].time<<endl;

//            //            for(int i=0;i<(N-1)/2;i++){
//            //                for(int j=0;j<quelist[i].size();j++)
//            //                    cout<<quelist[i][j]<<" ";
//            //                cout<<endl;
//            //            }






//        }



//    }




//    return 0;
//}
/* *******************************************
Author       : kuangbin
Created Time : 2013年09月08日 星期日 12时33分12秒
File Name    : 1003.cpp
******************************************* */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long a[20][20];
int n;
void change(int &x,int &y,int k)
{
    if(x == k)
    {
        if(y == k)
        {
            x++;
        }
        else y--;
    }
    else if(x == n+1-k)
    {
        if(y == n+1-k)
            x--;
        else y++;
    }
    else if(y == k)
        x++;
    else x--;
}
int main()
{
   // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
    while(scanf("%d",&n) && n)
    {
        for(int i = 1;i <=  n;i++)
            for(int j = 1;j <= n;j++)
                cin>>a[i][j];
        long long ans1 = 0, ans2 = 0;
        for(int i = 1;i <= n/2;i++)
        {
            int x0 = i,y0 = i;
            int x1 = i,y1 = n+1-i;
            int x2 = n+1-i,y2 = i;
            int x3 = n+1-i,y3 = n+1-i;
            int tmp1 = a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3];
            int tmp2 = 0;
            for(int j = 0;j < (n+2-2*i-2);j++)
            {
                change(x0,y0,i);
                change(x1,y1,i);
                change(x2,y2,i);
                change(x3,y3,i);
                int tt = min(j+1,n+2-2*i-1-(j+1));
                if(tmp1 < a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3])
                {
                    tmp1 = a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3];
                    tmp2 = tt;
                }
                else if(tmp1 == a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3] && tmp2 > tt)
                {
                    tmp2 = tt;
                }
            }
            ans1 += tmp1;
            ans2 += tmp2;
        }
        ans1 += a[n/2+1][n/2+1];
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
