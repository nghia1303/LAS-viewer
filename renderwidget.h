#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    // using QOpenGLWidget::QOpenGLWidget;
    RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();
private:
    QOpenGLShaderProgram m_shaderProgram;
    int m_frame = 0;
    QOpenGLVertexArrayObject m_vao;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(GLint w, GLint h) override;
};

#endif // RENDERWIDGET_H
