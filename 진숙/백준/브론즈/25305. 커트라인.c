#include <stdio.h>
#define SORT(a, b) { int temp = a; a = b; b = temp; }

int main() {
    int arr[1000 + 1] = { 0 };
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) SORT(arr[i], arr[j]);
        }
    }

    printf("%d", arr[k-1]);
    return 0;
}
