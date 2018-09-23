#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,ch,a,b,a1,a2,b1,b2,cot=0,x,y,mn=MI;
	scanf("%d",&ch);
	if(ch==24)
    {
        scanf("%d:%d",&a,&b);
        for(i=0;i<24;i++)
        {
            for(j=0;j<59;j++)
            {
                cot=0;
                a1=i/10;a2=i%10;b1=j/10;b2=j%10;
                if(a/10!=a1)cot++;
                if(a%10!=a2)cot++;
                if(b/10!=b1)cot++;
                if(b%10!=b2)cot++;
                if(mn>cot)
                {
                    mn=cot;x=i;y=j;
                }
            }
        }
        printf("%02d:%02d\n",x,y);
    }
	else
    {
        scanf("%d:%d",&a,&b);
        for(i=1;i<=12;i++)
        {
            for(j=0;j<59;j++)
            {
                cot=0;
                a1=i/10;a2=i%10;b1=j/10;b2=j%10;
                if(a/10!=a1)cot++;
                if(a%10!=a2)cot++;
                if(b/10!=b1)cot++;
                if(b%10!=b2)cot++;
                if(mn>cot)
                {
                    mn=cot;x=i;y=j;
                }
            }
        }
        printf("%02d:%02d\n",x,y);
    }
}
