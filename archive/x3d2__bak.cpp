#include<stdio.h>
void strrev(char *p)
{
  char *q = p;
  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}

char str[2000000];
long long v[2000000];
char op[2000000];
long long teema[2000000];
long long hashchk[2000000];
int main(){
    int n,i,j,k;
    scanf("%lld",&n);
    int fst=0,lst=1;
    int m=1;
    op[0]='.';
    v[0]=1;
    hashchk[1]=1;
    for(i=0;true;i++){
        if(n=1)break;
        if(v[fst]>0){
            if(v[fst]*3<=1234567){
                if(hashchk[v[fst]*3]==0){
                    op[lst]='x';
                    teema[lst]=fst;
                    hashchk[v[lst]]++;
                    v[lst++]=v[fst]*3;

                }
            }
            if(v[lst-1]==n)break;
            if(hashchk[v[fst]/2]==0){

                op[lst]='d';
                teema[lst]=fst;
                hashchk[v[lst]]++;
                v[lst++]=v[fst]/2;

            }
            if(v[lst-1]==n)break;
        }
        //else fst++;
        if(lst-fst>=0)fst++;
        //printf("FST=%d,LST=%d,V[FST]=%d\n",fst,lst,v[fst]);
        /*for(j=fst;j<lst;j++){
            printf("%d\n",v[j]);
        }*/


        //if(i>10)break;
         //printf("\n----\n");
    }
    int buffer=lst-1;
    /*for(i=0;i<lst-fst;i++){

        fst--;
    }
    fst--;*/
    if(n!=1){
        printf("1*3");
    }
    k=0;
    if(n==1)printf("1");
    else{
        for(i=lst-1;i>=0;i--){
            if(op[buffer]=='x'){
                str[k++]='3';
                str[k++]='*';
            }
            if(op[buffer]=='d'){
                str[k++]='2';
                str[k++]='/';
            }
            //printf("Location NOW(buffer) is = %d, OP is %c, Value[buffer]= %d\n",buffer,op[buffer],v[buffer]);
            buffer=teema[buffer];
            if(buffer==1)break;
        }
    }
    strrev(str);
    printf("%s",str);
   /* for(j=fst;j<lst;j++){
        //printf("OP[j]=%c , Teema[j]=%d , V[j-1]=%d\n",op[j],teema[j],j-1);
        if(op[j]=='x'){
        	for(i=0;i<lst;i++){
        		if(i==teema[j]){
        			printf("*3");
        		}
        	}
        }
        if(op[j]=='d'){
        	for(i=0;i<lst;i++){
        		if(i==teema[j]){
        			printf("/2");
        		}
        	}
        }
        //if(op[j]=='d'&&teema[j]==j-1)printf("/2");

    }
*/
}
