//https://codeforces.com/problemset/problem/285/C
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <long long> a;
	long long result = 0;
	for (int x, i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		result += abs(a[i] - i - 1);
	cout << result << endl;
	return 0;
}
