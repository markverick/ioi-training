#include<stdio.h>
int main()
{
	int n;
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i <= n - 1)
		{
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			for (j = 1; j <= (n - i) * 2 - 1; j++)
			{
				printf(".");
			}
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		if (i == n)
		{
			for (j = 1; j <= n * 2 - 1; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	for (i = n; i >= 1; i--)
	{
		if (i <= n - 1)
		{
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			for (j = 1; j <= (n - i) * 2 - 1; j++)
			{
				printf(".");
			}
			for (j = 1; j <= i; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}