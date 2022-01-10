/***
 * Autores : Natalia Mariscal Ruivo y Rocío Durán Cid
 * Fecha entrega : 20/01/2022
 */

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shaders.h"
#include "Model.h"
#include "Texture.h"

void configScene();
void renderScene();
void funFramebufferSize (GLFWwindow* window, int w, int h);
void drawObjectMat(Model model, Material material, glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawObjectTex(Model model, Textures textures, glm::mat4 P, glm::mat4 V, glm::mat4 M);

void drawObject(Model model, glm::vec3 color, glm::mat4 P, glm::mat4 V, glm::mat4 M, glm::vec3 colorLinea);
void drawHabitacion(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawSuelo(glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Paredes
void drawParedDerecha(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawParedIzquierda(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawParedFondo(glm::mat4 P, glm::mat4 V, glm::mat4 M);
//Sofá
void drawSofa(glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Mesa
void drawPatasMesa(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawMesa (glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Mesilla
void drawPatasMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawMesilla (glm::mat4 P, glm::mat4 V, glm::mat4 M);
// silla
void drawPatasSilla (glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawSilla (glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawRespaldoSilla (glm::mat4 P, glm::mat4 V, glm::mat4 M);
//Lampara mesilla
void drawBombillaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawBaseLamparaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawLamparaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M);
//Lamparas pared
void drawPantallaLamparaPared(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawConjuntoPantallaLamparaPared(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawPantallaLamparaParedIzquierda(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawPantallaLamparaParedDerecha(glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Cuadros
void drawCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawConjuntoCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawLaminasCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M);
//Chimenea
void drawChimenea(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawFondoChimenea(glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Alfombra
void drawAlfombra(glm::mat4 P, glm::mat4 V, glm::mat4 M);
//Ventilador de techo
void drawAspasVentilador(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawVentilador(glm::mat4 P, glm::mat4 V, glm::mat4 M);
// Vistas ventana
void drawJardin(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawVentana(glm::mat4 P, glm::mat4 V, glm::mat4 M);

void funcionMovimientoCamara(GLFWwindow *window, double x,double y);
void funcionFovy(GLFWwindow * window, double desplazamientoX, double desplazamientoY);
void funKey(GLFWwindow* window, unsigned int key);

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

Texture img4_marmol;
Textures texLuz;
Texture img1;
Texture img2;
Texture img3_chimenea;
Texture img_suelo;
Texture img_sofa;
Texture img5;
Texture img9_alfombra;
Texture img_parque_blanco;
Texture img_pared_blanca;
Texture img_lamina_cuadro_1;
Texture img_lamina_cuadro_2;
Texture img_fuego;
Texture img_cesped;
Texture img_ventana;

// Luces
#define   NLD 1
#define   NLP 1
#define   NLF 3
Light     lightG;
Light     lightD[NLD];
Light     lightP[NLP];
Light     lightF[NLF];

// Materiales
Material  ruby;
Material jade;
Material chrome;
Material silver;
Material perl;
Material white;

Textures texChimenea;
Textures texSuelo;
Textures texSofa;
Textures alfombra;
Textures noEmissive;
Textures texPared;
Textures texLamina1;
Textures texLamina2;
Textures texFuego;
Textures texCesped;
Textures texVentana;

// Viewport : tamaño de la ventana
int w = 500;
int h = 500;
int press = -1;

float alphaX = 0.0;
float alphaY = 10.0;
float fovyPrincipal = 120.0;
float rotCamara = 0.0;
float escX = 4.0;
float escZ = 4.0;
float trasZ = 0.5;
float rotVentilador = 1.8;

//Animaciones lights
float luzDireccional = 1.0;
float rLuzPosicional = 0.0;
bool FOCAL = true;

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
    glfwSetFramebufferSizeCallback(window, funFramebufferSize);
    glfwSetCharCallback(window, funKey);
    //glfwSetKeyCallback(window, funEspeciales);
    glfwSetCursorPosCallback(window, funcionMovimientoCamara);
    glfwSetScrollCallback(window, funcionFovy);

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

void funFramebufferSize(GLFWwindow* window, int width, int height) {
    // Configuracion del Viewport
    glViewport(0, 0, width, height);

    // Actualizacion de w y h
    w = width;
    h = height;
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
    img1.initTexture("resources/textures/img1.png");
    img4_marmol.initTexture("resources/textures/img4Luz.png");
    img2.initTexture("resources/textures/img2.png");
    img3_chimenea.initTexture("resources/textures/img3.png");
    img_sofa.initTexture("resources/textures/imgSofa.png");
    img_suelo.initTexture("resources/textures/suelo.png");
    img5.initTexture("resources/textures/img5.png");
    img9_alfombra.initTexture("resources/textures/img9.jpg");
    img_parque_blanco.initTexture("resources/textures/parqueBlanco.jpg");
    img_pared_blanca.initTexture("resources/textures/paredBlanca.jpg");
    img_lamina_cuadro_1.initTexture("resources/textures/cuadro.jpg");
    img_fuego.initTexture("resources/textures/img12.jpg");
    img_cesped.initTexture("resources/textures/cesped.jpg");
    img_ventana.initTexture("resources/textures/imgWindow.png");

    // Luz ambiental global
    lightG.ambient = glm::vec3(0.5, 0.5, 0.5);

    // Luces direccionales = la que da la chimenea
    lightD[0].direction = glm::vec3(-1.0, 0.0, 0.0);
    lightD[0].ambient   = glm::vec3( 0.5, 0.5, 0.5);
    lightD[0].diffuse   = glm::vec3( 0.7, 0.7, 0.7);
    lightD[0].specular  = glm::vec3( 0.7, 0.7, 0.7);

    // Luces posicionales
    lightP[0].position    = glm::vec3(0.0, 5.0, 0.0);
    lightP[0].ambient     = glm::vec3(0.2, 0.2, 0.2);
    lightP[0].diffuse     = glm::vec3(0.9, 0.9, 0.9);
    lightP[0].specular    = glm::vec3(0.9, 0.9, 0.9);
    lightP[0].c0          = 1.00;
    lightP[0].c1          = 0.22;
    lightP[0].c2          = 0.20;

    // Luces focales
    lightF[0].position    = glm::vec3(5.06, 1.0, -2.15);
    lightF[0].direction   = glm::vec3( 2.0, -2.0, -5.0);
    lightF[0].ambient     = glm::vec3( 0.2,  0.2,  0.2);
    lightF[0].diffuse     = glm::vec3( 0.9,  0.9,  0.9);
    lightF[0].specular    = glm::vec3( 0.9,  0.9,  0.9);
    lightF[0].innerCutOff = 10.0;
    lightF[0].outerCutOff = lightF[0].innerCutOff + 5.0;
    lightF[0].c0          = 1.000;
    lightF[0].c1          = 0.090;
    lightF[0].c2          = 0.032;

    lightF[1].position    = glm::vec3(-5.8, 2.5, 4.0);
    lightF[1].direction   = glm::vec3( 2.0, -2.0, 0.0);
    lightF[1].ambient     = glm::vec3( 0.2,  0.2,  0.2);
    lightF[1].diffuse     = glm::vec3( 0.9,  0.9,  0.9);
    lightF[1].specular    = glm::vec3( 0.9,  0.9,  0.9);
    lightF[1].innerCutOff = 10.0;
    lightF[1].outerCutOff = lightF[0].innerCutOff + 5.0;
    lightF[1].c0          = 1.000;
    lightF[1].c1          = 0.090;
    lightF[1].c2          = 0.032;

    lightF[2].position    = glm::vec3(-5.8, 2.5, 1.0);
    lightF[2].direction   = glm::vec3( 2.0, -2.0, 0.0);
    lightF[2].ambient     = glm::vec3( 0.2,  0.2,  0.2);
    lightF[2].diffuse     = glm::vec3( 0.9,  0.9,  0.9);
    lightF[2].specular    = glm::vec3( 0.9,  0.9,  0.9);
    lightF[2].innerCutOff = 10.0;
    lightF[2].outerCutOff = lightF[0].innerCutOff + 5.0;
    lightF[2].c0          = 1.000;
    lightF[2].c1          = 0.090;
    lightF[2].c2          = 0.032;

    // Materiales
    ruby.ambient   = glm::vec4(0.174500, 0.011750, 0.011750, 0.55);
    ruby.diffuse   = glm::vec4(0.614240, 0.041360, 0.041360, 0.55);
    ruby.specular  = glm::vec4(0.727811, 0.626959, 0.626959, 0.55);
    ruby.emissive  = glm::vec4(0.000000, 0.000000, 0.000000, 1.00);
    ruby.shininess = 76.8;

    jade.ambient = { 0.135f, 0.2225f, 0.1575f, 0.95f };
    jade.diffuse = {0.54f, 0.89f, 0.63f, 0.95f };
    jade.specular = {0.316228f, 0.316228f, 0.316228f, 0.95f };
    jade.emissive = {0.000000, 0.000000, 0.000000, 1.00 };
    jade.shininess = 12.8f;

    //Polished silver
    silver.ambient = { 0.23125f, 0.23125f, 0.23125f, 1.0f };
    silver.diffuse = {0.2775f, 0.2775f, 0.2775f, 1.0f };
    silver.specular = {0.773911f, 0.773911f, 0.773911f, 1.0f };
    silver.emissive = {0.000000, 0.000000, 0.000000, 1.00 };
    silver.shininess = 89.6f;

    //Chrome
    chrome.ambient = {0.25f, 0.25f, 0.25f, 1.0f  };
    chrome.diffuse = {0.4f, 0.4f, 0.4f, 1.0f };
    chrome.specular = {0.774597f, 0.774597f, 0.774597f, 1.0f };
    chrome.emissive = {0.000000, 0.000000, 0.000000, 1.00 };
    chrome.shininess = 76.8f;

    //perl
    perl.ambient = { 0.25f, 0.20725f, 0.20725f, 0.922f };
    perl.diffuse = {1.0f, 0.829f, 0.829f, 0.922f };
    perl.specular = {0.296648f, 0.296648f, 0.296648f, 0.922f };
    perl.emissive = {0.000000, 0.000000, 0.000000, 1.00 };
    perl.shininess = 11.264f;

    //White rubber
    white.ambient = { 0.05f,0.05f,0.05f,1.0f };
    white.diffuse = { 0.5f,0.5f,0.5f,1.0f};
    white.specular = { 0.7f,0.7f,0.7f,1.0f};
    white.emissive = {0.000000, 0.000000, 0.000000, 1.00 };
    white.shininess = 10.0f;

    // Texturas
    texLuz.diffuse = img4_marmol.getTexture();
    texLuz.specular = img4_marmol.getTexture();
    texLuz.emissive = img4_marmol.getTexture();;
    texLuz.normal = 0;
    texLuz.shininess = 10.0;

    texChimenea.diffuse = img3_chimenea.getTexture();
    texChimenea.specular = img3_chimenea.getTexture();
    texChimenea.emissive = img3_chimenea.getTexture();
    texChimenea.normal = 0;
    texChimenea.shininess = 10.0;

    texSuelo.diffuse = img_parque_blanco.getTexture();
    texSuelo.specular = img_parque_blanco.getTexture();
    texSuelo.emissive = img1.getTexture();
    texSuelo.normal = 0;
    texSuelo.shininess = 10.0;

    texSofa.diffuse = img5.getTexture();
    texSofa.specular = img_sofa.getTexture();
    texSofa.emissive = img5.getTexture();
    texSofa.normal = 0;
    texSofa.shininess = 10.0;

    alfombra.diffuse = img9_alfombra.getTexture();
    alfombra.specular = img9_alfombra.getTexture();
    alfombra.emissive = img1.getTexture();
    alfombra.normal = 0;
    alfombra.shininess = 10.0;

    texPared.diffuse = img_pared_blanca.getTexture();
    texPared.specular = img_pared_blanca.getTexture();
    texPared.emissive = img1.getTexture();
    texPared.normal = 0;
    texPared.shininess = 10.0;

    texLamina1.diffuse = img_lamina_cuadro_1.getTexture();
    texLamina1.specular = img_lamina_cuadro_1.getTexture();
    texLamina1.emissive = img1.getTexture();
    texLamina1.normal = 0;
    texLamina1.shininess = 10.0;

    texFuego.diffuse = img_fuego.getTexture();
    texFuego.specular = img_fuego.getTexture();
    texFuego.emissive = img_fuego.getTexture();
    texFuego.normal = 0;
    texFuego.shininess = 10.0;

    texCesped.diffuse = img_cesped.getTexture();
    texCesped.specular = img_cesped.getTexture();
    texCesped.emissive = img1.getTexture();
    texCesped.normal = 0;
    texCesped.shininess = 10.0;

    texVentana.diffuse = img_ventana.getTexture();
    texVentana.specular = img_ventana.getTexture();
    texVentana.emissive = img_ventana.getTexture();
    texVentana.normal = 0;
    texVentana.shininess = 10.0;
}

void renderScene() {
    // Borramos el buffer de color
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Indicamos los shaders a utilizar
    shaders.useShaders();

    // Matriz P (perspectiva)
    float fovy   = fovyPrincipal;
    float near =  0.1;
    float far = 50.0;
    float aspect = (float)w/(float)h;
    glm::mat4 P = glm::perspective(glm::radians(fovy), aspect, near, far);

    // Matriz V (ubicacion de la camara)
    float x = 10.0f*glm::cos(glm::radians(alphaY))*glm::sin(glm::radians(alphaX));
    float y = 10.0f*glm::sin(glm::radians(alphaY));
    float z = 10.0f*glm::cos(glm::radians(alphaY))*glm::cos(glm::radians(alphaX));
    glm::vec3 eye   (x,y,z);
    glm::vec3 center(0.0, 0.0,  0.0);
    glm::vec3 up    (0.0, 1.0f,  0.0);
    glm::mat4 V = glm::lookAt(eye, center, up);
    shaders.setVec3("ueye", eye);

    // Fijamos las luces
    setLights(P,V);

    // Dibujamos la escena
    /*glm::mat4 T = glm::translate(I, glm::vec3(desX, 1.0f, desZ));
    glm::mat4 S = glm::scale(I, glm::vec3(0.5f, 0.5f, 0.5));
    glm::mat4 TBajar = glm::translate(I, glm::vec3(0.0f, -1.9f, desZ));
    glm::mat4 RHelicoptero = glm::rotate(I, glm::radians(rotHelicoptero), glm::vec3(0.0f,1.0f,0.0f));*/
    glm::mat4 T = glm::translate(I, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 R = glm::rotate(I, glm::radians(rotCamara), glm::vec3(0.0,0.0,1.0));

    // dibujamos el plano
    drawHabitacion(P,V*R,T);

}

void setLights(glm::mat4 P, glm::mat4 V) {
    shaders.setLight("ulightG",lightG);
    for(int i=0; i<NLD; i++) shaders.setLight("ulightD["+toString(i)+"]",lightD[i]);
    for(int i=0; i<NLP; i++) shaders.setLight("ulightP["+toString(i)+"]",lightP[i]);
    for(int i=0; i<NLF; i++) shaders.setLight("ulightF["+toString(i)+"]",lightF[i]);

    for(int i=0; i<NLP; i++) {
        glm::mat4 M = glm::translate(I,lightP[i].position) * glm::scale(I,glm::vec3(0.1));
        /*glm::mat4 R = glm::rotate(I, glm::radians(rLuzPosicional), glm::vec3(0,1,0));
        lightP[0].position = glm::vec4 (-1.5, 0.2, 0.0, 1.0)*R;*/
        drawObjectTex(sphere, texLuz, P, V, M);
    }

    for(int i=0; i<NLF; i++) {
        glm::mat4 M = glm::translate(I,lightF[i].position) * glm::scale(I,glm::vec3(0.1));
        drawObjectTex(sphere, texLuz, P, V, M);
    }
}

void drawObjectMat(Model model, Material material, glm::mat4 P, glm::mat4 V, glm::mat4 M){
    shaders.setMat4("uN"  ,glm::transpose(glm::inverse(M)));
    shaders.setMat4("uM"  ,M);
    shaders.setMat4("uPVM",P*V*M);
    shaders.setBool("uWithMaterials",true);
    shaders.setMaterial("umaterial",material);
    model.renderModel(GL_FILL);
}

void drawObjectTex(Model model, Textures textures, glm::mat4 P, glm::mat4 V, glm::mat4 M){
    shaders.setMat4("uN"  ,glm::transpose(glm::inverse(M)));
    shaders.setMat4("uM"  ,M);
    shaders.setMat4("uPVM",P*V*M);
    shaders.setBool("uWithMaterials",false);
    shaders.setTextures("utextures",textures);
    /*if(textures.normal!=0) shaders.setBool("uWithNormals",true);
    else                   shaders.setBool("uWithNormals",false);*/
    model.renderModel(GL_FILL);
}

void drawHabitacion(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 T1 = glm::translate(I, glm::vec3(-2.5, 0.35, 2.0));
    glm::mat4 T2 = glm::translate(I, glm::vec3(-3.0, 0.0, -5.5));
    glm::mat4 R1 = glm::rotate(I, glm::radians(-90.0f), glm::vec3(1.0,0.0,0.0));
    glm::mat4 T3 = glm::translate(I, glm::vec3(0.0, 6.0, 0.0));
    glm::mat4 RVentilador = glm::rotate(I, (rotVentilador), glm::vec3(0, 1, 0));

    drawSuelo(P,V,M);
    drawParedDerecha(P,V,M);
    drawParedIzquierda(P,V,M);
    drawParedFondo(P,V,M);
    drawSofa(P,V,M);
    drawMesa(P,V,M);
    drawMesilla(P,V,M);
    drawSilla(P,V,M);
    drawSilla(P,V,M*T1);
    drawLamparaMesilla(P, V, M);
    drawConjuntoPantallaLamparaPared(P, V, M);
    drawConjuntoCuadroPared(P, V, M);
    drawChimenea(P,V,M*T2);
    drawAlfombra(P ,V, M);
    drawVentilador(P, V , M*T3*R1);
    drawLaminasCuadroPared(P ,V, M);
    drawFondoChimenea(P ,V, M);
    drawJardin(P, V, M);
    drawVentana(P, V, M);
}

void drawSuelo(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale    (I, glm::vec3(6.0, 1.0, 6.0));
    glm::mat4 T1 = glm::translate(I, glm::vec3(0.0,0.0, 0.0));
    drawObjectTex(plane, texSuelo, P, V, T1 * S1);
}

void drawParedDerecha(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(3.0, 1.0, 6.0));
    glm::mat4 R = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0.0,0.0,1.0));
    glm::mat4 T = glm::translate(I, glm::vec3(6.0, 3.0, 0.0));
    drawObjectTex(plane, texPared, P, V, T*R*S);
}
void drawParedIzquierda(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(3.0, 1.0, 6.0));
    glm::mat4 R = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0.0,0.0,1.0));
    glm::mat4 T = glm::translate(I, glm::vec3(-6.0, 3.0, 0.0));
    drawObjectTex(plane, texPared, P, V, T*R*S);
}

void drawParedFondo(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(6.0, 1.0, 3.0));
    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(1.0,0.0,0.0));
    glm::mat4 T = glm::translate(I, glm::vec3(0.0, 3.0, -6.0));
    drawObjectTex(plane, texPared, P, V, T*R*S);
}

void drawSofa(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(3.0, 3.0, 2.0));
    glm::mat4 T = glm::translate(I, glm::vec3(2.0, 0.50, -5.0));
    glm::mat4 R = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0.0,1.0,0.0));
    drawObjectTex(Koltuk, texSofa, P, V, R*T*S);
}

void drawPatasMesa(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.1, 0.7, 0.1));
    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,1.0f,0.0f));
    glm::mat4 T1 = glm::translate(I, glm::vec3(-5.0, 0.70, 0.0));
    glm::mat4 T2 = glm::translate(I, glm::vec3(-5.0, 0.70, 4.5));
    glm::mat4 T3 = glm::translate(I, glm::vec3(-3.5, 0.70, 0.0));
    glm::mat4 T4 = glm::translate(I, glm::vec3(-3.5, 0.70, 4.5));
    drawObjectMat(cylinder, jade, P, V, T1*R*S);
    drawObjectMat(cylinder, jade, P, V, T2*R*S);
    drawObjectMat(cylinder, jade, P, V, T3*R*S);
    drawObjectMat(cylinder, jade, P, V, T4*R*S);
}

void drawMesa (glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(1.25, 0.05, 3.25));
    glm::mat4 T = glm::translate(I, glm::vec3(-4.2, 1.4, 2.1));
    drawObjectMat(cube, jade, P, V, T*S);
    drawPatasMesa(P,V,M);
}

void drawPatasMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.05, 0.35, 0.05));
    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,1.0f,0.0f));
    glm::mat4 T1 = glm::translate(I, glm::vec3(4.8, 0.35, -2.5));
    glm::mat4 T2 = glm::translate(I, glm::vec3(5.5, 0.35, -1.8));
    glm::mat4 T3 = glm::translate(I, glm::vec3(5.5, 0.35, -2.5));
    glm::mat4 T4 = glm::translate(I, glm::vec3(4.8, 0.35, -1.8));
    drawObjectMat(cylinder, ruby, P, V, T1*R*S);
    drawObjectMat(cylinder, ruby, P, V, T2*R*S);
    drawObjectMat(cylinder, ruby, P, V, T3*R*S);
    drawObjectMat(cylinder, ruby, P, V, T4*R*S);
}

void drawMesilla (glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.7, 0.05, 0.7));
    glm::mat4 T = glm::translate(I, glm::vec3(5.06, 0.7, -2.15));
    drawObjectMat(cylinder, jade, P, V, T*S);
    drawPatasMesilla(P,V,M);
}

void drawPatasSilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.05, 0.35, 0.05));
    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,1.0f,0.0f));
    glm::mat4 T1 = glm::translate(I, glm::vec3(-2.8, 0.35, 3.3));
    glm::mat4 T2 = glm::translate(I, glm::vec3(-3.5, 0.35, 4.0));
    glm::mat4 T3 = glm::translate(I, glm::vec3(-2.8, 0.35, 4.0));
    glm::mat4 T4 = glm::translate(I, glm::vec3(-3.5, 0.35, 3.3));
    drawObjectMat(cylinder, ruby, P, V, T1*R*S);
    drawObjectMat(cylinder, ruby, P, V, T2*R*S);
    drawObjectMat(cylinder, ruby, P, V, T3*R*S);
    drawObjectMat(cylinder, ruby, P, V, T4*R*S);
}

void drawRespaldoSilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I, glm::vec3(0.5, 0.05, 0.5));
    glm::mat4 T = glm::translate(I, glm::vec3(-2.6, 1.4, 3.65));
    glm::mat4 R1 = glm::rotate(I, glm::radians(70.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectMat(cylinder, silver, P, V, T*R1*S1);

    glm::mat4 S2 = glm::scale(I, glm::vec3(0.03, 0.25, 0.03));
    glm::mat4 R2 = glm::rotate(I, glm::radians(-20.0f), glm::vec3(0.0f,0.0f,1.0f));
    glm::mat4 T1 = glm::translate(I, glm::vec3(-2.8, 0.9, 4.0));
    glm::mat4 T2 = glm::translate(I, glm::vec3(-2.8, 0.9, 3.3));
    drawObjectMat(cylinder, ruby, P, V, T1*R2*S2);
    drawObjectMat(cylinder, ruby, P, V, T2*R2*S2);
}

void drawSilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.5, 0.05, 0.5));
    glm::mat4 T = glm::translate(I, glm::vec3(-3.15, 0.67, 3.65));
    drawPatasSilla(P,V,M);
    drawRespaldoSilla(P,V,M);
    drawObjectMat(cube, silver, P, V, T*S);
}
void drawPantallaLamparaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.5, 0.3, 0.5));
    glm::mat4 T = glm::translate(I, glm::vec3(5.06, 1.5, -2.15));
    glm::mat4 R2 = glm::rotate(I, glm::radians(-20.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectMat(cone, jade, P, V, T*S);
}
void drawBombillaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.1, 0.1, 0.1));
    glm::mat4 T = glm::translate(I, glm::vec3(5.06, 1.3, -2.15));
    drawObjectMat(sphere, white, P, V, T * S);

}
void drawBaseLamparaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.03, 0.25, 0.03));
    glm::mat4 T = glm::translate(I, glm::vec3(5.06, 1.0, -2.15));
    drawObjectMat(cylinder, chrome, P, V, T * S);

}
void drawLamparaMesilla(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    drawPantallaLamparaMesilla(P, V, M);
    drawBaseLamparaMesilla(P,V,M);
    drawBombillaMesilla(P,V, M);
}

void drawPantallaLamparaParedIzquierda(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.15, 0.3, 0.15));
    glm::mat4 T = glm::translate(I, glm::vec3(-5.8, 2.5, 4.0));// x para regular lo pegado a la pared
    drawObjectMat(cylinder, jade, P, V, T *S);
}

void drawPantallaLamparaParedDerecha(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.15, 0.3, 0.15));
    glm::mat4 T = glm::translate(I, glm::vec3(-5.8, 2.5, 1.0));// x para regular lo pegado a la pared
    drawObjectMat(cylinder, jade, P, V, T *S);
}

void drawConjuntoPantallaLamparaPared(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    drawPantallaLamparaParedIzquierda(P, V, M);
    drawPantallaLamparaParedDerecha(P, V, M);
}

void drawCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    //glm::mat4 S = glm::scale(I, glm::vec3(3.0, 2.0, 3.0));
    //glm::mat4 T = glm::translate(I, glm::vec3(5.99, 2.5f, 2.15f));
    drawObjectMat(marco, silver, P, V, M);
}

void drawConjuntoCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I, glm::vec3(escX, 1.5, escZ));
    glm::mat4 T1 = glm::translate(I, glm::vec3(5.99, 2.5, 2.25));
    drawCuadroPared(P, V, M* T1* S1);

    glm::mat4 S2 = glm::scale(I, glm::vec3(1.5, 2.5, 1.5));
    glm::mat4 T2 = glm::translate(I, glm::vec3(5.99, 2.5, trasZ));
    drawCuadroPared(P, V, M* T2* S2);
}
void drawLaminasCuadroPared(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I,  glm::vec3(1.5, 2.5, 1.5));
    glm::mat4 T1 = glm::translate(I, glm::vec3(5.99, 2.5, 2.25));
    glm::mat4 R1 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectTex(plane, texLamina1, P, V,  M* T1* R1 * S1);

    /*glm::mat4 S2 = glm::scale(I, glm::vec3(1.5, 2.5, 1.5));
    glm::mat4 T2 = glm::translate(I, glm::vec3(5.99, 2.5, trasZ));
    drawObjectTex(plane, texLamina1, P, V,  M* T2* S2);*/
}

void drawChimenea(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I, glm::vec3(3.0, 0.2, 0.5));
    glm::mat4 T1 = glm::translate(I, glm::vec3(0.0, 1.8, 0.0));
    drawObjectTex(cube, texChimenea, P, V, M*T1*S1);

    glm::mat4 S2 = glm::scale(I, glm::vec3(1.5, 0.2, 0.5));
    glm::mat4 T2 = glm::translate(I, glm::vec3(0.5, 2.8, 0.0));
    glm::mat4 R2 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectTex(cube, texChimenea, P, V, M*R2*T2*S2);

    glm::mat4 S3 = glm::scale(I, glm::vec3(1.5, 0.2, 0.5));
    glm::mat4 T3 = glm::translate(I, glm::vec3(0.5, -2.8, 0.0));
    glm::mat4 R3 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectTex(cube, texChimenea, P, V, M*R3*T3*S3);
}

void drawFondoChimenea(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I,  glm::vec3(1.3, -3.5, 3.0));
    glm::mat4 T1 = glm::translate(I, glm::vec3(-3.0, 0.5, -5.8));
    glm::mat4 R1 = glm::rotate(I, glm::radians(90.0f), glm::vec3(1.0f,0.0f,0.0f));
    glm::mat4 R2 = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0.0f,1.0f,0.0f));
    drawObjectTex(plane, texFuego, P, V,  M* T1* R1 *R2*S1);
}
void drawAlfombra(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(3.0, 0.1, 3.0));
    glm::mat4 T = glm::translate(I, glm::vec3(0.0, -0.9, 0.0));
    drawObjectTex(plane, alfombra, P, V, M * T * S);
}

void drawAspasVentilador(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    //glm::mat4 R1 = glm::rotate(I, glm::radians(90.0f), glm::vec3(1, 0, 0));
    glm::mat4 S = glm::scale(I, glm::vec3(0.5, 1.5, 0.1));
    drawObjectTex(cone, texLuz, P, V, M*S);
}

void drawVentilador(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 R90 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 0, 1));
    glm::mat4 T = glm::translate(I, glm::vec3(0.0, -1.0, 0.0));
    drawAspasVentilador(P,V,M*T);
    drawAspasVentilador(P,V,M*R90*T);
    drawAspasVentilador(P,V,M*R90*R90*T);
    drawAspasVentilador(P,V,M*R90*R90*R90*T);
}

void drawJardin(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I,  glm::vec3(6.0, 1.0, 6.0));
    glm::mat4 T1 = glm::translate(I, glm::vec3(12.0, -1.0, 0.0));
    glm::mat4 R1 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,1.0f,0.0f));
    drawObjectTex(plane, texCesped, P, V,  M* T1* R1 * S1);
}

void drawVentana(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I,  glm::vec3(2.5, 3.0, 1.5));
    glm::mat4 T1 = glm::translate(I, glm::vec3(5.8, 1.5, -3.5));
    glm::mat4 R1 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0.0f,0.0f,1.0f));
    drawObjectTex(plane, texVentana, P, V,  M* T1* R1 * S1);
}


void funcionMovimientoCamara(GLFWwindow *window, double x,double y){
    x = x - 250;
    y = -(y - 250);
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) != GLFW_RELEASE){
        if (x >= 0){
            alphaX = (float) (x * 89) / 250;
        }else if (x < 0){
            alphaX = (float) (x * 89) / 250;
        }
        if (y >= 0){
            alphaY = (float) (y * 89) / 250;
            if (alphaY >= 89.0){
                alphaY = 89.0;
            }
        }else if (y < 0){
            alphaY = (float) (y * 89) / 250;

            if (alphaY <= -89.0){
                alphaY = -89.0;
            }
        }
    }
}

void funcionFovy(GLFWwindow * window, double desplazamientoX, double desplazamientoY){
   if(desplazamientoY == 1){
        if((fovyPrincipal >= 10) && (fovyPrincipal  < 150) ){
            fovyPrincipal += 5.0;
        }
    }
    if(desplazamientoY == -1){
        if((fovyPrincipal > 10) && (fovyPrincipal  <= 150) ){
            fovyPrincipal -= 5.0;
        }
    }
}

void funKey(GLFWwindow* window, unsigned int key) {
    switch (key) {
        case 'c':
            rotCamara = rotCamara + 1.0;
            break;
        case 'C':
            rotCamara = rotCamara - 1.0;
            break;
        case 'p':
            if(press = -1){
                /*fovyPrincipal = 50.0;
                alphaX = 45.0;
                alphaY = 45.0;*/
                fovyPrincipal = 10.0;
                alphaX = 0.0;
                alphaY = 10.0;
            }
            break;
        case 'P':
            if(press == -1){
                fovyPrincipal = 120.0;
                alphaX = 0.0;
                alphaY = 10.0;
            }
            break;
        case 'e':
            if(press == -1){
                escX -= 0.1;
                escZ -= 0.1;
                trasZ += 0.05;
                if((escX < 3.0) && (escZ < 3.0) && (trasZ > 1.0)){
                    escX = 3.0;
                    escZ = 3.0;
                    trasZ = 1.0;
                }
            }
            break;
        case 'E':
            if(press == -1){
                escX += 0.1;
                escZ += 0.1;
                trasZ -= 0.05;
                if((escX > 4.0) && (escZ > 4.0) && (trasZ < 0.5)){
                    escX = 4.0;
                    escZ = 4.0;
                    trasZ = 0.5;
                }
            }
            break;
    }
}