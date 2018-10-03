//http://codeforces.com/problemset/problem/451/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,value,l=-1,r=-1;
	vector<int> a,b;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>value;
		a.push_back(value);
	}
	b=a;	
	sort(b.begin(),b.end());
	for (int i=0;i<n;i++)
	  if (a[i] != b[i])
	  {
	  	l=i;
	  	break;
	  }
	for (int i=n-1;i>=0;i--)
	  if (a[i] != b[i])
	  {
	  	r=i;
	  	break;
	  }	  	
	if (l == -1 && r == -1)
		l = r = 0;
	for (int i=l, j=r;i<j;i++,j--)
	{
		int tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			cout << "no";
			return 0;
		}
	}
 
	cout << "yes" << endl;
	cout << l+1 << " " << r+1;
 
	return 0;}

