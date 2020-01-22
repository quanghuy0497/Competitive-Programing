//https://www.spoj.com/problems/CRSCNTRY/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector <int> Agness;
		int x, answer = 0;
		while (cin >> x, x != 0)
			Agness.push_back(x);
		while (cin >> x, x != 0)
		{
			vector <int> Tom;
			Tom.push_back(x);
			while (cin >> x, x != 0)
				Tom.push_back(x);
			int n = Agness.size(), m = Tom.size();
			int result[n + 1][m + 1];
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= m; j++)
					if (i == 0 || j == 0) result[i][j] = 0;
					else if (Agness[i - 1] == Tom[j - 1]) result[i][j] = result[i - 1][j - 1] + 1;
					else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
			answer = max(answer, result[n][m]);
		}
		cout<<answer<<endl;
	}
	return 0;
}
