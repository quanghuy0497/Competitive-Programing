#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int d=0;
	vector <int> v;
	for (int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	v.push_back(90);
	for (int i=0;i<=n;i++)
	{
		if (v[i]-d<=15)
		  d=v[i];
		else
		{
		  d=d+15;
		  break;
		}
	}
	cout<<d;
}
