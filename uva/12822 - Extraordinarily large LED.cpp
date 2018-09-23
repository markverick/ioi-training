#include<bits/stdc++.h>
char choice[10];
char team[10];
int pw[12];
int tim=0;
int temp=0;
int hS=0;
int gS=0;
int score=0;
int sum=0;
int pwer(int n)
{
    if(n==0)
        return pw[0];
    int su=0;
    int num=0;
    int i;
    for(i=floor(log10(n));i>=0;i--)
    {
        num=n%10;
        n/=10;
        su+=pw[num];
    }
    return su;
}
int main()
{
    int t=0;
    int a,b,c;
    pw[0]=6;pw[1]=2;pw[2]=5;pw[3]=5;pw[4]=4;pw[5]=5;pw[6]=6;pw[7]=3;pw[8]=7;pw[9]=6;
    //printf("%d",pwer(0));
    while(scanf("%s",choice)!=EOF)
    {
        if(choice[1]=='T') //start
        {
            t++;
            scanf("%d:%d:%d",&a,&b,&c);
            tim=60*(a*60+b)+c;
            hS=0;
            gS=0;
            sum=0;
        }
        if(choice[1]=='C') //score
        {
            scanf("%d:%d:%d %s %d",&a,&b,&c,team,&score);

            temp=60*(a*60+b)+c;
            sum+=(temp-tim)*(pwer(hS)+pwer(gS));
            tim=temp;
            //printf("%d\n",sum);
            if(team[0]=='h')
            {
                hS+=score;
            }
            if(team[0]=='g')
            {
                gS+=score;
            }
        }
        if(choice[1]=='N') //end
        {
            scanf("%d:%d:%d",&a,&b,&c);
            temp=60*(a*60+b)+c;
            sum+=(temp-tim)*(pwer(hS)+pwer(gS));
            tim=temp;
            printf("Case %d: %d\n",t,sum);
            sum=0;
        }

    }

}
