#include<stdio.h>
using namespace std;

int a[10000],b[10000];

void merge_sort(int st,int ed)
{
    if(st>=ed)
    {
        return;
    }
    merge_sort(st,(st+ed)/2);
    merge_sort((st+ed)/2+1,ed);
    int i=st,j=(st+ed)/2+1,idx = st;
    while(i<=(st+ed)/2&&j<=ed)
    {
        if(a[i]>a[j])
        {
            b[idx++]=a[j];j++;
        }
        else
        {
            b[idx++]=a[i];i++;
        }
    }
    while(i<=(st+ed)/2||j<=ed)
    {
        if(i<=(st+ed)/2)
            b[idx++]=a[i++];
        if(j<=ed)
            b[idx++]=a[j++];
    }
    for(idx=st;idx<=ed;idx++)
    {
        a[idx]=b[idx];
    }

}
int main()
{
    int n;
    int i;
    for(i=50;i>=0;i--)
    {
        a[i]=50-i;
    }
    merge_sort(0,50);
    for(i=0;i<=50;i++)
        printf("%d\n",a[i]);
}
