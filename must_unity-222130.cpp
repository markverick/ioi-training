#include<stdio.h>
int a[120000],b[120000],s[250000];
int main()
{
    int alen,blen;
    int i,j,k,bufA,bufB;
    scanf("%d",&alen);
    for(i=0;i<alen;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&blen);
    for(i=0;i<blen;i++)
    {
        scanf("%d",&b[i]);
    }
    char mark='0'; //remain
    int idxA=0,idxB=0,idxS=0;
    while(true)
    {
        if(idxA>=alen)
        {
            mark='B';
            break;
        }
        if(idxB>=blen)
        {
            mark='A';
            break;
        }
        bufA=idxA;
        bufB=idxB;
        if(a[bufA]<b[bufB])
        {
            s[idxS++]=a[idxA++];
        }
        else if(a[bufA]>b[bufB])
        {
            s[idxS++]=b[idxB++];
        }
        else
        {
            s[idxS++]=b[idxB++];
            s[idxS++]=a[idxA++];
        }
    }
    if(mark=='B')
    {
        while(true){
            if(idxB>=blen)break;
            s[idxS++]=b[idxB++];
        }
    }
    else if(mark=='A')
    {
        while(true){
            if(idxA>=alen)break;
            s[idxS++]=a[idxA++];

        }
    }
    for(i=idxS-1;i>=0;i--)
    {
        printf("%d ",s[i]);
    }
    //tomorrow is JATURAMITZZZ GO FIGHTINGGGGG
}
