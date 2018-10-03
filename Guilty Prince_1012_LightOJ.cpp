//http://lightoj.com/volume_showproblem.php?problem=1012
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
int n,m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, visited[60][60];
char a[60][60];
//============================================================================
void DFS(Point u, int &d)
{
	visited[u.x][u.y] = d;
	for (int i = 0; i < 4; ++i)
		if ((u.x + dx[i] >= 0) && (u.x + dx[i] < n) && (u.y + dy[i] >= 0) && (u.y + dy[i] < m) 
		  && (visited[ u.x + dx[i] ][ u.y + dy[i] ] == -1) && (a[ u.x + dx[i] ][ u.y + dy[i] ] == '.'))
			DFS(Point(u.x + dx[i], u.y + dy[i]), ++d);
}
//============================================================================
int main()
{
	int k, num = 0;
	cin>>k;
	while (k--)
	{
		int d = 1;
		cin>>m>>n;
		Point Pointed;
		for (int i = 0; i < n; i++)
		  for (int j = 0; j < m; j++)
	  	    {
	  		  cin>>a[i][j];
	  		  if (a[i][j]=='@')
		  	    Pointed = Point(i,j);
		  	  visited[i][j] = -1;
	  	    }
		DFS(Pointed, d);
		cout<<"Case "<<++num<<": "<<d<<endl;
	}
	return 0;
}
