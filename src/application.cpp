#include "application.h"
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Application::Application(int argc, char *argv[]) : m_argc(argc), m_argv(argv)
{
    this->initGlfw();
    this->initWindow();

    this->theMain();
}

Application::~Application()
{
    spdlog::info("释放 GLFW");

    glfwTerminate();
}

void Application::initGlfw()
{
    spdlog::info("初始化 GLFW");

    glfwInit();
}

void Application::initWindow()
{
    spdlog::info("初始化窗口");

    m_window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (m_window == nullptr)
    {
        spdlog::critical("创建窗口时失败");
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::critical("加载 OpenGL 失败");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_window, frameBufferResizeCallback);
}

void Application::frameBufferResizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Application::theMain()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}
