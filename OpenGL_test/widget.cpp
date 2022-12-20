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
    current_angle = cos(0.1 * atime);

    glColor3f(1.0, 1.0, 1.0);
#if 0
    // draw square
    glBegin(GL_POLYGON);
    glVertex3f(rectPosX, rectPosY, 0.0);
    glVertex3f(rectPosX, rectPosY - rectSize, 0.0);
    glVertex3f(rectPosX + rectSize, rectPosY - rectSize, 0.0);
    glVertex3f(rectPosX + rectSize, rectPosY, 0.0);

    // draw triangle
    glPointSize(8.0);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);

    // draw line
    glBegin(GL_LINES);
    GLfloat x = -0.8;
    GLfloat y = 0.4;

    for (int i = 0; i < 6; i++) {
        glVertex2f(x, y);
        x += 0.3;
        y *=-1;
    }

    // draw circle
    double rad = 0.5;
    glBegin(GL_POLYGON);

    for (int i =0; i < 360; i++) {
        double angle, x, y;
        angle = i * 3.141592 / 180;
        x = rad * cos(angle);
        y = rad * sin(angle);
        glVertex2f(x, y);
    }

    // draw to change line width
    GLfloat w = 1, y;
    for (y = 0.8; y > -0.8; y -= 0.2) {
        glLineWidth(w++);
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
    }

    // draw to change line sort
    GLushort arPat[] = {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa,
                        0x33ff, 0x33ff, 0x33ff, 0x57ff, 0x57ff};
    GLint arFac[] = {1, 2, 3, 4, 1, 2, 3, 1, 2};
    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx = 0;
    for (y = 0.8; y > -0.8; y -=0.2) {
        glLineStipple(arFac[idx], arPat[idx]);
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
        idx++;
    }
#else
    // draw pendulum movement
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    xcenter = -cord_length * sin(current_angle);
    ycenter = -cord_length * cos(current_angle);
    glVertex2f(xcenter, ycenter);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    theta = 0;
    while (theta <= 2 * M_PI) {
        x = xcenter + radius * sin(theta);
        y = ycenter + radius * cos(theta);
        glVertex2f(x, y);
        theta += delta_theta;
    }
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
