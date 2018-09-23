#include<stdio.h>
#include<string.h>
int strcut(char str[120000])
{
	int len = strlen(str);
	int k=0;
	int c,d=0,e=0;
	int l=0;
	int chc=len;
	while(true){
		c=0;
		d=0;
		int i, j = 0;
		
	
		
		
		char *p = &str[0];
		for (i = 0; i < len-c; i++)
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
		chc-=2*d;
		for (i = 0; c < len-chc; i++)
		{
			if (str[i] == 'f')
			{
				p += 2;
				c += 2;
				e++;
				l++;
			}
			
			str[i] = *p;
			p++;
			c++;
			
		}
	
	
	printf("%s\n",str);
	k++;
	if(k>len)break;
	if(d<e)break;
	if(chc==len)break;
	}
//	if(str[0]=='f'){str[0]='\0';}
//	printf("\n\n%d",len-2*l);
	len=strlen(str);
	if(len-2*l<0)
		l=len/2;
	str[len-2*l]='\0';
//	printf("\n\n%s",str);
//	printf("\n\n%d",strlen(str));
	 if ((strlen(str) ==0 &&len!=1)||str[0]=='f')
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
	int i, j, k,n;
	char str[1200000];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s", str);
		strcut(str);
	}
}