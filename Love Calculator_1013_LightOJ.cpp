//http://lightoj.com/volume_showproblem.php?problem=1013
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		string st1, st2;
		cin >> st1 >> st2;
		int n = st1.size(), m = st2.size();
		vector <vector <int> > result;
		vector <vector <long long> > num;
		result.resize(n + 1, vector<int>(m + 1));
    	num.resize(n + 1, vector<long long>(m + 1));
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <=m; j++)
				if (i == 0 || j == 0)
				{
					result[i][j] = i + j;
					num[i][j] = 1;
				}
				else if (st1[i - 1] == st2[j - 1])
				{
					result[i][j] = result[i - 1][j - 1] + 1;
					num[i][j] = num[i - 1][j - 1];
				}
				else
				{
					result[i][j] = min(result[i - 1][j], result[i][j - 1]) + 1;
					if (result[i][j] == result[i - 1][j] + 1)	num[i][j] += num[i - 1][j];
					if (result[i][j] == result[i][j - 1] + 1)	num[i][j] += num[i][j - 1];
				}
		cout<<"Case "<<cs<<": "<<result[n][m]<<" "<<num[n][m]<<endl;
	}
	return 0;
}
