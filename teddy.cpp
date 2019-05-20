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
     
     glBegin(GL_LINE_STRIP);
     for(int i=a;i<b;i++)
     {
            theta=(i*3.142)/180;
            glVertex2i(x+r*cos(theta),y+r*sin(theta));
     }
     glEnd();
}
void oval(int a,int b,int x,int y,int m,int n)
{
    float theta;
     glBegin(GL_LINE_STRIP);
     for(int i=a;i<b;i++)
     {
            theta=(i*3.142)/180;
            glVertex2i(x+m*cos(theta),y+n*sin(theta));
     }
     glEnd();
}
void cir(int a,int b,int x,int y,int r)
{
      float teta;
     
     glBegin(GL_POLYGON);
     for(int i=a;i<b;i++)
     {
            teta=(i*3.142)/180;
            glVertex2i(x+r*cos(teta),y+r*sin(teta));
     }
     glEnd();
}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     circle(160,382,500,400,350);//face
     circle(8,260,210,710,190);//ear-left
     circle(-74,171,770,710,190);//ear-right
     circle(76,108,500,400,350);//head
     oval(0,360,500,330,80,55);//nose
     oval(180,360,500,250,150,50);//mouth
     oval(189,351,500,220,80,90);//tongue
     oval(0,360,380,470,55,80);//eye-left
     glColor3f(1,1,1);
     oval(0,360,380,450,30,60);//eyeball-left
     glColor3f(1,1,1);
     oval(0,360,620,470,55,80);//eye-right
     glColor3f(1,1,1);
     oval(0,360,620,450,30,60);//eyeball-right
     glColor3f(1,1,1);
     glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("mickey");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
