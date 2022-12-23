#include "widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{

    setWindowTitle("OpenGL Cube");
    resize(300, 300);

/*    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        update();
    });
    timer->start(1000/60); */
}

Widget::~Widget()
{
}


void Widget::initializeGL( ) {
    initializeOpenGLFunctions( );
    glClearColor(0.0, 0.0, 0.0, 1.0);
    dl = glGenLists(1);
    glNewList(dl, GL_COMPILE);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.2);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();
    glEndList();
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
    glLoadIdentity( );

   // glPushMatrix();

    glColor3f(1, 0, 0);
    glCallList(dl);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0, 1, 0);
    glCallList(dl);

    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0, 0, 1);
    glCallList(dl);

    //glPopMatrix();
    glFlush( );
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key( )) {

    case Qt::Key_1:
        //yAngle += 2;
        break;
    case Qt::Key_2:
        //yAngle -= 2;
        break;
    case Qt::Key_3:
        //xAngle += 2;
        break;
    case Qt::Key_4:
        //xAngle -= 2;
        break;
    case Qt::Key_5:
        //zAngle += 2;
        break;
    case Qt::Key_6:
        //zAngle -= 2;
        break;
    case Qt::Key_0:
        //xAngle = yAngle = zAngle = 0.0;
        break;
    };

    //QString str = QString("Cube3D : x : %1, y : %2, z : %3").arg(xAngle).arg(yAngle).arg(zAngle);
    //setWindowTitle(str);
    update( );
}