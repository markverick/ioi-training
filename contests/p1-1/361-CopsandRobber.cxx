#include<bits/stdc++.h>
#define X first
#define Y second
#define PI 3.14159265
#define sig 0.00001
#define plst p[st[st.size()-1]].Y
#define pfst p[st[st.size()-2]].Y
#define plstt pp[stt[stt.size()-1]].Y
#define pfstt pp[stt[stt.size()-2]].Y
using namespace std;
vector<pair<double,double> > v;
vector<pair<pair<double,double>,int> > p;
vector<int> st;
vector<pair<double,double> > vv;
vector<pair<pair<double,double>,int> > pp;
vector<int> stt;
int hshct[1135][1135];
int hsht[1135][1135];
int chk(double p,double q)
{
    double r=p,s=q;
    while(p<q) //p>=q
        p+=360;
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
int isSame(pair<double,double> a,pair<double,double> b)
{
    if(abs(a.X-b.X)<=sig&&abs(a.Y-b.Y)<=sig)
        return 1;
    else
        return 0;
}
int main()
{
//    freopen("out.txt","w",stdout);
    int T=0,i,j,n,m,fu,fk,o,xx,yy;
    double k,tot,sum;
    double x,y,w,h,a,px,py,c,d,b;
    while(scanf("%d %d %d",&n,&m,&o)!=EOF)
    {
        T++;
        if(n==0&&m==0&&o==0)
            return 0;
        memset(hshct,0,sizeof hshct);
        memset(hsht,0,sizeof hsht);
        v.clear();p.clear();st.clear();
        vv.clear();pp.clear();stt.clear();
        fu=0;fk=0;
        sum=0;
        tot=0;

        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&xx,&yy);
            x=xx;y=yy;
            v.emplace_back(x,y);
            hshct[xx+505][yy+505]++;
        }

        if(n<=2)
        {
            fu=1;
        }
        else
        {
            sort(v.begin(),v.end());
            auto it=unique(v.begin(),v.end());
            v.resize(distance(v.begin(),it));
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
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&xx,&yy);
            x=xx;y=yy;
            vv.emplace_back(x,y);
            hsht[xx+505][yy+505]++;
        }
        if(m<=2)
        {
            fk=1;
        }
        else
        {
            sort(vv.begin(),vv.end());
            auto it=unique(vv.begin(),vv.end());
            vv.resize(distance(vv.begin(),it));
            px=vv[vv.size()-1].X;py=vv[vv.size()-1].Y;
            pp.emplace_back(make_pair(0,0),vv.size()-1);
            pp.emplace_back(make_pair(360,0),vv.size()-1);
            for(i=0;i<vv.size()-1;i++)
            {
                pp.emplace_back(make_pair(angle(px,py,vv[i].X,vv[i].Y),hypot(vv[i].X-px,vv[i].Y-py)),i);
            }
            sort(pp.begin(),pp.end());
            stt.emplace_back(0);
            stt.emplace_back(1);
            stt.emplace_back(2);
            for(i=3;i<pp.size();i++)
            {
                c=angle(vv[pfstt].X,vv[pfstt].Y,vv[plstt].X,vv[plstt].Y);
                d=angle(vv[plstt].X,vv[plstt].Y,vv[pp[i].Y].X,vv[pp[i].Y].Y);
                while(chk(c,d))
                {
                    stt.pop_back();
                    c=angle(vv[pfstt].X,vv[pfstt].Y,vv[plstt].X,vv[plstt].Y);
                    d=angle(vv[plstt].X,vv[plstt].Y,vv[pp[i].Y].X,vv[pp[i].Y].Y);
                }
                stt.push_back(i);
            }
        }
//        for(i=0;i<st.size();i++)
//        {
//            printf("%f %f\n",v[p[st[i]].Y].X,v[p[st[i]].Y].Y);
//        }
//        printf("\n");
//        for(i=0;i<stt.size();i++)
//        {
//            printf("%f %f\n",vv[pp[stt[i]].Y].X,vv[pp[stt[i]].Y].Y);
//        }
//        printf("\n");
        printf("Data set %d:\n",T);
        for(j=1;j<=o;j++)
        {
            scanf("%d %d",&xx,&yy);
            x=xx;y=yy;
            printf("     Citizen at (%.0f,%.0f) is ",round(x),round(y));
            if(hshct[xx+505][yy+505]>=1&&n>=3)
            {
                printf("safe.\n");
                continue;
            }
            sum=0;
            if(fu==0)
            {
                for(i=0;i<st.size()-1;i++)
                {
                    sum+=anglehelp(x,y,v[p[st[i+1]].Y].X,v[p[st[i+1]].Y].Y,v[p[st[i]].Y].X,v[p[st[i]].Y].Y);
                }
    //            printf("%f\n",sum);
                if(abs(sum-360)<=sig)
                {
                    printf("safe.\n");
                    continue;
                }
            }
            if(hsht[xx+505][yy+505]>=1&&m>=3)
            {
                printf("robbed.\n");
                continue;
            }
            if(fk==0)
            {
                sum=0;
                for(i=0;i<stt.size()-1;i++)
                {
                    sum+=anglehelp(x,y,vv[pp[stt[i+1]].Y].X,vv[pp[stt[i+1]].Y].Y,vv[pp[stt[i]].Y].X,vv[pp[stt[i]].Y].Y);
                }
    //            printf("%f\n",sum);
                if(abs(sum-360)<=sig)
                {
                    printf("robbed.\n");
                    continue;
                }
            }
            printf("neither.\n");
        }
        printf("\n");
    }
}


