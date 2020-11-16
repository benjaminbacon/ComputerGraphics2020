# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

Week 04 - Class 07

## Midterm Presentations Day Change

Due to a couple of logisitcal issues, we will hold the midterm presentations and application demos on **Monday, November 23rd - Week 05: Class 09** 

- Your midterm propsals are really good. Thanks!

- We will have Prof. Xu and others join us to critique your presentation and application.

- This allows you several extra days to polish your presentation and application. If you have questions, e-mail or come to my office hours.

- Please upload your presentation and application to your Github **before midnight Sunday, November 22nd**. I will check the timestamp. 

- Because of this we will combine course 08 and course 09 lectures into one lecture for the next course (course 08). This will leave course 09 for only presentations and application demos.

## Code Workshops

There is a request for code workshops. If we set this time up, when is a good time and what topics do you want covered? 

## Code Bugs

Visual Studio allows for this code to execute though it is wrong:
``ofVec2f ofApp::getForce(float posX, float posY);``

You will get this error on other C++ compiliers: Extra qualification on member 'getForce'

If you encounter the error, change the code similar to below

``ofVec2f getForce(float posX, float posY);``

## Some inspiration

- **[Thomas Wilfred](https://www.google.com/search?tbm=isch&q=Thomas+Wilfred)**
- **[Jim Campbell](https://www.vice.com/en_us/article/av43jz/jim-campbells-sculptural-led-light-installations)**
- **[Evan Roth - GRL](https://theinfluencers.org/en/evan-roth/video/1)**

## Example Code

### Continuation from course 06 (particles and forces)

- **`flowField`** - particles flow over a 2D grid of forces / terrain
- **`flowFieldImage`** - load an image as a flow field
- **`grid`** - prototype an LED array on screen
- **`screenGrabGrid`** - demo of capturing the screen and reading colors
- **`steering`** - demo of "steering" behavior, where mover seeks a target

### Drawing in 3D

- **`sphere`**: simple 3D sphere
- **`bouncing_spheres`**: 3D spheres bouncing inside a 3D box
- **`drawing_3D`**: drawing in space (with the Z axis)
- **`noisy_sphere`**: use noise to warp sphere vertices (and map webcam texture to sphere)

## Homework

There is no homework for today. Work on your midterm application and presentation. **We will have homework next course so use this time wisely.**

