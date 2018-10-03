//https://www.hackerrank.com/challenges/find-the-median/problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//=============================================
int main()
{
	int n, value;
	cin>>n;
	vector <int> a;
	for (int i = 0; i < n; ++i)
	{
		cin>>value;
		a.push_back(value);
	}
	sort(a.begin(), a.end());
	cout<<a[n/2]<<endl;
	return 0;
}
