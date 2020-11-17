# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

Week 04 - Class 08 + Week 05 - Class 09

## Midterm Presentations Day Change

Due to a couple of logisitcal issues, we will hold the midterm presentations and application demos on **Monday, November 23rd - Week 05: Class 09** 

- Your midterm propsals are really good. Thanks!

- We will have Prof. Xu and others join us to critique your presentation and application.

- This allows you several extra days to polish your presentation and application. If you have questions, e-mail or come to my office hours.

- Please upload your presentation and application to your Github **before midnight Sunday, November 22nd**. I will check the timestamp. 

- Because of this we will combine course 08 and course 09 lectures into one lecture for the next course (course 08). This will leave course 09 for only presentations and application demos.

## Currnet Grade Distribution 

- 5 Homework Assignments. 
- These count for 10% of your final grade.

``` c++  
    2 x A+
    1 x A-
    1 x B+
    1 x B
    2 x B-
    1 x C+
    2 x C
    1 x D
    4 x F

```

## Example Code

### Vector/Collision

- **`Vector Field`** - Create a Vector Field
- **`Collision Detection`** - Collision Detection

### Camera
- **`Slit Scan`** - shows how to sample from the webcam to make [slit scan](https://www.youtube.com/watch?v=NSesvu_uqLo) photos

### 3D & Scenes

- **`3d Basics`** - Draw a simple triangle from 3 points, and a sphere

### 3D Lighting

- **`Waver`** - 3D mesh grid, displaying image, with lighting and cameras
- **`LightsShapes`** - Create simple shapes and light them     

### Meshes

- **`Mesh Webcam`** - Warp a mesh based on webcam input    
- **`3d Slit Scan`** - Similar to `MeshWebcam` but uses slit-scan from webcam 
- **`Terrain`**  - Build a terrain based on a "height map" image. Apply a painted texture and accurate lighting (using normals)  
- **`Plane Mesh GUI`** - build a 3D plane (a grid mesh) modified by noise waves
   - uses ofxGui addon (+ ofParameter) to generate noise waves
- **`Volcano Particles`** - 3D particle system, volcano mesh and 3D lighting


## Review

### Using images

We can load images or video from many sources into openFrameworks... 

Images:

```c++
ofImage image;
image.load("image.jpg");  // or image.png, etc.
```

Video files or Webcam:

```c++
ofVideoGrabber camera;  // webcam source
ofVideoPlayer video;    // video file source

void ofApp::setup() {

    // start a webcam
    camera.listDevices();       // prints your available cameras to console
    camera.setup(640, 480);     // or camera.setup(1, 640,480) for camera #1
    
    // or load a video
    video.load("video.mp4");    
    video.play();               // start the video
}

void ofApp::update() {

    // update the video sources every frame
    camera.update();
    video.update();
}   
```

Once we've loaded the image or video into our application, we can:

+ access the pixels (to analyze or alter them)
+ draw the image in 2D or 3D

We use the graphics card when we **draw** an image, and in this case we call the image a **texture**.  
  
The `ofImage` class contains both an `ofPixels` component for pixel manipulation and an `ofTexture` component for drawing on screen:

```c++
ofImage image;
image.load("image.jpg");

// you can do this:
// ofColor color = image.getColorAt(0,0);      // access image pixel
// image.draw();                               // draw image on screen

// or access the image pixels and texture manually:

ofPixels pixels = image.getPixels();        // access the image's pixels
ofColor color   = pixels.getColorAt(0,0);   // access a single pixel

ofTexture texture = image.getTexture();     // access the drawable texture
texture.draw();                             // draw the image texture

```

### Meshes (`ofMesh`) - the building block of 3D

A `mesh` is a 3D surface made of triangles `▲▼▲▼▲` ( which form polygons `◤◢ => ▢` )

A 3D mesh is:

+ **vertices**: a bunch of points in 3D space
+ **indices**: a list of connections between the points to form triangles (or polygons)

In openFrameworks we often use the `ofMesh` class to represent a 3D triangle mesh.

`ofMesh` contains a bunch of data - most importantly, our vertices and indices.  

There are also additional (optional) data sets like texture coordinates, colors, and normals.

ofMesh has 2 vectors for drawing points and triangles:

- `vector<glm::vec3> vertices    // 3D points`

- `vector<int> indices           // triangle connections` 

```
  indices are the vertices that form triangles -

      e.g. triangle a,b,c  =>  vertices[a],vertices[b],vertices[c]

      to make a mesh grid:

        1 rectangle   =>        2 triangles

         A-------B          A-------B        B
         |     / |          |     /        / |
         |   /   |    =>    |   /   +    /   |
         | /     |          | /        /     |
         C-------D          C        C-------D

    indices are grouped in threes - a,b,c - clockwise:
    e.g: 0,1,2... 3,4,5... etc  ==> [0,1,2,3,4,5...]
    
```

```c++
ofMesh mesh;

// add 3 vertices
mesh.addVertex( ofVec3f(0,0,0) );       // vertex index 0
mesh.addVertex( ofVec3f(100,0,0) );     // vertex index 1
mesh.addVertex( ofVec3f(0,-100,0) );    // vertex index 3

// add 3 indices to our indices list to form a triangle:
mesh.addIndex(0);
mesh.addIndex(1);
mesh.addIndex(2);

// add color tint to our vertices
mesh.addColor( ofColor::red );      // vertex 0 will be red
mesh.addColor( ofColor::green);     // vertex 1 will be green
mesh.addColor( ofColor::blue);      // vertex 2 will be blue

// add texture coordinates per vertices
// this is how we will map an image texture to our mesh
mesh.addTexCoord( ofVec2f(0,0) );       // image(0,0) at vertex index 0
mesh.addTexCoord( ofVec2f(640,0) );     // image(640,0) at vertex index 1
mesh.addTexCoord( ofVec2f(0,480) );     // image(0,480) at vertex index 2

// for working with normals, see Week10/Terrain example...

```

# & references

'&' is a special symbol used when declaring variables
it means they reference another variable directly.  they act like a temporary nickname:

```
float& boxSize = box.getSize();        // returns float&
boxSize += 3;                        // box.size += 3
```

## Homework

**Code:**

1. **Finish your midterm project.**

2. Work on a sketch of your choosing.  You could:

 - Rework an old project from your homework repo into a 3D scene
 
 OR
 
 - Prototype an idea or technique you might want to use for your final
 
 OR 
 
 - Try out an [ofxAddon](http://www.ofxaddons.com/)

**Reading:** 

3. Read the [**Generating Meshes from Image**](http://openframeworks.cc/ofBook/chapters/generativemesh.html) chapter of **ofBook**  
   - this will review 3D meshes and introduces image sampling

4. Read the **[Preliminaries to Image Processing](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing)** section of **ofBook**  
    - explains how pixels are stored in memory & shows how to access and manipulate them

