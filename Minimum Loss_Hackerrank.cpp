//https://www.hackerrank.com/contests/womens-codesprint-2/challenges/minimum-loss
#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set <long long> a;
	long long minn = 1e18;
	while (n--)
	{
		long long value;
		cin >>value;
		set <long long> :: iterator k = a.upper_bound(value);
		a.insert(value);
		if (k != a.end())
	      minn = min(minn, *k - value);
	}
	cout<<minn<<endl;
	return 0;
}
