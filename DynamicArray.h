#pragma once
#include <string>
#include <iostream>
using namespace std;
template <typename T>
struct DynamicArray
{
   T *stuffs;
   T *newstuffs;
   int length, count, counter, problem, num, nums;
   /*====== Accessors ======*/
   unsigned int GetCapacity() const
   {
      return(length);
   };
   unsigned int GetSize() const
   {
      return(count);
   };
   const T* GetData() const
   {
      return(stuffs);
   };
   
   // Return a specific element from the internal array
   const T &operator[](unsigned int index) const
   {
      num=index;
      if (num>length)
         throw (runtime_error("Error! Invalid index"));
      else
         return(stuffs[index]);
   };
   T & operator[](unsigned int index)
   {
      num=index;
      if (num>length)
         throw (runtime_error("Error! Invalid index"));
      else
         return(stuffs[index]);
   };
   
   // Just like the brackets operator, but with a function
   const T &At(unsigned int index) const
   {
      num=index;
      if (num>length)
         throw (runtime_error("Error! Invalid index"));
      else
         return(stuffs[index]);
   };
   T &At(unsigned int index)
   {
      num=index;
      if (num>length)
         throw (runtime_error("Error! Invalid index"));
      else
         return(stuffs[index]);
   };
   /*====== Mutators ======*/
   // Add an item onto the end of the array, if there is room.
   // If not, the array will have to be resized to make space for one more.
   void Add(const T &data)
   {
      if (length==count)
         Resize(count+1);
      stuffs[count]=data;
      count++;
   };
   //This is the beefcake of a function that does the resizing.
   void Resize(unsigned int newSize)
   {
      cout<<"Resizing... old capacity: "<<length;
      nums=length;
      length=newSize;
      newstuffs=new T[length];
      if (nums<length)
      {
         if (nums!=0)
            for (int i=0; i<nums; i++)
               newstuffs[i]=stuffs[i];
      }
      else
         for (int i=0; i<length; i++)
            newstuffs[i]=stuffs[i];
      delete[] stuffs;
      stuffs=new T[length];
      if (nums!=0)
         for (int i=0; i<length; i++)
            stuffs[i]=newstuffs[i];
      cout<<" New capacity: "<<length<<endl;
      if (length<count)
         count=length;
      delete[] newstuffs;
   };
   // The data killer, the silent assassin, the slayer of array elements.
   // Removes an element from an array, and then shrinks the array to fill
   // the gap.
   void Remove (unsigned int index)
   {
      problem=index;
      if ((problem>=length)||(length<=0)||(problem<0))
         throw (runtime_error("Error! Invalid index"));
      else
      {
         counter=0;
         for (int i=0; i<length; i++)
         {
            if (i!=problem)
            {
               stuffs[counter]=stuffs[i];
               counter++;
            }
         }
         count--;
      }
   };
   // Default constructor
   DynamicArray()
   {
      length=0;
      count=0;
      stuffs=nullptr;
   };
   // Constructor with an initial capacity
   DynamicArray(unsigned int e)
   {
      length=e;
      count=0;
      stuffs=new T[e];
   };   
   //Trilogy of evil...
   DynamicArray(const DynamicArray &d)
   {
      length=d.length;
      count=d.count;
      stuffs=new T[d.length];
      for (int i=0; i<d.length; i++)
         stuffs[i]=d.stuffs[i];
   };
   DynamicArray &operator=(const DynamicArray &d)
   {
      length=d.length;
      count=d.count;
      stuffs=new T[d.length];
      for (int i=0; i<d.length; i++)
         stuffs[i]=d.stuffs[i];
      return *this;
   };
   ~DynamicArray()
   {
      if (stuffs!=nullptr)
         {
            delete[] stuffs;
         }
   };
};