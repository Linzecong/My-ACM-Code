#include <iostream>

#define MIN -2000000000

using namespace std;

 

long a[110000],front[110000],back[110000];

 

int main()

{

         long num,i,r,k;

         while(cin>>num,num)

         {

                   for(i=1;i<=num;i++) cin>>a[i];

                   front[0]=MIN;//特殊处理边界情况

                   back[num+1]=MIN;

                   for(i=1;i<=num;i++)

                   {

                            k=(front[i-1]+a[i])>a[i]?(front[i-1]+a[i]):a[i];

                            front[i]=front[i-1]>k?front[i-1]:k;//从前向后，找到加上a对应位置的值、不加该值、和只有该值（可能是一序列的开头）的最大者，记录于front数组

                   }

                   for(i=num;i>=1;i--)

                   {

                            k=(back[i+1]+a[i])>a[i]?(back[i+1]+a[i]):a[i];

                            back[i]=back[i+1]>k?back[i+1]:k;

                   }//从后向前，进行类似的活动

                   r=MIN;

                   for(i=1;i<num;i++)

                            if(front[i]+back[i+1]>r) r=front[i]+back[i+1];//从 所有前后两个序列的分界位置 所对应的和中 找到最大的 即为结果

                   cout<<r<<endl;

         }

         return 0;

}