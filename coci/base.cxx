#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string str[30135],s[30135];
int hsh[30135][135],id[30135],k[135],out[30135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,L,R,fst,mid,lst,mn,mc;
	vector<pair<int,int> > v;
	cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> str[i];
        s[i]=str[i];
        s[i].push_back('$');
    }
    sort(&s[1],&s[n+1]);
//    printf("\n");
//    for(i=1;i<=n;i++)
//    {
//        cout << s[i]<<"\n";
//    }
//    printf("\n");
    for(i=1;i<=n;i++)
    {
        v.clear();
        L=1;R=n;
        for(j=0;j<str[i].size();j++)
        {
            fst=L;lst=R;mc=L;mn=R;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                if(str[i][j]>s[mid][j])
                    fst=mid+1;
                else
                {
                    mn=min(mn,mid);
                    lst=mid-1;
                }
            }
            fst=L;lst=R;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                if(str[i][j]<s[mid][j])
                {
                    lst=mid-1;
                }
                else
                {
                    mc=max(mc,mid);
                    fst=mid+1;
                }
            }
            L=mn;R=mc;
            hsh[L][j]++;
            v.emplace_back(L,R);
        }
        id[L]=i;out[L]=i;
        for(j=0;j<v.size();j++)
        {
//            if(i==5)
//            {
//                printf("%d - %d [%d]\n",v[j].X,v[j].Y,hsh[v[j].X][j]);
//            }
//            bf[L][j]=hsh[v[j].X][j];
            out[L]+=hsh[v[j].X][j];
        }
    }
//    for(i=1;i<=n;i++)
//    {
//
//        printf("%d \n",out[i]);
//    }
//    printf("\n");
    int q,SUM,sum;
    string p;
    cin >> q;
    while(q--)
    {
        SUM=n;
        cin >> p;
        v.clear();
        p.push_back('$');
        L=1;R=n;
        for(i=0;i<p.size();i++)
        {
            fst=L;lst=R;mc=L;mn=R;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                if(p[i]>s[mid][i])
                    fst=mid+1;
                else
                {
                    mn=min(mn,mid);
                    lst=mid-1;
                }
            }
            fst=L;lst=R;
            while(fst<=lst)
            {
//                printf("%d <- %d -> %d - - %c %c\n",fst,mid,lst,p[i],s[mid][i]);
                mid=(fst+lst)/2;
                if(p[i]<s[mid][i])
                {
                    lst=mid-1;
                }
                else
                {
                    mc=max(mc,mid);
                    fst=mid+1;
                }
            }
            L=mn;R=mc;
            if(s[L][i]!=p[i])
            {
                printf("%d\n",SUM);break;
            }
            if(p[i]=='$')
            {
                if(s[L][i]=='$')
                {
                    printf("%d\n",out[L]);
                    break;
                }
                else
                {
                    printf("%d\n",SUM);break;
                }
            }
            SUM+=R-L+1;
        }
    }
}
