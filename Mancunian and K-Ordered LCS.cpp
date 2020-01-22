#include <iostream>
#include <vector>
using namespace std;
//==========================================================================
int LCS(int n, int m, vector <int> a, vector<int> b)
{
	vector<vector<int>> result (n + 1, vector<int>(m + 1));
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0) result[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) result[i][j] = result[i - 1][j - 1] + 1;
				else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
	return result[n][m];
}
//==========================================================================
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> a(n);
	vector <int> b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cout<<min(n,LCS(n,m,a,b) + k);
	return 0;
}
