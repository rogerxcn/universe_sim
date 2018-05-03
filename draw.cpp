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
    glPushMatrix();
    glRotatef(info.sun_day, 0, 0, 1);
    gluSphere(sun, 86.4, 100, 100);
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

    if (torus) glutSolidTorus(0.5, 360, 50, 100);
    glRotatef(info.mercury_year, 0, 0, 1);  // set rotation with respect to z axis
    glTranslatef(360,0,0);                  // set distance from center of sun
    glRotatef(info.mercury_day, 0.0, 0, 1.0);     // set rotation with respect to y axis
    gluSphere(mercury, 13, 20, 16);         // set diameter to .3

    glPopMatrix();
}


void draw_venus() {
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
    glPushMatrix();
    if (torus) glutSolidTorus(1.75, 672, 50, 100);
    glRotatef(info.venus_year, 0, 0, 1);
    glTranslatef(672, 0, 0);
    glRotatef(info.venus_day, 0.0, 0, 1.0);
    gluSphere(venus, 17.5, 20, 16);
    glPopMatrix();
}


void draw_earth() {
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
    glPushMatrix();
    if (torus) glutSolidTorus(1.79, 929.6, 50, 100);
    glRotatef(info.year, 0, 0, 1);
    glTranslatef(929.6, 0, 0);
    glRotatef(info.day, 0.0, 0, 1.0);
    gluSphere(earth, 17.9, 20, 16);


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
    glTranslatef(23.8, 0.0, 0.0);
    glutSolidSphere(2, 10, 10);
    glPopMatrix();

    glPopMatrix();
}


void draw_mars() {

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
    glPushMatrix();

    if (torus) glutSolidTorus(1.42, 1416, 50, 100);
    glRotatef(info.mars_year, 0, 0, 1);
    glTranslatef(1416, 0, 0);
    glRotatef(info.mars_day, 0.0, 0, 1.0);
    gluSphere(mars, 14.2, 20, 16);

    glPushMatrix();

    glRotatef(info.month / 20, 0.0, 1.0, 0.0);
    glTranslatef(1, 0.0, 0.0);
    glutSolidSphere(0.1, 10, 10);

    glPushMatrix();

    glRotatef(info.month / 46, 0.0, 0, 1.0);
    glTranslatef(25, 0.0, 0.0);
    glutSolidSphere(2, 10, 10);
    glPopMatrix();
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

    if (torus) glutSolidTorus(2.86, 3838, 50, 100);
    glRotatef(info.jupiter_year, 0, 0, 1.0);
    glTranslatef(3838, 0, 0);
    glRotatef(info.jupiter_day, 0.0, 0,  1.0);
    gluSphere(jupiter, 28.6, 20, 16);
    glPushMatrix();

    glRotatef(30, 0, 0, 1.0);
    glutSolidTorus(5, 85.0, 5, 64);
    glRotatef(-30, 1.0, 0, 1.0);

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
    glTranslatef(30, 0.0, 0.0);
    glutSolidSphere(6, 10, 10);

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
    if (torus) glutSolidTorus(3.72, 5907, 50, 100);
    glRotatef(info.saturn_year, 0, 0, 1);
    glTranslatef(5907, 0, 0);
    glRotatef(info.saturn_day, 0.0, 0, 1.0);
    gluSphere(saturn, 37.2, 20, 16);

    glPushMatrix();

    glRotatef(30, 0, 0, 1);
    glutSolidTorus(5, 143.0, 5, 64);
    glRotatef(-30, 0, 0, 1);

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.3, 0.6, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glPushMatrix();
    glRotatef(info.month / 76, 0.0, 1.0, 0.0);
    glTranslatef(77, 0.0, 0.0);
    glutSolidSphere(4, 10, 10);

    glPopMatrix();
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

    if (torus) glutSolidTorus(3.1, 7840, 50, 100);
    glRotatef(info.uranus_year, 0, 0, 1);
    glTranslatef(7840, 0, 0);
    glRotatef(info.uranus_day, 0.0, 0, 1.0);
    gluSphere(uranus, 31, 20, 16);

    glPushMatrix();

    glRotatef(30, 0.0, 0, 1.0);
    glutSolidTorus(5, 92.0, 5, 64);
    glRotatef(-30, 0.0, 0, 1.0);

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
    glTranslatef(72, 0.0, 0.0);
    glutSolidSphere(3, 10, 10);



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
    glTranslatef(85, 0.0, 0.0);
    glutSolidSphere(3.5, 10, 10);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void draw_neptune() {
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
    glPushMatrix();
    if (torus) glutSolidTorus(3, 13930, 50, 100);
    glRotatef(info.neptune_year, 0.0, 0.0, 1.0);
    glTranslatef(13930, 0, 0);
    glRotatef(info.day, 0.0, 0, 1.0);
    gluSphere(neptune, 30, 20, 16);

    glPushMatrix();
    glRotatef(0, 0, 0, 1.0);
    glutSolidTorus(5, 68.0, 5, 64);
    glRotatef(-0, 0, 0, 1.0);

    glPushMatrix();
    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {1.0, 0.0, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);
    glRotatef(info.month / 347, 0.0, 0.0, 1.0);
    glTranslatef(45, 0.0, 0.0);
    glutSolidSphere(3.5, 10, 10);

    glPushMatrix();
    GLfloat specular2[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess2[] = {50.0};
    GLfloat ambient2[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat light2[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light2);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient2);

    glRotatef(info.month / 389, 0.0, 0.0, 1.0);
    glTranslatef(65, 0.0, 0.0);
    glutSolidSphere(3, 10, 10);

    glPopMatrix();
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
