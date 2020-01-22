//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
int n;
//===================================================================================
vector <int> TopologicalSort(vector<vector<int> > &graph)
{
	vector<int> result;
	vector <int> indegree(n, 0);
	priority_queue<int, vector<int>, greater<int> > zero_indegree;
	for (int u = 0; u < n; u++)
		for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
			indegree[*it]++;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			zero_indegree.push(i);
	while (!zero_indegree.empty())
	{
		int u = zero_indegree.top();
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
	vector <vector<int> > graph;
	vector <int> result;
	int count = 0;
	while (cin >> n)
	{
		vector <string> name (n);
		for (int i = 0; i < n; i++)
			cin >> name[i];
		map <string, int> id;
		for (int i = 0; i < n; i++)
			id[name[i]] = i;
		vector <vector<int> > graph;
		graph.assign(n, vector<int>());
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string namea, nameb;
			cin >> namea >> nameb;
			graph[id[namea]].push_back(id[nameb]);
		}
		vector<int> result = TopologicalSort(graph);
		++count;
		cout<<"Case #"<<count<<": Dilbert should drink beverages in this order:";
		for (int i = 0; i < result.size(); i++)
			cout<<" "<<name[result[i]];
			cout<<"."<<endl;
	}
	return 0;
}
