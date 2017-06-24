# RTv1
The hole purpose of this project is to learn and implement the basics of ray tracing to pave the way for the final year project RT. 
 
## What is Ray tracing? 
 
> In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. - Wikipedia
 
Let's take a look at the figure below... So ray tracing is a computer graphic technique used to render a 3D scene (here the sphere) into a 2D screen (image). To do so we throw rays from a point a view (here represented by the camera objective) through the pixels of the screen and see what is the first object of the scene they hit. That help us to determine the color of the pixel we should display on the image. This is the basics of rt, but with this simple method we don’t take into account the refraction nor the light source. We just display the pixels of the rays that hit the sphere. 
