#include<GL/glut.h>
#include<stdio.h>
int x1,y1,x2,y2;
void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
bres(int x1,int x2,int y1, int y2)
{
	int dx,dy,i,p;
	int incx,incy,inc1,inc2;
	int x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	incx = 1;
	if(x2<x1)
	{
		incx = -1;
		incx = 1;
	}
	if(y2<y1)
		incy=1;
	x=x2;
	y=y1;
	if(dx>dy)
	{
		draw_pixel(x,y);
		p=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(i=0;i<dx;i++)
		{
			if(p>=0)
			{
				y+=incy;
				p+=inc1;
			}
			else
			{
				p+=inc2;
				x+=incx;
				draw_pixel(x,y);
			}
		}
	}
	else
	{
			draw_pixel(x,y);
			p=2*dx-dy;
			inc1 = 2*(dx-dy);
			inc2 = 2*dx;
			for(i=0;i<dy;i++)
			{
				if(p>=0)
			{
				x+=incx;
				p+=inc1;
			}
			else
			{
				p+=inc2;
				y+=incy;
				draw_pixel(x,y);
			}
		}
	}
	}
	void display()
	{
		bres(x1,x2,y1,y2);
		glFlush();
	}
	void myInit()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0,0.0,0.0,1.0);
		glColor3f(0.0,1.0,0.0);
		glPointSize(4.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0,499.0,0.0,499.0);
	}
	void main(int argc,char **argv)
	{
	printf("enter the values : ");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1367, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" first lab program");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	}
		
		
		
		
		
		
