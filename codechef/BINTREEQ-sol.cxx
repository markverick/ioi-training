#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#define lld long long int
#define ull unsigned long long
#define mod 1000000007
using namespace std;
int main()
{ int q;
  cin>>q;
    while(q--)
    { lld u,v,n,height=0;
       cin>>n>>u>>v;
      lld x=u; lld y=v;
	  while(x!=y)
	  { if((int)log2(x)>(int)log2(y))
	        x/=2;
		  else if((int)log2(x)<(int)log2(y))
		     y/=2;
		     else
	           { x/=2; y/=2; }
	     height++;
	  }
	  lld po=pow(2,height);
	  lld addi=max(u,v)-(po*x);
	  lld ans=(n-addi)/po;
	   cout<<ans<<endl;
    }
}

