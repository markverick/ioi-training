#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
    srand(135);
	int i,j,k,r,c,T;
    T=10;
    printf("%d\n",T);
    while(T--)
    {
        r=1;c=rand()%3+1;
        printf("%d %d\n",r,c);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                printf("%d ",rand()%3+1);
            }
            printf("\n");
        }
    }
}
