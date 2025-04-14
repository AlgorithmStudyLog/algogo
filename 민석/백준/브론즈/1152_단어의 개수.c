//strlen 문자열의 길이


#include <stdio.h>
#include <string.h>

int main() {

	char str[1000001]; // 크기를 1000000으로 하면 오류? 남
	int count = 0, tell = 0; // count 공백의 갯수, tell true / false

	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\n') 
			// str[i] 가 공백이 아닐 경우 그리고 \n이 아닌 경우
		{
			if (!tell) // false
			{
				count++;
				tell = 1; // true
			}
		}
		else 
		{
			tell = 0; // false
		}
	}

	printf("%d", count);
	return 0;
}
