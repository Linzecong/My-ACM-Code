#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long int ll;
const int MAXN = 300095;

double a[200008];

double sum=0;
struct point{
	double tot;
	int num;
	double cur;
	double dis;
	double di;
	bool operator <(const point &b)const{
		return di<b.di;
	}
	point(double a,int b,double c){
		tot=a;
		num=b;
		cur=c;
		dis=(cur-sum)*(cur-sum)*num;
		di=dis-((tot/(num+1)-sum)*(tot/(num+1)-sum)*(num+1));	
	}
};



int main()
{
	int T;
	scanf("%d",&T);
	for(int qqq=1;qqq<=T;qqq++){
		int N,M;
		scanf("%d%d",&N,&M);

		int left=M-N;

		priority_queue<point> que;

		sum=0;
		for(int i=0;i<N;i++){
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		sum/=M;
		for(int i=0;i<N;i++){
			que.push(point(a[i],1,a[i]));
		}

		while(left--){
			point tp=que.top();
			que.pop();
			que.push(point(tp.tot,tp.num+1,tp.tot/(tp.num+1)));
		}

		double fang=0;
		for(int i=0;i<N;i++){
			int num=que.top().num;
			double f=que.top().cur;
			que.pop();
			fang+=((f-sum)*(f-sum))*num;
		}
		fang/=M;
		printf("Case #%d: %.13lf\n",qqq,fang);
	}
	

	return 0;
}