#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int color[10005];

int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		int ans = 1;
		for(int i = 2; i <= N / 2 + 1; i++) {	//算出最小的颜色种类数 
			int tmp = 1;
			for(int j = i; j <= N; j *= 2) {
				tmp++;
			}
			if(tmp > ans) ans = tmp;
		}
		
		memset(color, 0, sizeof(color));	//记录每个数字的颜色 
		color[1] = 1;
		for(int i = 2; i <= N; i++) {
			if(color[i] == 0) {
				int c = 2;
				int t = i;
				for(int j = i; j <= N; j += i) {
					if(j >= t * 2) c++, t *= 2;
					color[j] = c;
				}
			}
		}
		
		printf("%d\n", ans);		//输出结果 
		for(int i = 1; i < N; i++) printf("%d ", color[i]);
		printf("%d\n", color[N]);
	}
	return 0;
}