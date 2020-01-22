#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
//====================================================================================
void KMPPreprocess(string& p, vector<long long> &prefix)
{
    prefix[0] = 0;
    int m = p.length();
    int j = 0;
    int i = 1;
    while (i < m) 
	{
        if (p[i] == p[j])
		{
            j++;
            prefix[i] = j;
            i++;
        } 
		else 
		{
            if (j != 0) 
			{
                j = prefix[j - 1];
            }
			else 
			{
                prefix[i] = 0;
                i++;
            }
        }
	}
}
//====================================================================================
int main()
{
	long long n;
	string st;
	while (cin >>n >>st, n != -1 && st !="*")
	{
		if (n < st.size()) cout << 0 << endl;
		else
		if (st.size() == 1) cout<<n<<endl;
		else
		{
			long long m = st.size();
			vector<long long> prefix(st.length());
			KMPPreprocess(st, prefix);
			cout<<(n - prefix[m - 1])/(m - prefix[m - 1])<<endl;
		}
	}
	return 0;
}
