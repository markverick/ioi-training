#include<bits/stdc++.h>
using namespace std;
char s[20];
int main()
{
	int i,j,k,len,n=0;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
    {
        s[i]-='0';
        n*=10;
        n+=s[i];
    }
    sort(&s[0],&s[len]);
    do
    {
        k=0;
        for(i=0;i<len;i++)
            k*=10,k+=s[i];
        if(k>n)
        {
            printf("%d",k);
            return 0;
        }
    }
    while(next_permutation(&s[0],&s[len]));
    printf("0");
}
