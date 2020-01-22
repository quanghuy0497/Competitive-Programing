//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=670
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//==============================================================================
void backtracking (int n, int h,string x, int index, int indexb, vector<string> &result)
{
	if (index == h)
	{
		result.push_back(x);
	}
	for (int i = indexb + 1 ; i < n; i++)
		if 	(x[i] =='0' && index < h)
		{
			x[i] = '1';
			index++;
			backtracking(n, h, x, index, i, result);
			index--;
			x[i] = '0';
		}
}
//==============================================================================
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, h;
		cin >> n >> h;
		string x;
		for (int i = 0; i < n; i++) x += '0';
		vector<string> result;
		backtracking(n, h,x, 0, -1, result);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
		cout<<endl;
	}
	return 0;
}
