#include<stdio.h>
#include<string.h>
int strcut(char str[100005])
{
	int len = strlen(str);
	int k = 0;
	int c=0, d = 0, e = 0,f=-1;
	int l = 0;
	int chc = len;
	int x,fu;
	int i,j;
	for(k=0;e<len;k++){
        e=0;
        for(i=0;i<len;i++){
            c++;
            for(j=i+1;str[j]=='f';j++)d++;
            if(d>len)break;
            printf("I is = %d, D is = %d, E is = %d\n",i,d,e);
            if((str[i]=='('&&str[i+1+d]==')')||(str[i]=='{'&&str[i+1+d]=='}')||(str[i]=='['&&str[i+1+d]==']')){
                str[i]='f';
                str[i+1+d]='f';
                i-=2;
            }
            printf(", STRING NOW IS = %s and RoundOfCheck = %d\n",str,k);
            if(e<d)e=d;
            d=0;
            if(e>=len-1)break;
        }
        if(f==e)break;
        f=e;
        if(e>=len-1)break;
	}
    fu=0;
    for(i=0;i<len;i++){
        if(str[i]!='f'){
            printf("no\n");
            fu=1;
            break;
        }
    }
    if(fu==0)printf("yes\n");
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
