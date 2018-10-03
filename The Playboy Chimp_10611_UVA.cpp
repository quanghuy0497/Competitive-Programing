//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=316&page=show_problem&problem=1552
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//======================================================
int main()
{
	int n, q, value;
	vector <int> a;
	cin >>n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		a.push_back(value);
	}
	cin>>q;
	for (int i = 0; i < q; i++)
	{
		cin>>value;
		vector<int> ::iterator uppervalue = upper_bound(a.begin(), a.end(), value);
		int indexupp = uppervalue - a.begin();
		vector<int> ::iterator lowervalue = lower_bound(a.begin(), a.end(), value);
		int indexlow = lowervalue - a.begin();
		if (indexlow > 0) cout<<a[indexlow - 1]; else cout<<"X";
		if (indexupp < n) cout<<" "<<a[indexupp]<<endl; else cout<<" X"<<endl;
	}
	return 0;
}
