#include <stdio.h>
#include <stdlib.h>
struct node_str
{
       int number;
       struct node_str* next;
       struct node_str* prev;
};
typedef struct node_str node;
main()
{
      char input[1001];
      int i,j,n=0,k,idrail,idnow=1,chk,found,result=0,train[100];
      gets(input);
      scanf("%d",&k);
      for(i=0;input[i]!='\0';i++)
      {
        if(input[i]!=' ')
        {
         for(train[n]=0;input[i]!=' '&&input[i]!='\0';i++)
           train[n] = train[n]*10+(input[i]-'0');
         i--;
         n++;
        }
      }
      node *rail[k],*rnow[k];
      int rcheck[k];
      for(i=0;i<k;i++)
        rail[i] = NULL,rnow[i]=NULL,rcheck[i]=0;
      for(i=n-1;i>=0;i--)
      {
        if(train[i]==idnow)
             idnow++;
        else
        {
           do
           {
            found=0;
            for(j=0;j<k;j++)
            {
              if(rnow[j]!=NULL&&rnow[j]->number==idnow)
              {
                      idnow++;
                      if(rnow[j]->prev==NULL)
                      {
                        free(rnow[j]);
                        rnow[j]=NULL;
                      }
                      else
                      {
                        rnow[j] = rnow[j] -> prev;
                        free(rnow[j]->next);
                        rnow[j]->next = NULL;
                      }
                      found=1;
                      break;
              }
            }
           }while(found!=0); 
           if(train[i]==idnow)
             idnow++;
           else
           {
             for(j=0;j<k;j++)
             {
              if(rnow[j]==NULL)
              {
                    if(rcheck[j]==0)
                      rcheck[j]=1,result++;
                    rail[j] = (node*)malloc(sizeof(node));
                    rail[j] -> number = train[i];
                    rail[j] -> next = NULL;
                    rail[j] -> prev = NULL;
                    rnow[j] = rail[j];
                    break;
              }
              else
              {
                  if(rnow[j]->number > train[i])
                  {
                     rnow[j]->next = (node*)malloc(sizeof(node));
                     rnow[j]->next->number = train[i];
                     rnow[j]->next->next = NULL;
                     rnow[j]->next->prev = rnow[j];
                     rnow[j] = rnow[j] -> next;
                     break;
                  }
              }
             }
             if(j==k)
             {
                   printf("No solution");
                   scanf(" ");
                   return 0;
             }
         }
        }
      }
      printf("%d",result);
      scanf(" ");
      return 0;
}
