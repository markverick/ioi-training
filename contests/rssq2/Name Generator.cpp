#include<bits/stdc++.h>
using namespace std;
char s[333];
int a[135],b[135],n,len;
int result[20],fk=0;
string val[6];
void gen(int word,int idx)
{
    int i,j;
    if(word==n)
    {
        for(i=1;i<=n;i++)
            val[i].clear();
        j=0;
        result[n]=len;
//        printf("!");
        for(i=1;i<=n;i++)
        {
            while(j<result[i])
            {
                val[i].push_back(s[j]);
                j++;
            }
//            cout << val[i] << " ";
        }
//        cout << "\n";
        int f=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(val[i]==val[j])
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
        {
            cout << "YES\n";
            fk=1;
            for(i=1;i<=n;i++)
            {
                cout << val[i] << "\n";
            }
        }
        return;
    }
    for(i=idx+1;i<len;i++)
    {
        result[word]=i;
        gen(word+1,i);
        if(fk==1)
            return;
    }
}
int main()
{
    int i,j,k,l,T,cp,sum=0;
    string a,b,c,d;
    scanf("%d",&T);
    while(T--)
    {
        result[0]=0;
        scanf("%s %d",s,&n);
        len=strlen(s);
        cp=0;
        for(i=n-1;i>=1;i--)
        {
            cp+=i;
        }
        if(len>=cp)
        {
            cout << "YES!\n";
            j=0;
            for(i=1;i<=n-2;i++)
            {
                for(k=1;k<=i;k++)
                {
                    cout << s[j++] << "!";
                }
                cout << "\n";
            }
            for(k=j;k<len;k++)
            {
                cout << s[k];
            }
            cout << "\n";
        }
        else
        {
            gen(1,0);
            if(fk==0)
            {
                cout << "NO\n";
            }
        }
    }
}
