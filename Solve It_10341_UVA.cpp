//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
#include <iostream>
#include <math.h>
int p ,q ,r ,s ,t ,u;
//===============================================
double equal(double x)
{
	return p *exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) +  t * pow (x, 2) + u;
}
//===============================================
using namespace std;
int main()
{
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		if (equal(0) < 0 || equal(1) > 0)
			cout<<"No solution"<<endl;
		else
		{
			int count = 50;
			double left = 0, right = 1, mid = 1;
		    while(count--)
			{
				mid = (left + right) / 2;
		        if (equal(mid) > 0) left = mid;
		        else right = mid;
		    }
			printf("%.4lf\n", mid);
		}
	}
	return 0;
}
