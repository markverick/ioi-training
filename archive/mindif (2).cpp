#include<stdio.h>
int main()
{
	int n, k, v[1010], vmin[1010];
	int i, j, l;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
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
		if (vmin[i]!=vmin[i-1]) 
		{
			printf("%d ", vmin[i]);
		}
	}
}