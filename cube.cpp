#include<stdio.h>
#include<GL/glut.h>
 float b=0,i,j,k,m,n,p;
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-600,600,-600,600,-600,600);
    glEnable(GL_DEPTH_TEST);
}
void spin()
{
    if(b<360)
        b+=0.035;
    else
    b=0;
}
void cube()
{
    glutSolidCube(100);
    glRotatef(45,1,1,0);
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            for(int k=0;k<1000;k++)
                glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(b,0,1,0);
    glPushMatrix();
    glRotatef(30,1,0,0);
    for(i=-150;i<=150;i+=150)
        for(j=-150;j<=150;j+=150)
            for(k=-150,p=0.5;k<=150;k+=150,p+=0.1)
            {
                glColor3f(0.2,0.2,p);
                glPushMatrix();
                glTranslatef(i,j,k);
                glutSolidCube(100);
                glPopMatrix();
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
	glutCreateWindow("cube");
    init();
    glutIdleFunc(spin);
	glutDisplayFunc(display);
	glutMainLoop();
}
    
