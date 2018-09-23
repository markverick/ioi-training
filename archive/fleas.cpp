#include<stdio.h>

int main()
{
	int n;						// input number
	int i, j, k;				// loops
	int r = 1;
	int rc = 0, lc = 0;			// count right/left
	int rmax = 0, lmax = 0;
	int count = 0;
	int row = 0;
	int amount = 0;
	int value = 0;
	int chcount = 0;
	int stuckcot;
	int sum = 0;
	int dif = 0;
	int rdif=0;
	int last;
	int lastcot;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{

		if (i % 2 == 0)
		{
			for (j = 1; j <= r; j++)
			{
				lc += 1;
				count += 1;
			}
			sum += lc;
			if (count >= n)
			{
				break;
			}
		}
		else
		{
			for (j = 1; j <= r; j++)
			{
				rc += 1;
				count += 1;
			}
			sum += rc;
			if (count >= n)
			{
				break;
			}
		}
		if (rmax <= rc)
		{
			rmax = rc;
		}
		if (lmax <= lc)
		{
			lmax = lc;
		}
		row += 1;
		if (count >= n)
		{
			break;
		}
		// printf("Rcount = %d Lcount = %d\n",lc,rc);
		lc = 0;
		rc = 0;
		r += 1;

	}
	printf("Rmax = %d LMax = %d", rmax, lmax);
	printf("Rows = %d\n", r);
	printf("Sum is %d\n", sum);
	printf("n = %d sum = %d Dif = %d RDif = %d\n", n, sum, dif,rdif);
	dif = sum - n;
	rdif = sum-n;
	if (r % 2 == 1)
	{
		dif = -1;
	}
	else{
		rdif=-1;
	}
	for (i = 0; i < r; i++)
	{
		if (i < r - 1)
		{
			if (i % 2 == 1)		// even rows
			{
				if (n==sum&&dif==0)
				{
					printf("x");
				}
				for (j = 0; j < lmax - i-1; j++)
				{
					printf(".");
				}
				 stuckcot = 'A' + value + i;

				for (j = 0; j <= i; j++)
				{
					if (stuckcot - j > 'Z')
					{
						printf("%c", stuckcot - 26 - j);
					}
					else
						printf("%c", stuckcot - j);
					chcount += 1;
					value += 1;
					last = value;

				}
				for (j = 0; j <= rmax - 2; j++)
				{
					printf(".");
				}
				if(n==sum&&rdif==0){
					printf("x");
				}
			}
			else				// odd rows
			{
				if (n==sum&&dif==0)
				{
					printf("x");
				}
				for (j = 0; j <= lmax - 2; j++)
					{
						printf(".");
					}
				for (j = 0; j <= i; j++)
				{
					if (value > 25)
					{
						value = 0;
					}
					printf("%c", value + 'A');
					chcount += 1;
					value += 1;
					last = value;

				}
				for (j = 0; j <= rmax-2 - i; j++)
				{
					printf(".");
				}
				if(n==sum&&rdif==0){
					printf("x");
				}

			}
			printf("\n");

		}
	}

	
	if (i == r)
	{
		if (r % 2 == 1)
		{
			
		}
		else
		{
			stuckcot = 'A' + last+lmax;
			for(j=0;j<sum-n;j++){
				printf(".");
			}
			for (j = 0; j <= r-sum+n; j++)
				{
					if (stuckcot - j > 'Z')
					{
						printf("%c", stuckcot - 26 - j);
					}
					else
						printf("%c", stuckcot - j-1);
					value += 1;

				}
			{
				for(j=0;j<rmax-1;j++)
				printf(".");
			}
		}

		// for(j=0;j<
	}
}