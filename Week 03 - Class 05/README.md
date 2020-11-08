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
    
    
    
