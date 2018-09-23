#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char* plusle(char *asuck,char *bsuck)
{
    int i,idx=0;
    int lA=strlen(asuck);
    int lB=strlen(bsuck);
    int a[120],b[120],c[120];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    if(lA>lB)
    {
  	  for(i=1;i<=lA+1;i++)
 	   {
  	      if(asuck[idx]!=0)a[i]=asuck[idx]-'0';
  	      idx++;
   	 }
   	 idx=0;
    	for(i=1+lA-lB;i<=lA+1;i++)
    	{
  	      if(bsuck[idx]!=0)b[i]=bsuck[idx]-'0';
  	      idx++;
    	}
    }
    else
    {
  	  for(i=1+lB-lA;i<=lB;i++)
 	   {
  	      if(asuck[idx]!=0)a[i]=asuck[idx]-'0';
  	      idx++;
   	 }
   	 idx=0;
    	for(i=1;i<=lB;i++)
    	{
  	      if(bsuck[idx]!=0)b[i]=bsuck[idx]-'0';
  	      idx++;
    	}
    }
  /*  for(i=0;i<=max(lA,lB);i++)
    	printf("%d ",a[i]);
    	printf("\n");
    for(i=0;i<=max(lA,lB);i++)
    	printf("%d ",b[i]);*/
    for(idx=max(lA,lB);idx>=0;idx--)
    {
        if(a[idx]+b[idx]>=10)
        {
        	a[idx-1]++;
        	c[idx]=(a[idx]+b[idx])%10;
        }
        else
        {
        	c[idx]=a[idx]+b[idx];
        }

    }
 //   printf("\n");
    int k=0;
    char d[120];
    memset(d,0,sizeof d);
    for(i=0;i<=max(lA,lB);i++)
    {
    	if(i==0&&c[i]==0)
            continue;
        //if(c[i]!=0)
    	d[k++]=c[i]+'0';
    }
    return d;

}
int main()
{
    char str1[120];
    char str2[120];
    scanf("%s %s",str1,str2);
    printf("%s",plusle(str1,str2));
}
