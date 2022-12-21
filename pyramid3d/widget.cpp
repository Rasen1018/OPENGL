#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    bDepthTest = GL_TRUE;
    bCullFace = GL_FALSE;
    bCcwFront = GL_TRUE;
    polygonMode = GL_FILL;
    shadeMode = GL_FLAT;

    setWindowTitle("OpenGL Pyramid3D");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
#if 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(shadeMode);

    /* if (bDepthTest) {
        glEnable(GL_DEPTH_TEST);
    } else {
        glDisable(GL_DEPTH_TEST);
    }

    if (bCullFace) {
        glEnable(GL_CULL_FACE);
    } else {
        glDisable(GL_CULL_FACE);
    } */

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    glColor3f(1, 1, 0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);

    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
#else
    glClear(GL_COLOR_BUFFER_BIT);

    if (bCullFace) {
        glEnable(GL_CULL_FACE);
    } else {
        glDisable(GL_CULL_FACE);
    }
    glFrontFace(bCcwFront ? GL_CCW: GL_CW);

    glPushMatrix( );
    glTranslatef(-0.5f, 0.0f, 0.0f);
    // CCW
    glBegin(GL_POLYGON);
      glVertex2f(0.0, 0.5);
      glVertex2f(-0.4, -0.5);
      glVertex2f(0.4, -0.5);
    glEnd( );
    glTranslatef(1.0f, 0.0f, 0.0f);
    // CW
    glBegin(GL_POLYGON);
      glVertex2f(0.0, 0.5);
      glVertex2f(0.4, -0.5);
      glVertex2f(-0.4, -0.5);
#endif
    glEnd();

    glPopMatrix();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event) {

    switch(event->key()) {
    /* case Qt::Key_Up:
        bDepthTest = GL_TRUE;
        break;
    case Qt::Key_Down:
        bDepthTest = GL_FALSE;
        break;
    case Qt::Key_Left:
        bCullFace = GL_TRUE;
        break;
    case Qt::Key_Right:
        bCullFace = GL_FALSE;
        break; */
    case Qt::Key_1:
        //yAngle += 2;
        polygonMode = GL_POINT;
        break;
    case Qt::Key_2:
        //yAngle -= 2;
        polygonMode = GL_LINE;
        break;
    case Qt::Key_3:
        //xAngle += 2;
        polygonMode = GL_FILL;
        break;
    case Qt::Key_4:
        //xAngle -=2;
        shadeMode = GL_SMOOTH;
        break;
    case Qt::Key_5:
        //zAngle +=2;
        shadeMode = GL_FLAT;
        break;
    case Qt::Key_6:
        xAngle -=2;
        break;
    /* case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break; */
    }

    QString str;
    str = QString("Pyramid3D : x : %1.1f, y : %2.1f, z : %3.1f").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);
    update();
}



