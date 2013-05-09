#include <GL/glut.h>

#include <stdlib.h>
#define red1 0
#define green1 1
#define blue1 1
#define red2 1
#define green2 0
#define blue2 0
#define amount 5000
#define distance 12
#define radius 0.001
#define fresnel 0.9
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
       
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    static int a;
   
   for(a=0;a<amount;a++) {
    glPushMatrix();
        glTranslated(0,0,-20-a);
        glColor3f(red1*(amount-a*fresnel)/amount+red2*a/amount*fresnel,green1*(amount-a*fresnel)/amount+green2*a/amount*fresnel,blue1*(amount-a*fresnel)/amount+blue2*a/amount*fresnel);
        glutSolidSphere(radius+a*0.1,16,16);
    glPopMatrix();
} 

    
        glutSwapBuffers();
}

static void 
idle(void)
{
    glutPostRedisplay();
}


    
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024,768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Fresnel");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    

    glutMainLoop();

    return EXIT_SUCCESS;
}
