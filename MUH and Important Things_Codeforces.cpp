//http://codeforces.com/problemset/problem/471/B
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 20010
using namespace std;
//=======================================================================================
int main()
{
	int n;
	cin>>n;
	vector <int> ch;
	pair <int, int> a[MAX];
	for (int i = 1; i <= n; i++)
	{
		int value;
		cin >> value;
		a[i].first = value;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	int  check = 0;
	for (int i = 1; i < n; i++)
	    if (a[i].first == a[i+1].first)
		{
		  check++;
		  ch.push_back(i);
		}
	if (check  < 2)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i = 1; i <=n; i++)
		  cout<<a[i].second<<" ";
		cout<<endl;
		swap(a[ch[0]], a[ch[0] +1 ]);
		for(int i = 1; i <=n; i++)
		  cout<<a[i].second<<" ";
		cout<<endl;
		swap(a[ch[1]], a[ch[1] + 1]);
		for(int i = 1; i <=n; i++)
		  cout<<a[i].second<<" ";
		cout<<endl;
	}
	return 0;
}
