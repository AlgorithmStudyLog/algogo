#include <iostream>
#include <vector>
using namespace std;

int cost(int N, const vector<int>& P, vector<double>& I);

int main()
{
	int N, i;
	int n;

	cin >> N;

	vector<int> P(N + 1);
	vector<double> I(N + 1);

	for (i = 1; i <= N; i++)
	{
		cin >> P[i];
		I[i] = P[i] / i;
	}

	n = cost(N, P, I);

	cout << n << endl;

	return 0;
}

int cost(int N, const vector<int>& P,const vector<double>& I)
{
	if (N != 0)
	{
		double max = -1;
		int maxP;
		int i, num;

		for (i = 1; i <= N; i++)
		{
			if (I[i] > max)
			{
				maxP = i;
				max = I[i];
			}
		}
		int M = N % maxP;
		return num = P[maxP] * (N / maxP) + cost(M, P, I);
	}
	else return 0;
}