# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

Week 03 - Class 05

## Creative Grading

If it is a homework assignment, the assignment is graded 50% technical and 50% creative. Many of you have asked what is meant by creative. Below you can find what is defined as technical and creative. 

50% Technical

* Code is functional and uses programming techniques appropriately, eg. object orientated programming where functions and objects are used to avoid repetition. Interaction design is considered so that the code operates as intended in a way that supports the underlying concept of the project (eg. details such mouse clicks or key press interactions are well designed). Code is clearly commented, referenced and formatted.

50% Creativity (25% for each)

* Concept: Your response is inventive and you are exploring ideas and questions outside of the obvious and predictable. Your project may respond to historic ideas or practices of art or design, however exploring these questions or subject matter in new ways.

* Aesthetic: The project is visually/sonically well resolved. This does not necessarily mean that your work is beautiful, but it must show a careful consideration of aesthetic choices where close attention has been paid to details such as font choices, color palette and compositional rhythm. These elements relate to the concept and intention behind the work.

If the assignment is your midterm or final project then documentation is also considered. So the breakdown would be 25% for technical, 25% for concept, 25% for aesthetic and 25% for documentation.

* Well documented: The presentation and proposal describing your project is well written, in sophisticated grammatically correct English. Your documentation shows project research and includes references to influences and research materials. It also includes appropriate visual/sonic materials documenting your work such as screenshots, GIFS or video material. It should clearly explain the intention behind your work to a non-expert audience. It should also include a link to the code on  Github.

## MIDTERM

**[Midterm Instructions](midterm/README.md)**

## Example Code

### From in-class code:

- **01_particle_systems** - create particle emitters on mouse click  
- **02_attraction** - simple attraction force, follow the mouse

### More examples:

- **03_attraction_repulsion** - create a grid of Movers, apply attraction and repulsion based on mouse
- **04_attractors** - create Attractor class, model gravity (see [Reading](#gravity))
- **05_elastic** - create an elastic force, particles spring back to starting point

## Homework

### Reading: The Nature of Code

- <a name=gravity>**[The Nature of Code: Chapter 2 Section 9 "Gravitational Attraction"](http://natureofcode.com/book/chapter-2-forces/#chapter02_section9)**

- **[The Nature of Code: Chapter 4 "Particle Systems"](http://natureofcode.com/book/chapter-4-particle-systems/)**

    Remember that **The Nature of Code** is written in the Processing language (Java), but the concepts of physics-based animation are easily translated to C++/oF and the C++/oF examples are on the course GitHub.
    
- Check out **Lewis Lepton's openFrameworks YouTube series**.  It is designed for beginners, but covers some concepts we haven't yet seen, like _ofxAddons_, video, sound, and GUI controls.

    **[Here's the first episode on creating a GUI using ofxGUI](https://www.youtube.com/watch?v=X_is1x8iVtw&list=PL4neAtv21WOmrV8z9rSzL20QpdLU1zJLr&index=20)**

### Sketches

1. **Interstellar**

    Create a "space" scene, taking inspiration from the orbital motion of galaxies, stars, planets, moons, comets, asteroids... (... and black holes? :sweat_smile:)  Get creative, and don't feel limited by duplicating the _actual_ laws of physics.  You can modify physics to suit your ideas!
      
    Your objects (e.g. your stars, planets, or asteroids, etc.) should be instances of classes that you design.  They should use **forces** like **_attraction_** and **_repulsion_** (or design your own forces).
    
    Now make it interactive! :innocent:
    
    **Bonus:** Game-ify it!  Think about classic space shooters, like [Asteroids](https://www.kevs3d.co.uk/dev/asteroids/index-debug.html)...

2. **Firework Display** 

    Using **particle systems**, create a sketch that makes colorful firework-like explosions.  The "explosions" should be composed of **_particles_** that _decay_ over time (and probably are affected by gravity, or other forces)...
    
    **Bonus:** Make an interactive firework *launcher* (for example, angle and force of launch is controlled by mouse - think *Angry Birds*...)
    
## Class Review

### The new GLM syntax

The new version of openFrameworks replaces the internal math library with GLM. GLM is a solid C++ library used for all the math operations needed when doing vectors and matrices operations. The use of this library implies some change in the syntax used to declare vectors and to execute vector's operation. The legacy mode is still supported, but the new mode, enabled by default, uses the new glm syntax.

If you are not interested using this library and you want to continue using the syntax you were used to, or if you want to run an old project using the last openFrameworks master branch, you can define the OF_USE_LEGACY_MESH constant in ofConstants.h. Doing this, glm will be disabled for ofPolyline and ofMesh.

Let's take a look: [GLM in oF](https://openframeworks.cc/learning/02_graphics/how_to_use_glm/)

### Normalizing Vectors

Recall that a vector has both a direction and a magnitude.  
What if we just want to know the direction, but don't care about the magnitude?  

When we **normalize** a vector, we set its magnitude to 1.0, but keep the direction.  
A vector with a magnitude of 1.0 is called a _unit vector_.
   
To **normalize**, we just divide the vector by its magnitude: 

```c++
 glm::vec2 vec    = glm::vec2(3,3);
 float length     = glm::length(vec);

 glm::vec2 normVec;
 if (length != 0)     // avoid dividing by 0!!!
 {
     normVec = vec / length;
 }
 ```

Use the `glm::length(vec)` function to get the length of any vector.  

_Note: Before normalizing, check the length is not 0.  
Always avoid dividing by 0 - it will crash your app!_

### Forces: Attraction, Repulsion and Damping (a.k.a. drag)

**Attraction and repulsion** are forces that describe interaction **between** objects.  
These simple forces allow us to create complex physics systems, where multiple objects affect each other.  

Attraction is a force based on the direction of an object to a target (the "Attractor").  
To get the direction, we **normalize** the vector between the objects:

```c++
 // Attraction

 glm::vec2 dir               = target.pos - mover.pos;
 float distance              = glm::length(dir);
 float attractionStrength    = 0.5; 

 if (length != 0) {
     glm::vec2 attraction    = dir/distance * attractionStrength;
     mover.applyForce(attraction);
 }
 ```

**Repulsion** is simply the inverse of **attraction**:

```c++
 // Repulsion

 glm::vec2 dir               = target.pos - mover.pos;
 float distance              = glm::length(dir);
 float repulsionStrength     = 0.5; 

 if (length != 0) {
     glm::vec2 repulsion     = dir/distance * repulsionStrength * -1;    // invert by multiplying by -1
     mover.applyForce(repulsion);
 }
 ```
    
A **damping** force slows things down.  It's also called "drag".  
It creates the feeling of moving through fluid, where objects will eventually come to a stop.

We create a **damping** force by pushing on the object in the inverse direction of its velocity:

```c++
 float speed             = glm::vec2(mover.velocity);
 if (speed != 0) {
     glm::vec2 damping   = mover.velocity / speed * -0.01;     // 0.01 damping
     mover.applyForce(damping);
 }
 ```

### Particle Systems

We can think of a "particle system" as simply a class that manages a collection of particle objects.  
In our case, this collection is a `vector<Particle>`.
 
The particle system takes care of creating new particles:  

```c++
 particles.push_back(Particle());
 ```  

and removing particles when the vector is getting too large:

```c++
 // remove as many particles as needed to keep size < 1000

 while (particles.size() > 1000) {            // max 1000 particles
     particles.erase(particles.begin());     // erase the first particle from the vector
 }
 ```
