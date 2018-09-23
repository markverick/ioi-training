#include<bits/stdc++.h>
#define MP make_pair
#define MT(x,y,z) make_pair(make_pair(x,y),z)
#define PB push_back
#define X first
#define Y second
using namespace std;
int n;
pair<int,int> a[1000005];
pair<pair<int,int>,int> b[1000005];
vector<int> c;
//multiset<pair<int,int> >st;
//multiset<pair<int,int> >::iterator it;
char hsh[10000005];
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int aa,bb;
        scanf("%d %d",&aa,&bb);
        a[i]=MP(aa,bb);
        //b[i]=MP(bb,aa);
    }
    sort(&a[0],&a[n]);
    for(i=0;i<n;i++)
    {
        b[i]=MT(a[i].Y,a[i].X,i);
    }
    sort(&b[0],&b[n]);
    hsh[b[n-1].Y]++;
    hsh[n-1]++;
    if(b[n-1].Y==n-1)
        c.push_back(n-1);
    for(i=0;i<n-1;i++)
    {
        if(a[i+1].X<=a[i].X||a[i+1].Y<=a[i].Y)
            hsh[i]++;
        if(hsh[i]==2)
            c.push_back(i);
    }
    //printf("%d\n",hsh[0]);
    for(i=0;i<n-1;i++)
    {
        if(b[i+1].X.X<=b[i].X.X||b[i+1].X.Y<=b[i].X.Y)
            hsh[b[i].Y]++;
        if(hsh[b[i].Y]==2)
            c.push_back(b[i].Y);
    }
    //printf("%d\n",hsh[0]);

    /*for(i=0;i<n;i++)
    {
        if(hsh[i]==0)
        {
            c.push_back(i);
        }
    }*/
    sort(c.begin(),c.end());
    //pair<int,int> out;
    for(i=0;i<c.size();i++)
    {
        printf("%d %d\n",a[c[i]].X,a[c[i]].Y);
    }
}
