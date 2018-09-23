#include<bits/stdc++.h>
char num[50],numMin[50],numMax[50];
char Max=0,Min=200;
void swap(char *a, char *b)
{
   char tmp = *a;
   *a = *b;
   *b = tmp;
   return;
}
int main()
{
    int t,n,i,j,k,idxMin=0,idxMax=0 ,len;
    scanf("%d",&t);
    for(i=0;i<t;i++) //multiple testcases;
    {
        scanf("%s",num);
        len=strlen(num);
        strcpy(numMax,num);
        strcpy(numMin,num);
        for(j=0;j<len;j++) //starting cursor if not swap;
        {
            idxMin=j;Min=num[j];
            for(k=j;k<len;k++) //working swapping
            {
                if(Min>=num[k]&&num[k]!='0')
                {
                    Min=num[k];
                    idxMin=k;
                }
            }
            if(num[idxMin]!=num[j]&&num[idxMin]!='0')
            {
                swap(&numMin[idxMin],&numMin[j]);
                break;
            }
        }
        for(j=0;j<len;j++) //starting cursor if not swap;
        {
            idxMax=j;Max=num[j];
            for(k=j;k<len;k++) //working swapping
            {
                if(Max<=num[k])
                {
                    Max=num[k];
                    idxMax=k;
                }
            }
            if(num[idxMax]!=num[j])
            {
                swap(&numMax[idxMax],&numMax[j]);
                break;
            }
        }
        printf("Case #%d: %s %s\n",i+1,numMin,numMax);
    }

}
