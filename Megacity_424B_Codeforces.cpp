//http://codeforces.com/problemset/problem/424/B
#include <iostream>
#include <math.h>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
	int n,s;
	cin >>n >>s;
	map <double, int> mp;
	for (int i = 0; i  < n; i++)
	{
		int a,b,c;
		cin >>a >>b >>c;
		mp[sqrt(a*a + b*b)] += c;
	}
	for (map <double, int>:: iterator it = mp.begin(); it != mp.end(); it++)
	{   
		s += it->second;
	    if (s >=1000000)
	    {
	   		cout<<fixed<< setprecision(6)<<it->first<<endl;
	   		return 0;
	    }
	}
	cout<<-1<<endl;
	return 0;
}
