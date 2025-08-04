#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> card;
int n, maxPrice = 0;

void solution(int count, int sum) {
    if (count == n) { // 구매한 카드 개수 = n 이 같아지면 비교 후 return
        if (sum > maxPrice) maxPrice = sum;
        return;
    }
    if (count > n) return;  // 구매한 카드 개수가 더 많으면 굳이 비교할 필요 없이 return

    for (int i = 1; i < card.size(); i++) {
        solution(count + i, sum + card[i]);
    }
}

int main() {
    card.push_back(0); // index 맞추려고

    // 입력받기: 구매해야하는 카드 개수(n)
    cin >> n;
    cin.ignore(); // cin 후 개행 제거

    // 입력받기: 카드팩 가격
    string str;
    getline(cin, str);

    // 분리하기: 한 줄로 된 카드팩 가격 분리하기
    int temp = 0;
    for (char c : str) {
        if (c == ' ') {
            card.push_back(temp);
            temp = 0;
            continue;
        } else {
            temp = temp * 10 + (c - '0');
        }
    }
    card.push_back(temp);

    // 최대값 찾고 출력
    solution(0, 0);
    cout << maxPrice;

    return 0;
}
