//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756
#include <iostream>
#include <set>
#include <string>
#include "sstream"
using namespace std;
//================================================================
void normalization(string &value)
{
	string st;
	for (int i = 0; i < value.size(); ++i)
		if (isalpha(value[i]))
			st += tolower(value[i]);
		else st += ' ';
	value = st;
}
//================================================================
int main()
{
	string st, word;
	set <string> dict;
	while (cin >>st)
	{
	  normalization(st);
	  stringstream ss(st);
	  while (ss >> word)
	    dict.insert(word);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	  cout<< *it<<endl;
	return 0;
}
