# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

Week 04 - Class 07


## Code Bugs

Visual Studio allows for this code to execute though it is wrong:
``ofVec2f ofApp::getForce(float posX, float posY);``

You will get this error on other C++ compiliers: Extra qualification on member 'getForce'

If you encounter the error, change the code similar to below

``ofVec2f getForce(float posX, float posY);``

