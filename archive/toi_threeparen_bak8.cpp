#include<stdio.h>
#include<string.h>
int strcut(char str[100005])
{
	int len = strlen(str);
	int k = 0;
	int c=0, d = 0, e = 0;
	int l = 0;
	int chc = len;
	int x,fu=0;
	int i,j;

	while (true)
	{
	    e++;
		d=0;
		j=0;
		for (i = 0; i <= len,str[i]!='\0'; i++)
		{
			switch (str[i])
			{
			case '(':
                for(k=i+1;str[k]=='f';k++)l++;
				if (str[i + l+1] == ')')
				{
					str[i]='f';
					str[i+1+l]='f';
					d++;
					c++;
				}
				break;
			case '{':
			    for(k=i+1;str[k]=='f';k++)l++;
				if (str[i + 1+l] == '}')
				{
					str[i]='f';
					str[i+1+l]='f';
					d++;
					c++;
				}
				break;
			case '[':
			    for(k=i+1;str[k]=='f';k++)l++;
				if (str[i + 1+l] == ']')
				{
					str[i]='f';
					str[i+1+l]='f';
					d++;
					c++;
				}
				break;
			}
			if(2*c>=len){
                    fu=1;
                    break;
			}
			printf("\n\nString is = %s\nChCount is = %d\nD is = %d\nLocation[I] is %d,E(count) = %d",str,chc,d,i,e);
		}
		if(fu==1)break;
	}
	for(i=0;str[i]=='f';i++){
      ;
	}
	if(i==len)fu=1;
	//printf("I=%d,len=%d",i,len);

	if (fu==1)
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
	char str[100005];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", str);
		strcut(str);
	}
}
