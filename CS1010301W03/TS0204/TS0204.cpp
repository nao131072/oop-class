#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		string name;
		long int salary;
		long int bonus;
		int spaceName = 0;
		int spaceSalary = 0;
		int spaceBonus = 0;
		vector<string> names;
		vector<long int> salaries;
		vector<long int> bonuses;

		for (int i = 0; i < n; i++)
		{
			cin >> name;
			cin >> salary;
			cin >> bonus;

			if (name.length() > spaceName)
				spaceName = name.length();

			if (int(log10(salary)) + 1 + 2 > spaceSalary)
				spaceSalary = int(log10(salary)) + 1 + 2;

			if (int(log10(bonus)) + 1 + 2 > spaceBonus)
				spaceBonus = int(log10(bonus)) + 1 + 2;

			names.push_back(name);
			salaries.push_back(salary);
			bonuses.push_back(bonus);
		}

		for (int i = 0; i < names.size(); i++)
		{
			cout << setw(spaceName) << right << names[i] << "|";
			cout << setw(spaceSalary) << right << salaries[i] << "|";
			cout << setw(spaceBonus) << right << bonuses[i] << endl;
		}
	}
}