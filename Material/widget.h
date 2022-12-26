#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GLfloat red, green, blue;
    GLfloat xAngle, yAngle, zAngle;
    GLboolean bColorTrack;

protected:
     void initializeGL( ) override;
     void paintGL( ) override;
     void resizeGL(int w, int h) override;
     void keyPressEvent(QKeyEvent* event);

};

#endif // WIDGET_H
