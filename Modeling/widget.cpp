#include "widget.h"
#include <GL/glut.h>

#include <QTimer>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{
    Action = 0;
    xAngle = 0;

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0);
    glScalef(1.5, 1.5, 1.0);
    glutWireTeapot(0.2);

    /* 위치 변환이 연속된 좌표에서 수행
    glTranslatef(0.6, -0.6, 0.0);
    glutWireTeapot(0.2);
    glTranslatef(-1.2, 0.0, 0.0);
    glutWireTeapot(0.2);
    glTranslatef(0.0, 1.2, 0.0);
    glutWireTeapot(0.2); */

    //초기화하고 나면 원점이 다시 (0, 0, 0)부터 시작
    glPushMatrix();
    glTranslatef(0.9, 0.0, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glTranslatef(0.0, 0.6, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();
    glFlush( );
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    switch(event->key( )) {

    case Qt::Key_Z:
        break;
    case Qt::Key_1:
        break;
    case Qt::Key_2:
        break;
    case Qt::Key_3:
        break;
    case Qt::Key_4:
        break;
    case Qt::Key_5:
        break;
    case Qt::Key_6:
        break;
    case Qt::Key_7:
        break;
    case Qt::Key_8:
        break;
    case Qt::Key_9:
        break;
    case Qt::Key_0:
        break;

    };

    //QString str = QString("Cube3D : x : %1, y : %2, z : %3").arg(xAngle).arg(yAngle).arg(zAngle);
    //setWindowTitle(str);
    update( );
}
