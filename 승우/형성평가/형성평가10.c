#include <stdio.h>

int main()
{

    int num, i;
    int count[11] = { 0 };

    for (i = 1; i <= 10; i++)
    {
        scanf("%d", &num);
        count[num]++;
    }

    for (i = 1; i <= 10; i++)
    {
        if (count[i] > 0)
        {
            printf("%d : %d\n", i, count[i]);
        }
    }

    return 0;
}