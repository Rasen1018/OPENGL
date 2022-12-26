#include "widget.h"

#include <QApplication>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    w.show();
    return a.exec();
}
