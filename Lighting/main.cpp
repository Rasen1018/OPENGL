#include "widget.h"

#include <GL/glut.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    glutInit(&argc, argv);
    glutCreateWindow("Open GL");
    w.show();
    return a.exec();
}
