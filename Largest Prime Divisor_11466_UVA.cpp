//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2461
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long n;
	while (cin >> n, n != 0)
	{
		n = abs(n);
		long long result = n;
		int count = 0;
		for (long long i = 2; i * i <= n; i++)
			if (n % i == 0)
			{
				count ++;
				while (n % i == 0)
					n /= i;
				result = i;
			}
		if (n > 1) 
		{
			result = n;
			count ++;
		}
		if (count == 1) cout << -1 << endl;
		else cout << result << endl; 
	}
	return 0;
}
