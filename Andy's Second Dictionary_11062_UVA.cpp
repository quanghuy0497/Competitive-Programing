//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2003
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
		else if (value[i] == '-')
			st += '-';
		else st += ' ';
	value = st;
}
//================================================================
int main()
{
	string line, text;
	set <string> dict;
	while (getline(cin, line))
	  if (line !="")
	  {
	  	text += line;
		if (text[text.length() - 1] == '-')
			text.erase(text.length() - 1);
		else text += ' ';	
	  }
	normalization(text);
	stringstream ss(text);
	while (ss >> line)
	  dict.insert(line);
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
	  cout<< *it<<endl;
	return 0;
}
