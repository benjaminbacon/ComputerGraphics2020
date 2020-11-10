# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
    
Fall Session 2 2020     

Week 03 - Class 06

## Final Exam

**Monday December 14th, 15:30 - 18:30 -- Room IB1012**

## Code Examples

 - **00_attraction-repulsion_in-class** apply attraction and repulsion forces to a grid of "Movers", in-class coding exercise
 - **01_attraction-repulsion_extra** slightly more complex version of above, with extra features (toggle forces, etc.) and comments
 
 ## Homework
 
 ### Reading
 
 [`ofImage()`](http://openframeworks.cc/documentation/graphics/ofImage/) in the openFrameworks docs ([further reading in ofBook](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing))
 
 ### Sketches
 
**1. Fatal Attraction**
 
Using forces, create a sketch that is a game about love using **attraction** and **repulsion**. Get creative, and don't feel limited by duplicating the actual laws of physics but the laws of attraction. Your objects should be instances of classes that you design similar to last sessions course. They should use **forces** like **attraction** and **repulsion** (or design your own forces). It must be an interactive game!


## Class Review

### Loading/drawing images: 

[`ofImage()`](http://openframeworks.cc/documentation/graphics/ofImage/) in the openFrameworks docs ([further reading in ofBook](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing))

### Attraction and Repulsion Forces

Attraction and repulsion are relative forces, applied between objects.  One object may be attracted to, or repulsed by, another object.  This is different than "universal" forces such as "gravity" / "wind", which apply to everything in our scene.

In general, attraction force is calculated based on the vector from an object to its target (the object it is attracted to).  That vector is calculated:

```c++
glm::vec2 vector = target.pos - object.pos;    
// this vector represents an arrow pointing from the object to its target
```

That vector represents both the direction, and the distance from the object to its target.  
We can isolate the direction of the vector (and ignore the distance) by "normalizing" the vector (assigning its length to 1).  To normalize a vector, we divide it by its length:

```c++
float distance = glm::length(distance);
if (distance != 0){
    glm::vec2 norm = vector / length;    // be careful never to divide by 0! 
}
```

Now just apply the normalized vector as a force on the object (scaling it to alter the strength of the force).
All together:

```c++
glm::vec2 vector     = target.pos - object.pos;    
float distance         = glm::length(distance);
if (distance != 0){
    glm::vec2 norm = vector / length;    // be careful never to divide by 0! 
    object.applyForce( norm * 0.1 );    // 0.1 is attraction force strength here
}
```

Repulsion is simply the inverse of attraction.  Just make the force negative:

```c++    
object.applyForce( -norm * 0.1 );    // move away from target
```

### Elastic Force

Elastic force is simply an attraction of an object to its original position, after it has been moved.  It bounces back to its start.
The only difference here is that the object should keep track of its original position.  The original position is its attraction "target".

```c++
// elastic force bounces back to original position

glm::vec2 vector     = object.originalPos - object.pos;    // original position is the target
float distance         = glm::length(distance);
if (distance != 0){
    glm::vec2 norm = vector / length;    // be careful never to divide by 0! 
    object.applyForce( norm * 0.1 );    // 0.1 is attraction force strength here
}
```
