#include<iostream>
#include<memory.h>
#define MAX 100
#define BASE 10000

using namespace std;

void multiply(int a[],int Max,int b) //大数乘法,注意参数的传递
{
    int i,array=0;
    for (i = Max-1; i >= 0; i--)
    {
        array += b * a[i];
        a[i] = array % BASE; // 数组每一位存放大数的四位数字
        array /= BASE;   
    }
    return;
}

void divide(int a[], int Max, int b) //模拟大数除法
{
    int i, div = 0;
    for (i = 0; i < Max; i++)   
    {
        div = div * BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}
int main()
{
    int a[101][MAX],i, n;
    memset(a[1],0,MAX*sizeof(int));
    for (i=2, a[1][MAX-1] = 1; i < 101; i++) // 高坐标存放大数低位
    {
        memcpy(a[i], a[i-1], MAX * sizeof(int));      //h[i] = h[i-1];
        multiply(a[i], MAX, 4 * i - 2);               //h[i] *= (4*i-2);
        divide(a[i], MAX, i + 1);                  //h[i] /= （i+1）;
    }
    while (cin >> n && n != -1)   
    {
        for (i = 0; i < MAX && a[n][i] == 0; i++); //去掉数组前为0的数字。
        cout << a[n][i++];             //输出第一个非0数
        for (; i < MAX; i++)   
        {
            printf("%04d",a[n][i]);       //输出后面的数，并每位都保持4位长度!(32767)
           }
        cout << endl;
    }
    return 0;
}