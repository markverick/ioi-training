#include<stdio.h>
int kill[2000000];
int hsh[2000000];
char stck[2000000];
int teema[2000000];
char op[2000000]; //x is multiply, d is division
int main(){
    int n,i,j,k;
    int fst=0,lst=1;
   // int x=1;
    scanf("%d",&n);
    kill[0]=1;
    hsh[1]=0;
    hsh[0]=1;
    int chck=0;
    for(i=0;true;i++){
        if(hsh[kill[fst]/2]==0){
            kill[lst++]=kill[fst]/2;
            hsh[kill[lst-1]]++;
            teema[lst-1]=fst;
            op[lst-1]='d';
            if(kill[lst-1]==n)break;
        }
        if(kill[fst]*3<=1234567&&hsh[kill[fst]*3]==0&&chck==0){
            kill[lst++]=kill[fst]*3;
            hsh[kill[lst-1]]++;
            teema[lst-1]=fst;
            op[lst-1]='x';
            if(kill[lst-1]==n)break;
        }
        fst++;
        /*printf("LAST = %d, FIRST = %d",lst,fst);
        printf("\nQueue now IS : ");
        for(j=fst;j<lst;j++){
            printf("%d ",kill[j]);
        }*/
    }
    //long long yay = kill[lst-1];
    int idx = 0;
    int buffer=lst-1; //position variable as well as teema[]
    for(i=0;buffer>0;i++){
        stck[idx++]=op[buffer];
        buffer=teema[buffer];
        //printf("BUFFER = %lld",buffer);

    }
    if(n!=1){
        printf("1");
        for(i=idx-1;i>=0;i--){
            if(stck[i]=='x'){
                printf("*3");
            }
            if(stck[i]=='d'){
                printf("/2");
            }
        }
    }
    else{
        printf("1");
    }
    //printf("\n%s ",stck);
}
