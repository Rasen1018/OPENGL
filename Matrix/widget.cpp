#include "widget.h"
#include <GL/glut.h>

#include <cmath>
#include <QTimer>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Cube");
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
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

#if 0
    GLfloat angle = 45.0;
    GLfloat value = angle * M_PI / 180;
    GLfloat trans[16] = {
        cos(value), -sin(value), 0, 0,
        sin(value), cos(value), 0, 0,
        0, 0, 1, 0,
        0.5, 0.5, 0, 1
    };

    GLfloat trans[16] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0.5, 0.5, 0, 1
    };
    glMultMatrixf(trans);

    GLfloat scale[16] = {
        1.5, 0, 0, 0,
        0, 1.5, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(scale);

    GLfloat transScale[16] = {
        1.5, 0, 0, 0,
        0, 1.5, 0, 0,
        0, 0, 1, 0,
        0.5, 0.5, 0, 1
    };
    glMultMatrixf(transScale);
#else
    GLfloat sheer[16] = {
        1, 0, 0, 0,
        0.5, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(sheer);
#endif
    glutWireTeapot(0.2);

    glPopMatrix();
    glFlush();
}
