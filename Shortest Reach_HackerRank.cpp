//https://www.hackerrank.com/challenges/bfsshortreach/problem
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//===============================================================
void BFS(int start, int n, int	*path, vector <int> graph[])
{
	int visited[1002];
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
		path[i] = -1;
	}
	queue <int> q;
	q.push(start);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); ++i)
		{
			if (!visited[graph[u][i]])
			{
				visited[graph[u][i]] = visited[u] + 1;
				q.push(graph[u][i]);
				path[graph[u][i]] = u;
			}
		}
	}
	for (int i=1 ; i<=n; i++)
		if (i!=start)
			if (visited[i]!=0)
			  cout<<6 * visited[i]<<" ";
			else cout<<-1<<" ";
}
//===============================================================
int main()
{
  int q;
  cin>>q;
  for (int k = 0; k < q; ++k)
  {
  	int n, m, start;
	vector <int> graph[1002];
	int path[1002];
  	cin>>n>>m;
	for (int i = 1; i <= m; ++ i)
  	{
  		int nodeA, nodeB;
  		cin>>nodeA>>nodeB;
  		graph[nodeA].push_back(nodeB);
  		graph[nodeB].push_back(nodeA);
	}
	cin>>start;
	BFS(start, n, path, graph);
	for (int i = 1; i <= n; ++i)
		while (!graph[i].empty())
			graph[i].pop_back();
	cout<<endl;
  }
  return 0;
}
