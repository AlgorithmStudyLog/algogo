#include <stdio.h>

int main() {
    int arr[100+1] = { 0 };
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int start = 0;
        int end = 0;
        int value = 0;

        scanf("%d %d %d", &start, &end, &value);
        for (int j = start; j <= end; j++) {
            arr[j] = value;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

