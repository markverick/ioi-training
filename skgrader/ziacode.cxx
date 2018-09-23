#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<bits/stdc++.h>
//OS Check
#ifdef __WIN32
#define OS_type 0
#include<windows.h>
#define clear {system("cls");}
#define gotoxy(x,y){COORD coord={x,y};SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}
#else
#define OS_type 2
#endif
// variables
int cursor_pos, menu_item,qq_classic=16,
dev_option = 0, random_output,
score=0,r_temp,hint=0,mode,h_score[3]= {0,0,0},e,b,c,d,f,g,h,z;
float time_attack_time=123.00;
char cursor, itemname[15];
//resources for word randomizer
char k_1_1[4][60]= {"A car","A bus","A ball","A car"};
char k_1_2[4][60]= {"moved for","has traveled","went","has a displacement of"};
char k_1_3[4][60]= {"find its velocity","What's its average velocity","tell the average speed","How much is its speed"};
char k_2_1[4][60]= {"A van's","A bicycle's","A taxi's","A cat's"};
char k_2_2[4][60]= {"velocity is","average speed is","rate of movement is","ratio between displacement and time taken is"};
char k_3_1[4][60]= {"How long does it take for","What's the time for","Calculate the time for","Find how long will it takes for"};
char k_3_2[4][60]= {"a man","a submarine","a row boat","a ferry"};
char k_3_3[4][60]= {"to travel for","to move for","to cover a distance of","to go to a distance of"};
char k_4_1[4][60]= {"An object's","A plane's","A dog's","A toy car's"};
char k_4_2[4][60]= {"with a velocity of","has the average speed of","ratio between displacement and time taken is","rate of movement is"};
char k_4_3[4][60]= {"accelerates at the rate of","increasing speed at the rate of","speed up at the rate of","increasing the velocity at the rate of"};
char k_4_4[4][60]= {"How much is its speed at","tell the average speed at","What's its average velocity at","find the velocity at"};
char k_5_1[4][60]= {"The velocity at first point of","The speed at starting point of","The beginning's speed of","The starting velocity of"};
char k_5_2[4][60]= {"a speedboat","a dog sled","a motorcycle","a bicycle"};
char k_5_3[4][60]= {"its velocity is","it is traveling at the rate of","it speed up to","its average speed is"};
char k_5_4[4][60]= {"find the acceleration","find the rate that it speed up","find the rate of velocity change","find the rate that speed increase"};
char k_6_1[4][60]= {"How long does it takes","Find how long will it takes for","Calculate the time for","What's the time for"};
char k_6_2[4][60]= {"an object","a horse","a RC helicopter","a tricycle"};
char k_6_3[4][60]= {"to change its velocity","to accelerate","to speed up","to change its speed"};
char k_6_4[4][60]= {"if its rate to speed up is","if its rate of changing velocity is","if its rate of increasing speed is","if its acceleration is"};
char k_7_1[4][60]= {"A helicopter","A buggy","A canoe","An old car"};
char k_7_2[4][60]= {"is moving at the speed of","is moving with beginning speed of","with the speed at starting point of","is traveling at the velocity of"};
char k_7_3[4][60]= {"and is accelerating at the rate of","and is increasing the velocity at the rate of","and is increasing speed at the rate of","and is speeding up at the rate of"};
char k_7_4[4][60]= {"how far it can go in","Find the distance it can go in","Find the displacement it can go in","What's the distance it can go in"};
char k_8_1[4][60]= {"Find the velocity of","What's the final velocity of","What's the speed of","Find the speed of"};
char k_8_2[4][60]= {"a boomerang","a basketball","a hovercraft","a sled"};
char k_8_3[4][60]= {"that increase the velocity from","that increase speed from","that speed up from","that start accelerating from"};
char k_8_4[4][60]= {"when the distance is","if it has moved for","when it moved for","when it traveled for"};
char k_9_1[3][60]= {"How long does","Find the duration that","How much time that"};
char k_9_2[3][60]= {"a paper plane","a coin","an object"};
char k_9_3[3][60]= {"stay off the ground","float","stay in the air"};
char k_9_4[3][60]= {"when it is fired perpendicular to the ground","when you throw it up","if it is launched upwards"};
char k_10_1[3][60]= {"Calculate the height that","How far can","Find the maximum height that"};
char k_10_2[3][60]= {"a bomb","a rock","a ball"};
char k_10_3[3][60]= {"can go upwards","travel without falling back down","travel upwards"};
char k_10_4[3][60]= {"when it is fired perpendicular to the ground","when you throw it up","if it is launched upwards"};
//arrays
// put functions here
void game_over();
int selec_type();
void menuitem(int menu_item, char itemname[15])
{
// check if the options is chosen or not
if (menu_item == cursor_pos)
printf(" o %s", itemname);
else
printf(" %s", itemname);
}
void dev()
{
int temp;
clear;
printf("Secret Options\n");
printf("1. Turn Hint on or off\n");
printf("2. Edit time for time_attack\n");
printf("3. Change Question Quantity for classic\n");
printf("Choose : ");
scanf("%d",&temp);
printf("Enter Your Number : ");
switch(temp)
{
case 1:
scanf("%d",&hint);
break;
case 2:
scanf("%f",&time_attack_time);
break;
case 3:
scanf("%d",&qq_classic);
break;
}
dev_option = 0;
getch();
}
void menuitemdisplay()
{
// display items
printf("\tMain Menu\n\n");
menuitem(0, "Classic\n");
menuitem(1, "Time Attack\n");
menuitem(2, "Survival\n");
menuitem(3, "Help\n");
menuitem(4, "High Score\n");
menuitem(5, "Exit\n");
}
// quiz packs
// support functions
int randomizer(int r_range,int r_min)
{
srand(GetTickCount());
r_temp=(rand()%r_range)+r_min;
return r_temp;
}
// helps
void help()
{
printf("\tHelp\n\n");
printf("All Questions are about Physics\n");
printf("Write down answer and Enter to submit your answer\n");
printf("Classic Mode : 16 Questions,No Time Limit\n");
printf("Time Attack Mode : Answer as much as you can before time runs out\n");
printf("Survival Mode : Keep Asking till you get a wrong answer\n");
printf("Answer the question with two-degit decimals");
}
void record()
{
if (score>h_score[mode])
h_score[mode]=score;

}
// time attack mode
void time_attack()
{
double diff_t;
time_t start,end;
mode=1;
time(&start);
while(diff_t<123)
{
clear;
score=score+select_type();
time(&end);
diff_t=difftime(end,start);
}
game_over();
}
// classic mode
void classic()
{
int i;
mode=0;
for(i=0; i<qq_classic; i++)
{
clear;
score=score+select_type();
}
game_over();
}
// survival mode
void survival()
{
mode=2;
while(select_type()==1)
{
clear;
score=score+1;
}
game_over();
}
// high score
void high_score()
{
printf("\t\tHigh Score\n\n");
printf("Classic High Score is\t\t: %d\n",h_score[0]);
printf("Time-Attack High Score is\t: %d\n",h_score[1]);
printf("Survival Score is\t\t: %d\n",h_score[2]);

}

void game_over()
{
clear;
if(mode==0)
{
gotoxy(27,10);
printf("You have complete the game");
}
else if(mode==1)
{
gotoxy(33,10);
printf("Your time is up");
}
else if(mode==2)
{
gotoxy(32,10);
printf("You have Survived");
}
gotoxy(40,11);
printf("%d\n",score);
gotoxy(35,12);
if(mode==2)
printf("Question(s)");
record();
score=0;
}
double round(double i)
{
int temp;
i=i*1000;
temp=i;
if(temp%10>5)
temp=temp+5;
i=temp;
i=i/1000;
i=i*100;
temp=i;
i=temp;
i=i/100;
return i;
}
int k1()
{
clear;
float v,s,t,ans_temp;
s=randomizer(50,10);
t=randomizer(15,3);
v=s/t;
v=round(v);
if(hint==8388)
printf("\nk1 %.2f\n",v);
printf("%s %s %.2f m in %.2f seconds %s",k_1_1[e],k_1_2[b],s,t,k_1_3[c]);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==v)
return 1;
else
return 0;
}
int k2()
{
clear;
float v,s,t,ans_temp;
v=randomizer(20,4);
t=randomizer(15,3);
s=v*t;
s=round(s);
if(hint==8388)
printf("\nk2 %.2f\n",s);
printf("%s %s %.2f m/s how far it can travel in %.2f seconds",k_2_1[e],k_2_2[b],v,t);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==s)
return 1;
else
return 0;
}
int k3()
{
clear;
float v,s,t,ans_temp;
s=randomizer(50,10);
v=randomizer(20,4);
t=s/v;
t=round(t);
if(hint==8388)
printf("\nk3 %.2f\n",t);
printf("%s %s %s %.2f m at %.2f m/s",k_3_1[e],k_3_2[b],k_3_3[c],s,v);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==t)
return 1;
else
return 0;
}
int k4()
{
clear;
float v,u,a,t,ans_temp;
u=randomizer(5,1);
a=randomizer(10,1);
t=randomizer(15,3);
v=u+(a*t);
v=round(v);
if(hint==8388)
printf("\nk4 %.2f\n",v);
printf("%s %s %d m/s %s %d m/s^2 %s %d seconds",k_4_1[e],k_4_2[b],v,k_4_3[c],a,k_4_4[d],t);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==v)
return 1;
else
return 0;
}
int k5()
{
clear;
float v,u,a,t,ans_temp;
u=randomizer(5,1);
v=u+randomizer(12,2);
t=randomizer(15,3);
a=(v-u)/t;
a=round(a);
if(hint==8388)
printf("\nk5 %.2f\n",a);
printf("%s %s is %.2f but %.2f seconds later %s %.2f m/s %s",k_5_1[e],k_5_2[b],u,t,k_5_3[c],v,k_5_4[d]);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==a)
return 1;
else
return 0;
}
int k6()
{
clear;
float v,u,a,t,ans_temp;
u=randomizer(5,1);
v=u+randomizer(12,2);
a=randomizer(10,1);
t=(v-u)/a;
t=round(t);
if(hint==8388)
printf("\nk6 %.2f\n",t);
printf("%s %s %s from %.2f to %.2f %s %.2f m/s^2",k_6_1[e],k_6_2[b],k_6_3[c],u,v,k_6_4[d],a);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==t)
return 1;
else
return 0;
}
int k7()
{
clear;
float s,u,a,t,ans_temp;
u=randomizer(5,1);
a=randomizer(10,1);
t=randomizer(15,3);
s=(u*t)+(0.5*a*t*t);
s=round(s);
if(hint==8388)
printf("\nk7 %.2f\n",s);
printf("%s %s %.2f %s %.2f m/s^2 %s %.2f seconds",k_7_1[e],k_7_2[b],u,k_7_3[c],a,k_7_4[d],t);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==s)
return 1;
else
return 0;
}
int k8()
{
clear;
float s,u,a,v,ans_temp;
s=randomizer(50,10);
u=randomizer(5,1);
a=randomizer(10,1);
v=sqrt(pow(u,2)+(2*a*s));
v=round(v);
if(hint==8388)
printf("\nk8 %.2f\n",v);
printf("%s %s %s %.2f m/s at the rate of %.2f m/s^2 %s %.2f m",k_8_1[e],k_8_2[b],k_8_3[c],u,a,k_8_4[d],s);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==v)
return 1;
else
return 0;
}
int k9()
{
clear;
float t,u,ans_temp;
u=randomizer(7,1)*10;
t=(2*u)/10;
t=round(t);
if(hint==8388)
printf("\nk9 %.2f\n",t);
printf("%s %s %s %s at the velocity of %.2f m/s",k_9_1[f],k_9_2[g],k_9_3[h],k_9_4[z],u);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==t)
return 1;
else
return 0;
}
int k10()
{
clear;
float s,u,ans_temp;
u=randomizer(7,1)*5;
s=(u*u)/20;
s=round(s);
if(hint==8388)
printf("\nk10 %.2f\n",s);
printf("%s %s %s %s at the velocity of %.2f m/s",k_10_1[f],k_10_2[g],k_10_3[h],k_10_4[z],u);
gotoxy(0,8);
printf("Your Answer : ");
scanf("%f",&ans_temp);
if(ans_temp==s)
return 1;
else
return 0;
}
int select_type()
{
int type,a;
type=randomizer(10,1);
e=randomizer(4,0);
f=randomizer(3,0);
Sleep(100);
b=randomizer(4,0);
g=randomizer(3,0);
Sleep(100);
c=randomizer(4,0);
h=randomizer(3,0);
Sleep(100);
d=randomizer(4,0);
z=randomizer(3,0);
switch(type)
{
case 1:
a=k1();
break;
case 2:
a=k2();
break;
case 3:
a=k3();
break;
case 4:
a=k4();
break;
case 5:
a=k5();
break;
case 6:
a=k6();
break;
case 7:
a=k7();
break;
case 8:
a=k8();
break;
case 9:
a=k9();
break;
case 10:
a=k10();
break;
}
return a;
}
// main
int main()
{
if (OS_type != 0)
{
printf("OS not supported\nPress any key to continue...");
getch();
clrscr();
goto exit;
}
// menu
do
{
clear;
menuitemdisplay();
cursor = getch();
if (cursor == 119)
cursor_pos = cursor_pos - 1;
else if (cursor == 115)
cursor_pos = cursor_pos + 1;
else if (cursor == 100)
dev_option = dev_option + 1;
if (cursor_pos > 5)
cursor_pos = 0;
else if (cursor_pos < 0)
cursor_pos = 5;
if (dev_option > 6)
dev();
}
while (cursor != 13);
// mode chooser
clear;
switch (cursor_pos)
{
case 0:
classic();
break;
case 1:
time_attack();
break;
case 2:
survival();
break;
case 3:
help();
break;
case 4:
high_score();
break;
case 5:
goto exit;
}
getch();
clear;
main();
exit:;
return 0;
}
