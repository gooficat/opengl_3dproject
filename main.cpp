#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

unsigned int SCR_WIDTH = 960;
unsigned int SCR_HEIGHT = 540;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
	if (!window)
	{
		std::cout << "GLFW3 window initialization failure, terminating...";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	gladLoadGL();
	
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	glClearColor(0.2f, 0.5f, 0.5f, 1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}