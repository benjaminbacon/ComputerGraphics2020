#include "ofMain.h"

class Ball{
    
public:
    
    Ball();
    
    void update();
    void draw();
    void click_update();
    
    double radius;
    double x, y;
    double dirY, aY = 0.4;
    
    ofColor color;
};
