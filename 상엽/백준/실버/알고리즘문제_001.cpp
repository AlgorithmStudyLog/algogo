#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int>rope;
int maxweight(vector<int>* rope, int k, int max);

int main()
{
	int k = 1, w = 0;
	int i;

	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> rope[i];
	}
		
	sort(rope.rbegin(), rope.rend());	//내림차순 정렬

	w = maxweight(rope, k, w); //E0413

	cout << w << endl;
}

int maxweight(vector<int>* rope, int k, int max)	// 최대값 찾을때까지 반복
{
	// C2440
	int l, w;

	l = rope[k - 1]; //E0413

	w = l * k;

	if (max < w && k <= N)
	{
		max = w;
		w = maxweight(rope, k + 1, max);
	}
	else return w;
}

/* gpt가 수정해준 코드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maxweight(const vector<int>& rope);

int main()
{
	cin >> N;
	vector<int> rope(N);

	for (int i = 0; i < N; i++)
	{
		cin >> rope[i];
	}

	sort(rope.rbegin(), rope.rend()); // 내림차순 정렬

	int maxW = maxweight(rope);

	cout << maxW << endl;
	return 0;
}

int maxweight(const vector<int>& rope)
{
	int maxW = 0;
	for (int k = 1; k <= rope.size(); k++)
	{
		int weight = rope[k - 1] * k;
		if (weight > maxW)
			maxW = weight;
	}
	return maxW;
}
*/