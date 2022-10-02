#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
        cout << "ESC" << mode << endl;
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // 初始化glfw
    if (!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // 创建window
    auto window = glfwCreateWindow(800, 600, "learn OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // 创建context
    glfwMakeContextCurrent(window);
    // 注册按键回调
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        glfwTerminate();
        return -1;
    }

    // 视口
    glViewport(0, 0, 800, 600);

    // render loop
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
