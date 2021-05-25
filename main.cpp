#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,a=0.0,b=0.0,c=0.0,d=0.0,s=0.0;
float p=0.4,q=0.0,r=0.4;
float u=1, v=0.2,w=0.2;
float e=0.9,f=0.9,g=0.0;
float s1=1.0, s2=1.0, s3=1.0;
float b1=0.0,b2=0.5,b3=0.7;
int count=0;

int light=1,day=1,comet=0,plane=0;


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
    glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glColor3f(0.0,0.9,0.6);
glVertex2f(0,700);
glColor3f(0.9,0.9,0.9);
glVertex2f(1100,700);
glColor3f(0.0,0.9,0.9);
glVertex2f(1100,380);
glEnd();


//sun
for(l=0;l<=35;l++){
    glColor3f(0.4,0.4,0.4);
    draw_circle(102,623,l);
}

for(l=0;l<=35;l++){
    glColor3f(0.9,1,0.1);
    draw_circle(100,625,l);

}
//
for(l=0;l<=30;l++){
    glColor3f(0.9,1,0.1);
    draw_circle(100,620,l);

}
for(l=0;l<=30;l++){
    glColor3f(0.9,1,0.2);
    draw_circle(100,625,l);

}
for(l=0;l<=30;l++){
    glColor3f(0.9,1,0.3);
    draw_circle(100,630,l);

}
for(l=0;l<=25;l++){
    glColor3f(0.9,1,0.4);
    draw_circle(95,630,l);

}
for(l=0;l<=20;l++){
    glColor3f(0.9,1,0.5);
    draw_circle(95,635,l);

}
for(l=0;l<=15;l++){
    glColor3f(0.9,1,0.6);
    draw_circle(90,640,l);
}
for(l=0;l<=10;l++){
    glColor3f(0.9,1,0.7);
    draw_circle(90,645,l);

}
for(l=0;l<=5;l++){
    glColor3f(0.9,1,0.8);
    draw_circle(90,645,l);

}


//plane
	glColor3f(0.9,0.8,1);
    glBegin(GL_POLYGON);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
    glEnd();

	glColor3f(0.8,0.8,0.8);
	glBegin(GL_LINE_LOOP);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
    glEnd();


//cloud1

for(l=0;l<=20;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(160+m,625,l);
}


for(l=0;l<=35;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(200+m,625,l);
    draw_circle(225+m,625,l);
}

for(l=0;l<=20;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(265+m,625,l);
}

//cloud2

for(l=0;l<=20;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(370+m,615,l);
}
for(l=0;l<=35;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(410+m,615,l);
    draw_circle(435+m,615,l);
    draw_circle(470+m,615,l);
}

for(l=0;l<=20;l++){
    glColor3f(1.0,1.0,1.0);
    draw_circle(500+m,615,l);
}
//grass
    glColor3f(0.6,0.8,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,390);
    glColor3f(0.1,0.3,0.0);
    glVertex2f(1100,390);
    glColor3f(0.6,0.8,0.2);
    glVertex2f(1100,0);
    glEnd();


//river

	glBegin(GL_POLYGON);

	glColor3f(0.5,0.3,1.0);
		glVertex2f(0,270);
		glColor3f(1,1,0.7);
		glVertex2f(0,370);
        glColor3f(0.5,0.3,1.0);
		glVertex2f(1100,370);
		glColor3f(0.5,0.3,1.0);
		glVertex2f(1100,270);
		glEnd();

//border
		glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,270);
		glVertex2f(0,275);
		glVertex2f(1100,275);
		glVertex2f(1100,270);
		glEnd();

//border
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,370);
		glVertex2f(0,375);
		glVertex2f(1100,375);
		glVertex2f(1100,370);
		glEnd();

//border1
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,200);
		glVertex2f(1100,200);
		glVertex2f(1100,0);
	glEnd();

//road
	glColor3f(0.4,0.4,0.4);
	glBegin(GL_POLYGON);
	//glColor3f(1,1,1);
		glVertex2f(0,0);
		glColor3f(0.4,0.4,0.4);
		glVertex2f(0,195);
		glColor3f(0,0,0);
		glVertex2f(1100,195);
		glColor3f(0.4,0.4,0.4);
		glVertex2f(1100,0);
	glEnd();

//border2
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,90);
		glVertex2f(1100,90);
		glVertex2f(1100,0);
	glEnd();
//ground
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glColor3f(0.6,0.8,0.3);
		glVertex2f(0,85);
		glColor3f(0.0,0.3,0.0);
		glVertex2f(1100,85);
		glColor3f(0.1,0.2,0);
		glVertex2f(1100,0);
	glEnd();
}
else
    {
//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//moon
int l;

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}

//star1

glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();

//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();

//star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();

//star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();

//star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();

//star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(100,528);
glVertex2f(95,520);
glVertex2f(105,520);
glVertex2f(100,518);
glVertex2f(95,525);
glVertex2f(105,525);
glEnd();

//star8
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(300,468);
glVertex2f(295,460);
glVertex2f(305,460);
glVertex2f(300,458);
glVertex2f(295,465);
glVertex2f(305,465);
glEnd();

//star9
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();


//comet

	for(l=0;l<=7;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(300+c,675,l);
	}

glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200+c,675);
	glVertex2f(300+c,682);
	glVertex2f(300+c,668);
	glEnd();



	for(l=0;l<=1;l++)
	{
		glColor3f(1.0,0.0,0.0);
		draw_circle(950+n,625+o,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(954+n,623+o,l);

	}

//grass
    glColor3f(0.0,0.3,0.0);
    glBegin(GL_POLYGON);
glColor3f(0.6,0.8,0.3);
    glVertex2f(0,160);
    glColor3f(0.0,0.3,0.0);
    glVertex2f(0,390);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(1100,390);
    glColor3f(0.0,0.3,0.0);
    glVertex2f(1100,160);
    glEnd();



//river
	glColor3f(0.5,0.3,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,270);
		glVertex2f(0,370);
		glVertex2f(1100,370);
		glVertex2f(1100,270);
		glEnd();

//border
		glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,270);
		glVertex2f(0,275);
		glVertex2f(1100,275);
		glVertex2f(1100,270);
		glEnd();

//border
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,370);
		glVertex2f(0,375);
		glVertex2f(1100,375);
		glVertex2f(1100,370);
		glEnd();

//border1
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,200);
		glVertex2f(1100,200);
		glVertex2f(1100,0);
	glEnd();

//road
	glColor3f(0.4,0.4,0.4);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
		glVertex2f(0,0);
		glColor3f(0.4,0.4,0.4);
		glVertex2f(0,195);
		glColor3f(0,0,0);
		glVertex2f(1100,195);
		glVertex2f(1100,0);
	glEnd();

//border2
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,90);
		glVertex2f(1100,90);
		glVertex2f(1100,0);
	glEnd();

//ground
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glColor3f(0.6,0.8,0.3);
		glVertex2f(0,85);
		glColor3f(0.0,0.3,0.0);
		glVertex2f(1100,85);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1100,0);
	glEnd();


}




//home on other side
//1
    glColor3f(0.0,0.0,0.2);
    glBegin(GL_POLYGON);

		glVertex2f(50,390);
		glVertex2f(50,430);
		glVertex2f(100,430);
		glVertex2f(100,390);

	glEnd();

	glColor3f(0.0,0.0,0.5);
    glBegin(GL_POLYGON);

		glVertex2f(100,390);
		glVertex2f(100,430);
		glVertex2f(110,420);
		glVertex2f(110,390);

	glEnd();

//w
    glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(55,400);
		glVertex2f(55,420);
		glVertex2f(70,420);
		glVertex2f(70,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(80,400);
		glVertex2f(80,420);
		glVertex2f(95,420);
		glVertex2f(95,400);
		glEnd();
//2
    glColor3f(0.8,0.4,0.6);
    glBegin(GL_POLYGON);

		glVertex2f(120,390);
		glVertex2f(120,450);
		glVertex2f(170,450);
		glVertex2f(170,390);

	glEnd();

	glColor3f(0.8,0.4,0.9);
    glBegin(GL_POLYGON);

		glVertex2f(170,390);
		glVertex2f(170,450);
		glVertex2f(180,440);
		glVertex2f(180,390);

	glEnd();

//w
        glColor3f(e,f,g);
	    glBegin(GL_POLYGON);

		glVertex2f(125,400);
		glVertex2f(125,420);
		glVertex2f(140,420);
		glVertex2f(140,400);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(150,400);
		glVertex2f(150,420);
		glVertex2f(165,420);
		glVertex2f(165,400);
		glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(125,425);
		glVertex2f(125,445);
		glVertex2f(140,445);
		glVertex2f(140,425);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(150,425);
		glVertex2f(150,445);
		glVertex2f(165,445);
		glVertex2f(165,425);
		glEnd();
//3
	    glColor3f(0.8,0.5,0.1);
    glBegin(GL_POLYGON);

		glVertex2f(190,390);
		glVertex2f(190,470);
		glVertex2f(240,470);
		glVertex2f(240,390);

	glEnd();

	glColor3f(0.8,0.5,0.4);
    glBegin(GL_POLYGON);

		glVertex2f(240,390);
		glVertex2f(240,470);
		glVertex2f(250,460);
		glVertex2f(250,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(195,445);
		glVertex2f(195,465);
		glVertex2f(210,465);
		glVertex2f(210,445);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(220,445);
		glVertex2f(220,465);
		glVertex2f(235,465);
		glVertex2f(235,445);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(220,415);
		glVertex2f(220,435);
		glVertex2f(235,435);
		glVertex2f(235,415);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(195,415);
		glVertex2f(195,435);
		glVertex2f(210,435);
		glVertex2f(210,415);
		glEnd();
//4
	    glColor3f(0.1,0.0,0.0);
    glBegin(GL_POLYGON);

		glVertex2f(260,390);
		glVertex2f(260,440);
		glVertex2f(310,440);
		glVertex2f(310,390);

	glEnd();

	glColor3f(0.1,0.0,0.3);
    glBegin(GL_POLYGON);

		glVertex2f(310,390);
		glVertex2f(310,440);
		glVertex2f(320,430);
		glVertex2f(320,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(265,400);
		glVertex2f(265,415);
		glVertex2f(280,415);
		glVertex2f(280,400);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(265,420);
		glVertex2f(265,435);
		glVertex2f(280,435);
		glVertex2f(280,420);
		glEnd();

		glBegin(GL_POLYGON);

		glVertex2f(290,400);
		glVertex2f(290,415);
		glVertex2f(305,415);
		glVertex2f(305,400);
		glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(290,420);
		glVertex2f(290,435);
		glVertex2f(305,435);
		glVertex2f(305,420);
		glEnd();

//5
	    glColor3f(0.6,0.1,0.0);
    glBegin(GL_POLYGON);

		glVertex2f(330,390);
		glVertex2f(330,490);
		glVertex2f(380,490);
		glVertex2f(380,390);

	glEnd();

	glColor3f(0.6,0.1,0.3);
    glBegin(GL_POLYGON);

		glVertex2f(380,390);
		glVertex2f(380,490);
		glVertex2f(390,480);
		glVertex2f(390,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(335,400);
		glVertex2f(335,415);
		glVertex2f(350,415);
		glVertex2f(350,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(335,425);
		glVertex2f(335,440);
		glVertex2f(350,440);
		glVertex2f(350,425);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(335,450);
		glVertex2f(335,465);
		glVertex2f(350,465);
		glVertex2f(350,450);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(360,400);
		glVertex2f(360,415);
		glVertex2f(375,415);
		glVertex2f(375,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(360,425);
		glVertex2f(360,440);
		glVertex2f(375,440);
		glVertex2f(375,425);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(360,450);
		glVertex2f(360,465);
		glVertex2f(375,465);
		glVertex2f(375,450);
		glEnd();

//6
	    glColor3f(0.1,0.1,0.2);
    glBegin(GL_POLYGON);

		glVertex2f(400,390);
		glVertex2f(400,470);
		glVertex2f(450,470);
		glVertex2f(450,390);

	glEnd();

	glColor3f(0.1,0.1,0.5);
    glBegin(GL_POLYGON);

		glVertex2f(450,390);
		glVertex2f(450,470);
		glVertex2f(460,460);
		glVertex2f(460,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(430,400);
		glVertex2f(430,425);
		glVertex2f(445,425);
		glVertex2f(445,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(430,430);
		glVertex2f(430,455);
		glVertex2f(445,455);
		glVertex2f(445,430);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(405,400);
		glVertex2f(405,425);
		glVertex2f(420,425);
		glVertex2f(420,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(405,430);
		glVertex2f(405,455);
		glVertex2f(420,455);
		glVertex2f(420,430);
		glEnd();

//7
        glColor3f(0.8,0.7,0.4);
	    glBegin(GL_POLYGON);

		glVertex2f(470,390);
		glVertex2f(470,420);
		glVertex2f(520,420);
		glVertex2f(520,390);
		glEnd();

        glColor3f(0.8,0.7,0.7);
	    glBegin(GL_POLYGON);

		glVertex2f(520,390);
		glVertex2f(520,420);
		glVertex2f(530,410);
		glVertex2f(530,390);
		glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(475,400);
		glVertex2f(475,415);
		glVertex2f(490,415);
		glVertex2f(490,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(500,400);
		glVertex2f(500,415);
		glVertex2f(515,415);
		glVertex2f(515,400);
		glEnd();

//8
        glColor3f(0.0,0.5,0.7);
	    glBegin(GL_POLYGON);

		glVertex2f(530,390);
		glVertex2f(530,460);
		glVertex2f(590,460);
		glVertex2f(590,390);

	glEnd();

//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(535,400);
		glVertex2f(535,425);
		glVertex2f(550,425);
		glVertex2f(550,400);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(535,430);
		glVertex2f(535,455);
		glVertex2f(550,455);
		glVertex2f(550,430);
		glEnd();

//9
        glColor3f(0.0,0.5,0.7);
        glBegin(GL_POLYGON);

		glVertex2f(770,390);
		glVertex2f(770,440);
		glVertex2f(820,440);
		glVertex2f(820,390);

	glEnd();

	glColor3f(0.0,0.5,1.0);
        glBegin(GL_POLYGON);

		glVertex2f(820,390);
		glVertex2f(820,440);
		glVertex2f(830,430);
		glVertex2f(830,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(775,395);
		glVertex2f(775,410);
		glVertex2f(815,410);
		glVertex2f(815,395);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(775,415);
		glVertex2f(775,430);
		glVertex2f(815,430);
		glVertex2f(815,415);
		glEnd();

//10
	        glColor3f(0.6,0.8,0.2);
        glBegin(GL_POLYGON);

		glVertex2f(840,390);
		glVertex2f(840,490);
		glVertex2f(890,490);
		glVertex2f(890,390);

	glEnd();

	glColor3f(0.6,0.8,0.5);
        glBegin(GL_POLYGON);

		glVertex2f(890,390);
		glVertex2f(890,490);
		glVertex2f(900,480);
		glVertex2f(900,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(845,460);
		glVertex2f(845,480);
		glVertex2f(860,480);
		glVertex2f(860,460);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(885,460);
		glVertex2f(885,480);
		glVertex2f(870,480);
		glVertex2f(870,460);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(845,440);
		glVertex2f(845,455);
		glVertex2f(860,455);
		glVertex2f(860,440);
		glEnd();
    glBegin(GL_POLYGON);

		glVertex2f(885,440);
		glVertex2f(885,455);
		glVertex2f(870,455);
		glVertex2f(870,440);
		glEnd();
//11
        glColor3f(0.8,0.5,0.1);
        glBegin(GL_POLYGON);

		glVertex2f(910,390);
		glVertex2f(910,460);
		glVertex2f(960,460);
		glVertex2f(960,390);

	glEnd();

	glColor3f(0.8,0.5,0.4);
        glBegin(GL_POLYGON);

		glVertex2f(960,390);
		glVertex2f(960,460);
		glVertex2f(970,450);
		glVertex2f(970,390);

	glEnd();
//w
        glColor3f(e,f,g);
	    glBegin(GL_POLYGON);

		glVertex2f(915,400);
		glVertex2f(915,420);
		glVertex2f(930,420);
		glVertex2f(930,400);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(940,400);
		glVertex2f(940,420);
		glVertex2f(955,420);
		glVertex2f(955,400);
		glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(915,425);
		glVertex2f(915,445);
		glVertex2f(930,445);
		glVertex2f(930,425);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(940,425);
		glVertex2f(940,445);
		glVertex2f(955,445);
		glVertex2f(955,425);
		glEnd();
//12
        glColor3f(0.0,0.0,0.1);
        glBegin(GL_POLYGON);

		glVertex2f(980,390);
		glVertex2f(980,480);
		glVertex2f(1030,480);
		glVertex2f(1030,390);

	glEnd();
	        glColor3f(0.0,0.0,0.3);
        glBegin(GL_POLYGON);

		glVertex2f(1030,390);
		glVertex2f(1030,480);
		glVertex2f(1040,470);
		glVertex2f(1040,390);

	glEnd();
//w
	glColor3f(e,f,g);
    glBegin(GL_POLYGON);

		glVertex2f(985,400);
		glVertex2f(985,415);
		glVertex2f(1000,415);
		glVertex2f(1000,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(985,425);
		glVertex2f(985,440);
		glVertex2f(1000,440);
		glVertex2f(1000,425);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(985,450);
		glVertex2f(985,465);
		glVertex2f(1000,465);
		glVertex2f(1000,450);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(1010,400);
		glVertex2f(1010,415);
		glVertex2f(1025,415);
		glVertex2f(1025,400);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(1010,425);
		glVertex2f(1010,440);
		glVertex2f(1025,440);
		glVertex2f(1025,425);
		glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(1010,450);
		glVertex2f(1010,465);
		glVertex2f(1025,465);
		glVertex2f(1025,450);
		glEnd();

//ship
	glColor3f(0.4,0.0,0.1);
	glBegin(GL_POLYGON);
		glVertex2f(260+s,290);
		glVertex2f(220+s,330);
		glVertex2f(400+s,330);
		glVertex2f(360+s,290);
		glEnd();

    glColor3f(0.4,0.0,0.3);
	glBegin(GL_POLYGON);
		glVertex2f(250+s,330);
		glVertex2f(250+s,360);
		glVertex2f(340+s,360);
		glVertex2f(370+s,330);
		glEnd();

        glColor3f(0.4,0.0,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(260+s,360);
		glVertex2f(260+s,380);
		glVertex2f(310+s,380);
		glVertex2f(330+s,360);
		glEnd();

//w
		    glColor3f(s1,s2,s3);
	glBegin(GL_POLYGON);
		glVertex2f(295+s,365);
		glVertex2f(295+s,375);
		glVertex2f(310+s,375);
		glVertex2f(310+s,365);
		glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(270+s,365);
		glVertex2f(270+s,375);
		glVertex2f(285+s,375);
		glVertex2f(285+s,365);
		glEnd();

       glBegin(GL_POLYGON);
		glVertex2f(260+s,340);
		glVertex2f(260+s,355);
		glVertex2f(280+s,355);
		glVertex2f(280+s,340);
		glEnd();

        glBegin(GL_POLYGON);
		glVertex2f(290+s,340);
		glVertex2f(290+s,355);
		glVertex2f(310+s,355);
		glVertex2f(310+s,340);
		glEnd();

       glBegin(GL_POLYGON);
		glVertex2f(320+s,340);
		glVertex2f(320+s,355);
		glVertex2f(340+s,355);
		glVertex2f(340+s,340);
		glEnd();

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(485,200);
glVertex2f(485,255);
glVertex2f(505,255);
glVertex2f(505,200);
glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(480,250,l);
		draw_circle(510,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(485,290,l);
		draw_circle(505,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(495,315,l);
	}
//tree2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(80,200);
glVertex2f(80,255);
glVertex2f(100,255);
glVertex2f(100,200);
glEnd();

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(70,250,l);
		draw_circle(110,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(80,290,l);
		draw_circle(100,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(90,315,l);
	}
//tree3
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(190,200);
glVertex2f(190,325);
glVertex2f(220,325);
glVertex2f(220,200);
glEnd();

	for(l=0;l<=45;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(180,300,l);
		draw_circle(230,300,l);
	}

	for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(190,350,l);
		draw_circle(220,350,l);
	}

	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(205,400,l);
	}

//home

	glColor3f(u,v,w);
	glBegin(GL_POLYGON);
		glVertex2f(550,200);
		glColor3f(1,0.7,0.4);
		glVertex2f(550,500);
		glColor3f(0.6,0.2,0.3);
		glVertex2f(750,500);
		glColor3f(0.6,0,0.0);
		glVertex2f(750,200);

	glEnd();
//3d
		glColor3f(1.0,0.4,0.5);
	glBegin(GL_POLYGON);

		glVertex2f(550,500);
		glColor3f(0.6,0.2,0.3);
		glVertex2f(580,530);
		glVertex2f(780,530);
		glColor3f(1.0,0.4,0.5);
		glVertex2f(750,500);

	glEnd();

	glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);
        glVertex2f(550,500);
		glVertex2f(580,530);
		glVertex2f(780,530);
		glVertex2f(750,500);
		glEnd();

    glColor3f(1.0,0.4,0.5);
	glBegin(GL_POLYGON);

		glVertex2f(750,200);
		glVertex2f(750,500);
		glColor3f(0.6,0.2,0.3);
		glVertex2f(780,530);
		glVertex2f(780,230);

	glEnd();
	glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);
		glVertex2f(750,200);
		glVertex2f(750,500);
		glVertex2f(780,530);
		glVertex2f(780,230);

	glEnd();

//window for home1

	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(570,415);
		glVertex2f(570,465);
		glVertex2f(610,465);
		glVertex2f(610,415);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(690,415);
		glVertex2f(690,465);
		glVertex2f(730,465);
		glVertex2f(730,415);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(630,415);
		glVertex2f(630,465);
		glVertex2f(670,465);
		glVertex2f(670,415);

	glEnd();


	glBegin(GL_POLYGON);

		glVertex2f(570,340);
		glVertex2f(570,390);
		glVertex2f(610,390);
		glVertex2f(610,340);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(690,340);
		glVertex2f(690,390);
		glVertex2f(730,390);
		glVertex2f(730,340);

	glEnd();
		glBegin(GL_POLYGON);

		glVertex2f(630,340);
		glVertex2f(630,390);
		glVertex2f(670,390);
		glVertex2f(670,340);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(570,260);
		glVertex2f(570,310);
		glVertex2f(610,310);
		glVertex2f(610,260);

	glEnd();


	glBegin(GL_POLYGON);

		glVertex2f(690,260);
		glVertex2f(690,310);
		glVertex2f(730,310);
		glVertex2f(730,260);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(630,260);
		glVertex2f(630,310);
		glVertex2f(670,310);
		glVertex2f(670,260);

	glEnd();


//door
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(620,200);
		glVertex2f(620,240);
		glVertex2f(680,240);
		glVertex2f(680,200);

	glEnd();


//home2
	//glColor3f(p,q,r);
	glBegin(GL_POLYGON);
        glColor3f(.7,.4,.4);
		glVertex2f(810,200);
		glColor3f(.7,.4,.5);
		glVertex2f(810,410);
		glColor3f(p,q,r);
		glVertex2f(910,410);

		glVertex2f(910,200);

	glEnd();


	glBegin(GL_POLYGON);

		glVertex2f(910,200);
		glVertex2f(910,350);
		glColor3f(0.3,0.0,0.2);
		glVertex2f(1080,350);
		glColor3f(0.2,0,0.2);
		glVertex2f(1080,200);
		glEnd();
//3d
	glColor3f(0.4,0.3,0.4);
	glBegin(GL_POLYGON);

		glVertex2f(910,350);
		glVertex2f(910,400);
		glVertex2f(920,400);
		glVertex2f(920,350);

	glEnd();


        glBegin(GL_POLYGON);

		glVertex2f(1080,200);
		glColor3f(0.4,0.3,0.4);

		glVertex2f(1080,370);
		glColor3f(.7,.4,.5);
		glVertex2f(1095,370);
		glVertex2f(1095,220);
		glEnd();

        glBegin(GL_POLYGON);
    glColor3f(.7,.4,.5);
		glVertex2f(910,350);

        glVertex2f(920,370);
		glColor3f(0.4,0.3,0.4);
		glVertex2f(1090,370);

		glVertex2f(1080,350);
		glEnd();



       glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);

		glVertex2f(910,350);
		glVertex2f(910,400);
		glVertex2f(920,400);
		glVertex2f(920,370);
        glEnd();

        glBegin(GL_LINE_LOOP);

		glVertex2f(1080,200);
		glVertex2f(1080,350);
		glVertex2f(1095,370);
		glVertex2f(1095,220);
		glEnd();

	glBegin(GL_LINE_LOOP);

		glVertex2f(910,350);
		glVertex2f(920,370);
		glVertex2f(1095,370);
		glVertex2f(1080,350);
		glEnd();



//chimney
    glColor3f(0.35,0.0,0.0);
	glBegin(GL_POLYGON);

		glVertex2f(800,400);
		glColor3f(0.3,0.1,0.0);
		glVertex2f(860,460);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(920,400);

	glEnd();

//window for home2

	glColor3f(0.4,0.4,0.4);
	glBegin(GL_POLYGON);

		glVertex2f(930,260);
		glVertex2f(930,320);
		glVertex2f(1055,320);
		glVertex2f(1055,260);

		glEnd();
//window
	glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(935,265);
		glVertex2f(935,315);
		glVertex2f(990.5,315);
		glVertex2f(990.5,265);
	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(995,265);
		glVertex2f(995,315);
		glVertex2f(1050,315);
		glVertex2f(1050,265);
	glEnd();

		glColor3f(0.4,0.4,0.4);
	glBegin(GL_POLYGON);

		glVertex2f(830,350);
		glVertex2f(830,390);
		glVertex2f(895,390);
		glVertex2f(895,350);

	glEnd();

			glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(835,355);
		glVertex2f(835,385);
		glVertex2f(890,385);
		glVertex2f(890,355);

	glEnd();


//door for home2
    glColor3f(e,f,g);
	glBegin(GL_POLYGON);

		glVertex2f(835,200);
		glVertex2f(835,250);
		glVertex2f(890,250);
		glVertex2f(890,200);

	glEnd();

//Lines

    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

		glVertex2f(50,150);
		glVertex2f(50,155);
		glVertex2f(200,155);
		glVertex2f(200,150);

	glEnd();
		glBegin(GL_POLYGON);

		glVertex2f(250,150);
		glVertex2f(250,155);
		glVertex2f(400,155);
		glVertex2f(400,150);

	glEnd();

		glBegin(GL_POLYGON);

		glVertex2f(450,150);
		glVertex2f(450,155);
		glVertex2f(600,155);
		glVertex2f(600,150);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(650,150);
		glVertex2f(650,155);
		glVertex2f(800,155);
		glVertex2f(800,150);

	glEnd();
		glBegin(GL_POLYGON);

		glVertex2f(850,150);
		glVertex2f(850,155);
		glVertex2f(1000,155);
		glVertex2f(1000,150);

	glEnd();
//traffic light
    glColor3f(0.255,0.102,0.102);
	glBegin(GL_POLYGON);
		glVertex2f(410,200);
		glVertex2f(410,300);
        glVertex2f(420,300);
		glVertex2f(420,200);

		glEnd();

    glColor3f(1.0,0.9,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(400,270);
		glVertex2f(400,350);
        glVertex2f(430,350);
		glVertex2f(430,270);

		glEnd();

//lights

for(l=0;l<=10;l++){
    glColor3f(0.8,0.0,0.0);
    draw_circle(415,335,l);

}
for(l=0;l<=10;l++){
    glColor3f(0.0,0.5,0.1);
    draw_circle(415,310,l);

}
for(l=0;l<=10;l++){
    glColor3f(0.9,1.0,0.0);
    draw_circle(415,285,l);

}

//stamp light1
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(320,200);
		glVertex2f(320,330);
        glVertex2f(330,330);
		glVertex2f(330,200);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(300,280);
		glVertex2f(300,290);
        glVertex2f(350,290);
		glVertex2f(350,280);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(290,280);
		glVertex2f(290,310);
        glVertex2f(300,310);
		glVertex2f(300,280);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(350,280);
		glVertex2f(350,310);
        glVertex2f(360,310);
		glVertex2f(360,280);

		glEnd();

//lights

for(l=0;l<=20;l++){
    glColor3f(s1,s2,s3);
    draw_circle(325,345,l);

}
for(l=0;l<=15;l++){
    glColor3f(s1,s2,s3);
    draw_circle(295,320,l);

}
for(l=0;l<=15;l++){
    glColor3f(s1,s2,s3);
    draw_circle(355,320,l);

}
//wheels on the other side
//wheel1
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(720+a,185,l);

}

//wheel2
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(775+a,185,l);

}

//Car1

    glColor3f(0.0,0.0,0.2);
	glBegin(GL_POLYGON);
        glVertex2f(700+a,180);
		glVertex2f(700+a,205);
		glVertex2f(830+a,205);
		glVertex2f(830+a,180);

		glEnd();

		//3d

	glBegin(GL_POLYGON);
        glVertex2f(670+a,190);
		glVertex2f(675+a,215);
		glVertex2f(705+a,205);
		glVertex2f(700+a,180);

		glEnd();


	glBegin(GL_POLYGON);
        glVertex2f(730+a,240);
		glVertex2f(700+a,250);
		glVertex2f(780+a,250);
		glVertex2f(800+a,240);

		glEnd();

		glColor3f(0.0,0.5,0.7);
	glBegin(GL_POLYGON);
        glVertex2f(675+a,215);
		glVertex2f(700+a,250);
		glVertex2f(730+a,240);
		glVertex2f(705+a,205);

		glEnd();

		//lineloop
		glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);
        glVertex2f(675+a,215);
		glVertex2f(700+a,250);
		glVertex2f(730+a,240);
		glVertex2f(705+a,205);

		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(730+a,240);
		glVertex2f(700+a,250);
		glVertex2f(780+a,250);
		glVertex2f(800+a,240);

		glEnd();

		glBegin(GL_LINE_LOOP);
        glVertex2f(670+a,190);
		glVertex2f(675+a,215);
		glVertex2f(705+a,205);
		glVertex2f(700+a,180);

		glEnd();

//car window
    glColor3f(0.0,0.5,0.7);
    glBegin(GL_POLYGON);

		glVertex2f(730+a,205);
		glVertex2f(730+a,240);
		glVertex2f(800+a,240);
		glVertex2f(800+a,205);

	glEnd();

    glColor3f(0.0,0.5,0.4);
    glBegin(GL_POLYGON);
		glVertex2f(705+a,205);
		glVertex2f(730+a,240);
		glVertex2f(730+a,205);

	glEnd();

    glBegin(GL_POLYGON);

		glVertex2f(800+a,205);
		glVertex2f(800+a,240);
		glVertex2f(825+a,205);

	glEnd();
//wheel1
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(730+a,180,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(730+a,180,l);

}
//wheel2
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(795+a,180,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(795+a,180,l);

}

//
////wheel1 other side
    for(l=0;l<=25;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(120+c,150,l);

}
    //wheel2 other side
    for(l=0;l<=25;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(230+c,150,l);

}

//bus

    glColor3f(1,1,0);
	glBegin(GL_POLYGON);
        glVertex2f(50+c,140);
		glVertex2f(50+c,250);
		glVertex2f(280+c,250);
		glVertex2f(280+c,140);

		glEnd();
		//3d

	glBegin(GL_POLYGON);
        glVertex2f(280+c,140);
		glVertex2f(280+c,250);
		glVertex2f(310+c,260);
		glVertex2f(310+c,160);

		glEnd();

	glBegin(GL_POLYGON);

        glVertex2f(50+c,250);
		glVertex2f(80+c,260);
		glVertex2f(310+c,260);
		glVertex2f(280+c,250);

		glEnd();
//lineloop
    glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);
        glVertex2f(280+c,140);
		glVertex2f(280+c,250);
		glVertex2f(310+c,260);
		glVertex2f(310+c,160);

		glEnd();//

	glBegin(GL_LINE_LOOP);
        glVertex2f(50+c,250);
		glVertex2f(80+c,260);
		glVertex2f(310+c,260);
		glVertex2f(280+c,250);

		glEnd();


//bus window
    glColor3f(b1,b2,b3);
	glBegin(GL_POLYGON);
        glVertex2f(60+c,200);
		glVertex2f(60+c,240);
		glVertex2f(100+c,240);
		glVertex2f(100+c,200);

		glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(110+c,200);
		glVertex2f(110+c,240);
		glVertex2f(150+c,240);
		glVertex2f(150+c,200);

		glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(160+c,200);
		glVertex2f(160+c,240);
		glVertex2f(200+c,240);
		glVertex2f(200+c,200);

		glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(210+c,200);
		glVertex2f(210+c,240);
		glVertex2f(260+c,240);
		glVertex2f(260+c,200);

		glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(270+c,200);
		glVertex2f(270+c,240);
		glVertex2f(280+c,240);
		glVertex2f(280+c,200);

		glEnd();
		glBegin(GL_POLYGON);
        glVertex2f(280+c,200);
		glVertex2f(280+c,240);
		glVertex2f(310+c,250);
		glVertex2f(310+c,215);

		glEnd();
//wheel1
    for(l=0;l<=25;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(100+c,135,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(100+c,135,l);
}
    //wheel2
    for(l=0;l<=25;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(210+c,135,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(210+c,135,l);

}



//car 2 wheels on the other side
//wheel1
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(460+c,140,l);

}


//wheel2
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(390+c,140,l);

}


//Car2

    glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
        glVertex2f(350+c,140);
		glVertex2f(350+c,170);
		glVertex2f(480+c,170);
		glVertex2f(480+c,140);

		glEnd();
//3d

	glBegin(GL_POLYGON);
        glVertex2f(480+c,140);
		glVertex2f(480+c,170);
		glVertex2f(500+c,180);
		glVertex2f(500+c,150);

		glEnd();
		//lineloop
		glColor3f(0.4,0.4,0.4);
        glBegin(GL_LINE_LOOP);
        glVertex2f(480+c,140);
		glVertex2f(480+c,170);
		glVertex2f(500+c,180);
		glVertex2f(500+c,150);

		glEnd();
		//3d
    glColor3f(0.0,0.5,0.7);
	glBegin(GL_POLYGON);
        glVertex2f(480+c,170);
		glVertex2f(460+c,205);
		glVertex2f(480+c,215);
		glVertex2f(500+c,180);

		glEnd();
//lineloop
    glColor3f(0.4,0.4,0.4);
	glBegin(GL_LINE_LOOP);
        glVertex2f(480+c,170);
		glVertex2f(460+c,205);
		glVertex2f(480+c,215);
		glVertex2f(500+c,180);

		glEnd();

			//3d
	  glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);

		glVertex2f(380+c,205);
		glVertex2f(400+c,215);
		glVertex2f(480+c,215);
		glVertex2f(460+c,205);

	glEnd();
	//lineloop

	  glColor3f(0.4,0.4,0.4);
    glBegin(GL_LINE_LOOP);

		glVertex2f(380+c,205);
		glVertex2f(400+c,215);
		glVertex2f(480+c,215);
		glVertex2f(460+c,205);

	glEnd();
//car window
    glColor3f(0.0,0.5,0.7);
    glBegin(GL_POLYGON);

		glVertex2f(380+c,170);
		glVertex2f(380+c,205);
		glVertex2f(460+c,205);
		glVertex2f(460+c,170);

	glEnd();



    glColor3f(0.0,0.4,0.4);
    glBegin(GL_POLYGON);

		glVertex2f(350+c,170);
		glVertex2f(380+c,205);
		glVertex2f(380+c,170);

	glEnd();

glColor3f(0.0,0.4,0.4);
    glBegin(GL_POLYGON);

        glVertex2f(460+c,170);
		glVertex2f(460+c,205);
		glVertex2f(480+c,170);

	glEnd();



//wheel1
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(450+c,135,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(450+c,135,l);

}

//wheel2
    for(l=0;l<=20;l++){
    glColor3f(0.0,0.0,0.0);
    draw_circle(380+c,135,l);

}
    for(l=0;l<=10;l++){
    glColor3f(0.8,0.8,0.8);
    draw_circle(380+c,135,l);

}



//bird
    glColor3f(0.73,0.16,0.96 );
	glBegin(GL_POLYGON);

		glVertex2f(290+b,465+d);
		glVertex2f(320+b,465+d);
		glVertex2f(320+b,450+d);


	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(320+b,475+d);
		glVertex2f(330+b,475+d);
		glVertex2f(320+b,465+d);


	glEnd();

	//

	glBegin(GL_POLYGON);

		glVertex2f(200+b,485+d);
		glVertex2f(230+b,485+d);
		glVertex2f(230+b,470+d);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(230+b,495+d);
		glVertex2f(240+b,495+d);
		glVertex2f(230+b,485+d);


	glEnd();


	//

	glBegin(GL_POLYGON);

		glVertex2f(150+b,485+d);
		glVertex2f(180+b,485+d);
		glVertex2f(180+b,470+d);

	glEnd();

	glBegin(GL_POLYGON);

		glVertex2f(180+b,495+d);
		glVertex2f(190+b,495+d);
		glVertex2f(180+b,485+d);


	glEnd();




//bench1
	glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

		glVertex2f(875,60);
		glVertex2f(875,100);
		glVertex2f(885,100);
		glVertex2f(885,60);

	glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(965,60);
		glVertex2f(965,100);
		glVertex2f(975,100);
		glVertex2f(975,60);

	glEnd();

    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

		glVertex2f(850,85);
		glVertex2f(850,100);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(1000,100);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1000,85);

	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(850,65);
		glVertex2f(850,80);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(1000,80);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1000,65);

	glEnd();



	glBegin(GL_POLYGON);

		glVertex2f(970,20);
		glVertex2f(970,40);
		glVertex2f(980,40);
		glVertex2f(980,20);

	glEnd();
		glBegin(GL_POLYGON);

		glVertex2f(985,40);
		glVertex2f(985,60);
		glVertex2f(995,60);
		glVertex2f(995,40);

	glEnd();

		glBegin(GL_POLYGON);

		glVertex2f(840,20);
		glVertex2f(840,40);
		glVertex2f(850,40);
		glVertex2f(850,20);

	glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(865,30);
		glVertex2f(865,40);
		glVertex2f(875,40);
		glVertex2f(875,30);

	glEnd();
	    glBegin(GL_POLYGON);

		glVertex2f(830,40);
		glVertex2f(850,60);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(1000,60);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(980,40);

	glEnd();

//lineloop
	    glColor3f(0.8,0.8,0.8);
	glBegin(GL_LINE_LOOP);

		glVertex2f(850,85);
		glVertex2f(850,100);
		glVertex2f(1000,100);
		glVertex2f(1000,85);

	glEnd();
glBegin(GL_LINE_LOOP);
		glVertex2f(850,65);
		glVertex2f(850,80);
		glVertex2f(1000,80);
		glVertex2f(1000,65);

	glEnd();

    glBegin(GL_LINE_LOOP);

		glVertex2f(830,40);
		glVertex2f(850,60);
		glVertex2f(1000,60);
		glVertex2f(980,40);

	glEnd();
//bench2
	glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

		glVertex2f(375,60);
		glVertex2f(375,100);
		glVertex2f(385,100);
		glVertex2f(385,60);

	glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(465,60);
		glVertex2f(465,100);
		glVertex2f(475,100);
		glVertex2f(475,60);

	glEnd();

    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

		glVertex2f(350,85);
		glVertex2f(350,100);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(500,100);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(500,85);

	glEnd();
glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(350,65);
		glVertex2f(350,80);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(500,80);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(500,65);

	glEnd();

glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

		glVertex2f(470,20);
		glVertex2f(470,40);

		glVertex2f(480,40);
		glVertex2f(480,20);

	glEnd();
	glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);

		glVertex2f(485,40);
		glVertex2f(485,60);
		glVertex2f(495,60);
		glVertex2f(495,40);

	glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

		glVertex2f(330,40);
		glVertex2f(350,60);
		glColor3f(0.8,0.8,0.8);
		glVertex2f(500,60);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(480,40);

	glEnd();
glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);

		glVertex2f(340,20);
		glVertex2f(340,40);
		glVertex2f(350,40);
		glVertex2f(350,20);

	glEnd();

        glBegin(GL_POLYGON);

		glVertex2f(365,30);
		glVertex2f(365,40);
		glVertex2f(375,40);
		glVertex2f(375,30);

	glEnd();




//stamp light2
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(140,90);
		glVertex2f(140,220);
        glVertex2f(150,220);
		glVertex2f(150,90);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(120,170);
		glVertex2f(120,180);
        glVertex2f(170,180);
		glVertex2f(170,170);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(110,170);
		glVertex2f(110,210);
        glVertex2f(120,210);
		glVertex2f(120,170);

		glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(170,170);
		glVertex2f(170,210);
        glVertex2f(180,210);
		glVertex2f(180,170);

		glEnd();

//lights

for(l=0;l<=20;l++){
    glColor3f(s1,s2,s3);
    draw_circle(145,240,l);

}
for(l=0;l<=15;l++){
    glColor3f(s1,s2,s3);
    draw_circle(115,215,l);

}
for(l=0;l<=15;l++){
    glColor3f(s1,s2,s3);
    draw_circle(175,215,l);

}

}



void move()
{

  n-=1;
    m+=0.2;

    c+=1;
    if(c==1200)
        c=0;
    a-=1;
    if(a==-1200)
        a=0;

    b+=1;
    d+=0.6;

    s+=1;
    if(s==1200)
        s=0;

glutPostRedisplay();

}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {

case 'd':
	case 'D':
		day=1;
		//p=0.75;
		//q=0.47;
		//r=0.14;
		u=1.0;
		v=0.2;
		w=0.2;
		s1=1.0,
		s2=1.0,
		s3=1.0;
		b1=0.0;
		b2=0.5;
		b3=0.7;

		break;

	case 'n':
case 'N':
		day=0;
		u=1.0;
		v=0.5;
		w=0.4;
		s1=0.9;
		s2=0.9;
		s3=0.0;
		b1=0.9;
		b2=0.8;
		b3=0.0;

		break;


		case 'l':
	case 'L':
		e=0.9;
		f=0.9;
		g=0.0;
		break;

		case 'f':
	case 'F':
		e=0.0;
		f=0.0;
		g=0.0;
		break;

    };

}






void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1100.0,0.0,700.0);
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glutSwapBuffers();
    glFlush();
}


int main(int argc,char** argv)
{

    printf("                                                  ");
    printf("City Scenario");
    printf("\n\n");
    printf("Press 'd' or 'D' to make it day. \n\n");
	printf("Press 'n' or 'N' to make it night. \n\n");
	printf("Press 'l' or 'L' to turn On the lights. \n\n");
	printf("Press 'f' or 'F' to turn Off the lights. \n\n");

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("City Scenario");
	glutDisplayFunc(display);
    glutIdleFunc(move);
    glutKeyboardFunc(keyboardFunc);
	myinit();
	glutMainLoop();
	return 0;
}

