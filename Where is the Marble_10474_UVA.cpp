//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1415
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//======================================================
int bsFirst(vector <int> &a, int left, int right, int x)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if ((mid == left || x > a[mid - 1]) && a[mid] == x)
			return mid + 1;
		else 
		  if (x > a[mid])
		    return bsFirst(a, (mid + 1), right, x);
		  else
		    return bsFirst(a, left, (mid - 1), x);
	}
	return -1;
}
//======================================================
int main()
{
	int n,q;
	int d = 0;
	while (cin>>n>>q, n != 0 && q != 0)
	{
		vector <int> a;
		int value;
		for (int i = 0; i < n; i++)
		{
			cin >> value;
			a.push_back(value);
		}
		sort(a.begin(),a.end());
		cout<<"CASE# "<<++d<<":"<<endl;
		while (q--)
		{
			cin>>value;
			if (bsFirst(a, 0, n - 1, value) == -1)
				cout<<value<<" not found"<<endl;
			else cout<<value<<" found at "<<kt <<endl;
		}
	}
	return 0;
}
