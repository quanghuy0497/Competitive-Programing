//http://acm.timus.ru/problem.aspx?num=1585
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	map <string, int > m;
	for (int i = 0; i < n; i++)
	{
		string st;
		getline(cin,st);
		map <string, int>::iterator it = m.find(st);
		if (it == m.end())
			m.insert(pair<string, int> (st, 1));
		else
			it->second ++;
	}
	int num = 0; string kind;
	for (map <string, int>::iterator it = m.begin(); it != m.end(); it++)
		if (num < it->second)
		{
			num = it->second;
			kind = it->first;
		}
	cout <<kind <<endl;
	return 0;
}
