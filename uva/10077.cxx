#include<bits/stdc++.h>
using namespace std;
vector<char> out;
int main()
{
    int i,j,k,f1,f2,l1,l2,m1,m2,x,y;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(x==1&&y==1)
            return 0;
        f1=0;f2=1;l1=1;l2=0;
        m1=f1+l1;
        m2=f2+l2;
        out.clear();
        while(m1!=x||m2!=y)
        {
            m1=f1+l1;m2=f2+l2;
            if((double)m1/m2==(double)x/y)
            {

            }
            else if((double)m1/m2>(double)x/y)
            {
                l1=m1;l2=m2;
                out.emplace_back('L');
            }
            else if((double)m1/m2<(double)x/y)
            {
                f1=m1;f2=m2;
                out.emplace_back('R');
            }
        }
        for(i=0;i<out.size();i++)
        {
            printf("%c",out[i]);
        }
        printf("\n");
    }
}
