# RTv1
The purpose of this project is to learn and implement the basics of ray tracing to pave the way for the final year project RT.

<p align="center"><img src="https://pbs.twimg.com/media/DDGqIf5U0AAqYTW.jpg:large"></p>
 
## What is Ray tracing? 
 
> In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. - Wikipedia
 
You get it? Easy right? Thank you Wikipedia! Let's take a look at the figure below... So ray tracing is a computer graphic technique used to render a 3D scene (here the sphere) into a 2D screen (image). To do so we throw rays from a point a view (here represented by the camera objective) through the pixels of the screen and see what is the first object of the scene they hit. That help us to determine the color of the pixel we should display on the image. This is the basics of rt, but with this simple method we don’t take into account the refraction, reflection nor the light source. We just display the pixels of the rays that hit the sphere. 

<p align="center"><img src="https://user-images.githubusercontent.com/17257576/27506227-2c3803e8-5869-11e7-9659-9f0cfc89ebfe.png" width="400"></p>
