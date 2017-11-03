# RTv1
The purpose of this project is to learn and implement the basics of ray tracing to pave the way for the final year project RT.

<p align="center"><img src="https://pbs.twimg.com/media/DDGqIf5U0AAqYTW.jpg:large"></p>
 
## What is Ray tracing? 
 
> In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. - Wikipedia
 
You get it? Easy right? Thank you Wikipedia! Let's take a look at the figure below... So ray tracing is a computer graphic technique used to render a 3D scene (here the sphere) into a 2D screen (image). To do so we throw rays from a point a view (here represented by the camera objective) through the pixels of the screen and see what is the first object of the scene they hit. That help us to determine the color of the pixel we should display on the image. This is the basics of rt, but with this simple method we don’t take into account the refraction, reflection nor the light source. We just display the pixels of the rays that hit the sphere. 

<p align="center"><img src="https://user-images.githubusercontent.com/17257576/27506227-2c3803e8-5869-11e7-9659-9f0cfc89ebfe.png" width="400"></p>

## How to start? 

The basic retracer we will build need to be able to render 4 types of structures, planes, spheres, cones and cylanders. Here are the differents formulas we will need for the project. The fillowing has been created by my awesome teamate for the RT project Nicolas Sampre, nsampre's credit for the rest of README! Awesome job!

### Ray Tracing Formulas ✖️➕➖➗

### Tips 👈
When you compute delta, chose the > 0 case (< 0 meaning no intersection, = 0 meaning one intersection)
When you find an intersection solution t, t1 or t2, chose :
- The positive solution (< 0 means behind the origin point)
- The min solution (closer to origin point)

### How did I get those magic formulas ? Am I a mathematician ? Am I a scientist ? Am I a genius ? Hell NO ! I'm a.. GOOGLER ! 👽

Some Ray Tracing explainations :
- https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
- http://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm

Some Ray Tracing mathematical knowledge :
- https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html
- http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm

A bunch of vector operation :
- https://vvvv.org/documentation/3d-vector-mathematics

A bunch of matrix operation :
- http://www.dcode.fr/determinant-matrice
- http://villemin.gerard.free.fr/ThNbDemo/EqaDeter.htm
- http://www.cg.info.hiroshima-cu.ac.jp/~miyazaki/knowledge/teche23.html
- https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions
- http://ncalculators.com/images/formulas/3x3-matrix-formula.jpg


##
## Camera 🎥
### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{direction.x, direction.y, direction.z} (normalize it)
```

### Launching a ray into each pixel of the camera's field of view
```ruby
Assuming 0 < i < WIN_WIDTH and 0 < j < WIN_HEIGHT
Assuming the FoV is 60 degrees
ray.direction.x = ((2 * ((i + 0.5) / WIN_WIDTH)) - 1) * ratio * (tan((60 / 2) * M_PI / 180));
ray.direction.y = ((1 - (2 * ((j + 0.5) / WIN_HEIGHT))) * tan((60 / 2) * M_PI / 180));
ray.direction.z = 1

ray.origin = camera.origin

Later we will handle rotated camera with an inverse matrix to cancel the camera rotation, but for now let's keep it simple with z = 1 and no rotation
```

##
## Plane ✈️

### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{direction.x, direction.y, direction.z} (normalize it)
{color.r, color.g, color.b}
```

### Quadratic
```ruby
b = obj.direction . ray.direction
if b > 0.000001
    a = obj.direction . (obj.origin - ray.origin)
    t = a / b
```

### Normal Unit Vector to a plane on the intersection point
```ruby
if (ray.direction . obj.direction) < 0
    n = vector_negative(obj.direction)
else
    n = obj.direction
n = normalize(n)
```

##
## Sphere 🌝

### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{radius} (square it)
{color.r, color.g, color.b}
```

### Quadratic
```ruby
v = ray.origin - obj.origin
a = ray.direction . ray.direction
b = 2.0 * (ray.direction . v)
c = (v . v) - obj.radius

delta = (b * b) - (4 * a * c)

t1 = (-b - sqrt(delta)) / (2.0 * a)
t2 = (-b + sqrt(delta)) / (2.0 * a)
```

### Normal Unit Vector to a sphere on the intersection point

```ruby
n = normalize(obj.intersection - obj.origin)
```

##
## Cylinder 🍺

### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{direction.x, direction.y, direction.z} (normalize it)
{radius} (square it)
{color.r, color.g, color.b}
```

### Quadratic
```ruby
dot_a = ray.direction . obj.direction
sca_a = obj.direction * dot_a
sub_a = ray.direction - sca_a

dot_b = v . obj.direction
sca_b = obj.direction * dot_b
sub_b = v - sca_b

a = sub_a . sub_a
b = 2 * (sub_a . sub_b)
c = (sub_b . sub_b) - obj.radius

delta = (b * b) - (4 * a * c)

t1 = (-b - sqrt(delta)) / (2.0 * a)
t2 = (-b + sqrt(delta)) / (2.0 * a)
```

### Normal Unit Vector to a cylinder on the intersection point

```ruby
a = obj.intersection - obj.origin
b = (a . obj.direction) * obj.direction
n = normalize(a - b)
```

##
## Cone 🍕

### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{direction.x, direction.y, direction.z} (normalize it)
{angle} (square it)
{color.r, color.g, color.b}
```

### Quadratic

```ruby
cos_sq = cos(obj.angle) * cos(obj.angle)
sin_sq = sin(obj.angle) * sin(obj.angle)

dot_a = obj.direction . ray.direction
sca_a = obj.direction * dot_a
sub_a = ray.direction - sca_a

dot_b = obj.direction . v
sca_b = obj.direction * dot_b
sub_b = v - sca_b

a = cos_sq * (sub_a . sub_a) - (sin_sq * dot_a * dot_a)
b = (2.0 * cos_sq * (sub_a . sub_b)) - (2.0 * sin_sq * dot_a * dot_b)
c = cos_sq * (sub_b . sub_b) - (sin_sq * dot_b * dot_b)

delta = (b * b) - (4 * a * c)

t1 = (-b - sqrt(delta)) / (2.0 * a)
t2 = (-b + sqrt(delta)) / (2.0 * a)
```


### Normal Unit Vector to a cone on the intersection point

```ruby
a = obj.intersection - obj.origin
m = a . obj.direction
A = obj.origin + (obj.direction * m)
k = len(obj.intersection - A) / m
b = obj.direction * m * (1.0 + k * k)
n = normalize(a - b)
```


## Lights 🔆

### Object Definition
```ruby
{origin.x, origin.y, origin.z}
{color.r, color.g, color.b}
```

### Global, diffuse and specular
```ruby
computed_color = {r = 0x00, g = 0x00, b = 0x00}
n = pick_normal_unit_vector_to_obj
L = obj.intersection - light.origin

sca = (L . n) / (n . n * L . L)

if sca > 1
   sca = 1
   
- Global illumination
if sca < 0.2
   sca = 0.2
- Diffuse light :
    computed_color += (obj.color * sca)
- Specular light :
    sca = pow(sca, 41)
    computed_color += (light.color * sca)
	
Assuming computer_color additions are bounded to a max color to prevent overflows
```
