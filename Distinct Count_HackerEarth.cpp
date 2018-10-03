//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/
#include <iostream>
#include <set>
using namespace std;
int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		int n,x;
		cin >> n >>x;
		set <int> a;
		while (n--)
		{
			int value;
			cin >>value;
			a.insert(value);
		}
		if (a.size() == x)
			cout<<"Good"<<endl;
	  	  else if (a.size() > x)
			cout<<"Average"<<endl;
		    else cout<<"Bad"<<endl;
	}
	return 0;
}
