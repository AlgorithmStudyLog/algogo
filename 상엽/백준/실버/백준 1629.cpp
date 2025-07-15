#include <iostream>
#include <cmath>
using namespace std;

long long sort(int a, int b);

int main(void)
{
	int a, b, c;
	long long n = 0;

	cin >> a >> b >> c;

	n = sort(a, b);

	cout << n % c;

}

long long sort(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b % 2 == 0)
	{
		long long tmp = sort(a, b / 2);
		return tmp * tmp;
	}
	else
		return a * sort(a, b - 1);
}


/*
int sort(int a, int b);

int main()
{
	int a, b, c;
	int n = 0;

	cin >> a >> b >> c;

	n = sort(a, b);


	cout << n % c;
}

int sort(int a, int b)
{
	int n = a;
	if (b != 0) {
		n = n * a;
		sort(a, b - 1);
	}
	return n;
}*/