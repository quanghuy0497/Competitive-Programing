//https://codeforces.com/problemset/problem/886/C
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <bool> a(n, false);
	int count = 1;
	for (int x, i = 0; i < n; i++)
	{
		cin >> x;
		a[x] = true;
	}
	for (int i = 0; i < n; i++)
		if (!a[i]) count ++;
	cout << count << endl;
	return 0;
}
