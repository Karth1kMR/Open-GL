#include<GL/glut.h>
#include<math.h>
void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,1000,0,1000);
}
void circle(int a,int b,int x,int y,int r)
{
    float theta;
     
     glBegin(GL_POLYGON);
     for(int i=a;i<b;i++)
     {
            theta=(i*3.142)/180;
            glVertex2i(x+r*cos(theta),y+r*sin(theta));
     }
     glEnd();
}
void lines()
{
    glBegin(GL_LINES);
    glVertex2i(200,1000);
    glVertex2i(200,0);
    glVertex2i(1000,200);
    glVertex2i(0,200);
    glEnd();
}
void semi(int a,int b,int x,int y,int r)
{
    glBegin(GL_LINE_STRIP);
    float teta;
    for(int i=a;i<b;i++)
    {
        teta=(i*3.142)/180;
        glVertex2i(x+r*cos(teta),y+r*sin(teta));
    }
    glEnd();
}
void circle1()
{
     glColor3f(0,0,1);
     circle(0,360,200,500,200);//face of an emoji
     glColor3f(1,1,0);
     circle(0,360,130,550,30);//eye1 
     glColor3f(1,1,0);
     circle(0,360,270,550,30);//eye2
     glColor3f(0,1,1);
     semi(0,180,200,400,80);//expression
}
void circle2()
{
     glColor3f(1,0,0);
     circle(0,360,700,500,200);//face of an emoji
     glColor3f(1,1,0);
     circle(0,360,770,550,30);//eye1 
     glColor3f(1,1,0);
     circle(0,360,630,550,30);//eye2
     glColor3f(0,1,1);
     semi(180,360,700,450,80);//expression
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     circle1();
     
     circle2();
     //glColor3f(1,1,1);
     //lines();
     glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("emoji");
    init();
	glutDisplayFunc(display);
	glutMainLoop();
}
