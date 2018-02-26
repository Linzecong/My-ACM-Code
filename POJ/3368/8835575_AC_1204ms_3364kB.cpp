#include<iostream>
#include<stdio.h>
using namespace std;
const int Max = 100050;

struct{
    int l, r, max;
}node[3*Max];
struct{
    int sta, end;
}seg[Max];
int num[Max], hash1[Max];

int max(int a, int b){
    return a > b ? a : b;
}

void BuildTree(int left, int right, int u){            //  建树。
    node[u].l = left;
    node[u].r = right;
    if(left == right){
        int k = left;
        node[u].max = seg[k].end - seg[k].sta + 1;     //  max保存这个点集的点的数量。
        return;
    }
    int mid = (left+right)>>1;
    BuildTree(left, mid, u<<1);
    BuildTree(mid+1, right, (u<<1)+1);
    node[u].max = max(node[u<<1].max, node[(u<<1)+1].max);
}

int query(int left, int right, int u){                 //  查询。
    if(node[u].l == left && node[u].r == right)
        return node[u].max;
    if(right <= node[u<<1].r)
        return query(left, right, u<<1);
    if(left >= node[(u<<1)+1].l)
        return query(left, right, (u<<1)+1);
    int a = query(left, node[u<<1].r, u<<1);
    int b = query(node[(u<<1)+1].l, right, (u<<1)+1);
    return max(a, b);
}

int main(){
    int n, m, i;
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        for(i = 1; i <= n; i ++)
            scanf("%d", &num[i]);
        int k = 0, pre = 999999;
        for(i = 1; i <= n; i ++){      //  离散化，将点的序列离散化为一个个的点集。
            if(num[i] != pre){
                pre = num[i];
                k ++;
                seg[k].sta = i;
                seg[k].end = i;
            }
            else seg[k].end = i;
            hash1[i] = k;               //  hash保存序列上第i个点，对应的点集的下标。
        }
        BuildTree(1, k, 1);
        while(m --){
            int a, b, pos1, pos2;
            scanf("%d%d", &a, &b);
            pos1 = hash1[a];
            pos2 = hash1[b];            //  *.如下，好的主函数操作能很大程度上简化线段树的复杂度。
            if(pos1 == pos2)           //  情况1：[a,b]为一个点集。
                printf("%d\n", b-a+1);
            else{                      //  情况2，3：[a,b]包含多个点集。
                int n1 = seg[pos1].end - a + 1;
                int n2 = 0;
                int n3 = b - seg[pos2].sta + 1;
                if(pos2 - pos1 > 1)    //  情况3：[a,b]包含3个以上点集，中间点集最大值用到线段树。
                    n2 = query(pos1+1, pos2-1, 1);
                printf("%d\n", max(max(n1, n3), n2));
            }
        }
    }
    return 0;
}
