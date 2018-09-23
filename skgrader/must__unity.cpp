#include<stdio.h>
int a[120000],b[120000],s[120000];
int main()
{
    int alen,blen;
    int i,j,k;
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
            mark='A';
            break;
        }
        if(idxB>=blen)
        {
            mark='B';
            break;
        }
        if(a[idxA]<b[idxB])
        {
            s[idxS++]=a[idxA++];
        }
        else
        {
            s[idxS++]=b[idxB++];
        }
    }
    if(mark=='A')
    {
        while(true){
            if(idxB>=blen)break;
            s[idxS++]=b[idxB++];
        }
    }
    if(mark=='B')
    {
        while(true){
            if(idxA>=alen)break;
            s[idxS++]=b[idxA++];
        }
    }
    for(i=idxS-1;i>=0;i--)
    {
        printf("%d ",s[i]);
    }
}
