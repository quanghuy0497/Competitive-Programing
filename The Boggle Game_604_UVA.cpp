//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=545
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
const string vowels="AEIYOU";
const pair<int, int> DIRs[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool start = true;
//=====================================================================================
int countvowels(const string& word) 
{
    int res = 0;
    for (char c = 0; c < word.size(); c++)
    	if (vowels.find(word[c]) != -1)
        	res += 1;
    return res;
}
//=====================================================================================
void backtracking(char board[4][4], int x, int y, const string& currentword, bool visited[4][4], set<string>& foundwords) 
{
    if (currentword.length() == 4)
	{
        if (countvowels(currentword) == 2)
            foundwords.insert(currentword);
        return;
    }
    
    visited[x][y] = true;
    for (auto d : DIRs)
    {
        int nx = x + d.first, ny = y + d.second;
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited[nx][ny]) 
		{
            string newcurrentword = currentword + board[nx][ny];
            backtracking(board, nx, ny, newcurrentword, visited, foundwords);
        }
    }
    visited[x][y] = false;
}
//=====================================================================================
int main()
{
	while (true)
	{
		char board[2][4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '#') exit(0);
				board[j >> 2][i][j &3] = ch;
			}
		if (!start) cout<<endl;
		start = false;
		bool visited[4][4];
		memset(visited, 0, sizeof(visited));
		set <string> words[2];
		for (int b = 0 ; b < 2; b ++)
			for (int i = 0; i < 4;  i++)
				for (int j = 0; j < 4; j++)
				{
					string currentword(1, board[b][i][j]);
					backtracking(board[b], i, j, currentword, visited, words[b]);
				}
		vector <string> common;
		for (const string& word : words[0])
        	if (words[1].find(word) != words[1].end())
            common.push_back(word);
	    
	    if (common.size() == 0)
	        cout << "There are no common words for this pair of boggle boards.\n";
	    else
	        for (int i = 0; i < common.size(); i++)
	            cout << common[i] << endl;
	}
}
