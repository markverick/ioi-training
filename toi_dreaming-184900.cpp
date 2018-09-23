#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1000],b[1000],c[1000];
char asuck[1000],bsuck[1000];
int lA,lB;
int main()
{
    int i,idx=0;
    scanf("%s %s",asuck,bsuck);
    lA=strlen(asuck);
    lB=strlen(bsuck);
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
    for(i=0;i<=max(lA,lB);i++)
    {
    	if(i==0&&c[i]==0)continue;
    	printf("%d",c[i]);
    }

}