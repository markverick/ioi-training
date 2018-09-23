#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char A[7][5];
int a[7],b[7];
vector<int> miss,hav;
bool valid()
{
    int i;
    for(i=1;i<=4;i++)
    {
        if(a[i]<0||a[i]>100)
            return 0;
    }
    if(a[5]<0||a[5]>300)
        return 0;
    int sm=0;
    for(i=2;i<=4;i++)
        sm+=a[i];
    if(sm==a[1]&&a[2]*3+a[3]==a[5])
        return 1;
    return 0;
}
void Print()
{
    int i;
    for(i=1;i<=4;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[5]);
}
int detect(int mis)
{
    switch(mis)
    {
    case 1:
        return a[2]+a[3]+a[4];
    case 2:
        return a[1]-a[3]-a[4];
    case 3:
        return a[1]-a[2]-a[4];
    case 4:
        return a[1]-a[2]-a[3];
    case 5:
        return a[2]*3+a[3];
    }
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,sj,tj,sk,tk,sl,tl,T,sum,hp,fk=0;
	scanf("%d",&T);
	while(T--)
    {
        miss.clear();hav.clear();
        for(i=1;i<=5;i++)
        {
            scanf("%s",A[i]);
            if(A[i][0]=='?')
                a[i]=-1,miss.emplace_back(i);
            else
                sscanf(A[i],"%d",&a[i]),hav.emplace_back(i);
        }
        sort(miss.begin(),miss.end());
        if(miss.size()==0)
        {
            Print();
        }
        else if(miss.size()==1)
        {
            a[miss[0]]=detect(miss[0]);
            Print();
        }
        else if(miss.size()==2)
        {
            for(i=0;i<=300;i++)
            {
                a[miss[0]]=i;
                a[miss[1]]=detect(miss[1]);
                if(valid())
                    break;
            }
            Print();
        }
        else if(miss.size()==3)
        {
            fk=0;
            for(i=0;i<=100;i++)
            {
                a[miss[0]]=i;
                for(j=0;j<=100;j++)
                {
                    a[miss[1]]=j;
                    a[miss[2]]=detect(miss[2]);
                    if(valid())
                    {
                        fk=1;
                        break;
                    }
                }
                if(fk)break;
            }
            Print();
        }
        else if(miss.size()==4)
        {
            if(a[1]==0)
            {
                for(i=2;i<=5;i++)
                    a[i]=0;
                    Print();
            }
            else if(miss[3]!=5) ///only one is 5
            {
                a[4]=0;
                fk=0;
                for(i=0;i<=100;i++)
                {
                    a[2]=i;
                    for(j=0;j<=100-i;j++)
                    {
                        a[3]=j;
                        a[1]=detect(1);
                        if(valid())
                        {
                            fk=1;
                            break;
                        }
                    }
                    if(fk)break;
                }
                Print();
            }
            else ///only 2-3-4 is possible
            {
                if(a[hav[0]]==100)
                {
                    a[1]=100;
                    for(i=2;i<=4;i++)
                        if(i!=hav[0])
                            a[i]=0;
                    a[5]=a[2]*3+a[3];
                    Print();
                }
            }
        }
    }
}
