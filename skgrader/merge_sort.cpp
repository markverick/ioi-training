#include<stdio.h>
int a[120000];
void merge(int,int,int);
void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int h,i,j,b[120000],k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i++]=a[k];
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i++]=a[k];
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(0,n-1);
    for(i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }
}
