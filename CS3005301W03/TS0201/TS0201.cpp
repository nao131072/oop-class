#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (getchar()!=EOF)
	{
		vector<double> scores;
		double total = 0;
		double score = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> score;
			scores.push_back(score);
			total += score;
		}

		double avg = total / double(n);
		double deviation = 0;
		for (double s : scores)
		{
			deviation += ((s - avg) * (s - avg));
		}
		deviation /= double(n);
		deviation = sqrt(deviation);
		cout << "Average:" << setprecision(6) << avg << "\t"
			<< "Standard deviation:" << setprecision(6) << deviation << endl;
		cin >> n;
	}
}