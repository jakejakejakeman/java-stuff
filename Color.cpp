#include "Color.h"

void Color::SetValue(int value)
{
   values=value;
}
void Color::SetName(const char* name)
{
   names=name;
}

unsigned char Color::GetR() const
{
   int tempy=values>>16;
   return(tempy&255);
}
unsigned char Color::GetG() const
{
   int tempy=values>>8;
   return(tempy&255);
}
unsigned char Color::GetB() const
{
   return(values&255);
}
string Color::GetHexValue() const
{
   string dads="0x";
   int temp1=values;
   int temp2;
   for (int i=5; i>-1; i--)
   {
      temp2=temp1/pow(16.0, i);
      if (temp2==0)
         dads+=('0');
      else if (temp2==1)
         dads+=('1');
      else if (temp2==2)
         dads+=('2');
      else if (temp2==3)
         dads+=('3');
      else if (temp2==4)
         dads+=('4');
      else if (temp2==5)
         dads+=('5');
      else if (temp2==6)
         dads+=('6');
      else if (temp2==7)
         dads+=('7');
      else if (temp2==8)
         dads+=('8');
      else if (temp2==9)
         dads+=('9');
      else if (temp2==10)
         dads+=('A');
      else if (temp2==11)
         dads+=('B');
      else if (temp2==12)
         dads+=('C');
      else if (temp2==13)
         dads+=('D');
      else if (temp2==14)
         dads+=('E');
      else
         dads+=('F');
      temp1%=(int)pow(16.0,i);
   }
   return (dads);
}
         
   
string Color::GetName() const
{
   return (names);
}
