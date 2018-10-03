//http://www.lightoj.com/volume_showproblem.php?problem=1008
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		long long value;
		cin>> value;
		long long c = ceil(sqrt(value));
		long long r = c * c - value;
		long long x,y;
		if (r < c)
		{
			y = r + 1;
			x = c;
		}
		else
		{
			x = 2 * c - r - 1;
			y = c;
		}
		if (c & 1) swap(x,y);
		cout<<"Case " <<i <<": " <<x <<" " <<y <<endl;
	}
	return 0;
}
