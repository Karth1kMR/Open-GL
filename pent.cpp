#include<GL/glut.h>
float q,t,r,a;
float angle=0;
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glOrtho(-300,300,-100,200,-500,500);
    glEnable(GL_DEPTH_TEST);
}
void spin()
{
    if(angle<360)
    {
        angle+=0.05;
    }
    else
        angle=0;
}
void display()
{
    GLUquadric *quad;
    quad=gluNewQuadric();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(105,1,0,0);
    glPushMatrix();
    glRotatef(angle,0,0,1);
    glColor3f(0,0,1);
        
    glBegin(GL_POLYGON);
    gluCylinder(quad,150.0f,150.0f,15.0f,32,32);
    glEnd();
    for(t=-15,r=150.0,a=20,q=0.5;r>=30.0;t-=15,r-=30,a+=20,q+=0.1)
    {
        //glPushMatrix();
        glLoadIdentity();
        glColor3f(0.2,0.2,q);
        glTranslatef(0,0,t);
        glRotatef(a,0,0,1);
        glBegin(GL_POLYGON);
        gluCylinder(quad,r,r,15,5,20);
        glEnd();
        //glPopMatrix();
    }
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
	glutCreateWindow("pent");
    init();
    glutIdleFunc(spin);
	glutDisplayFunc(display);
	glutMainLoop();
}
