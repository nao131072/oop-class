#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string sentence;
	while (cin >> sentence)
	{
		int n = 0;
		while (n * n < sentence.length())
		{
			n++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int index = n * j + i;
				if (index < sentence.length())
				{
					cout << sentence[index];
				}
			}
			cout << endl;
		}
	}
}