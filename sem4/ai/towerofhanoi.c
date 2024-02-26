#include<stdio.h>
void tower(int, char, char, char);
int count=0;
int main()
{    int num;
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    tower(num, 'A', 'C', 'B');
    printf("\nThe total number of moves involved:%d",count);
    return 0;
}
void tower(int num, char frompeg, char topeg, char inpeg)
{  if (num == 1)
    {
		count++;
        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    tower(num - 1, frompeg, inpeg, topeg);
    count++;
    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
    tower(num - 1, inpeg, topeg, frompeg);
}
