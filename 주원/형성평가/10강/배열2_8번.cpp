#include<iostream>

using namespace std;

int main() {
    int arr[4][2] = { 0 };
    int row, col[2] = { 0 }, sum = 0;

    for (int i = 0; i < 4; i++) {
        row = 0;
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
            row += arr[i][j];
            col[j] += arr[i][j];
            sum += arr[i][j];
        }
        cout << row / 2 << " ";
    }
    cout << endl;


    for (int j = 0; j < 2; j++) {
        cout << col[j] / 4 << " ";
    }
    cout << endl;


    cout << sum / 8;
    return 0;
}