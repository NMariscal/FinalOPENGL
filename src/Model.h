#ifndef MODEL_H
#define MODEL_H

#include <iostream>
// vectores y matrices
#include <vector> // vector estándar de c++
#include <GL/glew.h>
#include <glm/glm.hpp> // manejar vectores y matrices
#include <glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp>
// end vectores
#include <assimp/scene.h> // para cargar modelos
#include <assimp/postprocess.h>

#define I glm::mat4(1.0)

class Model {
    
    public:
                        
        void initModel  (const char *modelFile);
        void renderModel(unsigned long mode);        
               
        virtual ~Model();
               
    private:
        // vertices
        std::vector<glm::vec3>      positions; // donde meto el primer elemento
        std::vector<glm::vec3>      normals;
        std::vector<glm::vec2>      textureCoords;
        std::vector<unsigned short> indices;

        //  vbo para las posiciones normales y texturas  = identificador único 
        unsigned int vao;
        unsigned int vboPositions;
        unsigned int vboNormals;
        unsigned int vboTextureCoords;
        unsigned int eboIndices; // para los indices = element bufer object

};

#endif /* MODEL_H */
