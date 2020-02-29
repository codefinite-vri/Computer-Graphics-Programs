//trafiic signal with timer using DDA
#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<cmath>
#include<conio.h>

using namespace std;

void lineDDA(int xa, int ya, int xb, int yb,int co=WHITE)
{
	int dx, dy, steps, k;
	float xIncrement, yIncrement, x, y;
	dx=xb-xa;
	dy=yb-ya;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
		steps=abs(dy);
	xIncrement=dx/steps;
	yIncrement=dy/steps;
	x=xa;
	y=ya;
	putpixel(x,y, co);
	for(k=1;k<steps; k++)
	{
		x+=xIncrement;
		y+=yIncrement;
		putpixel(x, y, co);
	}
}

void timer()
{
	int co=BLACK;
	for(int i=9; i>=0; i--)
	{
		lineDDA(330,20,330,80);  //border
		lineDDA(330,80,370,80);
		lineDDA(370,20,330,20);
		lineDDA(370,80,370,20);
		
		switch(i)
		{			
			case 9:	lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50); //g
					lineDDA(340,65,340,50, co); //e 
					break;
			case 8: lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,65,340,50); //e 
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50); //g
					break;
			case 7: lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65,co); //d
					lineDDA(340,65,340,50,co); //e 
					lineDDA(340,50,340,35,co); //f
					lineDDA(340,50,360,50,co); //g
					break;
			case 6: lineDDA(340,35,360,35); //a
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,65,340,50); //e 
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50); //g
					lineDDA(360,35,360,50,co); //b
					break;
			case 5: lineDDA(340,35,360,35); //a
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50); //g
					lineDDA(360,35,360,50,co); //b
					lineDDA(340,65,340,50,co); //e 
					break;
			case 4: lineDDA(340,35,360,35,co); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65,co); //d
					lineDDA(340,65,340,50,co); //e 
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50); //g
					break;
			case 3: lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,65,340,50,co); //e 
					lineDDA(340,50,340,35,co); //f
					lineDDA(340,50,360,50); //g
					break;
			case 2: lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65,co); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,65,340,50); //e 
					lineDDA(340,50,340,35,co); //f
					lineDDA(340,50,360,50); //g
					break;
			case 1: lineDDA(340,35,360,35,co); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65,co); //d
					lineDDA(340,65,340,50,co); //e 
					lineDDA(340,50,340,35,co); //f
					lineDDA(340,50,360,50,co); //g
					break;
			case 0:	lineDDA(340,35,360,35); //a
					lineDDA(360,35,360,50); //b
					lineDDA(360,50,360,65); //c
					lineDDA(360,65,340,65); //d
					lineDDA(340,65,340,50); //e 
					lineDDA(340,50,340,35); //f
					lineDDA(340,50,360,50,co); //g
					break;
		}
		delay(1000);
	}
}

void traffic()
{
	lineDDA(300,600,300,100);  //traffic signal
	lineDDA(300,100,400,100);
	lineDDA(400,600,400,100);
	lineDDA(300,600,400,600);
	  
	lineDDA(310,250,310,150);  //first one
	lineDDA(310,150,390,150);
	lineDDA(390,150,390,250);
	lineDDA(390,250,310,250);
	   
	lineDDA(310,400,310,300);  //second one
	lineDDA(310,300,390,300);
	lineDDA(390,300,390,400);
	lineDDA(390,400,310,400);
	   
	lineDDA(310,550,310,450);  //third one
	lineDDA(310,450,390,450);
	lineDDA(390,450,390,550);
	lineDDA(390,550,310,550);
}


int main()
{
	int gd=DETECT, gm;
	initwindow(700,700);
	for(int i=0; ; i++)
	{		
	    traffic();	   	  
	   
	    if(i%4==0)
	    {
	   		setfillstyle(SOLID_FILL,RED);
	  		floodfill(370, 200,WHITE);
	   		timer();
	   		cleardevice();
	   	}
	   	else if(i%4==1||i%4==3)
	   	{
	   		setfillstyle(SOLID_FILL,YELLOW);
	  		floodfill(370,380,WHITE);
	  	 	delay(3000);
	   		cleardevice();
	   	}
	   	else
	   	{
	   		setfillstyle(SOLID_FILL,GREEN);
	   		floodfill(370, 500,WHITE);
	    	timer();
	   		cleardevice();
	   	}
	}
   	closegraph();
   	return 0;
}
