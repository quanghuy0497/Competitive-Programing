//http://www.spoj.com/problems/OPCPIZZA/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//======================================================
int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		int n, pride;
		cin >>n >>pride;
		vector <int> a;
		int value;
		for (int i = 0; i < n; i++)
		{
			cin >> value;
			a.push_back(value);
		}
		sort(a.begin(), a.end());
		int d = 0;
		for (int i = 0; i < n; i ++)
		  if (binary_search(a.begin() + i + 1 , a.end(), pride - a[i])) d++;
		cout<< d <<endl;
	}
	return 0;
} 
