#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int a,b,c,d,i,j,k,x;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(i=1;i<=3;i++)
    {
        scanf("%d",&x);
        x--;
        k=0;
        if(x%(a+b)<a)k++;
        if(x%(c+d)<c)k++;
        if(k==2)
            printf("both\n");
        else if(k==1)
            printf("one\n");
        else
            printf("none\n");
    }
}
