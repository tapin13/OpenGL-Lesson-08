#include "GL/freeglut.h"
#include "GL/gl.h"

float WinWid = 400.0;
float WinHei = 400.0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
   
    glutSwapBuffers();
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void MenuCheck(int v) {
    switch(v) {
        case 0 : glutSetWindowTitle("Value 0. Lesson 08");
                break;
        case 1 : glutSetWindowTitle("Value 1. Made by tapin13");
                break;
    }
}

void SubMenuCheck(int v) {
    switch(v) {
        case 5 : glutSetWindowTitle("Submenu");
                break;
    }
}

void MenuInit() {
    int M = glutCreateMenu(MenuCheck);
    int Msub = glutCreateMenu(SubMenuCheck);
    glutSetMenu(Msub);
    glutAddMenuEntry("Submenu!", 5);
    glutSetMenu(M);
    glutAddMenuEntry("Made by tapin13", 1);
    glutAddMenuEntry("Lesson 08", 0);
    glutAddSubMenu("Advanced", Msub);
    glutRemoveMenuItem(1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    //glutDetachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 08");
    
    glutDisplayFunc(Draw);
    Initsialaize();
    MenuInit();
    glutMainLoop();
    
    return 0;
}

