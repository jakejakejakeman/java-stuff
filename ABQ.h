#pragma once
#include <string>
#include <iostream>
using namespace std;
template <typename T>
struct ABQ
{
   T *stuffs;
   T *newstuffs;
   T guy;
   int length, count, nums;
   /*====== Accessors ======*/
   unsigned int getMaxCapacity() const
   {
      return(length);
   };
   unsigned int getSize() const
   {
      return(count);
   };
   const T* GetData() const
   {
      return(stuffs);
   };
   
   /*====== Mutators ======*/
   // Add an item onto the end of the array, if there is room.
   // If not, the array will have to be resized to make space for one more.
   void enqueue(T data)
   {
      if (length==count)
         Resize(count*2);
      stuffs[count]=data;
      count++;
   };
   //This is the beefcake of a function that does the resizing.
   void Resize(unsigned int newSize)
   {
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
      if (length<count)
         count=length;
      delete[] newstuffs;
   };
   // The data killer, the silent assassin, the slayer of array elements.
   // Removes an element from an array, and then shrinks the array to fill
   // the gap.
   T dequeue()
   {
      if (count==0)
         throw (-1);
      guy=stuffs[0];
      for (int i=0; i<count; i++)
         if (i!=count-1)
            stuffs[i]=stuffs[i+1];
      count--;
      if (count<(length/2.0))
         Resize(length/2);
      return (guy);
   };
   T peek()
   {
      if (count==0)
         throw (-1);
      return (stuffs[0]);
   }
   // Default constructor
   ABQ()
   {
      length=1;
      count=0;
      stuffs=new T[1];
   };
   // Constructor with an initial capacity
   ABQ(int capacity)
   {
      length=capacity;
      count=0;
      stuffs=new T[capacity];
   };   
   //Trilogy of evil...
   ABQ(const ABQ &d)
   {
      length=d.length;
      count=d.count;
      stuffs=new T[d.length];
      for (int i=0; i<d.length; i++)
         stuffs[i]=d.stuffs[i];
   };
   ABQ &operator=(const ABQ &d)
   {
      length=d.length;
      count=d.count;
      stuffs=new T[d.length];
      for (int i=0; i<d.length; i++)
         stuffs[i]=d.stuffs[i];
      return *this;
   };
   ~ABQ()
   {
      if (stuffs!=nullptr)
         {
            delete[] stuffs;
         }
   };
};