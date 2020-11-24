#pragma once
#include "ofMain.h"

class VectorField {
public:
    
    VectorField();
    VectorField(int _rows, int _cols, float _width, float _height);
    
    void setFieldRandomly();
    void setFieldNoisily(float scale);
    
    glm::vec2 getForceAtPos(glm::vec2 pos);
    
    void draw(float scale = 10);
    
    int rows, cols;
    float width, height;
    
    vector<glm::vec2> field;
    
};
