#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct Data{
    long long int a;
    long long int b;
}list[100001];

bool cmp(Data a,Data b){

    return (a.a)*(b.b)<(b.a)*(a.b);

}



int main()
{


    while(1){
        int n;
        cin>>n;
        if(n==0)
            break;
        else{

            long long int result=0;
            for(int i=0;i<n;i++)
                //cin>>list[i].a>>list[i].b;
            scanf("%I64d %I64d", &list[i].a, &list[i].b);

            sort(list,list+n,cmp);


            for(int i=0;i<n;i++){

                result+=list[i].a+result*list[i].b;
                result%=(365*24*60*60);


            }



            cout<<result<<endl;
        }
    }


    return 0;
}
