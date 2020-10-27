# ComputerGraphics2020

MEDIART 206: Computer Graphics - openFrameworks
	
Fall Session 2 2020	 

What is this course about?<br>

This course offers a deep dive into the fundamentals of creative software development in C++ / openFrameworks (oF) as well as an overview and history of computer graphics. A special focus will be placed on producing interactive artwork using 3D animation and computer vision beginning with the fundamentals of C++ and Object-Oriented Programming. Students will learn about different computational techniques, mathematical and graphical principles, and interactive trigonometric principles will be taught to understand the core of physics simulations and design of complex systems using multiple forces to see how collective patterns can emerge from individual behavior. Some of these concepts include coordinate systems and geometric transforms; drawing routines, antialiasing, supersampling; 3D object representation, spatial data structures, constructive solid geometry; hidden-surface-removal algorithms, z-buffer, A-buffer; illumination and shading models, surface details, radiosity; achromatic light, color specification, colorimetry, different color models; graphics pipeline; animation, levels of detail. Students will gain an in-depth understanding of how to build creative and interactive software, from design to development and deployment. Students will complete homework assignments for each course meeting in the form of code "sketches." In addition, students will spend several weeks building and presenting both a midterm and final project, applying learned concepts to create their own creative computer programs.

Watch the oF 3D primitives example I recorded: <br>
●	https://warpwire.duke.edu/w/E70DAA/

Awesome artwork and projects built with openFrameworks: <br>
●	https://www.creativeapplications.net/category/openframeworks/<br>
●	https://devart.withgoogle.com/#/?q=openframeworks

More about openFrameworks: <br>
●	https://openframeworks.cc/<br>
●	https://openframeworks.cc/zh_cn/

_Credits:_
_The content of this course is greatly indebted to [Tyler Henry](http://tylerhenry.com) from which much of this course originates, [Regina Flores Mir](http://www.reginafloresmir.com/),  [AlgoSims2016](https://github.com/reginaflores/AlgoSims2016), [Bryan Ma](http://bryan-ma.com/), [Bernardo Schorr](http://www.bernardoschorr.com/), [Patricio Gonzalez Vivo](http://patriciogonzalezvivo.com/), everyone at Parsons Design + Technology as well as the work of [Zach Leiberman](http://sfpc.io/), and countless other contributors to the OpenFrameworks community._  

You may find additional help and inspiration in the examples contained in the following repositories:

* [Algo2012](http://github.com/ofZach/algo2012) by [Zach Lieberman](http://thesystemis.com/)
* [Algo2013](https://github.com/cwhitney/algo2013) by [Charly Whitney](http://www.sharkbox.com/)
* [Sims2014](https://github.com/patriciogonzalezvivo/sims2014) by [Patricio Gonzalez Vivo](http://patriciogonzalezvivo.com/)
* [Animation by Code 2015](https://github.com/bschorr/OFAnimation_Spring2015) by [Bernardo Schorr](https://github.com/bschorr)
* [Creative Coding 2015](https://github.com/conorrussomanno/CreativeCoding_oF_F15) by [Conor Russomanno](https://github.com/conorrussomanno)
* [AlgoSims2016](https://github.com/reginaflores/AlgoSims2016) by [Regina Flores Mir](https://github.com/reginaflores)

##### RESOURCES

##### C++ and oF
Because we will code in C++, the sooner you get comfortable with it the better. There is A LOT of helpful extra material:

* [ofBook](https://github.com/openframeworks/ofBook/tree/master/chapters)

* [Stanford University - CS107 - Programming Paradigms](http://videolectures.net/stanfordcs107s08_programming_paradigms/) by Jerry Cain

* [Effective C++](http://www.amazon.com/Effective-Specific-Improve-Programs-Designs/dp/0321334876/ref=sr_1_23?ie=UTF8&qid=1408141753&sr=8-23&keywords=c%2B%2B) by Scott Meyers

As regular consulting material you will probably want to have the following links pre-bookmarked on your browser:

* [cplusplus.com](http://www.cplusplus.com/) (Note you may like [Dash](http://kapeli.com/dash) on MacOS)

* [OpenFrameworks Forum](http://forum.openframeworks.cc/) 

* [OpenFrameworks IRC Channel](http://webchat.freenode.net/?channels=openframeworks&uio=MT1mYWxzZSY5PXRydWUmMTE9Mjk39)

* StackOverFlow [C++](http://stackoverflow.com/questions/tagged/c%2b%2b), [CodeBlocks](http://stackoverflow.com/questions/tagged/codeblocks) & [Xcode](http://stackoverflow.com/questions/tagged/xcode) (There is an openFrameworks tag, but is better if you use the OF-forum for questions.)

##### Algorithms and Simulation
There are a huge number of papers, books and examples online about algorithms and simulation. Not all of them are in C++, but hopefully you will train yourself to interpret and translate them. Here are some friendly approaches:

* [Nature of Code](http://natureofcode.com/book/) by Daniel Shiffman

* [FORM+CODE](http://www.amazon.com/Form-Code-Design-Architecture-Briefs/dp/1568989377/ref=pd_sim_b_5?ie=UTF8&refRID=1JSMXNRNDJXKC5N91R2J) by Casey Reas

* [Generative Design](http://www.amazon.com/dp/1616890770/ref=wl_it_dp_o_pC_nS_ttl?_encoding=UTF8&colid=2P8RIIKRMUEMF&coliid=I5PWJK09L1FVH) by Hartmut Bohnacker, Benedikt Gross, Julia Laub and Claudius Lazzeroni

* [The Computational Beauty of Nature](http://www.amazon.com/gp/product/0262561271/ref=oh_aui_detailpage_o07_s00?ie=UTF8&psc=1) by Gary William Flake ( [here](https://github.com/gwf/CBofN) are the code examples from the book)

* [The Algorithmic Beauty of Plants](http://algorithmicbotany.org/papers/abop/abop.pdf) by Przemyslaw Prusinkiewicz and Aristid Lindenmayer

* [Golan’s](http://golancourses.net/2013/lectures/lecture-01-30/) class notes of Generative Art

##### Computer Vision
In the second half of the semester, we will focus on the use of computer vision to create software that can "see".  We will primarily use the OpenCV library, the most popular open-source platform for computer vision in C++.

* [OpenCV library](http://opencv.org/)
* [ofxCv addon](https://github.com/kylemcdonald/ofxCv) by [Kyle McDonald](http://www.kylemcdonald.net/)
* [learnopencv.com](https://www.learnopencv.com/) C++ tutorials and examples by Satya Mallick
* [Learning OpenCV book](http://www-cs.ccny.cuny.edu/~wolberg/capstone/opencv/LearningOpenCV.pdf) by Gary Bradski and Adrian Kaehler

##### GLSL Shaders
We will speak briefly about shaders and their implementation in OF. Here are some resources:

* [The Book of Shaders](http://patriciogonzalezvivo.com/2015/thebookofshaders/) by [Patricio Gonzalez Vivo](http://patriciogonzalezvivo.com/)
* [Shader Studio 2015](https://github.com/patriciogonzalezvivo/ss2015) by [Patricio Gonzalez Vivo](http://patriciogonzalezvivo.com/)
* [Shader Toy](https://www.shadertoy.com/)
