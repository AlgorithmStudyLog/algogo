#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[11][11] = { 1, };

    cin >> n;
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j < i;j++) {
            if (j == 0 || j == i) {
                arr[i][j] += arr[i - 1][j];
            }
            else
                arr[i][j] += arr[i - 1][j - 1] + arr[i - 1][j];

        }
    }


    for (int i = n;i >= 0;i--) {
        for (int j = 0;j < i;j++) {
            cout << arr[i][j] << " ";
        }cout << endl;
    }

    return 0;
}