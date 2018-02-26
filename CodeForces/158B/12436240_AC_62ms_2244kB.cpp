#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<memory.h>

using namespace std;

int a[100005];

int main(){

    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);

    sort(a,a+N);

    int l=0,r=N-1;

    int num=0;
    while(l<=r){
        if(a[r]==4){
            num++;
            r--;
            continue;
        }

        if(a[r]==3){
            if(a[l]==1){
                l++;
                r--;
                num++;
                continue;
            }
            else{
                r--;
                num++;
                continue;
            }
        }

        if(a[r]==2){
            if(a[l]==2){
                r--;
                l++;
                num++;
                continue;
            }
            else{
                if(a[l+1]==1){
                    l+=2;
                    r--;
                    num++;
                }
                else{
                    r--;
                    l++;
                    num++;

                }

                continue;
            }
        }

        if(a[r]==1){
            int aaa=0;
            for(int i=l;i<=r;i++)
                aaa++;

            if(aaa%4)
                num+=aaa/4+1;
            else
                num+=aaa/4;
            break;
        }
    }

    printf("%d\n",num);

    return 0;
}

