//http://codeforces.com/problemset/problem/572/A
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int na,nb,k,m,value;
	vector <long> a,b;
	cin >>na >>nb >>k >>m;
	for (int i = 0; i < na; i++)
	{
		cin >>value;
		a.push_back(value);
	}
	for (int i = 0; i < nb; i++)
	{
		cin >>value;
		b.push_back(value);
	}
	if (a[k - 1] < b[nb - m])
	 cout<<"YES";
	else cout<<"NO";
}
