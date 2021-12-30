/***
 * Autores : Natalia Mariscal Ruivo y Rocío Durán Cid
 * Fecha entrega : 20/01/2022
 */

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shaders.h"
#include "Model.h"

void funFramebufferSize (GLFWwindow* window, int w, int h);
void configScene();
void renderScene();

// ILUMINACIÓN Y TEXTURAS
void setLights(glm::mat4 P, glm::mat4 V);

// Shaders
Shaders shaders;

// Modelos
Model cone;
Model cylinder;
Model plane;
Model sphere;
Model torus;
Model triangle;
Model Koltuk;
Model marco;
Model cube;

// Viewport : tamaño de la ventana
int w = 500;
int h = 500;

int main() {
    // Inicializamos GLFW
    if(!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Creamos la ventana
    GLFWwindow* window;
    window = glfwCreateWindow(w, h, "Practica final", NULL, NULL);
    if(!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Inicializamos GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if(GLEW_OK != err) {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
        return false;
    }

    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    std::cout <<"This system supports OpenGL Version: " << oglVersion << std::endl;

    // Configuramos los CallBacks
    //glfwSetFramebufferSizeCallback(window, funFramebufferSize);

    // Entramos en el bucle de renderizado
    configScene();
    while(!glfwWindowShouldClose(window)) {
        renderScene(); // crear la imagen
        glfwSwapBuffers(window);
        glfwSwapInterval(0);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void configScene() {
    // Test de profundidad
    glEnable(GL_DEPTH_TEST);

    // Shaders
    shaders.initShaders("resources/shaders/vshader.glsl","resources/shaders/fshader.glsl");

    // Modelos
    plane.initModel("resources/models/plane.obj");
    cube.initModel("resources/models/cube.obj");
    cone.initModel("resources/models/cone.obj");
    cylinder.initModel("resources/models/cylinder.obj");
    sphere.initModel("resources/models/sphere.obj");
    torus.initModel("resources/models/torus.obj");
    triangle.initModel("resources/models/triangle.obj");
    Koltuk.initModel("resources/models/Koltuk.obj");
    marco.initModel("resources/models/marco.obj");

    // Texturas

    // Luces direccionales

    // Luces posicionales

    // Luces focales

    // Materiales
}

void renderScene() {

    // Borramos el buffer de color
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Indicamos los shaders a utilizar
    shaders.useShaders();

    // Matriz P (perspectiva)
    /*float fovy   = fovyPrincipal;
    float near =  0.1f;
    float far = 50.0f;
    float aspect = (float)w/(float)h;
    glm::mat4 P = glm::perspective(glm::radians(fovy), aspect, near, far);*/

    // Matriz V (ubicacion de la camara)
   /* float x = 10.0f*glm::cos(glm::radians(alphaY))*glm::sin(glm::radians(alphaX));
    float y = 10.0f*glm::sin(glm::radians(alphaY));
    float z = 10.0f*glm::cos(glm::radians(alphaY))*glm::cos(glm::radians(alphaX));
    glm::vec3 punto   (x,y,z);
    glm::vec3 center(0.0, 0.0,  0.0);
    glm::vec3 up    (0.0, 1.0f,  0.0);
    glm::mat4 V = glm::lookAt(punto, center, up);
    shaders.setVec3("ueye", punto);*/

    // Fijamos las luces
    //setLights(P,V);

    // Dibujamos la escena
    /*glm::mat4 T = glm::translate(I, glm::vec3(desX, 1.0f, desZ));
    glm::mat4 S = glm::scale(I, glm::vec3(0.5f, 0.5f, 0.5));
    glm::mat4 TBajar = glm::translate(I, glm::vec3(0.0f, -1.9f, desZ));
    glm::mat4 RHelicoptero = glm::rotate(I, glm::radians(rotHelicoptero), glm::vec3(0.0f,1.0f,0.0f));*/

    // dibujamos el plano

}

void setLights(glm::mat4 P, glm::mat4 V) {
}