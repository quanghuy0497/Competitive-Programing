//https://codeforces.com/problemset/problem/262/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, k, result = 0, minn = 1e9;
	vector <int> a;
	cin >> n >> k;
	for (int x, i = 0; i < n; i++)
	{
		cin >> x;
		minn = min(minn, abs(x));
		if (x < 0 && k > 0)
		{
			result -= x; 
			k--;
		}
		else result += x;
	}
	if (k % 2 == 1)
		result -= 2 * minn;
	cout<< result << endl;
}
