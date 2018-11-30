#include <iostream>
#include <cstring>
using namespace std;
const int maxn=50;
char a[maxn],b[maxn];
char A[20][20],B[20][20];
int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> a >> b;
		int len1=strlen(a);
		int len2=strlen(b);
		int cnt1=0,cnt2=0;
		for (int i=0;i<len1;i++){
			if (a[i]=='-') continue;
			if (a[i]!='0'){
				cnt1++;
				A[cnt1][0]=a[i];
				for (int j=1;j<=len1-i-1;j++){
					A[cnt1][j]='0';
				}
				A[cnt1][len1-i]='\0';
			}
		}
		for (int i=0;i<len2;i++){
			if (b[i]=='-') continue;
			if (b[i]!='0'){
				cnt2++;
				B[cnt2][0]=b[i];
				for (int j=1;j<=len2-i-1;j++){
					B[cnt2][j]='0';
				}
				B[cnt2][len2-i]='\0';
			}
		}
		for (int i=1;i<=cnt1;i++)
			for (int j=1;j<=cnt2;j++){
				if (i==1&&j==1){
					int f1=a[0]=='-',f2=b[0]=='-';
					if (f1^f2)
						printf("-");
					printf("%s x %s",A[i],B[j]);
				}
				else{
					int f1=a[0]=='-',f2=b[0]=='-';
					if (f1^f2){
						printf(" - %s x %s ",A[i],B[j]);
					}
					else{
						printf(" + %s x %s ",A[i],B[j]);
					}
				}
			}
		printf("\n");
	}
}