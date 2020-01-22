//https://codeforces.com/problemset/problem/510/C
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int k;
//===================================================================================
bool TopologicalSort(vector<vector<int> > &graph, vector<int> &result)
{
	vector <int> indegree(26, 0);
	queue<int> zero_indegree;
	for (int u = 0; u < 26; u++)
		for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
			indegree[*it]++;
	for (int i = 0; i < 26; i++)
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
	for (int i = 0; i < 26; i++)
		if (indegree[i] != 0)
			return false;
	return true;
}
//===================================================================================
int main()
{
	vector <vector<int> > graph;
	vector <int> result;
	graph.assign(26, vector<int>());
	cin >> k;
	char x;
	string pre_st;
	for (int i = 0; i < k; i++)
	{
		string st;
		cin >> st;
		if (i > 0)
			for (int j = 0; j <= min(st.length(), pre_st.length()); j++)
				if (pre_st[j] == st[j])
				{
					if (j == min(st.length(), pre_st.length()) - 1)
						if (pre_st.length() > st.length())
						{
							cout <<"Impossible";
							return 0;
						}
				}
				else
				{
					graph[pre_st[j] - 'a'].push_back(st[j] - 'a');
					break;
				}
		pre_st = st;	
	}
	if (TopologicalSort(graph, result) == true)
		for (int i = 0; i < 26; i++)
			cout << (char) (result[i] + 'a');
	else cout <<"Impossible";
	return 0;
}
