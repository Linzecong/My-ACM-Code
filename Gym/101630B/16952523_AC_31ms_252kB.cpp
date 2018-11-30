#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c;
int w,h;
bool get(int u,int v){
	return (u<=w&&v<=h)||(v<=w&&u<=h);
}
bool judge(int a,int b,int c){
	return get(2*a+b,2*c+2*a)|get(a+b+c,2*a+2*c)|get(2*a+b,b+2*c+a)|get(a+b+c,b+2*c+a)|get(3*a+b+c,b+c)|get(a+b+c,2*b+a+c);
}
int main(){
	cin >> a >> b >> c;
	cin >> w >> h;
	bool flag=judge(a,b,c)|judge(b,a,c)|judge(b,c,a)|judge(a,c,b)|judge(c,a,b)|judge(c,b,a);
	if (flag) cout << "Yes" ;
	else cout << "No";
} 