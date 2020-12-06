# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
Fall Session 2 2020  

Week 07- Class 13  – Monday December 7th – Shaders, Graphics Pipeline, Kinect, Face Tracking

# UPDATES

- We will hold the student showcase during the first week of session 3.
- Kinect is not working for some of you. We will go through installing it today for both ofxNI2 and ofxKinectForWindows2.

## KINECT V2

We are using the `Kinect for X-Box (V2)` Model 1520. 

Check out and read up about the Kinect V2 NI2 add-on and how to install it on Mac and Windows: [ofxNI2][2]. 

Windows: [ofxKinctForWindows2](https://github.com/elliotwoods/ofxKinectForWindows2).

You can check out a Kinect V2 from the Media & Arts cage.

## Code

- **Shader Mask** - Mask one image texture using another (eg. create a spotlight effect)
- **Fragment Shader** - Fragment shader masking and `ofFbo` (FBO = `frame buffer object` off-screen drawing canvas)
- **Vertex Shader** - Distort a 3D plane mesh using a vertex shader (sin waves)
- **Face Tracker - AR** - Track your face and a hat on the top of your head. ofxCV blob tracking, face detection and tracking, ofxTSNE example.
- **ofPath To Mesh** - ofxAddon ofPath to create a mesh.
	  
**KINECT**
 - **035\_ofxKinectV2** - ofxKinectV2.
- **036\_ofxKinectV2Haar** - ofxKinectV2.
- **kinect2-NI-ParticlePainter** - ofxNI2..

## Review

### notes on OpenCV:
---------------
 
OpenCV is the most popular library for computer vision - it's used by everyone from academics to Snapchat engineers to artists.

It's a huge, powerful collection of image processing and machine learning algorithms written in C++.

oF works well with OpenCV, through 2 addons:

 + **ofxOpenCv** adds the OpenCV library to your project  
    this addon comes with oF

 + **ofxCv** provides an elegant interface to bridge oF and OpenCV  
    download / learn about ofxCv here:
    https://github.com/kylemcdonald/ofxCv

`ofxCv` has a ton of functions and classes that work beautifully out of the box in oF.  It can handle object detection, tracking, blob detection, and much more.

In addition, it can convert native oF classes to native OpenCV classes, so you can work directly with any OpenCV algorithms.  

Here's an example of how to convert an `ofImage` to a native OpenCV `Mat` object (an image "matrix"):  

```c++

   ofImage img;
   img.load("image.png");
   Mat imgMat = toCv(img);   ofx::toCv(ofImage)

   // now you can use the image as a Mat with any OpenCV algorithm
```

### Kinect V2 Tutorials

**We will go over this in class today:**

Dan Buzzo

[Kinect2 Natural Interaction Skeleton Tracking Tutorial in openFrameworks: Part 01][5]

[Kinect2 Natural Interaction Skeleton Tracking Tutorial in openFrameworks: Part 02][6]

You will need to install [LibFreenect2][7] AND [ofxNI2][8] to get this working. Follow the instructions on the GitHub page. 

## Homework

No more homework for class. Work on your final projects until presentations.

[1]:	https://github.com/ofTheo/ofxKinectV2
[2]:	https://github.com/roymacdonald/ofxNI2
[3]:	https://www.youtube.com/watch?v=yeBcKppa9UM
[4]:	https://youtu.be/YCduMQTZq_w
[5]:	https://www.youtube.com/watch?v=HF74L-DvCUE
[6]:	https://www.youtube.com/watch?v=Hn_onMOUcno
[7]:	https://github.com/OpenKinect/libfreenect2/
[8]:	https://github.com/roymacdonald/ofxNI2
