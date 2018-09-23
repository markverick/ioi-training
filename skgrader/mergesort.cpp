#include<bits/stdc++.h>
using namespace std;
int n;
int a[120000];
int b[120000];
void merge_(int fst,int mid,int lst);
void merge_sort(int fst,int lst)
{
    if(fst>=lst)
        return;
       // printf("%d %d\n",fst,lst);
    int mid=(lst+fst)/2;
    merge_sort(fst,mid);
    merge_sort(mid+1,lst);
    merge_(fst,mid,lst);
}
void merge_(int fst,int mid,int lst)
{
    if(fst+1==lst)
    {
        int x=min(a[lst],a[fst]);
        int y=max(a[lst],a[fst]);
        a[fst]=x;
        a[lst]=y;
        return;
    }
    int i=fst,j=mid+1;
    int h=fst;
    while(i<=mid&&j<=lst)
    {

        if(a[i]<a[j])
        {
            b[h++]=a[i++];
        }
        else
        {
            b[h++]=a[j++];
        }
    }
    if(i<=mid)
    {
        while(i<=mid)
        {

            b[h++]=a[i++];
        }
    }
    else if(j<=lst)
    {
        while(j<=lst)
        {
            b[h++]=a[j++];
        }
    }
    for(i=fst;i<=lst;i++)
    {
        a[i]=b[i];
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);

    }
}
