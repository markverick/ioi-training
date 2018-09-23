#include<stdio.h>
#include<string.h>
char stck[1000];
int stk[1000];
char post[1000];
char str[200];
int main(){
    //stack
    int i,j=0,k,c;
    int idx=0;

    scanf("%s",str);
    int len=strlen(str);
    for(i=0;i<=len;i++){
        if(i==len){
            for(c=0;true;c++){
                idx--;
                if(idx<0)break;
                post[j++]=stck[idx];
            }

        }
        if(str[i]=='('){
            stck[idx++]=str[i];
        }
        else if(str[i]=='+'){
            for(c=0;true;c++){
                if(stck[idx-1]!='*'&&stck[idx-1]!='/'&&stck[idx-1]!='-'&&stck[idx-1]!='+'){ //suck str[i] mak gwa top of stack
                    stck[idx++]=str[i];
                    break;
                }
                else{
                    if(idx<0)break;
                    if(stck[idx-1]!='(')post[j++]=stck[idx-1];
                    idx--;
                }
            }
        }
        else if(str[i]=='-'){
            for(c=0;true;c++){
                if(stck[idx-1]!='*'&&stck[idx-1]!='/'&&stck[idx-1]!='-'&&stck[idx-1]!='+'){ //suck str[i] mak gwa top of stack
                    stck[idx++]=str[i];
                    break;
                }
                else{
                    if(idx<0)break;
                    if(stck[idx-1]!='(')post[j++]=stck[idx-1];
                    idx--;
                }
            }
        }
        else if(str[i]=='*'){
            for(c=0;true;c++){
                if(stck[idx-1]!='/'&&stck[idx-1]!='*'){ //suck str[i] mak gwa top of stack
                    stck[idx++]=str[i];
                    break;
                }
                else{
                    if(idx<0)break;
                    if(stck[idx-1]!='(')post[j++]=stck[idx-1];
                    idx--;
                }
            }
        }
        else if(str[i]=='/'){
            for(c=0;true;c++){
                if(stck[idx-1]!='*'&&stck[idx-1]!='*'){ //suck str[i] mak gwa top of stack
                    stck[idx++]=str[i];
                    break;
                }
                else{
                    if(idx<0)break;
                    if(stck[idx-1]!='(')post[j++]=stck[idx-1];
                    idx--;
                }
            }
        }
        else if(str[i]==')'){
            idx--;
            while(true){


                if(stck[idx]=='(')break;
                post[j++]=stck[idx];
                idx--;
            }
        }
        else{//operand
            post[j++]=str[i];
        }/*
        printf("Round %d is ",i+1);
        for(k=0;k<idx;k++){
            printf("%c",stck[k]);
        }
        printf("\n");*/
    }
    printf("%s\n",post);
    len=strlen(post);
    idx=0;
    int sum=0;

    for(i=0;i<len;i++){
        if(post[i]=='+'){
            //idx--;
            stk[idx-2]=stk[idx-1]+stk[idx-2];
            idx--;
        }
        else if(post[i]=='-'){
            //idx--;
            stk[idx-2]=stk[idx-2]-stk[idx-1];
            idx--;
        }
        else if(post[i]=='*'){
            //idx--;
            stk[idx-2]=stk[idx-2]*stk[idx-1];
            idx--;
        }
        else if(post[i]=='/'){
            //idx--;
            stk[idx-2]=stk[idx-2]/stk[idx-1];
            idx--;
        }
        else{
            stk[idx++]=post[i]-'0';
        }
        /*printf("STACK NOW IS = ");
        for(k=0;k<idx;k++){
            printf("%d",stk[k]);
        }
        printf(" and Index is %d\n",idx);
        */
    }
    printf("%d",stk[0]);
}
