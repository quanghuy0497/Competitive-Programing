//https://www.spoj.com/problems/ADFRUITS/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	string sta, stb;
	while (cin >> sta >> stb)
	{
		int n = sta.size(), m = stb.size();
		sta = '#' + sta;
		stb = '#' + stb;
		vector<vector<int>> result (n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				if (i == 0 || j == 0) result[i][j] = 0;
				else if (sta[i] == stb[j]) result[i][j] = result[i - 1][j - 1] + 1;
					else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
		string answer;
		for (int i = n, j = m; i || j;)
			if (i == 0)
				answer += stb[j--];
			else if (j == 0)
					answer += sta[i--];
				else if (sta[i] == stb[j])
				{
					answer += sta[i--];
					j--;
				}
				else if(result[i][j] == result[i-1][j])
					answer += sta[i--];
				else answer += stb[j--];
		cout<<string(answer.rbegin(), answer.rend())<<endl;
	}
	return 0;
}
