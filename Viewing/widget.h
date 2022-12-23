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

    GLfloat xAngle, yAngle, zAngle;
    GLfloat ex, ey, ez;


protected:
     void initializeGL( ) override;
     void paintGL( ) override;
     void resizeGL(int w, int h) override;
     void keyPressEvent(QKeyEvent* event) override;

private:
};

#endif // WIDGET_H
