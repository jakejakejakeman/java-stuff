#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Color
{

   public:
      int values;
      string names;
      void SetValue(int value);
      void SetName(const char* name);
      
      unsigned char GetR() const;
      unsigned char GetG() const;
      unsigned char GetB() const;
      string GetHexValue() const;
      string GetName() const;
};