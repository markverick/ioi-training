#include<bits/stdc++.h>
#define MP make_pair
#define MT(x,y,z) make_pair(make_pair(x,y),z)
#define PB push_back
#define X first
#define Y second
using namespace std;
int n;
pair<int,int> a[1000005];
vector<int> c;
//multiset<pair<int,int> >st;
//multiset<pair<int,int> >::iterator it;
//char hsh[10000005];
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].X,&a[i].Y);
    }
    sort(&a[0],&a[n]);
    int mc=-999999999;
    int maxrow=-999999999;
    int row=a[n-1].X;
    for(i=n-1;i>=0;i--)
    {
        //mc=0;
        if(row==a[i].X)
        {
            if(a[i].Y>=maxrow)
            {
                c.push_back(i);
            }
            mc=max(mc,a[i].Y);
        }
        else
        {

            maxrow=max(maxrow,mc);
            if(a[i].Y>=maxrow)
            {
                c.push_back(i);
            }
            mc=max(mc,a[i].Y);
           // maxrow=max(maxrow,mc);

        }

        row=a[i].X;
    }
    sort(c.begin(),c.end());
    for(i=0;i<c.size();i++)
    {
        printf("%d %d\n",a[c[i]].X,a[c[i]].Y);
    }
}
