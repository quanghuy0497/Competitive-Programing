//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/aish-and-xor-2/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, q;
	cin >> n;
	vector <int> a(n);
	for (int x, i = 0; i < n; i++)
	{
		cin >> x;
		if (i > 0) a[i] = a[i - 1] + x;
		else a[i] = x;
	}
	cin >> q;
	while (q--)
	{
		int l, r, x = 0, y = 0;
		cin >>l >>r;
		--l; --r;
		if (l > 0) x = a[r] - a[l - 1];
		else x = a[r];
		y = r - l + 1 - x;
		cout << x % 2<<" "<< y << endl;
	}
	return 0;
}
