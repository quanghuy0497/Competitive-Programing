//https://codeforces.com/problemset/problem/448/C
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> a;
//=================================================================================
int backtracking (int left, int right, int heigh)
{
	if (left > right) return 0;
	int minn = left;
	for (int i = left + 1; i <= right; i++)
		if (a[i] < a[minn])	minn = i;
	return min(right - left + 1, a[minn] - heigh + backtracking(left, minn - 1, a[minn]) + backtracking(minn + 1, right, a[minn]));
}
//=================================================================================
int main()
{
	int n;
	cin >> n;
	for (int x, i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	cout << backtracking(0, n - 1, 0);
	return 0;
}
