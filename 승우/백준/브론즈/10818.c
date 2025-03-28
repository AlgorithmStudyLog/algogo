#include <stdio.h>

int main()
{
    int a[1000000];
    int i, N;
    int max = -1000001, min = 1000001;

    scanf("%d", &N); // 5


    for (i = 0; i < N; i++) // 0 1 2 3 4
    {
        scanf("%d", &a[i]);
        if (max < a[i])
            max = a[i];

        if (min > a[i])
            min = a[i];

    }
    printf("%d %d", min, max);



    return 0;
}