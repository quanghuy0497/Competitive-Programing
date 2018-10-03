//http://acm.timus.ru/problem.aspx?space=1&num=1837
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#define MAX 1010
using namespace std;
vector <int> graph[MAX];
int visited[MAX];
int dist[MAX];
//=====================================================================
void BFS(int s)
{
	for (int i = 0; i < MAX; i++)
	{
		visited [i] = false;
		dist [i] = 0;
	}
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
//=====================================================================
using namespace std;
int main()
{
	int n, d = 1;
	cin >> n;
	map <string, int > m;
	for (int i = 0; i < n; i++)
	{
		string st0, st1, st2;
		cin >>st0 >>st1 >>st2;
		if (!m[st0]) 
		  	m[st0] = d++;
		if (!m[st1]) 
		  	m[st1] = d++;
		if (!m[st2]) 
			m[st2] = d++;
		graph[m[st0]].push_back(m[st1]);
		graph[m[st1]].push_back(m[st0]);
		graph[m[st2]].push_back(m[st1]);
		graph[m[st1]].push_back(m[st2]);
		graph[m[st2]].push_back(m[st0]);
		graph[m[st0]].push_back(m[st2]);
	}
	
	BFS(m["Isenbaev"]);

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    	if (it -> second != 0)
	 		if (!visited[it -> second])
				cout << it -> first << " undefined" << endl;
			else
				cout << it -> first << " " << dist[it -> second] << endl;
	return 0;
}
