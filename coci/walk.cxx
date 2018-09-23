#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[10135];
class bigint {
public:
   vector<int> digits;
   bigint( int x ) {
      digits.push_back( x );
   }
   void output() {
      int n = digits.size();
      printf( "%d", digits[--n] );
      while( n > 0 ) printf( "%09d", digits[--n] );
      printf( "\n" );
   }
   void operator += (const bigint &b ) {
      int carry = 0;
      for( int i = 0; i < digits.size() || i < b.digits.size() || carry; ++i ) {
         int x = carry;
         if( i < digits.size() ) x += digits[i];
         if( i < b.digits.size() ) x += b.digits[i];
         carry = x >= 1000000000;
         if( carry ) x -= 1000000000;

         if( i < digits.size() ) digits[i] = x;
         else digits.push_back( x );
      }
   }
};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,len;
    scanf("%s",s);
    len=strlen(s);
    bigint x(1),y(0);
    for(i=len-1;i>=0;i--)
    {
        bigint a(0),b(0);
        if(s[i]=='P'||s[i]=='*')
        {
            a+=x;
            b+=y;
        }
        if(s[i]=='L'||s[i]=='*')
        {
            a+=x;
            a+=x;
            b+=y;
        }
        if(s[i]=='R'||s[i]=='*')
        {
            a+=x;
            a+=x;
            b+=x;
            b+=y;
        }
        x=a;y=b;
    }
    x+=y;
    x.output();
    printf("\n%d\n",x.digits.size());
}
