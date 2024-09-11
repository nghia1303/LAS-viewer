#include "renderwidget.h"

static const char* vertexShaderSource =
    R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;

    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
    )"
;

static const char* fragmentShaderSource =
    R"(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    }
    )"
;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

RenderWidget::RenderWidget(QWidget* parent) : QOpenGLWidget(parent) {
    resize(500, 500);
    setWindowTitle("Qt6 C++, OpenGL ES 2.0");

}

RenderWidget::~RenderWidget() {

}

void RenderWidget::initializeGL(){
    initializeOpenGLFunctions();

    m_vao.create();
    m_vao.bind();

    prepareShaderProgram();

    prepareVertexBuffers();

    m_vao.release();

    glClearColor(0.5, 1, 1, 1);
}

void RenderWidget::resizeGL(GLint w, GLint h) {
    glViewport(0, 0, w, h);
}

void RenderWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    m_shaderProgram.bind();

    m_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);

    m_vao.release();

    m_shaderProgram.release();
}
