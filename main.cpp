#include "common.hpp"

/*--------------------------------------------------------------------------
Global variables
--------------------------------------------------------------------------*/
Info info;
unsigned char* sunTexture;
unsigned char* mercuryTexture;
unsigned char* venusTexture;
unsigned char* earthTexture;
unsigned char* marsTexture;
unsigned char* jupiterTexture;
unsigned char* saturnTexture;
unsigned char* uranusTexture;
unsigned char* neptuneTexture;
unsigned int height_mer, width_mer;
unsigned int height_ear, width_ear;
unsigned int height_j, width_j;
unsigned int height_mars, width_mars;
unsigned int height_nep, width_nep;
unsigned int height_sat, width_sat;
unsigned int height_sun,width_sun;
unsigned int height_ur, width_ur;
unsigned int height_ven, width_ven;

GLuint textureID_sun, textureID_mer, textureID_j, textureID_ear, textureID_mars, textureID_nep, textureID_sat, textureID_ur, textureID_ven;

/*--------------------------------------------------------------------------
function headers
--------------------------------------------------------------------------*/
void init();
void step();
void calcLightPos();
void display();
void idle();
void reshape(int, int);
void keyboard(unsigned char, int, int);
void draw_sun();
void draw_mercury();
void draw_venus();
void draw_earth();
void draw_mars();
void draw_jupiter();
void draw_saturn();
void draw_uranus();
void draw_neptune();
void load_images();
void deleteTexture();

/*--------------------------------------------------------------------------
Main function
----------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Universe Sim");

    load_images();

    memset(&info, 0, sizeof(Info));
    info.l_rad = 8.0;
    info.axis_y = 0.5;
    info.axis_z = 0.5;
    info.angle = 80;

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    deleteTexture();
    return 0;
}


/*--------------------------------------------------------------------------
section for all display functions
--------------------------------------------------------------------------*/
void init() {
    glClearColor(0, 0, 0, 0);
    //calcLightPos();
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void display() {
    //calcLightPos();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    draw_sun();
    draw_mercury();
    draw_venus();
    draw_earth();
    draw_mars();
    draw_jupiter();
    draw_saturn();
    draw_uranus();
    draw_neptune();

    step();

    glutSwapBuffers();
}


void step() {
    info.year += 0.08;
    info.year = (info.year > 360) ? (info.year-360) : info.year;

    info.month += 0.03;
    info.month = (info.month > 360) ? (info.month-360) : info.month;

    info.mercury_year += 0.12;
    info.mercury_year = (info.mercury_year > 360) ? (info.mercury_year-360) : info.mercury_year;

    info.venus_year += 0.1;
    info.venus_year = (info.venus_year > 360) ? (info.venus_year-360) : info.venus_year;

    info.mars_year += 0.06;
    info.mars_year = (info.mars_year > 360) ? (info.mars_year-360) : info.mars_year;

    info.jupiter_year += 0.05;
    info.jupiter_year = (info.jupiter_year > 360) ? (info.jupiter_year-360) : info.jupiter_year;

    info.saturn_year += 0.04;
    info.saturn_year = (info.saturn_year > 360) ? (info.saturn_year-360) : info.saturn_year;

    info.uranus_year += 0.03;
    info.uranus_year = (info.uranus_year > 360) ? (info.uranus_year-360) : info.uranus_year;

    info.neptune_year += 0.01;
    info.neptune_year = (info.neptune_year > 360) ? (info.neptune_year-360) : info.neptune_year;

    glutPostRedisplay();
}


void idle() {
    info.day += 10;
    info.day = (info.day > 360) ? (info.day-360) : info.day;

    glutPostRedisplay();
}

#include "draw.cpp"

/*---------------------------------------------------------------------------
Section for all call backs
-----------------------------------------------------------------------------*/
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(info.angle, (GLfloat)w / (GLfloat)h, 1, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -50);
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'U':
        case 'u':
            info.axis_y -= 0.1;
            info.axis_z += 0.1;
            break;
        case 'D':
        case 'd':
            info.axis_y += 0.1;
            info.axis_z -= 0.1;
            break;
    }

    glutPostRedisplay();
}

/*---------------------------------------------------------------------------
Other helper functions
-----------------------------------------------------------------------------*/
void calcLightPos() {
    float y = info.l_rad * cos(info.l_angle);
    float z = info.l_rad * sin(info.l_angle);
    float l_pos[4] = {3, y, z, 0};
    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
}
