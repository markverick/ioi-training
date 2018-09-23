#include<bits/stdc++.h>
using namespace std;
char str[30][30];
char van[6]="VANZ";
int main()
{
    int r,c,a,i,j,k,cot=0,fu=0;
    cin >> r >> c;
    for(i=1;i<=r;i++)
        a=scanf("%s",str[i]+1);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c-3;j++)
        {
            fu=0;
            for(k=0;k<4;k++)
            {
                if(str[i][j+k]!=van[k])
                    fu=1;
            }
            if(fu==0)cot++;
        }
    }
    for(i=1;i<=c;i++)
    {
        for(j=1;j<=r-3;j++)
        {
            fu=0;
            for(k=0;k<4;k++)
            {
                if(str[j+k][i]!=van[k])
                    fu=1;
            }
            if(fu==0)cot++;
        }
    }
    cout <<cot;
}
