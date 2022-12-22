#include "widget.h"
#include <GL/glut.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    Widget w;
    w.show();
    return a.exec();
}
