#include <stdio.h>

int main() {
    char line[101]; 

    while (fgets(line, 101, stdin)) //���ڿ��� �Է¹��� �� ��� (�迭, ũ��, �Է�)
    { 
        int small = 0, big = 0, num = 0, space = 0;

        for (int i = 0; line[i] != '\0'; i++) // ���ڿ��� ���������� Ȯ��
        {
            char c = line[i];

            if (c >= 'a' && c <= 'z') small++;    
            else if (c >= 'A' && c <= 'Z') big++;   
            else if (c >= '0' && c <= '9') num++;   
            else if (c == ' ') space++;             
        }

        printf("%d %d %d %d\n", small, big, num, space);
    }

    return 0;
}
