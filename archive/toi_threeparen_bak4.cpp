#include<stdio.h>
#include<string.h>
int strcut(char str[100005])
{
	int len = strlen(str);
	int k = 0;
	int c, d = 0, e = 0;
	int l = 0;
	int chc = len;
	int x,fu;
	while (d*2<len)
	{
		c = 0;
		d=0;
		int i, j = 0;

        //find strlen quick

		char *p;
        fu=0;
		for (i = 0; i <= chc; i++)
		{
            p=&str[0];
			switch (str[i])
			{
			case '(':
				if (str[i + 1] == ')')
				{
					//str[i] = 'f';
					for(j=i;j<=chc;j++){
                        str[j]=str[j+2];
					}
					d++;
					chc-=2;
					str[chc]='\0';
					// str[i+1]=NULL;
					fu=1;
				}
				break;
			case '{':
				if (str[i + 1] == '}')
				{
					for(j=i;j<=chc;j++){
                        str[j]=str[j+2];
					}
					d++;
					chc-=2;
					str[chc]='\0';
					fu=1;
				}
				break;
			case '[':
				if (str[i + 1] == ']')
				{
					for(j=i;j<=chc;j++){
                        str[j]=str[j+2];
					}
					d++;
					chc-=2;
					str[chc]='\0';
					fu=1;
				}
				break;
			}
			/*if(str[i]=='f'){
                for(j=i;j<chc;j++){
                    if(j+2=='\0'){
                        str[j+3]='\0';
                        str[j+2]=0;
                    }
                    str[j]=str[j+2];
                }
                i=-1;
                str[chc]='\0';
               // d++;
            }
            */
            if(d*2>=len)break;

			printf("\n\nString is = %s\nChCount is = %d\nD is = %d\nLocation[I] is %d,FU = %d",str,chc,d,i,fu);
		if(fu==1)break;
		}
        if(d*2>=len)break;
		if(d==0)break;
	}


	if (chc==0)
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
