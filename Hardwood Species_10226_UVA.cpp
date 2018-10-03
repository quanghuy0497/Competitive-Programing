//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
//================================================================
int main()
{
	int k;
	string st;
	cin >>k;
	getline(cin, st);
	getline(cin, st);
	while (k--)
	{
	  map <string, int> trees;
	  int count = 0;
	  while (getline(cin, st))
	  {
	  	if (st.empty()) 
		  break;
	  	if (trees.find(st) == trees.end())
			trees[st] = 1;
	  	else trees[st]++;
	  	count++;
	  }
	  for (map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
	    cout<< it->first <<" "<<fixed<< setprecision(4) << (100.0*(it->second) / count)<<endl;
	  if (k)
		cout << endl;	
	}
	return 0;
}
