#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Data{
    double t;
    double x;
    double y;
}list[1005];

bool cmp(Data a,Data b){

    return (a.t)<(b.t);

}



int main()
{

    int i;
    cin>>i;

    while(i--){
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>list[i].t>>list[i].x>>list[i].y;

            sort(list,list+n,cmp);

            double minnum=-1;
            for(int i=1;i<n;i++){
                minnum=max(minnum,sqrt((list[i].x-list[i-1].x)*(list[i].x-list[i-1].x)+(list[i].y-list[i-1].y)*(list[i].y-list[i-1].y))/((list[i].t-list[i-1].t)));
            }



            cout<<setiosflags(ios::fixed)<<setprecision(10)<<minnum<<endl;


    }


    return 0;
}
