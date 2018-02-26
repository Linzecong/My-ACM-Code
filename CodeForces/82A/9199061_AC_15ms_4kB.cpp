#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<iomanip>  
using namespace std;  
int main()  
{  
    int n,n1 = 0,oldn=0;                             //n:第几个数,n1:所在数的上一组  
    int temp;  
    cin>>n;                                          //输入input的值  
    if(n>5)                                          //如果n大于5才进行运算,因为如果是前5个数直接输出就行.  
    {  
        oldn = n;                                    //保存一下是第几个人  
        n = n/5+1;                                   //公式前n项和推导出:2^n = input/5 + 1  
        for(int i=0;i<100;i++)  
        {  
            if(pow(2,i)>n)                           //如果算的等比数列前n项和比input大,用它上一组的  
            {  
                n1 = i-1;                            //求上一组的n是多少.  
                break;  
            }  
        }  
        //        cout<<n1<<endl;  
        //        cout<<oldn<<" "<<(5*(pow(2,n1)-1))<<endl;  
  
        temp = oldn - (5*(pow(2,n1)-1));             //用input减去所在数的上一组的前n项和(别忘了*5)  
  
        //        cout<<temp<<endl;  
        //        cout<<(int)(pow(2,n1))<<endl;  
  
        switch (temp/(int)(pow(2,n1))) {           //然后用这个数除以它分裂的个数(pow(2,n1))取整  
        case 0:  
            cout<<"Sheldon"<<endl;  
            break;  
        case 1:  
            cout<<"Leonard"<<endl;  
            break;  
        case 2:  
            cout<<"Penny"<<endl;  
            break;  
        case 3:  
            cout<<"Rajesh"<<endl;  
            break;  
        case 4:  
            cout<<"Howard"<<endl;  
            break;  
        }  
    }  
    else  
    {  
        switch (n) {                        //因为如果是前5个数直接输出就行.  
        case 1:  
            cout<<"Sheldon"<<endl;  
            break;  
        case 2:  
            cout<<"Leonard"<<endl;  
            break;  
        case 3:  
            cout<<"Penny"<<endl;  
            break;  
        case 4:  
            cout<<"Rajesh"<<endl;  
            break;  
        case 5:  
            cout<<"Howard"<<endl;  
            break;  
        }  
  
    }  
    return 0;  
}  