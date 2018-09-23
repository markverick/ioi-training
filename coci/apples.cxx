#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[111],y[111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,n,cot=0;
	double rad,cir=acos(-1.0)*2,t;
	for(i=0;i<3;i++)
        scanf("%d %d",&x[i],&y[i]);
    printf("%.1f\n",((double)abs(x[0]*(y[1]-y[2])+x[1]*(y[2]-y[0])+x[2]*(y[0]-y[1])))/2 );
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        for(i=0;i<3;i++)
        {
            if(abs(a-x[i])==0&&abs(b-y[i])==0)
            {
                a=-1;
                break;
            }
        }
        if(a==-1)
        {
            cot++;
            continue;
        }
        rad=0;
        for(i=0;i<3;i++)
        {
            t=atan2(x[i]-a,y[i]-b)-atan2(x[(i+1)%3]-a,y[(i+1)%3]-b);
            if(t<-0.001)t+=cir;
            if(t>cir/2)
                t=cir-t;
            rad+=t;
        }
        if(abs(rad-cir)<=0.0001)
            cot++;
    }
    printf("%d",cot);
}
