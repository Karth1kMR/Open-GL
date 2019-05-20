#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
float pk,r;
int xc,yc;
void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,600,0,600);
}
void draw_pixel(int x,int y)
{
      glBegin(GL_POINTS);
      glVertex2f(x+xc,y+yc);
      glEnd();
}
void display()
{
     int x=0,y=r;
     glClear(GL_COLOR_BUFFER_BIT);
     pk=5/4-r;
     draw_pixel(x,y);
     while(y>x)
     {
        if(pk<0)
        {
            x++;
            pk=pk+2*x+1;
        }
        else
        {
            y--;
            x++;
            pk=pk+2*(x-y)+1;
        }
        draw_pixel(x,y);
        draw_pixel(x,-y);
        draw_pixel(-x,y);
        draw_pixel(-x,-y);
        draw_pixel(y,x);
        draw_pixel(-y,x);
        draw_pixel(y,-x);
        draw_pixel(-y,-x);
     }
     glFlush();
}
int main(int argc,char **argv)
{
    	glutInit(&argc,argv);
    	printf("Enter the radius\n");
    	scanf("%f",&r);
    	printf("Enter the center values\n");
    	scanf("%d%d",&xc,&yc);
   	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("mid");
    	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
          
