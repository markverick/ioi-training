#include<bits/stdc++.h>

char str[5];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int inv=1;
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[1]=='b')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            j=0;
            while(a>0)
            {
                j++;a/=2;
            }
            k=0;
            while(b>0)
            {
                k++;b/=2;
            }
            if(j%2==0)
                printf("%d\n",(1-inv+abs(j-k)+3)/2);
            else
                printf("%d\n",(inv+abs(j-k)+3)/2);
            //printf("%d\n",1+(abs(j-k)+1));
        }
        else if(str[1]=='r')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            j=0;
            while(a>0)
            {
                j++;a/=2;
            }
            k=0;
            while(b>0)
            {
                k++;b/=2;
            }
            //if(j%2==inv)
            if(j%2==1)
                printf("%d\n",(1-inv+abs(j-k)+3)/2);
            else
                printf("%d\n",(inv+abs(j-k)+3)/2);
            //else
              //  printf("%d\n",1+(abs(j-k)+1));
        }
        else
        {
            inv=1-inv;
        }
    }
}
