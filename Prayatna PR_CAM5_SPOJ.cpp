//http://www.spoj.com/problems/CAM5/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,k;
vector <int> graph[100002];
int visited[100002];
//==============================================================================
void DFS(int s)
{
	for (int i = 0; i< graph[s].size(); ++i)
		if (!visited[ graph[s][i] ])
		{
			visited[ graph[s][i] ] = visited[s] + 1;
			DFS(graph[s][i]);
		}
}
//==============================================================================
int main()
{
	int k;
	cin>>k;
	while (k--)
	{
		cin>>n;
		int a;
		cin>>a;
		for (int i = 0; i < a ; ++i)
		{
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 0; i < n; ++i)
			visited[i] = 0;
		int d = 0;
		for (int i = 0; i < n; ++i)
			if (! visited[i])
			{
				DFS(i);
				d++;
			}
		cout<<d<<endl;
		for (int i = 0; i < n; ++i)
			graph[i].clear();
	}
	return 0;
}

