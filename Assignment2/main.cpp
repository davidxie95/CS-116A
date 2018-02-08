//David Xie

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

struct Vector{
    GLfloat v[3];
};
Vector terrain[10000];

int x = 100;
int y = 100;
int z = 100;

GLdouble eyeX = 50.0f;
GLdouble eyeY = 5.0f;
GLdouble eyeZ = 0.0f;
GLdouble centerX = 50.0f;
GLdouble centerY = 5.0f;
GLdouble centerZ = 50.0f;

void init(){
    //create random triangles
    for(int i=0; i<z; i++){
        for(int j=0; j<x; j++){
            terrain[j*x+i].v[0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + float(i);
            terrain[j*x+i].v[1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            terrain[j*x+i].v[2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + float(j);
        }
    }
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0f, 1.0f, 0.0f);
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0); //white space
    glColor3f(0.0,0.0,0.0); //black lines
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    //draw the triangles
    for(int i=0; i<z-1; i++){
        for(int j=0; j< x-1; j++){
            glVertex3f(terrain[i*z+j].v[0], terrain[i*z+j].v[1], terrain[i*z+j].v[2]);
            glVertex3f(terrain[i*z+j+1].v[0], terrain[i*z+j+1].v[1], terrain[i*z+j+1].v[2]);
            glVertex3f(terrain[(i+1)*z+j].v[0], terrain[(i+1)*z+j].v[1], terrain[(i+1)*z+j].v[2]);
        }
    }
    glEnd();

    glutSwapBuffers();
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0f, 1.0f, 0.0f);
}

void reshape(int x, int y){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, (GLfloat)x/y, 0.0f, 720.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard (unsigned char key, int x, int y){
    switch (key){
        case 'a':
            if(eyeY > 10)
                break;
            eyeY += 0.1f;
            centerY += 0.1f;
            display();
            break;
        case 'z':
            if(eyeY < 1)
                break;
            eyeY -= 0.1f;
            centerY -= 0.1f;
            display();
            break;
    }
}

void special (int key, int x, int y){
    switch (key){
        case GLUT_KEY_LEFT:
            if(eyeX > 95)
                break;
            eyeX += 0.1f;
            centerX += 0.1f;
            display();
            break;
        case GLUT_KEY_RIGHT:
            if(eyeX < 5)
                break;
            eyeX -= 0.1f;
            centerX -= 0.1f;
            display();
            break;
        case GLUT_KEY_UP:
            if(eyeZ > 75)
                break;
            eyeZ += 0.1f;
            centerZ += 0.1f;
            display();
            break;
        case GLUT_KEY_DOWN:
            if(eyeZ <= 0.0)
                break;
            eyeZ -= 0.1f;
            centerZ -= 0.1f;
            display();
            break;
    }
}

int main (int argc, char **argv){

	glutInit (&argc, argv);
	glutInitWindowSize (720, 480);
	glutCreateWindow ("Window");

    init();
    display();

    glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);

	glutMainLoop ();
}
