#include<bits/stdc++.h>
int n,c;
int a[20];
int result[20];
int wei=0;
int highest=0;
void fx(int idx)
{
    if(idx==n)
    {
        for(int i=0;i<n;i++)
        {
            if(result[i]==1)
            {
                wei+=a[i];
            }

        }
        if(wei<=c&&wei>highest)
        {
            highest=wei;
        }
        wei=0;
        return;
    }
    result[idx]=0;
    fx(idx+1);
    result[idx]=1;
    fx(idx+1);
}
int main()
{
    scanf("%d %d",&c,&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    fx(0);
    printf("%d",highest);

}
