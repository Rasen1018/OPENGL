#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    radius = 0.05;
    delta_theta = 2*M_PI/20;
    theta = 0.0;
    cord_length = 0.5;

    /* rectPosX = 0.0f;
    rectPosY = 0.0f;
    rectSize = 250;

    xStep = 15.0f;
    yStep = 15.0f; */

    setWindowTitle("Hello OpenGL");
    resize(600, 600);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(timerFunction()));
    timer->start(1000/60);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    windowWidth = w;
    windowHeight = h;

    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(-1*w, w, -1*h, h, -1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glColor3f(1.0, 1.0, 1.0);
    //glShadeModel(GL_FLAT);
#if 0
    // draw triangle by strip
    glBegin(GL_TRIANGLE_STRIP);
    GLfloat x = -0.8;
    GLfloat y = 0.4;

    for (int i = 0; i < 6; i++) {
        if (i% 2==0) {
            glColor3f(1.0, 0.0, 0.0);
        } else {
            glColor3f(0.0, 1.0, 0.0);
        }
        glVertex2f(x, y);

        x += 0.3;
        y *= -1;
    }

    // draw triangle by fan
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.35, 0.35);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.5, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.35, -0.35);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    //
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.5, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, -0.5);

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.0, -0.5);
#else
    if (alias) {
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    } else {
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

    glHint(GL_POINT_SMOOTH_HINT, hint? GL_NICEST: GL_FASTEST);
    glHint(GL_LINE_SMOOTH_HINT, hint? GL_NICEST: GL_FASTEST);
    glHint(GL_POLYGON_SMOOTH_HINT, hint? GL_NICEST: GL_FASTEST);

    glPointSize(10.0);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.8);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, 0.7);
    glVertex2f(0.8, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(0.0, 0.4);
    glColor3f(0, 1, 0);
    glVertex2f(-0.4, 0.0);
    glColor3f(0, 0, 1);
    glVertex2f(0.0, -0.4);
    glColor3f(1, 1, 0);
    glVertex2f(0.4, 0.0);
#endif
    glEnd();
    glFlush();
}

void Widget::timerFunction() {
#if 0
    //draw square
    if(rectPosX > windowWidth - rectSize || rectPosX < -windowWidth)
        xStep = -xStep;

    if(rectPosY > windowHeight || rectPosY < -windowHeight + rectSize)
        yStep = -yStep;

    rectPosX += xStep;
    rectPosY += yStep;

    if(rectPosX > (windowWidth - rectSize + xStep))
        rectPosX = windowWidth - rectSize - 1;
    else if (rectPosX < -(windowWidth + xStep))
        rectPosX = -windowWidth - 1;

    if(rectPosY > (windowHeight + yStep))
        rectPosY = windowHeight - 1;
    else if (rectPosY < -(windowHeight + yStep))
        rectPosY = -windowHeight + rectSize - 1;

    repaint();
#else
    //draw pendulum movement
    atime++;
    update();
#endif
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()) {
        case Qt::Key_Up:
            alias = TRUE;
            break;
        case Qt::Key_Down:
            alias = FALSE;
            break;
        case Qt::Key_Left:
            hint = TRUE;
            break;
        case Qt::Key_Right:
            hint = FALSE;
            break;
    }

    update();
}
