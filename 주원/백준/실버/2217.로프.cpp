#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int main()
{
	int n = 0, min_loop = 10001;
	cin >> n;
	vector<int> arr;
	int re1 = 0, re2 = 10001;
	int sum = 0;

	for (int i = 0;i < n;i++)
	{
		int loop;
		cin >> loop;
		arr.push_back(loop);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0;i < arr.size();i++)
	{
		min_loop = min(min_loop, arr[i]);
	}

	re1 = min_loop * arr.size();

	for (int i = 0;i < arr.size();i++)
	{
		sum += arr[i];
	}

	int avg = sum / arr.size();
	int cnt = 0;
	
	
	for (int i = 0;i < arr.size();i++)
	{
		if (avg < arr[i])
		{
			cnt++;
			re2 = min(arr[i], re2);
		}
		
	}
	
	re2 = cnt * re2;
	cout << max(re1, re2);
}