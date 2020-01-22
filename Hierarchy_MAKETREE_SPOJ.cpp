//https://www.spoj.com/PGELMWPZ/problems/MAKETREE/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
//===================================================================================
bool TopologicalSort(vector<vector<int> > &graph, vector<int> &result)
{
	vector <int> indegree(n, 0);
	queue <int> zero_indegree;
	for (int u = 0; u < n; u++)
		for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
			indegree[*it]++;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			zero_indegree.push(i);
	while (!zero_indegree.empty())
	{
		int u = zero_indegree.front();
		zero_indegree.pop();
		result.push_back(u);
		for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
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
	cin >> n >> k;
	graph.assign(n, vector<int>());
	for (int u, v, i = 0; i < k; i++)
	{
		cin >> u;
		while (u--)
		{
			cin >> v;
			v--;
			graph[i].push_back(v);
		}		
	}
	bool success = TopologicalSort(graph, result);
	vector <int> answer(n);
	answer[result[0]] = 0;
	for (int i = 1; i < n; i++)
		answer[result[i]] = result[i - 1] + 1;
	for (int i = 0; i < n; i++)
		cout<<answer[i]<<endl;
	return 0;
}
