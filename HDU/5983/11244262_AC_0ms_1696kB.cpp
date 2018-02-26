#include<iostream>
using namespace std;
int ding[5];
	int qian[5];
	int di[5];
	int hou[5];
	int zuo[5];
	int you[5];

bool judge(){
	if(ding[1]==ding[2]&&ding[2]==ding[3]&&ding[3]==ding[4]&&ding[4]==ding[1]&&
	qian[1]==qian[2]&&qian[2]==qian[3]&&qian[3]==qian[4]&&qian[4]==qian[1]&&
	di[1]==di[2]&&di[2]==di[3]&&di[3]==di[4]&&di[4]==di[1]&&
	hou[1]==hou[2]&&hou[2]==hou[3]&&hou[3]==hou[4]&&hou[4]==hou[1]&&
	zuo[1]==zuo[2]&&zuo[2]==zuo[3]&&zuo[3]==zuo[4]&&zuo[4]==zuo[1]&&
	you[1]==you[2]&&you[2]==you[3]&&you[3]==you[4]&&you[4]==you[1]
	)
	return 1;
	else
	return 0;	
}


void dingzuo(){
		int t1=zuo[2];
		int t2=zuo[4];
		zuo[2]=hou[4];
		zuo[4]=hou[3];
		
		hou[3]=you[1];
		hou[4]=you[3];
		
		you[1]=qian[2];
		you[3]=qian[1];
		qian[1]=t1;
		qian[2]=t2;
}

void dingyou(){
		int t1=zuo[2];
		int t2=zuo[4];
		
		zuo[2]=qian[1];
		zuo[4]=qian[2];
		
		qian[1]=you[3];
		qian[2]=you[1];
		
		you[1]=hou[3];
		you[3]=hou[4];
		
		hou[3]=t2;
		hou[4]=t1;	
}


void dizuo(){
	
		int t1=zuo[1];
		int t2=zuo[3];
		zuo[1]=hou[2];
		zuo[3]=hou[1];
		
		hou[1]=you[2];
		hou[2]=you[4];
		
		you[2]=qian[4];
		you[4]=qian[3];
		qian[4]=t2;
		qian[3]=t1;
}


void diyou(){
		int t1=zuo[1];
		int t2=zuo[3];
		
		zuo[1]=qian[3];
		zuo[3]=qian[4];
		
		qian[3]=you[4];
		qian[4]=you[2];
		
		you[4]=hou[2];
		you[2]=hou[1];
		
		hou[1]=t2;
		hou[2]=t1;	
}


void zuozuo(){
		int t1=ding[1];
		int t2=ding[3];
		
		ding[1]=qian[1];
		ding[3]=qian[3];
		
		qian[1]=di[1];
		qian[3]=di[3];
		
		di[1]=hou[1];
		di[3]=hou[3];
		
		hou[3]=t2;
		hou[1]=t1;
}

void zuoyou(){
		int t1=ding[1];
		int t2=ding[3];
		
		ding[1]=hou[1];
		ding[3]=hou[3];
		
		hou[1]=di[1];
		hou[3]=di[3];
		
		di[1]=qian[1];
		di[3]=qian[3];
		
		qian[3]=t2;
		qian[1]=t1;
}

void youzuo(){
		int t1=ding[2];
		int t2=ding[4];
		
		ding[2]=hou[2];
		ding[4]=hou[4];
		
		hou[2]=di[2];
		hou[4]=di[4];
		
		di[2]=qian[2];
		di[4]=qian[4];
		
		qian[4]=t2;
		qian[2]=t1;
}

void youyou(){
		int t1=ding[2];
		int t2=ding[4];
		
		ding[2]=qian[2];
		ding[4]=qian[4];
		
		qian[2]=di[2];
		qian[4]=di[4];
		
		di[2]=hou[2];
		di[4]=hou[4];
		
		hou[4]=t2;
		hou[2]=t1;
}


void qianzuo(){
	int t1=ding[3];
	int t2=ding[4];
	
	ding[3]=you[3];
	ding[4]=you[4];
	
	you[3]=di[2];
	you[4]=di[1];
	
	di[2]=zuo[3];
	di[1]=zuo[4];
	
	zuo[3]=t1;
	zuo[4]=t2;
	
}

void qianyou(){
	int t1=ding[3];
	int t2=ding[4];
	
	ding[3]=zuo[3];
	ding[4]=zuo[4];
	
	zuo[3]=di[2];
	zuo[4]=di[1];
	
	di[2]=you[3];
	di[1]=you[4];
	
	you[3]=t1;
	you[4]=t2;	
}

void houyou(){
	int t1=ding[1];
	int t2=ding[2];
	
	ding[1]=you[1];
	ding[2]=you[2];
	
	you[1]=di[4];
	you[2]=di[3];
	
	di[4]=zuo[1];
	di[3]=zuo[2];
	
	zuo[1]=t1;
	zuo[2]=t2;
}

void houzuo(){
	int t1=ding[1];
	int t2=ding[2];
	
	ding[1]=zuo[1];
	ding[2]=zuo[2];
	
	zuo[1]=di[4];
	zuo[2]=di[3];
	
	di[4]=you[1];
	di[3]=you[2];
	
	you[1]=t1;
	you[2]=t2;	
}

int main(){
	
	
	
	int n;
	cin>>n;
	while(n--){
		for(int i=1;i<=4;i++)cin>>ding[i];
		for(int i=1;i<=4;i++)cin>>qian[i];	
		for(int i=1;i<=4;i++)cin>>di[i];	
		for(int i=1;i<=4;i++)cin>>hou[i];	
		for(int i=1;i<=4;i++)cin>>zuo[i];	
		for(int i=1;i<=4;i++)cin>>you[i];
			
		
		bool flag=0;
		flag=judge();
		
	//	cout<<flag<<endl;
		
		//ding
		dingzuo();
		flag=judge()|flag;
		
		dingyou();
		dingyou();
		flag=judge()|flag;	
		dingzuo();
		
		//di
		dizuo();
		flag=judge()|flag;
		diyou();
		diyou();
		flag=judge()|flag;
		dizuo();
		
		//zuo
		zuozuo();
		flag=judge()|flag;
		zuoyou();
		zuoyou();
		flag=judge()|flag;
		zuozuo();
		
		//you
		youyou();
		flag=judge()|flag;
		youzuo();
		youzuo();
		flag=judge()|flag;
		youyou();
		
		//qian
		qianzuo();
		flag=judge()|flag;
		qianyou();
		qianyou();
		flag=judge()|flag;
		qianzuo();
		
		//hou
		houzuo();
		flag=judge()|flag;
		houyou();
		houyou();
		flag=judge()|flag;
		houzuo();
			
			
		if(flag==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;	
			
			
			
			
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}


