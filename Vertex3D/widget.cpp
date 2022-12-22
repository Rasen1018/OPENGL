#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = 120, yAngle = 30, zAngle = 75;
    setWindowTitle("OpenGL ColorArray");
    resize(600, 600);

    QTimer *timer = new QTimer;

    connect(timer, &QTimer::timeout, this, [=](){
      xAngle += 2;
      yAngle += 2;
      zAngle += 2;
      update();
    });

    timer->start(1000/60);
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
    static GLfloat vertcolor[] = {
        1, 1, 1, 0, 0, -0.8,
        0, 0, 1, 0.5, 0.5, 0,
        1, 0, 0, -0.5, 0.5, 0,
        1, 1, 0, -0.5, -0.5, 0,
        0, 1, 0, 0.5, -0.5, 0,
    };

    static GLubyte index[] = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 1,
    };

    //glClear(GL_COLOR_BUFFER_BIT);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1, 1, 1);
    glRectf(-0.5, 0.5, 0.5, -0.5);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*6, &vertcolor[3]);
    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, sizeof(GLfloat)*6, vertcolor);

    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);

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
        yAngle += 2;
        break;
    case Qt::Key_2:
        yAngle -= 2;
        break;
    case Qt::Key_3:
        xAngle += 2;
        break;
    case Qt::Key_4:
        xAngle -=2;
        break;
    case Qt::Key_5:
        zAngle +=2;
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





