//http://codeforces.com/problemset/problem/169/A
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,a,b,value;
	vector<int> v;
	cin>>n>>a>>b;
	for (int i=0;i<n;i++)
	{
		cin>>value;
		v.push_back(value);
	}
	sort(v + 1, v + n + 1) ;
	if (v[b-1]<v[b])
	  cout<<v[b]-v[b-1];
	else cout<<0;
	return 0;
}
