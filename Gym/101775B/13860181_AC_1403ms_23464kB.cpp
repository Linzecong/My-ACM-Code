#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long int ll;
const int MAXN = 300095;

double a[200008];


struct point{
	double tot;
	int num;
	double cur;
	double dis;
	double di;
	double sss;
	friend bool operator <(point a, point b){
		return a.di<b.di;
	}
	point(double s,double a,int b,double c){
		sss=s;
		tot=a;
		num=b;
		cur=c;
		dis=(cur-sss)*(cur-sss)*num;
		//cout<<dis<<endl;
		di=dis-((tot/(num+1)-sss)*(tot/(num+1)-sss)*(num+1));
		//cout<<tot<<" "<<num<<" "<<cur<<" "<<di<<endl;
			
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

		double sum=0;
		for(int i=0;i<N;i++){
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		sum/=M;
		for(int i=0;i<N;i++){
			que.push(point(sum,a[i],1,a[i]));
		}

		priority_queue<point> que2;

		// while(!que.empty()){
		// 	cout<<que.top().tot<<" "<<que.top().num<<" "<<que.top().cur<<" "<<que.top().di<<endl;
		// 	point tp=que.top();
		// 	que.pop();
		// 	que2.push(tp);
		// }
			


		while(left--){
			point tp=que.top();
			que.pop();
			//cout<<que.top().tot<<" "<<que.top().num<<" "<<que.top().cur<<" "<<que.top().di<<endl;

			point aaa=point(sum,tp.tot,tp.num+1,tp.tot/(tp.num+1));
			que.push(aaa);
			//cout<<que.top().tot<<" "<<que.top().num<<" "<<que.top().cur<<" "<<que.top().di<<endl;

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
