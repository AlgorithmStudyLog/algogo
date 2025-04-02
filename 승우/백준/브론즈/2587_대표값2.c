#include <stdio.h>

int main() {
    int i, j, l;
    int num[5];
    int sum = 0;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                l = num[j];
                num[j] = num[j + 1];
                num[j + 1] = l;
            }
        }
    }

    printf("%d\n", sum / 5);
    printf("%d\n", num[2]);

    return 0;
}