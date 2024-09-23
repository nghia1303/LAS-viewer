#include "renderwidget.h"
#include <qapplication.h>

GLfloat vertices[] = {
  0.0f,  0.707f,
  -0.5f, -0.5f,
  0.5f, -0.5f
};
GLfloat colors[] = {
  1.0f, 0.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 0.0f, 1.0f
};

RenderWidget::RenderWidget(QWidget* parent) : QOpenGLWidget(parent), m_indexBuffer(QOpenGLBuffer::IndexBuffer){

}

RenderWidget::~RenderWidget() {

}
// D:/Working/Projects/PointCloudViewer
void RenderWidget::prepareShaderProgram() {
  if (!m_shaderProgram.addShaderFromSourceFile (QOpenGLShader::Vertex, "../../shader/vertex_shader.vsh"))
    close ();
  if (!m_shaderProgram.addShaderFromSourceFile (QOpenGLShader::Fragment, "../../shader/fragment_shader.fsh"))
    close ();
  if (!m_shaderProgram.link())
    close ();
}

void RenderWidget::prepareVertexBuffers() {
  m_arrayBuffer.create();
  m_arrayBuffer.bind();
  m_arrayBuffer.allocate(vertices, 0);
}

void RenderWidget::prepareFragmentBuffers() {

}


void RenderWidget::initializeGL(){
    initializeOpenGLFunctions();

    prepareShaderProgram();

    glClearColor(0, 0, 0, 1);
}

void RenderWidget::resizeGL(GLint w, GLint h) {
    glViewport(0, 0, w, h);
}

void RenderWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT);
  m_shaderProgram.bind();

  GLuint m_posAttr = m_shaderProgram.attributeLocation("qt_Vertex");
  GLuint m_colAttr = m_shaderProgram.attributeLocation("colAttr");

  glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
  glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

  glEnableVertexAttribArray(m_posAttr);
  glEnableVertexAttribArray(m_colAttr);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(m_posAttr);
  glDisableVertexAttribArray(m_colAttr);
  m_shaderProgram.release();
}
