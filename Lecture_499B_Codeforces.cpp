//http://codeforces.com/problemset/problem/499/B
#include <iostream>
#include <string>
using namespace std;
///===============================================
string Choose(string a, string b)
{
	if (a.size() <= b.size())
		return a;
	else return b;
}
///===============================================
int main()
{
	int n,m;
	cin>>n>>m;
	string value, a[3002], b[3002];
	for (int i = 0; i < m; ++i)
		cin>>a[i]>>b[i];
	for (int i = 0; i < n; ++i)
	{
		cin>>value;
		for (int j = 0; j < m; ++j)
			if (value == a[j])
				cout<< Choose(a[j],b[j])<<" ";
	}
	return 0;
}
