//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/the-monk-and-prateek/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
//====================================================================================
int r3gz3n (int n)
{
	int c = 0, x = n;
	while (x != 0)
	{
		c += x % 10;
		x /= 10;
	}
	return n ^ c;
}
//====================================================================================
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> a;
	int maxhash = -1, collisions = 0, minvalue, maxvalue, maxcollisions = -1;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[r3gz3n(x)]++;
	}
	for (unordered_map<int, int>:: iterator i = a.begin(); i != a.end(); i++)
	{
		if (i->second > 1) collisions += i->second - 1;
		if (maxcollisions < i->second)
		{
			maxcollisions = i->second;
			minvalue = i->first;
		}
		else if (maxcollisions == i->second && minvalue > i->first) minvalue = i->first;
		maxvalue = max(maxvalue, i->first);
	}
	if (collisions == 0)
		cout<<maxvalue<<" "<<collisions<<endl;
	else
		cout<<minvalue<<" "<<collisions<<endl;
	return 0;
}
