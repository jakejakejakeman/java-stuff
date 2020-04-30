#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define PI 3.14159f
using namespace std;
class Shape
{
   public:
      virtual void Scale(float scalefactor) = 0;
      virtual void Display() const = 0;
   virtual ~Shape(){}
};
class Shape2D : virtual public Shape
{
   public:
      virtual float Area() const = 0;
      void ShowArea() const;
      virtual string GetName2D() const = 0;
      bool operator>( const Shape2D &rhs) const;
      bool operator<( const Shape2D &rhs) const;
      bool operator==( const Shape2D &rhs) const;
   virtual ~Shape2D(){}
};
class Shape3D : virtual public Shape
{
   public:
      virtual float Volume() const = 0;
      void ShowVolume() const;
      virtual string GetName3D() const = 0;
      bool operator>( const Shape3D &rhs) const;
      bool operator<( const Shape3D &rhs) const;
      bool operator==( const Shape3D &rhs) const;
   virtual ~Shape3D(){}
};
class Square : public Shape2D 
{
   public:
      float side, sarea;
      Square();
      Square(float a);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Square(){}
};
class Rectangle : public Shape2D 
{
   public:
      float rwidth, rheight, rarea;
      Rectangle();
      Rectangle(float b, float c);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Rectangle(){}
};
class Triangle : public Shape2D 
{
   public:
      float tlength, theight, tarea;
      Triangle();
      Triangle(float d, float e);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Triangle(){}
};
class Circle : public Shape2D 
{
   public:
      float cradius, carea;
      Circle();
      Circle(float f);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Circle(){}
};
class Ellipse : public Shape2D 
{
   public:
      float minor, major, earea;
      Ellipse();
      Ellipse(float g, float h);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Ellipse(){}
};
class Trapezoid : public Shape2D 
{
   public:
      float aside, bside, trheight, trarea;
      Trapezoid();
      Trapezoid(float i, float j, float k);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Trapezoid(){}
};
class Sector : public Shape2D 
{
   public:
      float sradius, angle, searea;
      Sector();
      Sector(float l, float m);
      float Area() const;
      string GetName2D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Sector(){}
};
class TriangularPyramid : public Shape3D, private Triangle
{
   public:
      float tpheight, tvolume;
      TriangularPyramid();
      TriangularPyramid(float n, float o, float p);
      float Volume() const;
      string GetName3D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~TriangularPyramid(){}
};
class RectangularPyramid : public Shape3D, private Rectangle
{
   public:
      float rpheight, rvolume;
      RectangularPyramid();
      RectangularPyramid(float q, float r, float s);
      float Volume() const;
      string GetName3D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~RectangularPyramid(){}
};
class Cylinder : public Shape3D, private Circle
{
   public:
      float cyheight, cvolume;
      Cylinder();
      Cylinder(float t, float u);
      float Volume() const;
      string GetName3D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Cylinder(){}
};
class Sphere : public Shape3D, private Circle
{
   public:
      float svolume;
      Sphere();
      Sphere(float v);
      float Volume() const;
      string GetName3D() const;
      void Scale(float scalefactor);
      void Display() const;
      ~Sphere(){}
};
