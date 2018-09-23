#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[7];
void print()
{
    for(int i=1;i<=5;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
	int i,j,k,n=5,fk=1;
	for(i=1;i<=5;i++)
    {
        scanf("%d",&a[i]);
    }
    while(fk==1)
    {
        fk=0;
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                fk=1;
                print();
            }
        }
    }
}
