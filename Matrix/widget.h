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

protected:
     void initializeGL( ) override;
     void paintGL( ) override;
     void resizeGL(int w, int h) override;

};

#endif // WIDGET_H
