#include<stdio.h>
#include<string.h>
int strcut(char str[120000])
{
	int len = strlen(str);
	int k = 0;
	int c, d = 0, e = 0;
	int l = 0;
	int chc = len;
	int x;
	while (true)
	{
		c = 0;
		d = 0;
		int i, j = 0;

        //find strlen quick
        for(x=0;str[x]!='\0';x++){;}
        printf("FLIPPIN X = %d",x);


		char *p = &str[0];
		for (i = 0; i < chc; i++)
		{

			switch (str[i])
			{
			case '(':
				if (str[i + 1] == ')')
				{
					str[i] = 'f';
					d++;
					// str[i+1]=NULL;
				}
				break;
			case '{':
				if (str[i + 1] == '}')
				{
					str[i] = 'f';
					d++;
					// str[i+1]=NULL;
				}
				break;
			case '[':
				if (str[i + 1] == ']')
				{
					str[i] = 'f';
					d++;
					// str[i+1]=NULL;
				}
				break;
			}
		}

		while (*p != 'f')
		{
			p++;
			c++;
			if(*p='\0')break;
		}
        printf("\nC = %d.\n",c);
		printf("\n;last %c.\n",str[c-1]);
        printf("*P is = %d",*p);
		for(i=c;*p!='\0';i++){
			str[i]=*p;

		}
		str[x]='\0';
		printf("\nx = %d\n",x-1);
		printf("\n str[x] = %c\n",str[x]);

		printf("\n string of str = %s\n",str);
		if(len-chc<=0)break;
		if(d*2>=len-chc)break;
	}
//	str[len-chc]='\0';
	// if(str[0]=='f'){str[0]='\0';}
	// printf("\n\n%d",len-2*l);
//	len = strlen(str);
//	if (len - 2 * l < 0)
		//l = len / 2;
//	str[len - 2 * l] = '\0';
	// printf("\n\n%s",str);
	// printf("\n\n%d",strlen(str));
	printf("%d",strlen(str));
	if (strlen(str)==0)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

}

int main()
{
	int i, j, k, n;
	char str[1200000];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", str);
		strcut(str);
	}
}
