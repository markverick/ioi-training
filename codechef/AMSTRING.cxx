#include<bits/stdc++.h>
using namespace std;
char a[1135],b[1135];
int main()
{
    int i,j,k,T,n,bd,ham,cot=0;
    scanf("%d",&T);
    while(T--)
    {
        cot=0;
        scanf("%d %d",&n,&bd);
        scanf("%s %s",a+1,b+1);
        for(i=0;i<n;i++)
        {
            k=1;ham=0;
            for(j=1;i+j<=n;j++)
            {
                if(a[j]!=b[i+j])
                    ham++;
                while(ham>bd)
                {
                    if(a[k]!=b[i+k])
                        ham--;
                    k++;
                }
                cot+=j-k+1;
            }
        }
        for(i=1;i<n;i++)
        {
            k=1;ham=0;
            for(j=1;i+j<=n;j++)
            {
                if(b[j]!=a[i+j])
                    ham++;
                while(ham>bd)
                {
                    if(b[k]!=a[i+k])
                        ham--;
                    k++;
                }
                cot+=j-k+1;
            }
        }
        printf("%d\n",cot);
    }

}
