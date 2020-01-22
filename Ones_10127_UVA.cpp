//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1068
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int y = 1, i = 0;
		while (++i)
		{
			if (y % n == 0) break;
			y = y * 10 + 1;
			y %= n;
		}
		cout << i << endl;
	}
}
