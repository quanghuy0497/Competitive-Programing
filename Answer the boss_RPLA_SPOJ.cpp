//https://www.spoj.com/problems/RPLA/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
//===================================================================================
vector <int> TopologicalSort(vector<vector<int> > &graph)
{
	vector <int> indegree(n, 0);
	vector<int> result;
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
	return result;
}
//===================================================================================
int main()
{
	int test, cases;
	cin >> test;
	cases = 0;
	while (test--)
	{
		cin >> n >> k;
		vector < vector<int> > graph;
		
		vector <int> indegree(n , 0);
		graph.assign(n, vector<int>());
		
		for (int u, v, i = 0; i < k; i++)
		{
			cin >> u >> v;
			graph[v].push_back(u);
			++indegree[u];
		}
		vector <int> result = TopologicalSort(graph);
		cout<< "Scenario #"<<++cases<<":"<<endl;
		vector <int> rank(n);
		
		for (int u = 0; u < result.size(); u++)
		{
			if (indegree[result[u]] == 0) 
				rank[result[u]] = 1;		
					
			for (vector<int>::iterator v = graph[result[u]].begin(); v != graph[result[u]].end(); v++)
				rank[*v] = max(rank[*v], rank[result[u]] + 1);
		}
		vector <pair<int,int> > answer;
		for (int i = 0; i < n; i++) answer.push_back(make_pair(rank[i],i));
		sort(answer.begin(),answer.end());
		for (int i = 0; i < n; i++)
			cout<<answer[i].first<<" "<<answer[i].second<<endl;	
	}
	return 0;
}
