#include "widget.h"
#include <GL/glut.h>

#include <cmath>
#include <QTimer>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{
    lx =0, ly = 0, lz = -1.0;
    xAngle = 0, yAngle =0, zAngle = 0;
    red = green = blue = 0.2;
    bAmbient = FALSE;
    bAttach = FALSE;

    setWindowTitle("OpenGL Stencil");
    resize(600, 600);

    QTimer* timer = new QTimer(this);
    /*connect(timer, &QTimer::timeout, [=](){
        xAngle +=2;
        //zAngle +=2;
        update();
    });
    timer->start(1000/60); */
}

Widget::~Widget()
{
}

void Widget::initializeGL( ) {
    initializeOpenGLFunctions( );
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h) {

    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL( )
{
#if 0
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    if (bAttach) {
        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
    }

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightpos[] = {lx, ly, lz, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    if(bAmbient) {
        GLfloat ambient[4] = {0.94, 0.35, 1, 1};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    } else {
        GLfloat ambient[4] = {0, 0, 0, 1};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    }

    if(bAttach == false) {
        glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
        glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
        glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
    }
#else
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    GLfloat arLight[] = {red, green, blue, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);


    glPushMatrix( );

    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

#endif
    glutSolidTeapot(0.5);
    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event) {
#if 0
    switch(event->key()) {
    case Qt::Key_1:
        bAmbient = GL_TRUE;
        break;
    case Qt::Key_2:
        bAmbient = GL_FALSE;
        break;
    case Qt::Key_3:
        bAttach = GL_TRUE;
        break;
    case Qt::Key_4:
        bAttach = GL_FALSE;
        break;

    case Qt::Key_A:
        yAngle += 2;
        break;
    case Qt::Key_S:
        yAngle -= 2;
        break;
    case Qt::Key_D:
        xAngle += 2;
        break;
    case Qt::Key_F:
        xAngle -= 2;
        break;
    case Qt::Key_G:
        zAngle += 2;
        break;
    case Qt::Key_H:
        zAngle -= 2;
        break;
    case Qt::Key_J:
        xAngle = yAngle = zAngle = 0.0;
        break;

    case Qt::Key_Z:
        lx -= 0.1;
        break;
    case Qt::Key_X:
        lx += 0.1;
        break;
    case Qt::Key_C:
        ly -= 0.1;
        break;
    case Qt::Key_V:
        ly += 0.1;
        break;
    case Qt::Key_B:
        lz -= 0.1;
        break;
    case Qt::Key_N:
        lz += 0.1;
        break;
    case Qt::Key_M:
        lx = ly = 0, lz = -1.0;
        break;
    }
#else
    switch(event->key( )) {
    case Qt::Key_1:          // Ambient ON
        yAngle += 2;
        break;
    case Qt::Key_2:         // Ambient OFF
        yAngle -= 2;
        break;
    case Qt::Key_3:         // Attach light
        xAngle += 2;
        break;
    case Qt::Key_4:         // Unattach light
        xAngle -= 2;
        break;
    case Qt::Key_5:         // Unattach light
        zAngle += 2;
        break;
    case Qt::Key_6:         // Unattach light
        zAngle -= 2;
        break;
    case Qt::Key_0:         // Unattach light
        xAngle = yAngle = zAngle = 0.0;
        break;

    case Qt::Key_A:
        red += 0.1;
        break;
    case Qt::Key_S:
        red -= 0.1;
        break;
    case Qt::Key_D:
        green += 0.1;
        break;
    case Qt::Key_F:
        green -= 0.1;
        break;
    case Qt::Key_G:
        blue += 0.1;
        break;
    case Qt::Key_H:
        blue -= 0.1;
        break;
    case Qt::Key_J:
        red = blue = green = 0.5;
        break;
    }

#endif
    update();
}
