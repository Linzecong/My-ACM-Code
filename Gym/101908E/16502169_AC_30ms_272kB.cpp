#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int MAXN=10005;

char str1[MAXN];
char str2[MAXN];

int main(){
	
	
	scanf("%s%s",str1,str2);
	int l1=strlen(str1);
	int l2=strlen(str2);
	bool flag;
	int ans=0;
	for(int i=0;i+l2<=l1;i++){
		flag=1;
		for(int j=0;j<l2;j++){		
			if(str2[j]==str1[i+j]){
				flag=0;
				break;
			}
			
		}
		if(flag)
			ans++;
	}
	printf("%d",ans);
	
	
	return 0;
}