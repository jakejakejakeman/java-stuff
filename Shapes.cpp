#include "Shapes.h"
bool Shape2D::operator>( const Shape2D &rhs) const
{
   if (Area()>rhs.Area())
      return (true);
   else
      return (false);
}
bool Shape2D::operator<( const Shape2D &rhs) const
{
   if (Area()<rhs.Area())
      return (true);
   else
      return (false);
}
bool Shape2D::operator==( const Shape2D &rhs) const
{
   if (Area()==rhs.Area())
      return (true);
   else
      return (false);
}
void Shape2D::ShowArea() const
{
   cout<<"The area of the "<<GetName2D()<<" is : "<<Area()<<endl;
}
bool Shape3D::operator>( const Shape3D &rhs) const
{
   if (Volume()>rhs.Volume())
      return (true);
   else
      return (false);
}
bool Shape3D::operator<( const Shape3D &rhs) const
{
   if (Volume()<rhs.Volume())
      return (true);
   else
      return (false);
}
bool Shape3D::operator==( const Shape3D &rhs) const
{
   if (Volume()==rhs.Volume())
      return (true);
   else
      return (false);
}
void Shape3D::ShowVolume() const
{
   cout<<"The volume of the "<<GetName3D()<<" is : "<<Volume()<<endl;
}
Square::Square()
{
   side=0;
   sarea=0;
}
Square::Square(float a)
{
   side=a;
   sarea=side*side;
}
float Square::Area() const
{
   return(sarea);
}
string Square::GetName2D() const
{
   return("Square");
}
void Square::Scale(float scalefactor)
{
   side=side*scalefactor;
   sarea=side*side;
}
void Square::Display() const
{
   cout<<"The area of the Square is : "<<sarea<<endl;
   cout<<"Length of a side: "<<side<<endl;
   cout<<endl;
}
Rectangle::Rectangle()
{
   rwidth=0;
   rheight=0;
   rarea=0;
}
Rectangle::Rectangle(float b, float c)
{
   rwidth=b;
   rheight=c;
   rarea=rwidth*rheight;
}
float Rectangle::Area() const
{
   return(rarea);
}
string Rectangle::GetName2D() const
{
   return("Rectangle");
}
void Rectangle::Scale(float scalefactor)
{
   rwidth*=scalefactor;
   rheight*=scalefactor;
   rarea=rwidth*rheight;
}
void Rectangle::Display() const
{
   cout<<"The area of the Rectangle is : "<<rwidth*rheight<<endl;
   cout<<"Length: "<<rwidth<<endl;
   cout<<"Width: "<<rheight<<endl;
   cout<<endl;
}
Triangle::Triangle()
{
   tlength=0;
   theight=0;
   tarea=0;
}
Triangle::Triangle(float d, float e)
{
   tlength=d;
   theight=e;
   tarea=0.5*tlength*theight;
}
float Triangle::Area() const
{
   return (tarea);
}
string Triangle::GetName2D() const
{
   return("Triangle");
}
void Triangle::Scale(float scalefactor)
{
   tlength*=scalefactor;
   theight*=scalefactor;
   tarea=0.5*tlength*theight;
}
void Triangle::Display() const
{
   cout<<"The area of the Triangle is : "<<0.5*tlength*theight<<endl;
   cout<<"Base: "<<tlength<<endl;
   cout<<"Height: "<<theight<<endl;
   cout<<endl;
}
Circle::Circle()
{
   cradius=0;
   carea=0;
}
Circle::Circle(float f)
{
   cradius=f;
   carea=PI*cradius*cradius;
}
float Circle::Area() const
{
   return(carea);
}
string Circle::GetName2D() const
{
   return("Circle");
}
void Circle::Scale(float scalefactor)
{
   cradius*=scalefactor;
   carea=PI*cradius*cradius;
}
void Circle::Display() const
{
   cout<<"The area of the Circle is : "<<PI*cradius*cradius<<endl;
   cout<<"Radius: "<<cradius<<endl;
   cout<<endl;
}
Ellipse::Ellipse()
{
   minor=0;
   major=0;
   earea=0;
}
Ellipse::Ellipse(float g, float h)
{
   minor=g;
   major=h;
   earea=PI*major*minor;
}
float Ellipse::Area() const
{
   return(earea);
}
string Ellipse::GetName2D() const
{
   return("Ellipse");
}
void Ellipse::Scale(float scalefactor)
{
   minor*=scalefactor;
   minor*=scalefactor;
   earea=PI*major*minor;
}
void Ellipse::Display() const
{
   cout<<"The area of the Ellipse is : "<<earea<<endl;
   cout<<"Length of semi-major axis: "<<minor<<endl;
   cout<<"Length of semi-minor axis: "<<major<<endl;
   cout<<endl;
}
Trapezoid::Trapezoid()
{
   aside=0;
   bside=0;
   trheight=0;
   trarea=0;
}
Trapezoid::Trapezoid(float i, float j, float k)
{
   aside=i;
   bside=j;
   trheight=k;
   trarea=0.5*(aside+bside)*trheight;
}
float Trapezoid::Area() const
{
   return(trarea);
}
string Trapezoid::GetName2D() const
{
   return("Trapezoid");
}
void Trapezoid::Scale(float scalefactor)
{
   aside*=scalefactor;
   bside*=scalefactor;
   trheight*=scalefactor;
   trarea=0.5*(aside+bside)*trheight;
}
void Trapezoid::Display() const
{
   cout<<"The area of the Trapezoid is : "<<trarea<<endl;
   cout<<"Length of side A: "<<aside<<endl;
   cout<<"Length of side B: "<<bside<<endl;
   cout<<"Height: "<<trheight<<endl;
   cout<<endl;
}
Sector::Sector()
{
   sradius=0;
   angle=0;
   searea=0;
}
Sector::Sector(float l, float m)
{
   sradius=l;
   angle=m*PI/180;
   searea=0.5*sradius*sradius*angle;
}
float Sector::Area() const
{
   return(searea);
}
string Sector::GetName2D() const
{
   return("Sector");
}
void Sector::Scale(float scalefactor)
{
   sradius*=scalefactor;
   angle*=scalefactor;
   searea=0.5*sradius*sradius*angle;
}
void Sector::Display() const
{
   cout<<"The area of the Sector is : "<<searea<<endl;
   cout<<"Radius: "<<sradius<<endl;
   cout<<"Angle in radians: "<<angle<<endl;
   cout<<"Angle in degrees: "<<(angle*180/PI)<<endl;
   cout<<endl;
}
TriangularPyramid::TriangularPyramid()
{
   tpheight=0;
   tvolume=0;
}
TriangularPyramid::TriangularPyramid(float n, float o, float p)
{
   tpheight=n;
   Triangle::tlength=o;
   Triangle::theight=p;
   tvolume=(0.5*Triangle::tlength*Triangle::theight*tpheight)/3;
}
float TriangularPyramid::Volume() const
{
   return (tvolume);
}
string TriangularPyramid::GetName3D() const
{
   return("Triangular Pyramid");
}
void TriangularPyramid::Scale(float scalefactor)
{
   tpheight*=scalefactor;
   Triangle::tlength*=scalefactor;
   Triangle::theight*=scalefactor;
   tvolume=(0.5*Triangle::tlength*Triangle::theight*tpheight)/3;
}
void TriangularPyramid::Display() const
{
   cout<<"The volume of the Triangular Pyramid is : "<<tvolume<<endl;
   cout<<"The height is: "<<tpheight<<endl;
   Triangle::Display();
   cout<<endl;
}
RectangularPyramid::RectangularPyramid()
{
   rpheight=0;
   rvolume=0;
}
RectangularPyramid::RectangularPyramid(float q, float r, float s)
{
   rpheight=q;
   Rectangle::rwidth=r;
   Rectangle::rheight=s;
   rvolume=(Rectangle::rwidth*Rectangle::rheight*rpheight)/3;
}
float RectangularPyramid::Volume() const
{
   return(rvolume);
}
string RectangularPyramid::GetName3D() const
{
   return("RectangularPyramid");
}
void RectangularPyramid::Scale(float scalefactor)
{
   rpheight*=scalefactor;
   Rectangle::rwidth*=scalefactor;
   Rectangle::rheight*=scalefactor;
   rvolume=(Rectangle::rwidth*Rectangle::rheight*rpheight)/3;
}
void RectangularPyramid::Display() const
{
   cout<<"The volume of the Rectangular Pyramid is : "<<rvolume<<endl;
   cout<<"The height is: "<<rpheight<<endl;
   Rectangle::Display();
   cout<<endl;
}
Cylinder::Cylinder()
{
   cyheight=0;
   Circle::cradius=0;
   cvolume=0;
}
Cylinder::Cylinder(float t, float u)
{
   cyheight=t;
   Circle::cradius=u;
   cvolume=PI*pow(Circle::cradius, 2.0)*cyheight;
}
float Cylinder::Volume() const
{
   return(cvolume);
}
string Cylinder::GetName3D() const
{
   return("Cylinder");
}
void Cylinder::Scale(float scalefactor)
{
   cyheight*=scalefactor;
   Circle::cradius*=scalefactor;
   cvolume=PI*pow(Circle::cradius, 2.0)*cyheight;
}
void Cylinder::Display() const
{
   cout<<"The volume of the Cylinder is : "<<cvolume<<endl;
   cout<<"The height is: "<<cyheight<<endl;
   Circle::Display();
   cout<<endl;
}
Sphere::Sphere()
{
   Circle::cradius=0;
   svolume=0;
}
Sphere::Sphere(float v)
{
   Circle::cradius=v;
   svolume=(4*PI*pow(Circle::cradius, 3.0))/3.0;
}
float Sphere::Volume() const
{
   return(svolume);
}
string Sphere::GetName3D() const
{
   return("Sphere");
}
void Sphere::Scale(float scalefactor)
{
   Circle::cradius*=scalefactor;
   svolume=(4*PI*pow(Circle::cradius, 3.0))/3;
}
void Sphere::Display() const
{
   cout<<"The volume of the Sphere is : "<<svolume<<endl;
   Circle::Display();
   cout<<endl;
}