#include<stdio.h>
int main()
{
	long n, k, v[2000], vmin[2000];
	long i, j, l;
	scanf("%ld %ld", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%ld", &v[i]);
	}
	for (j = 1; j <= k; j++)
	{
		vmin[j] = v[1];
		for (i = 1; i <= n; i++)
		{
			if (v[i] < vmin[j])
			{
				vmin[j] = v[i];
			}
		}
		for (l = 1; l <= n; l++)
		{
			if (vmin[j] == v[l])
			{
				v[l] = 1100000000 + v[l];
				break;
			}
		}
	}
	vmin[0]=1100000000;
	for (i = 1; i <= k; i++)
	{
		if (vmin[i]!=vmin[i-1]&&vmin[i]<=1000000000)
		{
			printf("%ld\n", vmin[i]);
		}
	}
}
