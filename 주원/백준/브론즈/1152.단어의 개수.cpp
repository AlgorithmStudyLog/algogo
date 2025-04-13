#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// 양쪽 공백 제거
string trim(string str)
{
	// 왼쪽 제거
	auto start = find_if_not(str.begin(), str.end(), ::isspace);
	return string(start, str.end());
	// 오른쪽 제거
	//auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();
	//if (start >= end) return "";
	//return string(start, end);

}
int main() {
	string n;
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	getline(cin,n);
	
	int cnt = 0;
	n =trim(n);
	
	for (int i = 0; i < n.size(); i++)
	{
		
		if (n[i] == ' ' || i == n.size() - 1)
		{
			cnt++;
		}
		
	}
	cout << cnt;
	
}
