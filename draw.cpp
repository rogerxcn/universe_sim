#include <windows.h>
#include <stdio.h>
#include <TextureLoader.h>


void load_images(){
    mercuryTexture = loadbmp("../src/mercury.bmp", height_mer, width_mer);
    earthTexture = loadbmp("../src/earth.bmp", height_ear, width_ear);
    jupiterTexture = loadbmp("../src/jupiter.bmp", height_j, width_j);
    marsTexture = loadbmp("../src/mars.bmp", height_mars, width_mars);
    neptuneTexture = loadbmp("../src/neptune.bmp", height_nep, width_nep);
    saturnTexture = loadbmp("../src/saturn.bmp", height_sat, width_sat);
    sunTexture = loadbmp("../src/sun.bmp", height_sun, width_sun);
    uranusTexture = loadbmp("../src/uranus.bmp", height_ur, width_ur);
    venusTexture = loadbmp("../src/venus.bmp", height_ven, width_ven);

    glGenTextures(1, &textureID_sun);
    glGenTextures(1, &textureID_mer);
    glGenTextures(1, &textureID_ven);
    glGenTextures(1, &textureID_ear);
    glGenTextures(1, &textureID_mars);
    glGenTextures(1, &textureID_j);
    glGenTextures(1, &textureID_nep);
    glGenTextures(1, &textureID_sat);
    glGenTextures(1, &textureID_ur);
}
void draw_sun() {
    glPushMatrix();
    //sun object
    GLUquadric* sun = gluNewQuadric();
    //texture
    gluQuadricTexture(sun, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_sun);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    GLuint success = gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_sun, height_sun,GL_BGR_EXT, GL_UNSIGNED_BYTE, sunTexture);
    if(success != 0){
        std::cout<< "fail to mipmap texture" << std::endl;
    }
    //movement sun
    glTranslatef(-15, 0, 0);
    glRotatef(info.day, 0, 1, 0);
    gluSphere(sun, 10, 200, 200);
    glPopMatrix();
}

void draw_mercury() {
    //mercury object
    GLUquadric* mercury = gluNewQuadric();
    //texture
    gluQuadricTexture(mercury, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_mer);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_mer, height_mer,GL_BGR_EXT, GL_UNSIGNED_BYTE, mercuryTexture);
    //movement
    glPushMatrix();
    glTranslatef (-15,0,0);
    glRotatef(info.mercury_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15,0,0);
    glTranslatef(0.2,0,0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-0.5,0,0);
    glTranslatef(0.5,0,0);
    gluSphere(mercury, .5, 20, 16);
    glPopMatrix();
}

void draw_venus() {
    glPushMatrix();
    //venus
    GLUquadric* venus = gluNewQuadric();
    //texture
    gluQuadricTexture(venus, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_ven);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_ven, height_ven,GL_BGR_EXT, GL_UNSIGNED_BYTE, venusTexture);
    //movement
    glTranslatef(-15, 0, 0);
    glRotatef(info.venus_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(0.8, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef (-1, 0, 0);
    glTranslatef (1, 0, 0);
    gluSphere(venus, .8, 20, 16);
    glPopMatrix();
}

void draw_earth() {
    glPushMatrix();
    //earth
    GLUquadric* earth = gluNewQuadric();
    //texture
    gluQuadricTexture(earth, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_ear);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_ear, height_ear,GL_BGR_EXT, GL_UNSIGNED_BYTE, earthTexture);
    //movement
    glTranslatef(-15, 0, 0);
    glRotatef(info.year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(2, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef (-2, 0, 0);
    glTranslatef (2, 0, 0);
    gluSphere(earth, 1.0, 20, 16);


    //moon
    glPushMatrix();
    GLfloat specular1[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.0, 0.1, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);
    glRotatef(info.month / 100, 0.0, 0.0, 1.0);
    glTranslatef(2, 0.0, 0.0);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();

    glPopMatrix();
}

void draw_mars() {
    glPushMatrix();
    //mars
    GLUquadric* mars = gluNewQuadric();
    //texture
    gluQuadricTexture(mars, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_mars);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_mars, height_mars,GL_BGR_EXT, GL_UNSIGNED_BYTE, marsTexture);
    //move
    glTranslatef(-15, 0, 0);
    glRotatef(info.mars_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(7, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-7, 0, 0);
    glTranslatef(7, 0, 0);
    //glutSolidSphere(0.6, 20, 16);
    gluSphere(mars, .6, 20, 16);
    glPushMatrix();


    glRotatef(info.month / 20, 0.0, 1.0, 0.0);
    glTranslatef(1, 0.0, 0.0);
    glutSolidSphere(0.1, 10, 10);

    glPopMatrix();


    glPushMatrix();



    glRotatef(info.month / 46, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();


    glPopMatrix();
}

void draw_jupiter() {
    GLUquadric* jupiter = gluNewQuadric();
    gluQuadricTexture(jupiter, GL_TRUE);
    //bind texture to object
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_j);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    // texture parameter
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_j, height_j,GL_BGR_EXT, GL_UNSIGNED_BYTE, jupiterTexture);

    glPushMatrix();

    glTranslatef(-15, 0, 0);
    glRotatef(info.jupiter_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(13, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-13, 0, 0);
    glTranslatef(13, 0, 0);
//    glutSolidSphere(2.0, 20, 16);
    gluSphere(jupiter, 2.0, 20, 16);
    glPushMatrix();

    glRotatef(90, 1.0, 0, 0.0);
    glutSolidTorus(0.25, 5.0, 5, 64);
    glRotatef(-90, 1.0, 0, 0.0);

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.3, 0.6, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glRotatef(90, 1.0, 0, 0.0);
    glRotatef(info.month / 58, 0.0, 1.0, 0.0);
    glTranslatef(3, 0.0, 0.0);
    glutSolidSphere(0.6, 10, 10);

    glPopMatrix();
    glPopMatrix();
}

void draw_saturn() {
    GLUquadric* saturn = gluNewQuadric();
    gluQuadricTexture(saturn, GL_TRUE);
    //bind texture to object
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_sat);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    // texture parameter
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_sat, height_sat,GL_BGR_EXT, GL_UNSIGNED_BYTE, saturnTexture);

    glPushMatrix();
    glTranslatef(-15, 0, 0);
    glRotatef(info.saturn_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(20, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-20, 0, 0);
    glTranslatef(20, 0, 0);
    glRotatef(0.3, 1.0, 0.0, 0.0);
    //glutSolidSphere(1.4, 20, 16);
    gluSphere(saturn, 1.4, 20, 16);

    glPushMatrix();

    glRotatef(90, 1.0, 0, 0.0);
    glutSolidTorus(0.1, 3.0, 5, 64);
    glRotatef(-90, 1.0, 0, 0.0);

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.3, 0.6, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glRotatef(info.month / 76, 0.0, 1.0, 0.0);
    glTranslatef(2.7, 0.0, 0.0);
    glutSolidSphere(0.4, 10, 10);

    glPopMatrix();
    glPopMatrix();
}

void draw_uranus() {
    GLUquadric* uranus = gluNewQuadric();
    gluQuadricTexture(uranus, GL_TRUE);
    //bind texture to object
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_ur);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    // texture parameter
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_ur, height_ur,GL_BGR_EXT, GL_UNSIGNED_BYTE, uranusTexture);

    glPushMatrix();

    glTranslatef(-15, 0, 0);
    glRotatef(info.uranus_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(28, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-28, 0, 0);
    glTranslatef(28, 0, 0);
    glRotatef(0.5, 1.0, 0.0, 0.0);
    //glutSolidSphere(1.5, 20, 16);
    gluSphere(uranus, 1.5, 20, 16);

    glPushMatrix();

    glRotatef(90, 1.0, 0, 0.0);
    glutSolidTorus(0.1, 3.0, 5, 64);
    glRotatef(-90, 1.0, 0, 0.0);

    glPushMatrix();

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.3, 0.2, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glRotatef(info.month / 108, 0.0, 1.0, 0.0);
    glTranslatef(2, 0.0, 0.0);
    glutSolidSphere(0.23, 10, 10);
    glPopMatrix();


    glPushMatrix();

    GLfloat specular2[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess2[] = {50.0};
    GLfloat ambient2[] = {0.3, 0.4, 0.0, 1.0};
    GLfloat light2[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient2);

    glRotatef(info.month / 145, 0.0, 1.0, 0.0);
    glTranslatef(3.5, 0.0, 0.0);
    glutSolidSphere(0.35, 10, 10);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
}

void draw_neptune() {
    glPushMatrix();
    GLUquadric* neptune = gluNewQuadric();
    gluQuadricTexture(neptune, GL_TRUE);
    //bind texture to object
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID_nep);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    // texture parameter
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width_nep, height_nep,GL_BGR_EXT, GL_UNSIGNED_BYTE, neptuneTexture);
    //move
    glTranslatef(-15, 0, 0);
    glRotatef(info.neptune_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(32, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-32, 0, 0);
    glTranslatef(32, 0, 0);
    glRotatef(0.5, 1.0, 0.0, 0.0);
    //glutSolidSphere(1.3, 20, 16);
    gluSphere(neptune, 1.3, 20, 16);

    glPushMatrix();
    glRotatef(90, 1.0, 0, 0.0);
    glutSolidTorus(0.1, 3.0, 5, 64);
    glRotatef(-90, 1.0, 0, 0.0);
    glPushMatrix();

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {1.0, 0.0, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glRotatef(info.month / 347, 0.0, 1.0, 0.0);
    glTranslatef(2.5, 0.0, 0.0);
    glutSolidSphere(0.35, 10, 10);
    glPopMatrix();


    glPushMatrix();

    GLfloat specular2[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess2[] = {50.0};
    GLfloat ambient2[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat light2[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient2);

    glRotatef(info.month / 389, 0.0, 1.0, 0.0);
    glTranslatef(3.5, 0.0, 0.0);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
}

void deleteTexture(){
    delete[] mercuryTexture;
    delete[] sunTexture;
    delete[] mercuryTexture;
    delete[] venusTexture;
    delete[] earthTexture;
    delete[] marsTexture;
    delete[] jupiterTexture;
    delete[] saturnTexture;
    delete[] uranusTexture;
    delete[] neptuneTexture;

}
