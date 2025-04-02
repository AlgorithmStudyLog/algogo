#include <stdio.h>

int main() 
{
    int i, j;
    int a[4][2];
    int sum = 0;
    double avg = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", a[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
        {
            a[0][j] += a[i][j];

            printf("%d ", a[i][j]);
        }
    }

    
    return 0;
}