#include<bits/stdc++.h>
int n;
int nTile=0;
int omelet(int idx,int shape)
{
    if(idx==0)
    {
        if(shape==1)
            return 1;
        else
            return 0;
    }

    switch (shape) //from omelet's note book
    {
    case 1:return omelet(idx-1,5)+omelet(idx-1,6)+omelet(idx-1,8)+omelet(idx-1,9)+omelet(idx-1,10);break;
    case 2:return omelet(idx-1,1)+omelet(idx-1,14)+omelet(idx-1,16);break;
    case 3:return omelet(idx-1,1)+omelet(idx-1,17)+omelet(idx-1,19);break;
    case 4:return omelet(idx-1,15)+omelet(idx-1,18);break;
    case 5:return omelet(idx-1,3)+omelet(idx-1,11);break;
    case 6:return omelet(idx-1,2)+omelet(idx-1,13);break;
    case 7:return omelet(idx-1,4);break;
    case 8:return omelet(idx-1,11)+omelet(idx-1,12)+omelet(idx-1,2);break;
    case 9:return omelet(idx-1,11)+omelet(idx-1,13);break;
    case 10:return omelet(idx-1,12)+omelet(idx-1,13)+omelet(idx-1,3);break;
    case 11:return omelet(idx-1,1);break;
    case 12:return omelet(idx-1,1);break;
    case 13:return omelet(idx-1,1);break;
    case 14:return omelet(idx-1,6);break;
    case 15:return omelet(idx-1,7);break;
    case 16:return omelet(idx-1,6);break;
    case 17:return omelet(idx-1,5);break;
    case 18:return omelet(idx-1,7);break;
    case 19:return omelet(idx-1,5);break;

    }
    return 0;
}
int main()
{

    scanf("%d",&n);
    nTile=3*n/2;
    printf("%d",omelet(nTile,1));
}
