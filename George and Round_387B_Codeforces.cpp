//http://codeforces.com/problemset/problem/387/B
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	cin>> n >>m;
	vector <int> a,b;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	for (int i = 0; i < m; i++)
	{
		int value;
		cin>>value;
		b.push_back(value);
	}
	int check = 0, flag  = 0;
	for (int i = 0; i < n; i++)
		for (; flag < m; flag++)
		  if (a[i] <= b[flag])
		  {
		  	check++;
		  	flag++;
		  	break;
		  }
	cout<< n - check<<endl;
	return 0;
}
