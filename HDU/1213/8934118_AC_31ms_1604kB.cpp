#include <iostream>  
using namespace std;  
  
int pre[1010];  
  
int find(int x)  
{  
    int r = x;  
    while (pre[r] != r)  
        r = pre[r];  
    int i = x, j;  
    while (i != r)  
    {  
        j = pre[i];  
        pre[i] = r;  
        i = j;  
    }  
    return r;  
}  
  
int main()  
{  
    int n, m;  
    int t;  
    cin >> t;  
    while (t --)  
    {  
        int total;   
        cin >> n;  
        for (int i = 1; i<=n; i++)  
            pre[i] = i;  
        total = n;  
        cin >> m;  
        int p1, p2, f1, f2;  
        while (m --)  
        {  
            cin >> p1>> p2;  
            f1 = find(p1);  
            f2 = find(p2);  
            if (f1 != f2)  
            {  
                pre[f2] = f1;  
                total -- ;  
            }  
        }  
        cout << total<< endl;  
    }  
    return 0;  
}