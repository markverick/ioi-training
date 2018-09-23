#include<bits/stdc++.h>
using namespace std;
int n;
int a[120000];
int b[120000];
long long sum=0;
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
    /*if(fst+1==lst)
    {
        if(a[fst]>a[lst])
        {
            sum++;
            int temp=a[fst];
            a[fst]=a[lst];
            a[lst]=temp;
        }
        return;
    }*/
    int i=fst,j=mid+1;
    int h=fst;
    while(i<=mid&&j<=lst)
    {

        if(a[i]<=a[j])
        {
            b[h++]=a[i++];
        }
        else
        {
            sum+=mid-i+1;
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
    printf("%lld\n",sum);//4 5 8 7 2 3 1 2
}
