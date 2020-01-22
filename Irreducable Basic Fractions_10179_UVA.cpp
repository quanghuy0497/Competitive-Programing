//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120
#include <iostream>
using namespace std;
int main()
{
	long long n;
	while (cin >> n, n != 0)
	{
		long long result = n;
		for (long long i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				while (n % i == 0)
					n /= i;
				result = result / i * (i - 1);
			}
		}
		if (n > 1) result = result / n * (n - 1);
		cout<< result<<endl;
	}
}
