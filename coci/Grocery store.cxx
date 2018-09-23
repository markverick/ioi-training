#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n=2000,i,j,k,l;
	for(i=1;i<=2000;i++)
    {
        for(j=1;j<=200000/i;j++)
        {
            for(k=1;k<=20000000/(i*j);k++)
            {
                for(l=1;l<=20000000/(i*j*k);l++)
                {
                    if(i*j*k*l==(i+j+k+l)*1000000)
                    {
                        printf("%d\n",i*j*k*l);
                        printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",i/100,i%200,j/100,j%100,k/100,k%100,l/100,l%100);
                    }
                }
            }
        }
    }
}
