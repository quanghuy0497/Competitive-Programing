//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/description/
#include <iostream>
#include <set>
using namespace std;
int main()
{
	int k;
	cin >>k;
	while (k--)
	{
		int n,m;
		long long value;
		cin >>n >>m;
		set <long long> s;
		for (int i = 0; i < n; i++)
		{
			cin>>value;
			s.insert(value);
		}
		for (int i = 0; i < m; i++)
		{
			cin>>value;
			if (s.find(value) == s.end())
			{
			   cout<<"NO"<<endl;
			  s.insert(value);
			}
			else
			  cout<<"YES"<<endl;
		}
	}
	return 0;
}
