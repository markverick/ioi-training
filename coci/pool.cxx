#include<bits/stdc++.h>
#define all 31250.00
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
	int x,y,i,j,k,inv=0;
	double sum,fst,mid,lst,a,b;
	scanf("%d %d",&x,&y);
	if(x==0&&y==0)
    {
        printf("125.00 125.00");
        return 0;
    }
    if(x==0||y==0)
    {
        if(y==0)
            swap(x,y),inv=1;
            ///x==0
        if(y<=125)
        {
            fst=0;lst=250;
            while(abs(fst-lst)>0.00001)
            {
                mid=(fst+lst)/2;
                a=mid;
                b=250.0-a;
                sum=(250.0-y)*a/2;
                if(sum>=all-sum)
                {
                    lst=mid;
                }
                else
                {
                    fst=mid;
                }
            }
            if(inv==0)
                printf("%.2f %.2f",mid,250.0-mid);
            else
                printf("%.2f %.2f",250.0-mid,mid);
        }
        else
        {
            fst=0;lst=250;
            while(abs(fst-lst)>0.00001)
            {
                mid=(fst+lst)/2;
                a=mid;
                b=250.0-a;
                sum=a*y/2;
                if(sum>=all-sum)
                {
                    lst=mid;
                }
                else
                {
                    fst=mid;
                }
            }
            if(inv==0)
                printf("%.2f 0.00",mid);
            else
                printf("0.00 %.2f",mid);
        }
    }
    else
    {
        if(x==y)
        {
            printf("0.00 0.00");
            return 0;
        }
        if(x>125)
        {
            swap(x,y);
            inv=1;
        }
        fst=0;lst=250;
        while(abs(fst-lst)>0.00001)
        {
            mid=(fst+lst)/2;
            sum=(250.0-mid)*(250.0-x)/2;
            if(all-sum>=sum)
            {
                lst=mid;
            }
            else
            {
                fst=mid;
            }
//            printf("%f <-> %f\n",all-sum,sum);
        }
        if(inv==0)
            printf("%.2f 0.00",mid);
        else
            printf("0.00 %.2f",mid);
    }
}
