//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=167
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//====================================================================================
int lowerBound(const vector<int> &a, const vector<int> &sub, int n, int x)
{
	int left = 0;
	int right = n;
	int pos = right;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[sub[mid]] > x)
		{
			pos = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return pos;
}
//====================================================================================
int main()
{
	int t = 0, x;
	while (cin >>x, x != -1)
	{
		vector <int> a;
		a.push_back(x);
		while (cin >> x, x != -1)
			a.push_back(x);
		reverse(a.begin(), a.end());
		t++;
		int length = 1;
		vector <int> result;
		result.push_back(0);
		for (int i = 1; i < a.size(); i++)
			if (a[i] < a[result[0]])
				result[0] = i;
			else if (a[i] >= a[result[length - 1]])
			{
				result.push_back(i);
				length++;
			}
			else
			{
				int pos = lowerBound(a, result, length, a[i]);
				result[pos] = i;
			}
		if (t > 1) cout<<endl;
		cout<<"Test #"<<t<<":"<<endl;
		cout<<"  maximum possible interceptions: "<<length<<endl;
	}
	return 0;
}
