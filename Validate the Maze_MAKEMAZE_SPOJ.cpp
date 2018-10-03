//http://www.spoj.com/problems/MAKEMAZE/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//============================================================================
struct Point
{
	int x,y;
	Point (int a, int b)
	{
		x = a;
		y = b;
	};
};
int n,m, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, visited[30][30];
char a[30][30];
//============================================================================
bool BFS(Point Start, Point End)
{
	queue <Point> q;
	visited [Start.x][Start.y] = 1;
	q.push(Start);
	while (!q.empty())
	{
		Point u = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		  if ((u.x + dx[i] >= 0) && (u.x + dx[i] < n) && (u.y + dy[i] >= 0) && (u.y + dy[i] < m) 
		  && (visited[ u.x + dx[i] ][ u.y + dy[i] ] == 0) && (a[ u.x + dx[i] ][ u.y + dy[i] ] == '.'))
		  {
		  	visited[ u.x + dx[i] ][ u.y + dy[i] ] = 1;
		  	if (u.x + dx[i] == End.x && u.y + dy[i] == End.y)
			  return true;
		  	q.push(Point(u.x + dx[i], u.y + dy[i]));
		  }
	}
	return false;
}
//============================================================================
int main()
{
	int k;
	cin>>k;
	while (k--)
	{
		cin>>n>>m;
		vector <Point> pointed;
		for (int i=0; i<n; ++i)
		  for (int j=0; j<m; ++j)
		  {
		  	cin>>a[i][j];
		  	if ((i == 0 || i == n-1 || j == 0 || j == m-1) && (a[i][j]=='.'))
		  	  pointed.push_back(Point(i,j));
		  	visited[i][j] = 0;
		  }
		if (pointed.size()==2)
			if (BFS(pointed[0], pointed[1]))
				cout<<"valid"<<endl;
			else cout<<"invalid"<<endl;
		else cout<<"invalid"<<endl;
	}
	return 0;
}
