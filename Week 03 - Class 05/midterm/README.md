# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

# MIDTERM

## START THE MIDTERM, PROPOSAL DUE WED, NOV 11th/PROJECT DUE WED, NOV 18th 

Your midterm project package will include: a project proposal due one week before presentations, you’re working midterm application, the code from your application and the PowerPoint you use during your presentation.

Start by coming up with a general project concept. What do you want to visualize or create? What type of animation and interaction would help you achieve that goal? Now break that idea down into classes: what are the core elements of your concept? What attributes do those elements have (variables)? What behaviours could they exhibit (functions)?

You should have a concept and some rough, initial prototype code ready to share with me before the next class as a project proposal, **Wed, Nov. 11th**. An example proposal will be shared with you in class. **The proposal should be about 750 words. Your proposals will be returned to you before 12:00, Fri, Nov. 13th**.

* **Code an app in C++/openFrameworks that produces an interactive animation**, and which speaks to your own artistic or design interests!

Feel free to explore generative design, physics simulation, games, abstract composition, color, images, drawing, data or math visualizations, motion graphics, or any aesthetic direction you wish. You should show off your own skills and unique interests.

You are welcome to combine this project with other classwork or outside work - but you must use openFrameworks, and there must be animation and interaction elements to your application.

* **Be ready to demo the app on the big screen in class on Wed, Nov. 18th.** 

* You should organize your code using classes, objects, `vector`, and any of the C++ programming techniques we've learned so far in a PPT for the presentation.

### Animation techniques you can use:

+ `glm::vec2`, velocity, forces, attraction, particles, particle systems...
+ interpolation, `ofMap()`, scale...
+ oscillation, `sin(), cos(), atan2()`, rotation, angles...
+ `ofColor(), ofNoise(), ofGetElapsedTimef()`...

+ or feel free to explore techniques of your own choosing and interpretation!
  
_PS:_ To load and draw images, check out [`ofImage()`](http://openframeworks.cc/documentation/graphics/ofImage/) in the openFrameworks docs ([further reading in ofBook](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing))
    
    
### Interaction 

Focus on mouse and keyboard!  Keep it simple first...

```c++
    ofGetMouseX(); ofGetMouseY(); ofGetPreviousMouseX(); ofGetPreviousMouseY();
    
    // ofApp functions
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
```
- **GUIs: If you're interested in creating a quick UI, check out [Lewis Lepton's YouTube channel](https://www.youtube.com/watch?v=X_is1x8iVtw&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=20)**, where he goes through using ofxGUI for animation.  

I encourage you to focus on the animation aspects - try to figure out how to create the motion and the colors, shapes, and images that you envision.  Be sure you achieve that core animation before you get too caught up in addons, or extra technologies for fancy interactions. Your effort should be primarily on the look and feel of your animated "world".
