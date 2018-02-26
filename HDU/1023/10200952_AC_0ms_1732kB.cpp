#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[110][110];    //大数卡特兰数
int b[110];         //卡特兰数的长度 

void Catalan(){     //求卡特兰数
    int i,j,len,carry,tmp;
    a[1][0]=b[1]=1;
    len=1;
    for(i=2;i<=100;i++){
        for(j=0;j<len;j++)      //乘法 
            a[i][j]=a[i-1][j]*(4*i-2);
        carry=0;
        for(j=0;j<len;j++){     //处理相乘结果
            tmp=carry+a[i][j];
            a[i][j]=tmp%10;
            carry=tmp/10;
        }
        while(carry){       //进位处理 
            a[i][len++]=carry%10;
            carry/=10;
        }
        //carry=0;
        for(j=len-1;j>=0;j--){  //除法 
            tmp=carry*10+a[i][j];
            a[i][j]=tmp/(i+1);
            carry=tmp%(i+1);
        }   
        while(!a[i][len-1])     //高位零处理
            len--;
        b[i]=len;
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    int n;
    Catalan();
    while(~scanf("%d",&n)){
        for(int i=b[n]-1;i>=0;i--)
            printf("%d",a[n][i]);
        printf("\n");
    }
    return 0;
}