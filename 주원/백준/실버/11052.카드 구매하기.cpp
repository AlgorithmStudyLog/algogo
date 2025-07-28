#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int maxWon = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0;i < n;i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	for (int i = 0;i < n;i++)
	{
		if(n % (i+1) == 0)
			maxWon = max(maxWon, arr[i] * n/(i+1));
		else if (n % (i + 1) != 0)
		{
			int a = n % (i + 1);
			maxWon = max(maxWon, arr[i] * n / (i + 1) + arr[a-1]);
		}
	}
	cout << maxWon;
}
