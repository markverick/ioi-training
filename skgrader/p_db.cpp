#include<bits/stdc++.h>
using namespace std;
char s[10][50];
char z[1350][10][50];
string x[1350][10];
int state,city,ln,fn;
int main()
{
    int n;
    int i,j,k;
    scanf("%s,%s,%s,%s,%s,%s,%s",s[1],s[2],s[3],s[4],s[5],s[6],s[7]);
    printf("%s",s[1]);
    for(i=1;i<=7;i++)
    {
        if(strcmp(s[i],"state")==0)
            state=i;
        if(strcmp(s[i],"city")==0)
            city=i;
        if(strcmp(s[i],"last_name")==0)
            ln=i;
        if(strcmp(s[i],"first_name")==0)
            fn=i;
    }
    //memset(s,0,sizeof s);
    cout << state << city << ln << fn << "\n";
    while(scanf("%s,%s,%s,%s,%s,%s,%s",z[i][1],z[i][2],z[i][3],z[i][4],z[i][5],z[i][6],z[i][7])!=EOF)
    {
        i++;
        x[i][1]=z[i][state];
        x[i][2]=z[i][city];
        x[i][3]=z[i][ln];
        x[i][4]=z[i][fn];
        for(j=1;j<=4;j++)
        {
            cout << x[i][j] << ",";
        }
    }

}
