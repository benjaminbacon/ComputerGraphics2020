//
//  flower.hpp
//  tw229_dkuOF_2020_w1c02hw01
//
//  Created by 吴桐 on 10/30/20.
//

#ifndef flower_hpp
#define flower_hpp

#include <ofMain.h>

#endif /* flower_hpp */

class Flower{
public:
    
    Flower();
    void update();
    void draw();

    float radius;        // size
    float x, y;            // position
    float dirX, dirY;
    float red    = ofRandom(150,235);
    float green    = ofRandom(190,225);
    float blue    = ofRandom(150,200);
    float r=red;
    float g=green;
    float b=blue;
    float theta;
    int frames=90;
    int flowerrotating;
    ofColor colorcenter;
    ofColor colorpetal;
    ofColor colorheart;
};
