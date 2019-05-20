#include<GL/glut.h>
#include<math.h>

void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,1000,0,1000);
}
void circle(int a,int b,int x,int y,int m,int n)
{
     glBegin(GL_LINE_STRIP);
     float t;
     for(int i=a;i<b;i++)
     {
            t=(i*3.142)/180;
            glVertex2i(x+m*cos(t),y+n*sin(t));
     }
     glEnd();
}
void lines(int a,int b,int c,int d)
{
    glBegin(GL_LINES);
    glVertex2i(a,b);
    glVertex2i(c,d);
    glEnd();
}
void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     circle(-60,240,500,400,380,335);//face
     circle(-60,50,500,330,280,230);//right-inner-line
     circle(130,240,500,330,280,230);//left-inner-line
     circle(0,360,410,530,90,110);//left-eye
     circle(0,360,590,530,90,110);//right-eye
     circle(0,360,500,400,50,50);//nose
     circle(0,360,450,530,10,20);//eyeball-left
     circle(0,360,550,530,10,20);//eyeball-right
     circle(180,360,500,270,150,120);//mouth
     lines(350,270,650,270);//mouth1
     lines(500,350,500,270);//middleline
     circle(30,150,500,150,120,80);//tongue
     lines(200,430,400,400);//left-moustache
     lines(200,330,400,350);//left-moustache
     lines(800,430,600,400);//right-moustache
     lines(800,330,600,350);//right-moustache
      glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("doraemon");
    init();
	glutDisplayFunc(display);
	glutMainLoop();
}
