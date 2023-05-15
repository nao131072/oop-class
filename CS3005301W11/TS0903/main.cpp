
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<char, char>> dictionary;
map<char, map<char, bool>> availableSymbols;
vector<pair<string, string>> targets;

int main()
{
	int m, n;
	cin >> m >> n;
	while (m > 0 && n > 0)
	{
		for (int i = 0; i < m; i++)
		{
			pair<char, char> tp;
			cin >> tp.first >> tp.second;
			dictionary.push_back(tp);
		}
		for (int i = 0; i < n; i++)
		{
			pair<string, string> tp;
			cin >> tp.first >> tp.second;
			targets.push_back(tp);
		}
		cin >> m >> n;
	}

	for (int i = 0; i < dictionary.size(); i++)
	{
		
	}
}