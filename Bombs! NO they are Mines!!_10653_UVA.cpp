//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1010
struct Point
{
	int x,y;
	Point (int a = 0, int b = 0)
	{
		x = a;
		y = b;
	};
};
int n, m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, a[MAX][MAX];
Point Path[MAX][MAX];
//============================================================================
void BFS(Point Start)
{
	queue <Point> q;
	q.push(Start);
	a[Start.x][Start.y] = -1;
	while (!q.empty())
	{
		Point u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		  if ((u.x + dx[i] >= 0) && (u.x + dx[i] < n) && (u.y + dy[i] >= 0) && (u.y + dy[i] < m) 
		  && (a[ u.x + dx[i] ][ u.y + dy[i] ] == 0))
		  {
		  	a[ u.x + dx[i] ][ u.y + dy[i] ] = -1;
		  	q.push(Point(u.x + dx[i], u.y + dy[i]));
		  	Path[u.x + dx[i]][u.y + dy[i]] = u; 
		  }
	}
}
//============================================================================
int FindPath(Point S, Point E)
{
    if ((S.x == E.x && S.y ==E.y) || (E.x == -1 && E.y == -1))
	    return 0;
	else return 1 + FindPath(S, Path[E.x][E.y]); 
}
//============================================================================
int main()
{
	int k;
	Point Start, End;
	n = 1; m = 1;
	while (n != 0 && m != 0)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		cin >> k;
		for (int i = 0; i <= n; i++)
	  	  for (int j = 0; j <= m; j++)
	  	  {
			a[i][j] = 0;
			Path[i][j]= Point(-1, -1);
		  }
		for (int i = 0; i < k; i++)
		{
			int row, x, bomb;
			cin >> row >> x;
			for (int j = 0; j < x; j++)
			{
				cin >> bomb;
				a[row][bomb] = 1;
			}
		}
		cin>> Start.x>> Start.y>> End.x>> End.y;
		BFS(Start);
		cout<< FindPath(Start, End) <<endl;
	}
	return 0;
}
