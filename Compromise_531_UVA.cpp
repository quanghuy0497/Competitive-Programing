//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	string st;
	while (cin >> st)
	{
		int n = 0, m = 0;
		vector <string> sta, stb;
		sta.push_back(st);
		n++;
		while (cin >> st, st!="#")
		{
			sta.push_back(st);
			n++;
		}
		while (cin >> st, st!= "#")
		{
			stb.push_back(st);
			m++;
		}
		int result[n+1][m+1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				if (i == 0 || j == 0) result[i][j] = 0;
				else if (sta[i - 1] == stb[j - 1]) result[i][j] = result[i - 1][j - 1] + 1;
				else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
		vector <string> answer(result[n][m]);
		int length = result[n][m];
		while (n > 0 && m > 0)
		{
			if (sta[n - 1] == stb[m - 1])
			{
				answer.push_back(sta[n - 1]);
				n --;
				m --;
				length --;
			}
			else if (result[n - 1][m] > result[n][m - 1])
				n --;
			else m --;
		}
		reverse(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout<<answer[i]<<" ";	
	}
	return 0;
}
