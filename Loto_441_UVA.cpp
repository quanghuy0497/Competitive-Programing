//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=382
#include <iostream>
#include <vector>
using namespace std;
//================================================================================
void backtracking(vector <int> &x, vector <int> &result, int index)
{
	if (index == 6 )
	{
		for(int i = 0; i < 6; i++)
			cout << result[i] <<" ";
		cout << endl;
	}
	for (int j = 0; j < x.size(); j++)
		if ( (index == 0) || ((index > 0) && (result[index - 1] < x[j])) )
		{
			result[index] = x[j];
			backtracking(x, result, index + 1);
		}
}
//================================================================================
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		vector <int> x (n);
		for (int i = 0; i < n; i++)
			cin >> x[i];
		vector <int> result(6, 0);
		backtracking(x, result, 0);
		cout<<endl;
	}
	return 0;
}
