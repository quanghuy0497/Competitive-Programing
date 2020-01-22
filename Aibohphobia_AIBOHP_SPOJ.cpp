//https://www.spoj.com/problems/AIBOHP/
#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string sta;
	cin >> sta;
	string stb = sta;
	reverse(sta.begin(), sta.end());
	int result[sta.size() + 1][sta.size() + 1];
	for (int i = 0; i <= sta.size(); i++)
		for (int j = 0; j <= sta.size(); j++)
			if (i == 0 || j == 0) result[i][j] = 0;
			else if (sta[i - 1] == stb[j - 1]) result[i][j] = result[i - 1][j - 1] + 1;
				else result[i][j] = max(result[i - 1][j], result[i][j - 1]);
	cout<<sta.size() - result[sta.size()][stb.size()]<<endl;
	return 0;
}
