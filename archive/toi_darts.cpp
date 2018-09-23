#include<stdio.h>
#include<math.h>
int main(){
    int x,y;
    int i,j,k,c=0,n,s=0;
    double b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        //x[i]=x[i]<0?-x[i]:x[i];
        //y[i]=y[i]<0?-y[i]:y[i];
        b=sqrt(pow((double)x,2)+pow((double)y,2));
        if(b<=2)s+=5;
        else if(b<=4)s+=4;
        else if(b<=6)s+=3;
        else if(b<=8)s+=2;
        else if(b<=10)s+=1;
       // printf("\n\n%d\n\n",s);
    }
    printf("%d",s);


}
