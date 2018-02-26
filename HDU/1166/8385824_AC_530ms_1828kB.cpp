#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int bit[50005];

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=(i & -i);
    }
    return s;
}

void add(int i,int x,int n){
    while(i<=n){
        bit[i]+=x;
        i+=(i & -i);
    }
}

int main()
{

    int T;
    cin>>T;

    for(int qqq=0;qqq<T;qqq++){
        int N;
        cin>>N;

        for(int i=0;i<=N;i++)
            bit[i]=0;



        for(int i=0;i<N;i++){
            int temp;
            scanf("%d",&temp);
            add(i+1,temp,N);

           // scanf("%d",&bit[i]);
        }





        // cin>>list[i];



        cout<<"Case "<<qqq+1<<":"<<endl;

        string order;
        int a,b;
        while(1){
            cin>>order;
            if(order=="End")
                break;
            else{
                scanf("%d",&a);
                scanf("%d",&b);
                // cin>>a>>b;

                if(order=="Query"){
                    cout<<sum(b)-sum(a-1)<<endl;
                    continue;
                }


                if(order=="Add"){
                    add(a,b,N);
                    continue;
                }

                if(order=="Sub"){
                    add(a,-b,N);
                    continue;
                }



            }
        }



    }

    return 0;
}
