#ifndef APPLICATION_H
#define APPLICATION_H

// glfw 不能在 glad 之后加载，不要删掉这行！！！
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application
{
private:
    int m_argc;
    char **m_argv;
    GLFWwindow *m_window;

    void initGlfw();
    void initWindow();
    static void frameBufferResizeCallback(GLFWwindow *window, int width, int height);
    void theMain();
public:
    Application(int argc, char *argv[]);
    ~Application();
};

#endif // APPLICATION_H