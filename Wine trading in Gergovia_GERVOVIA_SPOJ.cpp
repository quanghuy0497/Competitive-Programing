//https://www.spoj.com/problems/GERGOVIA/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		long long result = 0, count = 0;
		for (int x, i = 0; i < n; i++)
		{
			cin >> x;
			count += x;
			result += abs(count);
		}
		cout << result << endl;
	}
}
