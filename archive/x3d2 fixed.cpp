#include<stdio.h>
int que[2000000],dad[2000000];
char how[2000000],tag[2000000];
int tops=0;
int x=1,i,ans,front=0,end=0,idxs=0,mark;
void pop()
{
    front++;
}
void push(int a)
{
    que[end++]=a;
}
void pushs(char c)
{
    how[tops++]=c;
}

int main()
{
    scanf("%d",&ans);
    que[end++]=x;
    tag[1]=1;
    if(ans==1)
        mark=1;
    while(mark!=1)
    {
        if(que[front]*3<=1234567&&tag[que[front]*3]!=1)
        {
            push(que[front]*3);
            dad[end-1]=front;
            tag[que[end-1]]=1;
            if(que[end-1]==ans)
            {
                break;
            }
        }
        if(tag[que[front]/2]!=1)
        {
            push(que[front]/2);
            dad[end-1]=front;
            tag[que[end-1]]=1;
            pop();
            if(que[end-1]==ans)
            {
                break;
            }
        }
        else
            front++;
    }

    i=end-1;
    while(i!=0)
    {
        if(que[dad[i]]/2==que[i])
        {
            how[idxs++]='/';
            x=i;
            i=dad[x];
        }
        else if(que[dad[i]]*3==que[i])
        {
            how[idxs++]='*';
            x=i;
            i=dad[x];
        }
    }
    printf("1");
    for(i=idxs-1;i>=0;i--)
    {
        if(how[i]=='/')
            printf("/2");
        else
            printf("*3");
    }
    scanf(" ");
}


