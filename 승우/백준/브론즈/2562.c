#include <stdio.h>
int main()
{
	int a[9] = { 0 };
	int max = 0;
	int cnt = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]); // a[0] a[1] a[2] ... a[8] 입력 
	}

	for (int i = 0; i < 9; i++)
	{
		if (a[i] > 100)
			break;

		if (max < a[i])
		{
			cnt = i + 1;
			max = a[i];		// 최댓값일때 정수를 저장할수 있는 ??	
		}
	}

	printf("%d\n%d", max, cnt);


	return 0;
}