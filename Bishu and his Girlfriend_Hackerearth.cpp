///https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,q;
vector <int> graph[1002];
int girl[1002], visited[1002];
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
	cin>>n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin>>q;
	for (int i = 0; i < q; ++i)
		cin>>girl[i];
	for (int i = 1; i <= n; ++i)
		visited[i] = 0;
	visited[1]=1;
	DFS(1);
	int minn = girl[0];
	for (int i = 1; i < q; ++i)
		if (visited[minn] > visited[girl[i]])
			minn = girl[i];			
	cout<<minn;
	return 0;
}

