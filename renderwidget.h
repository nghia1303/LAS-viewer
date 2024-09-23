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
    RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();
private:
    QOpenGLShaderProgram m_shaderProgram;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_arrayBuffer;
    QOpenGLBuffer m_indexBuffer;
    int m_frame = 0;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(GLint w, GLint h) override;
    void prepareShaderProgram();
    void prepareVertexBuffers();
    void prepareFragmentBuffers();
};

#endif // RENDERWIDGET_H
