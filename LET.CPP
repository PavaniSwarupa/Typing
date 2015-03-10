#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
int x,x1,x2,x3,y,z,z1,z2,z3,j,p,f=1,c1=0,c2=0,c3=0,score=0,ch;
void play(int t,int n)
{       cleardevice();
	z1=random(26);
	z2=random(26);
	z3=random(26);
	x1=25+random(600);
	x2=25+random(600);
	x3=25+random(600);
	y=500;
	j=y;
	if(n==1)
		c2=c3=1;
	if(n==2)
		c3=1;
	while(j>=0)
	{       char l1[1],l2[1],l3[1];
		*l1=97+z1;
		*(l1+1)=NULL;
		*l2=97+z2;
		*(l2+1)=NULL;
		*l3=97+z3;
		*(l3+1)=NULL;
		if(c1==0)
		{       fillellipse(x1,j,25,25);
			outtextxy(x1-5,j-20,l1);
		}
		if(c2==0)
		{       fillellipse(x2,j,25,25);
			outtextxy(x2-5,j-20,l2);
		}
		if(c3==0)
		{	fillellipse(x3,j,25,25);
			outtextxy(x3-5,j-20,l3);
		}
		j=j-50;
		if(kbhit())
		{       ch=getch();
			if(ch==97+z1&&c1==0)
			{	score++;
				c1=1;
			}
			if(ch==97+z2&&c2==0)
			{	score++;
				c2=1;
			}
			if(ch==97+z3&&c3==0)
			{	score++;
				c3=1;
			}
			if(c1==1&&c2==1&&c3==1)
			{	cleardevice();
				return;
			}
		 }
		delay(t);
		cleardevice();
	}
}
int msg(int l,int n,int m)
{       int f;
	gotoxy(5,5);
	printf("\nLEVEL%d IS COMPLETED.\nYOUR SCORE IS : %d",l,score);
	p=(score*100)/(20*l);
	printf("\nYOU GOT %d PERCENTAGE.",p);
	if(p<50)
		printf("\nYOU ARE RECOMMENDED TO CONTINUE LEVEL%d.",l);
	else if(m!=-1)
		printf("\nYOU ARE RECOMMENDED TO PLAY LEVEL%d.",n);
	if(m==-1)
		printf("To PLAY LEVEL%d ENTER '0' :",l);
	else
		printf("\nTO GO TO LEVEL%d ENTER '2' or ENTER '1' FOR LEVEL%d or '0' to exit or 'p' to pause the game : ",n,l);
	f=getch()-48;
	return f;
}
void run(int t,int n)
{       int i=1; //2
	while(i<=20)
	{       c1=c2=c3=0;
		play(t,n);
		i++;
		delay(200);
	}
}
void set(int b,int f)
{       settextstyle(1,0,3);
	setbkcolor(b);
	setcolor(b);
	setfillstyle(SOLID_FILL,f);
}
void draw()
{       setfillstyle(SOLID_FILL,GREEN);
	fillellipse(320,240,1.5,1.5);
	delay(100);
	for(x=25;x<=250;x=x+25)
	{       setcolor(GREEN);
		fillellipse(320-x,240,1.5,1.5);
		fillellipse(320-x/2,240-x/2,1.5,1.5);
		fillellipse(320+x/2,240+x/2,1.5,1.5);
		fillellipse(320-x/2,240+x/2,1.5,1.5);
		fillellipse(320+x/2,240-x/2,1.5,1.5);
		fillellipse(320+x,240,1.5,1.5);
		fillellipse(320,240+x,1.5,1.5);
		fillellipse(320,240-x,1.5,1.5);
		delay(50);
	}
}
void main()
{       clrscr();
	int gd=DETECT;
	initgraph(&gd,0,"");
	settextstyle(4,0,7);
	setbkcolor(5);
	setcolor(9);
	delay(1000);
	int i,j,k,l;
	for(i=0,j=450;i<=200;i+=20,j-=20)
	{
		outtextxy(180,i,"T");
		outtextxy(220,j,"Y");
		outtextxy(260,i,"P");
		outtextxy(300,j,"I");
		outtextxy(340,i,"N");
		outtextxy(380,j,"G");
		delay(50);
		cleardevice();
	}
	outtextxy(180,200,"TYPING");
	delay(200);
	for(i=200,j=200,k=180,l=180;j<=550;i-=20,j+=20,k-=30,l+=30)
	{	outtextxy(180,i,"TYPING");
		outtextxy(180,j,"TYPING");
		outtextxy(k,200,"TYPING");
		outtextxy(l,200,"TYPING");
		delay(50);
		cleardevice();
	}
	outtextxy(180,200,"TYPING");
	delay(500);
	int menu;
	setbkcolor(0);
	while(1)
	{       cleardevice();
		gotoxy(1,1);
		printf("*******MENU*******\n1.ABOUT\n2.INSTRUCTIONS\n3.LEVELS\n4.DEVELOPERS\n5.START\n6.EXIT\nEnter Your choice:[ ]\b\b");
		menu=getch()-48;
		if(menu==6)
			exit(0);
		if(menu==5)
			break;
		if(menu>5||menu<1)
		{	printf("Enter right choice.");
			delay(500);
		}
		else
		{       cleardevice();
			gotoxy(1,1);
			switch(menu)
			{   	case 1: printf("\t\t\t\tABOUT\n\nThe alphabets a-z are displayed on the console randomly.\nThe player should type the letter before it disappears from the console.\nEven if you miss it you can try it till it disappears from the console.\n\nPress Enter to skip this menu.");
					getch();
					break;
				case 2: printf("\t\t\t\tINSTRUCTIONS\n\nThe alphabet displayed on console should be pressed on the key board before it  disappears fom the console.\nPress 1 to play the same level again.\nPress 2 to go for next level.\nPress 0 to stop the game.\nPress 'p' to pause the game.\n\nPress Enter to skip This Menu.");
					getch();
					break;
				case 3: printf("\t\t\t\tLEVELS\nThere are 6 levels of typing.\nAs the level increases the speed increases and the number of alphabets also increases.\n\nLEVEL1\nOne alphabet with normal speed.\n\nLEVEL2\nOne alphabet with high speed.\n\nLEVEL3\nTwo alphabets with normal speed.\n\nLEVEL4\nTwo alphabets with high speed.\n\nLEVEL5\nThree alphabets with normal speed.\n\nLEVEL6\nThree alphabets with high speed.\n\nPress Enter to skip this menu.");
					getch();
					break;
				case 4: printf("\t\t\t\tDEVELOPERS\n\nCSE\nII year\n\nN.Anusha\nB.smitha\nN.deepika\nK.pavaniswarupa\nM.sunithasowjanya\n\nPress Enter to skip this menu.");
					getch();
					break;
			}
		}
	}
	cleardevice();
	settextstyle(0,0,0);
	randomize();
	setcolor(5);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL1");
	draw();
	cleardevice();
	set(5,9);
	while(f==1)
	{       score=0;
		run(200,1);
		f=msg(1,2,0);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				printf("\nGame is paused to play press 'p'.");
				if(getch()=='p')
					break;
			}
	}
	f=1;
	cleardevice();
	setbkcolor(0);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL2");
	draw();
	set(9,5);
	while(f==1)
	{       run(150,1);
		f=msg(2,3,0);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				outtextxy(1,1,"Game is paused to play press 'p'.");
				if(getch()==p)
					break;
			}
	}
	f=1;
	cleardevice();
	setbkcolor(0);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL3");
	draw();
	set(5,9);
	while(f==1)
	{	run(200,2);
		f=msg(3,4,0);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				printf("\nGame is paused to play press 'p'.");
				if(getch()=='p')
					break;
			}
	}
	f=1;
	cleardevice();
	setbkcolor(0);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL4");
	draw();
	set(9,5);
	while(f==1)
	{       run(150,2);
		f=msg(4,5,0);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				printf("\nGame is paused to play press 'p'.");
				if(getch()=='p')
					break;
			}
	}
	f=1;
	cleardevice();
	setbkcolor(0);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL5");
	draw();
	set(5,9);
	while(f==1)
	{	run(200,3);
		f=msg(5,6,0);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				printf("\nGame is paused to play press 'p'.");
				if(getch()=='p')
					break;
			}
	}
	f=1;
	cleardevice();
	setbkcolor(0);
	settextstyle(4,0,6);
	outtextxy(220,215,"LEVEL6");
	draw();
	set(9,5);
	while(f==1)
	{	run(150,3);
		f=msg(6,7,-1);
		if(f==0)
			exit(0);
		if(f==64)
			while(1)
			{       gotoxy(1,12);
				printf("\nGame is paused to play press 'p'.");
				if(getch()=='p')
					break;
			}
	}
	cleardevice();
	setbkcolor(0);
	printf("\n\n\n\n\n\n\t\t\t\t     SCORE: %d",score);
	draw();
	getch();
}