#include<bits/stdc++.h>
using namespace std;
string a[100135],tmp;
int main()
{
    int n,i,j,k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(&a[1],&a[n+1]);
    int fu=0;
    for(i=1;i<n;i++)
    {
        x=a[i].size();y=a[i+1].size();
        fu=0;
        if(x!=y);
        {
            for(j=0;j<min(x,y);j++)
            {
                if(a[i][j]!=a[i+1][j])
                {
                    fu=1;break;
                }
            }
            if(fu==0)
            {
                //printf("F");
                if(x>y)
                {
                    if(a[i][y]<a[i+1][y-1])
                    {
                        tmp=a[i+1];
                        a[i+1]=a[i];
                        a[i]=tmp;
                    }
                }
                else if(y>x)
                {
                    //printf("E");
                    if(a[i+1][x]<a[i+1][x-1])
                    {
                        tmp=a[i+1];
                        a[i+1]=a[i];
                        a[i]=tmp;
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout << a[i];
    }
}
