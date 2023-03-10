#include "widget.h"
#include <GL/GLU.h>

#include <QTimer>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{
    Action = 1;

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

    glViewport(0, 0, w, h);
    if(h==0) return;
    lastWidth = w;
    lastHeight = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    if (w > h) {
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, 1.0, -1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0/aspect, 1.0/aspect, 1.0, -1.0);
    }
}

void Widget::paintGL( )
{
#if 0
    // 뷰포트
    switch (Action) {
        case 1:
            glViewport(0, 0, lastWidth, lastHeight);
            break;
        case 2:
            glViewport(0, 0, lastWidth/2, lastHeight/2);
        break;
        case 3:
            glViewport(lastWidth/2, 0, lastWidth/2, lastHeight/2);
        break;
        case 4:
            glViewport(30, 30, 200, 200);
        break;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);
    glRectf(-1.0, 1.0, 1.0, -1.0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
#else
    // 종횡비 유지
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glRectf(-1.0, 1.0, 1.0, -1.0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);

#endif
    glEnd();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);

    switch(event->key( )) {

    case Qt::Key_1:
        Action = 1;
        break;
    case Qt::Key_2:
        Action = 2;
        break;
    case Qt::Key_3:
        Action = 3;
        break;
    case Qt::Key_4:
        Action = 4;
       break;
    };

    resizeGL(width(), height());

    //QString str = QString("Cube3D : x : %1, y : %2, z : %3, bNear : %4, bFar : %5")
    //        .arg(xAngle).arg(yAngle).arg(zAngle).arg(bNear).arg(bFar);
    //setWindowTitle(str);
    update( );
}
