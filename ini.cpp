#include<GL/glut.h>

void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,600,0,600);
}
void lines()
{
    glBegin(GL_LINES);
    glVertex2i(200,600);
    glVertex2i(200,0);
    glVertex2i(600,200);
    glVertex2i(0,200);
    glEnd();
}
void box1()
{
    glBegin(GL_POLYGON);
    glVertex2i(200,150);
    glVertex2i(200,450);
    glVertex2i(250,450);
    glVertex2i(250,150);
    glEnd();
}
void box2()
{
    glBegin(GL_POLYGON);
    glVertex2i(200,300);
    glVertex2i(350,450);
    glVertex2i(390,410);
    glVertex2i(200,230);
    glEnd();
}
void box3()
{
    glBegin(GL_POLYGON);
    glVertex2i(200,350);
    glVertex2i(400,190);
    glVertex2i(360,150);
    glVertex2i(200,280);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    box1();
    box2();
    box3();
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("Initials");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
    
