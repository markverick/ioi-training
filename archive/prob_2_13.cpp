#include<stdio.h>
int main()
{
	int n;
	int i, j, k;
	scanf("%d", &n);
	for(j=1;j<=n;j++){
        for (i=n-j;i>0;i--)
        {
            printf(" ");
        }
        for (i=n-j; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
