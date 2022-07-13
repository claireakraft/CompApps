
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#pragma warning (disable: 4996) 
int main(void)
{
	int x;
	int y;
	printf("Enter two integers to be sum together:\n");
	scanf("%i", &x);
	scanf("%i", &y);
	int sum;
	sum = x + y;
	printf("The sum of the two integers is %i.\n", sum);

	return 0;
}

