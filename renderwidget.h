#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H
#include <QtOpenGLWidgets/qopenglwidget.h>

class RenderWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    RenderWidget(QWidget *parent = nullptr);
    ~RenderWidget();

private:

};

#endif // RENDERWIDGET_H
