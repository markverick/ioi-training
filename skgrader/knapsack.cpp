#include<bits/stdc++.h>
using namespace std;
int v[1000]; //values
int w[1000]; //weight
int n,capacity;
int omelet(int idx,int cap)
{
    if(idx==0)
    {
        return v[0];
    }
    else
    {
        return max(omelet(idx-1,cap-w[idx])+v[idx],omelet(idx-1,cap));
    }
}
int main()
{

    int i,j,k;
    printf("Enter Capacity of a Inventory : ");
    scanf("%d",&capacity);
    printf("Enter Number of Items : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d slot of items \"Weight\" \"SellPrice\" : ");
        scanf("%d %d",&w[i],&v[i]);
    }
    printf("%d",omelet(n,capacity));
}
