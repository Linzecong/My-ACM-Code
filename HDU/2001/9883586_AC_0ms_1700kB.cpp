#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

struct point{
	double x;
	double y;
};

int main()
{
	point a, b;
	while(scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y)!=EOF)
	{
		double len = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
		printf("%.2lf\n", len); 
	}

	return 0;
}