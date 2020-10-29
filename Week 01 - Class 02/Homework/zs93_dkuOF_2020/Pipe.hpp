//
//  Pipe.hpp
//  zs93_week1class2
//
//  Created by Zeyu Shen on 10/29/20.
//

#include "ofMain.h"

class Pipe{
public:
    
    Pipe();
    
    void update();
    void draw();
    
    double width, upper, lower;
    double dirX = 1, X;
    
    ofColor color;
};
