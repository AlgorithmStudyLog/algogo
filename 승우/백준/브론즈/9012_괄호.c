#include <stdio.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);

    while (num--) {
        char A[51];
        scanf("%s", A);

        int count = 0;
        for (int i = 0; A[i] != '\0'; i++) {
            if (A[i] == '(') {
                count++;
            }
            else if (A[i] == ')') {
                count--;
                if (count < 0) break;
            }
        }

        if (count == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
