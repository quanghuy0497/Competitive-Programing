//https://www.spoj.com/problems/TOPOSORT/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
//===================================================================================
bool TopologicalSort(vector<vector<int> > &graph, vector<int> &result)
{
	vector <int> indegree(n, 0);
	priority_queue <int, vector <int>, greater<int> > zero_indegree;
	for (int u = 0; u < n; u++)
	{
		vector<int>::iterator it;
		for (it = graph[u].begin(); it != graph[u].end(); it++)
			indegree[*it]++;
	}
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			zero_indegree.push(i);
	while (!zero_indegree.empty())
	{
		int u = zero_indegree.top();
		zero_indegree.pop();
		result.push_back(u);
		vector<int>::iterator it;
		for (it = graph[u].begin(); it != graph[u].end(); it++)
		{
			indegree[*it]--;
			if (indegree[*it] == 0)
				zero_indegree.push(*it);
		}
	}
	for (int i = 0; i < n; i++)
		if (indegree[i] != 0)
			return false;
	return true;
}
//===================================================================================
int main()
{
	vector< vector<int> > graph;
	vector <int> result;
	cin >> n >> m;
	graph.assign(n, vector<int>());
	for (int u, v, i = 0; i < m; i++)
	{
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
	}
	if (TopologicalSort(graph, result) == true)
		for (int i = 0; i < result.size(); i++)
			cout<<result[i] + 1<<" ";
	else
		cout<<"Sandro fails.";
	return 0;
}
