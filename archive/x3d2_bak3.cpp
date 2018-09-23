#include<stdio.h>
char btn[2000000]; //x3 = 'x' /3 = 'd'
int main(){
    int i,j,k=0;
    int fst=0,lst=0;
    int n,m=1,p=1;
    scanf("%d",&n);
    int q=n;
    if(q%3!=0){
        q/=2;
        //btn[lst++]='d';
    }
    while(true){
        if(q%3==0)break;
        q*=2;
        //btn[lst++]='x';
    }
    printf("Q=%d\n",q);
    printf("1");
    while(false&&m!=q){
        m=1;
        if(p<=q){
            //if(k>0)fst++;
            btn[lst++]='x';
        }
        else if(p>=q/2){
            //if(k>0)fst++;
            btn[lst++]='d';
        }
        else{
            lst--;
            //btn[lst++]='d';
        }
        for(i=0;i<lst-fst;i++){
            if(btn[i]=='x')m=m*3;
            if(btn[i]=='d')m=m/2;
        }
        printf("\n\t\tBTN NOW IS = %s\n",btn);
        printf("\n\t\tM NOW IS = %d\n",m);
        if(m==n)break;
        p=m;
    }
    for(i=0;i<lst-fst;i++){
            if(btn[i]=='x')printf("*3");
            if(btn[i]=='d')printf("/2");
    }
}
