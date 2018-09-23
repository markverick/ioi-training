#include<stdio.h>
int [120][120];
char maps[120][120];
int kx[120000];
int ky[120000];
int fx=999999,fy=999999;
char arrow[120][120];
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

                lst++;
            }
            if(maps[i][j]=='C'){
                fx=i;
                fy=j;
            }
        }

    }
    int co=0;
    //printf("FST = %d LST = %d",fst,lst);
    int x,y;
    //printf("FST = %d,%d ",kx[0],ky[0]);
    //kx[0]=

    for(i=0;true;i++){

        x=kx[fst];
        y=ky[fst];
        if(y+1<c&&maps[x][y+1]=='.'&&hashxy[x][y+1]==0){
            ky[lst]=y+1;
            kx[lst]=x;
            lst++;
            hashxy[x][y+1]++;
            //arrow[x][y+1]='>';
        }

        if(y-1>=0){
            if(maps[x][y-1]=='.'&&hashxy[x][y-1]==0){
                ky[lst]=y-1;
                kx[lst]=x;
                lst++;
                hashxy[x][y-1]++;
                //arrow[x][y-1]='<';
            }
        }

        if(x+1<r&&maps[x+1][y]=='.'&&hashxy[x+1][y]==0){
            ky[lst]=y;
            kx[lst]=x+1;
            lst++;
            hashxy[x+1][y]++;
            //arrow[x+1][y]='v';
        }

        if(x-1>=0){
            if(maps[x-1][y]=='.'&&hashxy[x-1][y]==0){
                ky[lst]=y;
                kx[lst]=x-1;
                lst++;
                hashxy[x-1][y]++;
                //arrow[x-1][y]='^';
            }
        }
        if(y-1>=0){
            if(maps[x][y-1]=='C'){
                //arrow[x][y-1]='<';
                //printf("2nd!");
                break;
            }
        }
        if(x+1<r&&maps[x+1][y]=='C'){
            //arrow[x+1][y]='v';
            //printf("3rd!");
            break;
        }
        else if(y+1<c&&maps[x][y+1]=='C'){
            //arrow[x][y+1]='>';
            //printf("1st!");
            break;
        }
        else if(x-1>=0){
            if(maps[x-1][y]=='C'){
                //printf("4th!");
                //arrow[x-1][y]='^';
                break;
            }
        }
        //hashxy[kx[fst]][ky[fst]]++;
        fst++;
    }
    printf("%d",fst);
}
