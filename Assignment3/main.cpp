#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

struct Vector{
    GLfloat v[3];
};

Vector vertices[8192];
Vector faces[8192];

int count = 0;
int GL_MODE;

GLdouble eyeX = 0.0f;
GLdouble eyeY = 0.0f;
GLdouble eyeZ = 0.5f;

void init(const char *filename){

    FILE *file;
    file = fopen(filename, "r");

    char ch;
    int line, i = 0;
    GLfloat x, y, z;

    if(file == NULL){
        printf("Error 404 not found: %s\n", filename);
        exit(0);
    }

    while(!(feof(file))){
            line=fscanf(file,"%c %f %f %f", &ch, &x, &y, &z);
            if(line == 4 && ch =='v'){
                //store all vertex
                vertices[i].v[0] = x;
                vertices[i].v[1] = y;
                vertices[i].v[2] = z;
                i++;
            }else if(line == 4 && ch =='f'){
                //store all face
                faces[count].v[0] = x;
                faces[count].v[1] = y;
                faces[count].v[2] = z;
                count++;
            }
        }

    fclose(file);

    gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f); //yellow rabbit

    glPolygonMode(GL_FRONT_AND_BACK, GL_MODE);
    glBegin(GL_TRIANGLES);

    for(int i = 0; i < count; i++){
            for(int j = 0; j < 3; j++){
                //add the three points from vertex per face
                glVertex3f(vertices[(int) faces[i].v[j] - 1].v[0],
                           vertices[(int) faces[i].v[j] - 1].v[1],
                           vertices[(int) faces[i].v[j] - 1].v[2]);
            }
        }

    glEnd();

    glutSwapBuffers();
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.1f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void reshape(int x, int y){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, (GLfloat)x/y, 0.0f, 720.0f);
    glMatrixMode(GL_MODELVIEW);
}

void wire(){
    GL_MODE = GL_LINE;
    display();
}
void solid(){
    GL_MODE = GL_FILL;
    display();
}

void keyboard (unsigned char key, int x, int y){
    switch (key){
        case 'w':
            wire();
            break;
        case 's':
            solid();
            break;
    }
}

void special (int key, int x, int y){
    switch (key){
        case GLUT_KEY_UP:
            //camera closer
            eyeX *= 0.99f;
            eyeZ *= 0.99f;
            display();
            break;
        case GLUT_KEY_DOWN:
            //camera away
            eyeX *= 1.01f;
            eyeZ *= 1.01f;
            display();
            break;
        case GLUT_KEY_LEFT:
            //camera counter clockwise
            eyeX = eyeX*cos(0.01) - eyeZ*sin(0.01);
            eyeZ = eyeZ*cos(0.01) + eyeX*sin(0.01);
            display();
            break;
        case GLUT_KEY_RIGHT:
            //camera clockwise
            eyeX = eyeX*cos(-0.01) + eyeZ*sin(0.01);
            eyeZ = eyeZ*cos(-0.01) - eyeX*sin(0.01);
            display();
            break;
    }
}


int main (int argc, char **argv){

	glutInit (&argc, argv);
	glutInitWindowSize (720, 480);
	glutCreateWindow ("Window");

    init("bunny.obj");

    glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);

	glutMainLoop ();
}
