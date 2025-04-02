#include<iostream>

using namespace std;

int main() {
    char arr[3][5]={'\0'};
    char temp;

    for(int i=0;i<3;i++){

        for (int j = 0;j < 5;j++) {
            temp = ' ';
            cin >> arr[i][j];
            temp = arr[i][j] + 32;
            
            cout << temp  << " ";
        }cout << endl;
    }
    return 0;
}
