#include<bits/stdc++.h>
#define X first
#define Y second
#define PI 3.14159265
#define sig 0.00001
#define plst p[st[st.size()-1]].Y
#define pfst p[st[st.size()-2]].Y
using namespace std;
vector<pair<double,double> > v;
vector<pair<pair<double,double>,int> > p;
vector<int> st;
int chk(double p,double q)
{
    double r=p,s=q;
    while(p<q) //p>=q
        p+=360;
    while(s<r) //r<=s&&p<=q
        s+=360;
    if(p-q+sig<180)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double angle(double px,double py,double x,double y)
{
    double tmp=abs(atan((y-py)/(x-px)))*180/PI;
    if(x>=px)
    {
        if(y>=py)
            return tmp;
        else
            return 360-tmp;
    }
    else
    {
        if(y>=py)
            return 180-tmp;
        else
            return 180+tmp;
    }
}
double anglehelp(double px,double py,double xa,double ya,double xb,double yb)
{
    double a=angle(px,py,xa,ya),b=angle(px,py,xb,yb);
    if(a<b)
        a+=360;
    return min(a-b,b+360-a);
}
int main()
{
//    freopen("out.txt","w",stdout);
    int T,i,j,n;
    double k,tot;
    double x,y,w,h,a,px,py,c,d,b,det=0;
    scanf("%d",&T);
    while(T--)
    {
        v.clear();p.clear();st.clear();
        tot=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&x,&y);
            v.emplace_back(x,y);
        }
        sort(v.begin(),v.end());
        px=v[v.size()-1].X;py=v[v.size()-1].Y;
        p.emplace_back(make_pair(0,0),v.size()-1);
        p.emplace_back(make_pair(360,0),v.size()-1);
        for(i=0;i<v.size()-1;i++)
        {
            p.emplace_back(make_pair(angle(px,py,v[i].X,v[i].Y),hypot(v[i].X-px,v[i].Y-py)),i);
        }
        sort(p.begin(),p.end());
        st.emplace_back(0);
        st.emplace_back(1);
        st.emplace_back(2);
        for(i=3;i<p.size();i++)
        {
            c=angle(v[pfst].X,v[pfst].Y,v[plst].X,v[plst].Y);
            d=angle(v[plst].X,v[plst].Y,v[p[i].Y].X,v[p[i].Y].Y);
            while(chk(c,d))
            {
                st.pop_back();
                c=angle(v[pfst].X,v[pfst].Y,v[plst].X,v[plst].Y);
                d=angle(v[plst].X,v[plst].Y,v[p[i].Y].X,v[p[i].Y].Y);
            }
            st.push_back(i);
        }
        tot=0;det=0;
        for(i=0;i<st.size()-1;i++)
        {
            tot+=hypot(v[p[st[i]].Y].X-v[p[st[i+1]].Y].X,v[p[st[i+1]].Y].Y-v[p[st[i]].Y].Y);
        }
        printf("Diameter = %.5f\n",max(k,tot));
        for(i=0;i<st.size()-1;i++)
        {
            det+=v[p[st[i]].Y].X*v[p[st[i+1]].Y].X-v[p[st[i]].Y].Y*v[p[st[i+1]].Y].X;
        }
        double sum=0;
        printf("Area = %.5f\n",det);
        scanf("%lf %lf",&x,&y);
        for(i=0;i<st.size()-1;i++)
        {
            sum+=anglehelp(x,y,v[p[st[i+1]].Y].X,v[p[st[i+1]].Y].Y,v[p[st[i]].Y].X,v[p[st[i]].Y].Y);
        }
        if(abs(sum-360)<=sig)
        {
            printf("inside\n");
        }
        else
        {
            printf("outside\n");
        }
    }
}

