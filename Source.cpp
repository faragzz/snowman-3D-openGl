#include<windows.h>
#include<GL/freeglut.h>

int delay = 1000 / 75;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
double shiftXaxis = 0.0;
double shiftZaxis = 0.0;

double shiftCubeX = 0.0;
double shiftCubeZ = 0.0;

double moveSpeed = 0.01;
double snowManMove = 0;

float eyeX = 0;
float eyeY = -0.2;
float eyeZ = -0.5;
float upX = 0;
float upY = 1;
float upZ = 0;

float x = 5;
float x1 = -5;

float shiftworldX = 0;
float shiftworldY = 0;
float shiftworldZ = 0;




void color(float R, float G, float B) {
    glColor3f(1.0f*R/255.0, 1.0f*G/255.0, 1.0f*B/255.0);
}

void reshapeFunc(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(0, -1, -1);
    glRotatef(-30, 1, 0, 0);
    gluPerspective(60.0, 2, 1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
void texture(void) {

    const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void MyInit(){
    glClearColor(0,0.07,0.05,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Perspective Projection
    glFrustum(-1 , 1 , -1 , 1 , 2 , 10);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,0,0);
}

void square() {

    //front
    color(245, 226, 149);
    glVertex3f(-1.0 + x, 1.0, 1.0);
    glVertex3f(-1.0 + x, -1.0, 1.0);
    glVertex3f(1.0 + x, -1.0, 1.0);
    glVertex3f(1.0 + x, 1.0, 1.0);
    //back
    color(245, 226, 149);
    glVertex3f(1.0 + x, 1.0, -1.0);
    glVertex3f(1.0 + x, -1.0, -1.0);
    glVertex3f(-1.0 + x, -1.0, -1.0);
    glVertex3f(-1.0 + x, 1.0, -1.0);
    //right
    color(245, 226, 149);
    glVertex3f(1.0 + x, 1.0, 1.0);
    glVertex3f(1.0 + x, -1.0, 1.0);
    glVertex3f(1.0 + x, -1.0, -1.0);
    glVertex3f(1.0 + x, 1.0, -1.0);
    //left
    color(245, 226, 149);
    glVertex3f(-1.0 + x, 1.0, -1.0);
    glVertex3f(-1.0 + x, -1.0, -1.0);
    glVertex3f(-1.0 + x, -1.0, 1.0);
    glVertex3f(-1.0 + x, 1.0, 1.0);
    //top
    color(245, 226, 149);
    glVertex3f(-1.0 + x, 1.0, -1.0);
    glVertex3f(-1.0 + x, 1.0, 1.0);
    glVertex3f(1.0 + x, 1.0, 1.0);
    glVertex3f(1.0 + x, 1.0, -1.0);
    //bottom
    color(245, 226, 149);
    glVertex3f(-1.0 + x, -1.0, -1.0);
    glVertex3f(-1.0 + x, -1.0, 1.0);
    glVertex3f(1.0 + x, -1.0, 1.0);
    glVertex3f(1.0 + x, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}
void triangle() {
    glPushMatrix();
    glRotated(180, 1, 0, 0);
    glRotated(30,0,1,0);
    glTranslatef(-0.5, -1.8, -2);
    glBegin(GL_QUADS);
//front
    color(77, 38, 25);
    glVertex3f(-1.0 + x1,2.0,3.0);
    glVertex3f(0.0 + x1,-2.0,3.0);
    glVertex3f(1.0 + x1,2.0,3.0);
    glVertex3f(1.0 + x1,2.0,3.0);
//right
    color(77, 38, 25);
    glVertex3f(1.0 + x1,2.0,3.0);
    glVertex3f(0.0 + x1,-2.0,3.0);
    glVertex3f(-1 + x1,2.0,1.0);
    glVertex3f(-1 + x1,2.0,1.0);
    //left
    color(77, 38, 25);
    glVertex3f(-1.0 + x1,2.0,3.0);
    glVertex3f(0.0 + x1,-2.0,3.0);
    glVertex3f(-1 + x1,2.0,1.0);
    glVertex3f(-1 + x1,2.0,1.0);
    //base
    color(77, 38, 25);
    glVertex3f(-1.0 + x1,2.0,3.0);
    glVertex3f(1.0 + x1,2.0,3.0);
    glVertex3f(-1 + x1,2.0,1.0);
    glVertex3f(-1 + x1,2.0,1.0);
    glEnd ();
    glPopMatrix();
}
void snowManAnimate() {
    glPushMatrix();
    glTranslated(0 + snowManMove, 0.8, -10 );
    color(219, 218, 230);
    glutSolidSphere(1.1, 20, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0 + snowManMove, 2, -10 );
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0 + snowManMove, 3, -10 );
    glutSolidSphere(0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2 + snowManMove, 3, -9.7 );
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.2 + snowManMove, 3, -9.7 );
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.01 + snowManMove, 2.9, -9.6 );
    color(245, 127, 59);
    glutSolidCone(0.08, 0.2, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45 + snowManMove, 2.5, -10 );
    color(0, 0, 0);
    glRotatef(90, 1, 1, 0);
    glutSolidCylinder(0.08, 1.7, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5 + snowManMove, 2.5, -10 );
    color(0, 0, 0);
    glRotatef(270, 1, 1, 0);
    glutSolidCylinder(0.08, 1.7, 10, 10);
    glPopMatrix();

}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(shiftworldX, shiftworldY, shiftworldZ);
    glPushMatrix();

    glTranslatef(0.0, -1, 0.0);
    color(128, 127, 130);
    glScalef(30, 1, 40);
    glutSolidCube(0.6);

    glPopMatrix();

    glPushMatrix();
    glTranslated(0+ shiftXaxis, 0.8, -10+ shiftZaxis);
    color(219, 218, 230);
    glutSolidSphere(1.1,20,20);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0 + shiftXaxis, 2, -10 + shiftZaxis);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0 + shiftXaxis, 3, -10 + shiftZaxis);
    glutSolidSphere(0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2+ shiftXaxis, 3, -9.7+ shiftZaxis);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.2 + shiftXaxis, 3, -9.7 + shiftZaxis);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.01 + shiftXaxis, 2.9, -9.6 + shiftZaxis);
    color(245, 127, 59);
    glutSolidCone(0.08,0.2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45 + shiftXaxis, 2.5, -10 + shiftZaxis);
    color(0, 0, 0);
    glRotatef(90,1,1,0);
    glutSolidCylinder(0.08,1.7,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5 + shiftXaxis, 2.5, -10 + shiftZaxis);
    color(0, 0, 0);
    glRotatef(270, 1, 1, 0);
    glutSolidCylinder(0.08, 1.7, 10, 10);
    glPopMatrix();

    snowManAnimate();

    glPushMatrix();
    glBegin(GL_QUADS);
    glScalef(0, 0, -1);
    glTranslatef(5,0,0);
    square();
    triangle();
    glutSwapBuffers();

}

void idleFunc(void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);


    snowManMove += moveSpeed;
    if (snowManMove > 5 || snowManMove < -5) {
        moveSpeed = -moveSpeed;
    }

}
void normalinput(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
       shiftworldZ  ++;
        break;
    case 's':
        shiftworldZ --;
        break;
    case 'd':
        shiftworldX--;
        break;
    case 'a':
        shiftworldX++;
        break;
    case 'q':
        shiftworldY--;
        break;
    case 'e':
        shiftworldY++;
        break;
    }
}
void specialinput(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        shiftXaxis --;
        break;
    case GLUT_KEY_RIGHT:
        shiftXaxis ++;
        break;
    case GLUT_KEY_UP:
        shiftZaxis--;
        break;

    case GLUT_KEY_DOWN:
        shiftZaxis++;
        break;
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(700, 200);
    glutCreateWindow("Ahmed Khaled Farag 20109481");
    glClearColor(1.0, 1.0, 1.0, 0.0);

    MyInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(normalinput);
    glutSpecialFunc(specialinput);
    glutIdleFunc(idleFunc);
    glutTimerFunc(0, timer, 0);


    glClearColor(119/255.0, 127/255.0, 242/255.0, 1.0);
    texture();
    PlaySound(TEXT("x.wav"), NULL, SND_ASYNC);
    glutMainLoop();
    
}