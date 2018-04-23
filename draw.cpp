void draw_sun() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.day, 0, 1, 0);
    glutSolidSphere(10, 200, 200);

    glPopMatrix();
}

void draw_mercury() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {1.3, 0.0, 0.2, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef (-15,0,0);
    glRotatef(info.mercury_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15,0,0);
    glTranslatef(0.2,0,0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-0.5,0,0);
    glTranslatef(0.5,0,0);
    glutSolidSphere(0.5, 20, 16);

    glPopMatrix();
}

void draw_venus() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.venus_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(0.8, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef (-1, 0, 0);
    glTranslatef (1, 0, 0);
    glutSolidSphere(0.8, 20, 16);

    glPopMatrix();
}

void draw_earth() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {1.0, 0.2, 0.6, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(2, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef (-2, 0, 0);
    glTranslatef (2, 0, 0);
    glutSolidSphere(1.0, 20, 16);

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
}

void draw_mars() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {1.0, 0.1, 0.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.mars_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(7, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-7, 0, 0);
    glTranslatef(7, 0, 0);
    glutSolidSphere(0.6, 20, 16);

    glPushMatrix();

    GLfloat specular1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess1[] = {50.0};
    GLfloat ambient1[] = {0.0, 1.0, 1.0, 1.0};
    GLfloat light1[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient1);

    glRotatef(info.month / 20, 0.0, 1.0, 0.0);
    glTranslatef(1, 0.0, 0.0);
    glutSolidSphere(0.1, 10, 10);
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

    glRotatef(info.month / 46, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();


    glPopMatrix();
}

void draw_jupiter() {
    glPushMatrix();

    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {0.8, 0.7, 0.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.jupiter_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(13, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-13, 0, 0);
    glTranslatef(13, 0, 0);
    glutSolidSphere(2.0, 20, 16);

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
    glPushMatrix();

    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {0.6, 0.6, 0.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.saturn_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(20, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-20, 0, 0);
    glTranslatef(20, 0, 0);
    glRotatef(0.3, 1.0, 0.0, 0.0);
    glutSolidSphere(1.4, 20, 16);

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
    glPushMatrix();

    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {0.3, 0.3, 0.7, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.uranus_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(28, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-28, 0, 0);
    glTranslatef(28, 0, 0);
    glRotatef(0.5, 1.0, 0.0, 0.0);
    glutSolidSphere(1.5, 20, 16);

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

    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat ambient[] = {0.0, 0.1, 1.0, 1.0};
    GLfloat light[] = {1.0, 1.0, 1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

    glTranslatef(-15, 0, 0);
    glRotatef(info.neptune_year, info.axis_x, info.axis_y, info.axis_z);
    glTranslatef(15, 0, 0);
    glTranslatef(32, 0, 0);
    glRotatef(info.day, 0.0, 1.0, 0.0);
    glTranslatef(-32, 0, 0);
    glTranslatef(32, 0, 0);
    glRotatef(0.5, 1.0, 0.0, 0.0);
    glutSolidSphere(1.3, 20, 16);

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
