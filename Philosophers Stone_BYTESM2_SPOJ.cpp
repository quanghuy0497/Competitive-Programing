//https://www.spoj.com/problems/BYTESM2/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int h, w;
		cin >> h >> w;
		int matrix[h + 3][w + 3], result[h + 3][w + 3];
		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
				result[i][j] = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				cin >> matrix[i][j];
				result[i][j] = max(result[i - 1][j], max(result[i - 1][j - 1], result[i - 1][j + 1])) + matrix[i][j];
			}
		int answer = result[h][1];
		for (int i = 2; i <= w; i++)
			answer = max(answer, result[h][i]);
		cout << answer << endl;
	}
	return 0;
}
