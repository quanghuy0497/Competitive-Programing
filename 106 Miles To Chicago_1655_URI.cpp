//https://www.urionlinejudge.com.br/judge/en/problems/view/1655
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//=====================================================
#define MAX 105
struct triad
{
	int begin, end;
	double weigh;
};
vector<double> dist (MAX, 0);
vector <triad> graph;
int n,m;
//=====================================================
int main()
{
	while (1)
	{
		cin >> n;
		if (!n) return 0;
		cin >> m;
		graph.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >>v >>w;
			graph.push_back((triad) {u, v, w/100.0});
		}
		dist = vector <double> (n + 1, -1.5);
		dist[1] = 1.0;
		for (int i = 1; i <= n; i++)
		  for (int j = 0; j < m; j++)
		  {
		  	dist[graph[j].begin] = max(dist[graph[j].begin], dist[graph[j].end] * graph[j].weigh);	
		  	dist[graph[j].end] = max(dist[graph[j].end], dist[graph[j].begin] * graph[j].weigh);
		  }
		printf("%.6lf percent\n" , dist[n] * 100.0);
	}
	return 0;
}
