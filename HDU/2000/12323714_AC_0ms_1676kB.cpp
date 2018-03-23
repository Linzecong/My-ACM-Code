#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char str[3], ch;
	int i = 0;
	while(cin>>ch){
		str[i] = ch;
		i++;
		if(i == 3){
			sort(str, str+3);
			for(int j = 0; j < 3; j++){
				cout<<str[j];
				if(j < 2)  cout<<" ";
			}
			cout<<endl;
			i = 0;
		}
	}
	return 0;
}