//http://codeforces.com/problemset/problem/723/D
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
//============================================================================
struct Point
{
	int x,y;
	Point (int a = 0, int b = 0)
	{
		x = a;
		y = b;
	};
};
struct lake
{
	Point Start;
	int Size;
	bool operator < (const lake& B) 
	{
		if (Size < B.Size)
			return true;
		return false;
	};
};
int n, m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, visited[60][60];
char a[60][60];
//============================================================================
void DFS(Point u)
{
	visited[u.x][u.y] = 1;
	a[u.x][u.y] = '*';
	for (int i = 0; i < 4; ++i)
		if (visited[ u.x + dx[i] ][ u.y + dy[i] ] == 0)
			DFS(Point(u.x + dx[i], u.y + dy[i]));
}
//============================================================================
int DFS_Ocean(Point u)
{
	int kt = 1, count = 1;
	if ((u.x == 0) || (u.x == n - 1) || (u.y == 0) || (u.y == m -1)) kt = 0;
	visited[u.x][u.y] = 0;
	for (int i = 0; i < 4; ++i)
		if ((visited[ u.x + dx[i] ][ u.y + dy[i] ] == -1) && (a[ u.x + dx[i] ][ u.y + dy[i] ] == '.'))
		{
			int d = DFS_Ocean(Point(u.x + dx[i], u.y + dy[i]));
			if (d == -1) kt = 0;
			else count += d;
		}
	if (kt) return count;
	else return -1;
}
//============================================================================
int main()
{
	int k;
	cin>>n>>m>>k;
	vector <Point> Pointed;
	vector <lake> Lake;
	for (int i = 0; i < n; i++)
	  for (int j = 0; j < m; j++)
	  {
	  	cin>>a[i][j];
	  	visited[i][j] = -1;
	  }
	for (int i = 0; i < n; i++)
	  for (int j = 0; j < m; j++)
	    {
	    	if (a[i][j] == '.' && visited[i][j] == -1)
	    	{
	    		int u = DFS_Ocean(Point(i,j));
	    		if (u != -1)
	    		{
	    			lake tmp; tmp.Start = Point(i,j); tmp.Size = u;
					Lake.push_back(tmp);
				}
			}
		}
	int countCell = 0;
	sort(Lake.begin(), Lake.end());
	for (int i = 0; i < Lake.size() - k; i++)
	{
		countCell += Lake[i].Size;
		DFS(Lake[i].Start);
	}
	cout<<countCell<<endl;
	for (int i = 0; i < n; i++)
	{
	  for (int j = 0; j < m; j++)
	      cout<<a[i][j];
	  cout<<endl;
	}
	return 0;
}
