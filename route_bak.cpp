#include<stdio.h>
#include<stdlib.h>
int hashxy[120][120];
char maps[120][120];
long long kx[200000];
long long ky[200000];
int fx=99999999,fy=99999999;
long long numb[120][120];
//int tx[1000][1000];
//int ty[1000][1000];
int main(){
    int i,j,k;
    int n;
    int r,c; //c=length r = height
    int fst=0,lst=0;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        scanf("%s",maps[i]);
        for(j=0;j<c;j++){
            if(maps[i][j]=='B'){
                //printf("I = %d, J = %d",i,j);
                kx[lst]=i;
                ky[lst]=j;
				numb[i][j]=1;
                lst++;
            }
            if(maps[i][j]=='C'){
                fx=i;
                fy=j;
            }
        }

    }

    //printf("FST = %d LST = %d",fst,lst);
    int x,y;
    //printf("FST = %d,%d ",kx[0],ky[0]);
    //kx[0]=
    int chck=0;
    for(i=0;true;i++){
        x=kx[fst];
        y=ky[fst];
        if(hashxy[x][y+1]==0&&y+1<c&&maps[x][y+1]=='.'){
            ky[lst]=y+1;
            kx[lst]=x;
            lst++;
            numb[x][y+1]=numb[x][y]+1;
            chck=1;
            hashxy[x][y+1]++;
        }
        if(y-1>=0){
            if(maps[x][y-1]=='.'&&hashxy[x][y-1]==0){
                ky[lst]=y-1;
                kx[lst]=x;
                lst++;
                numb[x][y-1]=numb[x][y]+1;
                hashxy[x][y-1]++;
            }
        }

        if(x+1<r&&maps[x+1][y]=='.'&&hashxy[x+1][y]==0){
            ky[lst]=y;
            kx[lst]=x+1;
            lst++;
            numb[x+1][y]=numb[x][y]+1;
            hashxy[x+1][y]++;
        }

        if(x-1>=0){
            if(maps[x-1][y]=='.'&&hashxy[x-1][y]==0){
                ky[lst]=y;
                kx[lst]=x-1;
                lst++;
                numb[x-1][y]=numb[x][y]+1;
                hashxy[x-1][y]++;
            }
        }
        if(y-1>=0){
            if(maps[x][y-1]=='C'){
                numb[x][y-1]=numb[x][y]+1;
                //printf("2nd!");;
                fx=x;
                fy=y-1;
                break;
            }
        }
        if(x+1<r&&maps[x+1][y]=='C'){
            numb[x+1][y]=numb[x][y]+1;
            //printf("3rd!");
            fx=x+1;
            fy=y;
            break;
        }
        if(y+1<c&&maps[x][y+1]=='C'){
            numb[x][y+1]=numb[x][y]+1;
            //printf("1st!");
            fx=x;
            fy=y+1;
            break;

        }
        if(x-1>=0){
            if(maps[x-1][y]=='C'){
                //printf("4th!");
                numb[x-1][y]=numb[x][y]+1;
                fx=x-1;
                fy=y;
                break;
            }

        }
        hashxy[kx[fst]][ky[fst]]++;

        fst++;
        /*
        printf("\n");
        for(k=0;k<r;k++){
            for(j=0;j<c;j++){
                printf("%d ",numb[k][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(k=0;k<r;k++){
            for(j=0;j<c;j++){
                printf("%d ",hashxy[k][j]);
            }
            printf("\n");
        }
        printf("\nQUEUE FST = %d LST = %d ",fst,lst);
        for(j=fst;j<lst;j++){
            printf("[%d][%d] ",kx[j],ky[j]);
        }
        system("pause");
        */
    }
    //printf("\n%d %d\n",fx,fy);
    //printf("%c",maps[fx][fy]);
    int co=0;
    int buffer;

    //printf("\nBX = %d, BY = %d\n",bx,by);
    /*for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c ",arrow[i][j]);
        }
        printf("\n");
    }*/

    printf("%lld",numb[fx][fy]-1);
}
