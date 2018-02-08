//David Xie

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

struct shape {
    int x[4];
    int y[4];
    GLfloat r = 1.0;
    GLfloat g = 1.0;
    GLfloat b = 1.0;
    int type;
    int points;
};

shape shapes[720];
int count = 0;

void drawRectangle(shape s){
    int gl_mode;
    if(s.type == 0)
        gl_mode = GL_POLYGON;
    if(s.type == 1)
        gl_mode = GL_LINE_LOOP;

    glBegin (gl_mode);
    glColor3f (s.r, s.g, s.b);

    glVertex3f (s.x[0], s.y[0], 0.0);
    glVertex3f (s.x[1], s.y[0], 0.0);
    glVertex3f (s.x[1], s.y[1], 0.0);
    glVertex3f (s.x[0], s.y[1], 0.0);

    glEnd ();
}

void drawLine(shape s){
    glBegin (GL_LINES);
    glColor3f (s.r, s.g, s.b);

    glVertex3f (s.x[0], s.y[0], 0.0);
    glVertex3f (s.x[1], s.y[1], 0.0);
    glEnd ();
}

void drawEllipse(shape s){
    int gl_mode;
    if(s.type == 2)
        gl_mode = GL_POLYGON;
    if(s.type == 3)
        gl_mode = GL_LINE_LOOP;

    glBegin (gl_mode);
    glColor3f (s.r, s.g, s.b);

    for(double i=0; i<2*M_PI; i+=2*M_PI/360){
        int x = s.x[0]+(s.x[1]-s.x[0])*cos(i);
        int y = s.y[0]+(s.y[1]-s.y[0])*sin(i);
        glVertex3f (x, y, 0.0);
    }
    glEnd ();
}

void drawBezier(shape s){

    glBegin (GL_LINE_STRIP);
    glColor3f (s.r, s.g, s.b);

    for(float i=0; i<1.0; i+=0.01){
        GLfloat x = 0.0;
        GLfloat y = 0.0;

        x += pow((1-i),3)*s.x[0]*pow(i,0);
        y += pow((1-i),3)*s.y[0]*pow(i,0);

        x += pow((1-i),2)*s.x[1]*3*pow(i,1);
        y += pow((1-i),2)*s.y[1]*3*pow(i,1);

        x += pow((1-i),1)*s.x[2]*3*pow(i,2);
        y += pow((1-i),1)*s.y[2]*3*pow(i,2);

        x += pow((1-i),0)*s.x[3]*pow(i,3);
        y += pow((1-i),0)*s.y[3]*pow(i,3);

        glVertex3f (x, y, 0.0);
    }
    glEnd();
}

void mouse(int button, int state, int x, int y){

    if(state != 0)return;
    if(button != 2)return;
    int num = 0;
    if (shapes[count].type == 5)
        num = 4;
    else
        num =2;
    if(shapes[count].points < num){
        shapes[count].x[shapes[count].points] = x;
        shapes[count].y[shapes[count].points] = y;
        shapes[count].points++;
        if(shapes[count].points == num){
            count++;
        }
    }
}

void mainMenu(int i){

    if (i == 1){
        shapes[count].type = 0;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 2){
        shapes[count].type = 0;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 3){
        shapes[count].type = 0;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 4){
        shapes[count].type = 0;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 5){
        shapes[count].type = 0;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 6){
        shapes[count].type = 0;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 7){
        shapes[count].type = 0;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 8){
        shapes[count].type = 0;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 9){
        shapes[count].type = 1;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 10){
        shapes[count].type = 1;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 11){
        shapes[count].type = 1;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 12){
        shapes[count].type = 1;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 13){
        shapes[count].type = 1;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 14){
        shapes[count].type = 1;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 15){
        shapes[count].type = 1;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 16){
        shapes[count].type = 1;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 17){
        shapes[count].type = 2;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 18){
        shapes[count].type = 2;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 19){
        shapes[count].type = 2;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 20){
        shapes[count].type = 2;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 21){
        shapes[count].type = 2;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 22){
        shapes[count].type = 2;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 23){
        shapes[count].type = 2;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 24){
        shapes[count].type = 2;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 25){
        shapes[count].type = 3;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 26){
        shapes[count].type = 3;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 27){
        shapes[count].type = 3;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 28){
        shapes[count].type = 3;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 29){
        shapes[count].type = 3;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 30){
        shapes[count].type = 3;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 31){
        shapes[count].type = 3;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 32){
        shapes[count].type = 3;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 33){
        shapes[count].type = 4;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 34){
        shapes[count].type = 4;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 35){
        shapes[count].type = 4;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 36){
        shapes[count].type = 4;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 37){
        shapes[count].type = 4;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 38){
        shapes[count].type = 4;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 39){
        shapes[count].type = 4;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 40){
        shapes[count].type = 4;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 41){
        shapes[count].type = 5;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }else if (i == 42){
        shapes[count].type = 5;
        shapes[count].r = 0.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 43){
        shapes[count].type = 5;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 44){
        shapes[count].type = 5;
        shapes[count].r = 1.0;
        shapes[count].g = 1.0;
        shapes[count].b = 0.0;
    }else if (i == 45){
        shapes[count].type = 5;
        shapes[count].r = 1.0;
        shapes[count].g = 0.0;
        shapes[count].b = 1.0;
    }else if (i == 46){
        shapes[count].type = 5;
        shapes[count].r = 1.0;
        shapes[count].g = 0.5;
        shapes[count].b = 0.0;
    }else if (i == 47){
        shapes[count].type = 5;
        shapes[count].r = 0.5;
        shapes[count].g = 0.5;
        shapes[count].b = 0.5;
    }else if (i == 48){
        shapes[count].type = 5;
        shapes[count].r = 0.0;
        shapes[count].g = 0.0;
        shapes[count].b = 0.0;
    }
    shapes[count].points = 0;
}

void display(){
    glClear (GL_COLOR_BUFFER_BIT);

    for(int i=0; i<count; i++){
        if(shapes[i].points == 2){
            if (shapes[i].type == 0 || shapes[i].type == 1)
                drawRectangle(shapes[i]);
            else if (shapes[i].type == 2 || shapes[i].type == 3)
                drawEllipse(shapes[i]);
            else if (shapes[i].type == 4)
                drawLine(shapes[i]);
        }
        if(shapes[i].points == 4 && shapes[i].type == 5){
            drawBezier(shapes[i]);
        }
    }
    glFlush();
}


void reshape(int x, int y){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, x, y, 0.0);
	glMatrixMode(GL_MODELVIEW);
}

void init(){

    glClearColor(1.0, 1.0, 1.0, 1.0);

    int filledRectangleMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 1);
    glutAddMenuEntry("green", 2);
    glutAddMenuEntry("blue", 3);
    glutAddMenuEntry("yellow", 4);
    glutAddMenuEntry("purple", 5);
    glutAddMenuEntry("orange", 6);
    glutAddMenuEntry("gray", 7);
    glutAddMenuEntry("black", 8);

    int outlineRectangleMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 9);
    glutAddMenuEntry("green", 10);
    glutAddMenuEntry("blue", 11);
    glutAddMenuEntry("yellow", 12);
    glutAddMenuEntry("purple", 13);
    glutAddMenuEntry("orange", 14);
    glutAddMenuEntry("gray", 15);
    glutAddMenuEntry("black", 16);

    int filledEllipseMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 17);
    glutAddMenuEntry("green", 18);
    glutAddMenuEntry("blue", 19);
    glutAddMenuEntry("yellow", 20);
    glutAddMenuEntry("purple", 21);
    glutAddMenuEntry("orange", 22);
    glutAddMenuEntry("gray", 23);
    glutAddMenuEntry("black", 24);

    int outlineEllipseMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 25);
    glutAddMenuEntry("green", 26);
    glutAddMenuEntry("blue", 27);
    glutAddMenuEntry("yellow", 28);
    glutAddMenuEntry("purple", 29);
    glutAddMenuEntry("orange", 30);
    glutAddMenuEntry("gray", 31);
    glutAddMenuEntry("black", 32);

    int lineMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 33);
    glutAddMenuEntry("green", 34);
    glutAddMenuEntry("blue", 35);
    glutAddMenuEntry("yellow", 36);
    glutAddMenuEntry("purple", 37);
    glutAddMenuEntry("orange", 38);
    glutAddMenuEntry("gray", 39);
    glutAddMenuEntry("black", 40);

    int bezierMenu = glutCreateMenu(mainMenu);
    glutAddMenuEntry("red", 41);
    glutAddMenuEntry("green", 42);
    glutAddMenuEntry("blue", 43);
    glutAddMenuEntry("yellow", 44);
    glutAddMenuEntry("purple", 45);
    glutAddMenuEntry("orange", 46);
    glutAddMenuEntry("gray", 47);
    glutAddMenuEntry("black", 48);

    int rectangleMenu = glutCreateMenu(mainMenu);
    glutAddSubMenu("filled", filledRectangleMenu);
    glutAddSubMenu("outline", outlineRectangleMenu);

    int ellipseMenu = glutCreateMenu(mainMenu);
    glutAddSubMenu("filled", filledEllipseMenu);
    glutAddSubMenu("outline", outlineEllipseMenu);

    int initialMenu = glutCreateMenu(mainMenu);
    glutAddSubMenu("add rectangle", rectangleMenu);
    glutAddSubMenu("add ellipse", ellipseMenu);
    glutAddSubMenu("add line", lineMenu);
    glutAddSubMenu("add bezier curve", bezierMenu);

    glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main (int argc, char **argv){

	glutInit (&argc, argv);
	glutInitWindowSize (720, 480);
	glutCreateWindow ("Window");

    init();

    glutDisplayFunc (display);
	glutMouseFunc (mouse);
	glutReshapeFunc (reshape);

	glutMainLoop ();
}
