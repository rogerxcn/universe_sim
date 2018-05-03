#include "common.hpp"

/*--------------------------------------------------------------------------
Global variables
--------------------------------------------------------------------------*/
// All essential time and axis info
Info info;

// All textures are loaded to these global variabless
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

int window_x = 1024;
int window_y = 768;

float theta = 0;
float phi = 10;
float r = 600;

float eye_x, eye_y, eye_z;

float c_x = 0;
float c_y = 0;
float c_z = 0;

float u_x = 0;
float u_y = 0;
float u_z = 1;

bool torus = false;
/*--------------------------------------------------------------------------
function prototypes
--------------------------------------------------------------------------*/
void step();
void display();
void on_reshape(int, int);
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
void change_perspective();

/*--------------------------------------------------------------------------
Main function
----------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
    // Initialize OpenGL window
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (window_x, window_y);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Simulator for Hilariously Interesting extraTerrestrial Objects");

    // Load texture
    load_images();

    // Initialize information structure
    memset(&info, 0, sizeof(Info));
    info.axis_y = 0.5;
    info.axis_z = 0.5;
    info.angle = 90;

    // Initialize gl parameters
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_COLOR_MATERIAL);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_BLEND);
//
//    glEnable(GL_POINT_SMOOTH);
//    glHint(GL_POINT_SMOOTH_HINT, GL_LINEAR);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_LINEAR);

    // Set callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(keyboard);

    // Graphic rendering loop
    glutMainLoop();

    // Clean up
    deleteTexture();

    return 0;
}


/*--------------------------------------------------------------------------
section for all display functions
--------------------------------------------------------------------------*/
void display() {
    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    change_perspective();

    // Draw LOTS of things (defined in draw.cpp)
    draw_sun();
    draw_mercury();
    draw_venus();
    draw_earth();
    draw_mars();
    draw_jupiter();
    draw_saturn();
    draw_uranus();
    draw_neptune();

    // Bookkeeping
    step();

    // Show them what you have drawn
    glutSwapBuffers();
}


void step() {
    // Increase time ticks for each planet
    info.year += 0.08;
    info.day += 10;
    info.month += 0.33;
    info.mercury_year += 0.12;
    info.venus_year += 0.1;
    info.mars_year += 0.06;
    info.jupiter_year += 0.05;
    info.saturn_year += 0.04;
    info.uranus_year += 0.03;
    info.neptune_year += 0.01;
    info.sun_day += 100;
    info.mercury_day += 200;
    info.venus_day += 300;
    info.mars_day += 10;
    info.jupiter_day += 4;
    info.saturn_day += 4;
    info.uranus_day += 7;
    info.neptune_day += 7;

    // Bound check
    info.year = (info.year > 360) ? (info.year-360) : info.year;
    info.day = (info.day > 360) ? (info.day-360) : info.day;
    info.month = (info.month > 360) ? (info.month-360) : info.month;
    info.mercury_year = (info.mercury_year > 360) ? (info.mercury_year-360) : info.mercury_year;
    info.venus_year = (info.venus_year > 360) ? (info.venus_year-360) : info.venus_year;
    info.mars_year = (info.mars_year > 360) ? (info.mars_year-360) : info.mars_year;
    info.jupiter_year = (info.jupiter_year > 360) ? (info.jupiter_year-360) : info.jupiter_year;
    info.saturn_year = (info.saturn_year > 360) ? (info.saturn_year-360) : info.saturn_year;
    info.uranus_year = (info.uranus_year > 360) ? (info.uranus_year-360) : info.uranus_year;
    info.neptune_year = (info.neptune_year > 360) ? (info.neptune_year-360) : info.neptune_year;

    glutPostRedisplay();
}

// The drawing functions are so lengthy that I put them to an individual cell for aesthetic consideration
#include "draw.cpp"


/*---------------------------------------------------------------------------
Section for all call backs
-----------------------------------------------------------------------------*/
// If any naughty boy dared to drag the arrow
void on_reshape(int w, int h) {
    window_x = w;
    window_y = h;
    glViewport(0, 0, (GLsizei)window_x, (GLsizei)window_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(info.angle, (GLfloat)window_x / (GLfloat)window_y, 1, 100000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -50);
}

void change_perspective() {
    eye_x = r * cos(theta / 180 * PI) * cos(phi / 180 * PI);
    eye_y = r * sin(theta / 180 * PI) * cos(phi / 180 * PI);
    eye_z = r * sin(phi / 180 * PI);
    glViewport(0, 0, (GLsizei)window_x, (GLsizei)window_y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(info.angle, (GLfloat)window_x / (GLfloat)window_y, 1, 100000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -50);
    gluLookAt( eye_x, eye_y, eye_z, c_x, c_y, c_z, u_x, u_y, u_z);
}

// Or if someone just want to get another perspective
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'Q':
        case 'q':
            theta += 10;
            break;
        case 'E':
        case 'e':
            theta -= 10;
            break;
        case 'Z':
        case 'z':
            if (phi < 80)
                phi += 10;
            break;
        case 'C':
        case 'c':
            if (phi > -80)
                phi -= 10;
            break;
        case 'W':
        case 'w':
            r -= 100.0;
            break;
        case 'S':
        case 's':
            r += 100.0;
            break;
        case 'T':
        case 't':
            torus = !torus;
            break;
    }

    glutPostRedisplay();
}

/*---------------------------------------------------------------------------
Other helper functions
-----------------------------------------------------------------------------*/
// Sadly, the program does not have any friends. So surely there won't be any helpers.