//https://www.spoj.com/problems/UCI2009D/
#include <iostream>
#include <set>
using namespace std;

char graph[10][10];
bool visited[10][10];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
set <long long> octaves;
int n;
//===============================================================================
bool check (int x, int y)
{
	return x >= 0 && x <n && y >= 0 && y < n;
}
//===============================================================================
void backtracking (int x, int y, int step, long long bit)
{
	visited[x][y] = true;
	bit |= 1LL << (x * n + y);
	if (step == 8)
		octaves.insert(bit);
	else
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if (check(nextx, nexty) && !visited[nextx][nexty] && graph[nextx][nexty] == 'X')
				backtracking(nextx, nexty, step + 1, bit);
		}
	bit &= ~(1 << (x * n + y));
	visited[x][y] = false;
}
//===============================================================================
int main()
{
	int t;
	cin >> t;
	long long bit;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> graph[i][j];
				visited[i][j] = false;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][j] == 'X')
				{
					bit = 0;
					backtracking(i, j, 1, bit);
				}
		cout << octaves.size() << endl;
		octaves.clear();
	}
	return 0;
	}
