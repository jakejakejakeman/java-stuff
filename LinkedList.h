#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
struct LinkedList
{
   struct Node
   {
      T data;
      Node *prev;
      Node *next;
   };
   Node* head;
   Node* tail;
   int counter, num, nums;
   unsigned int counts;
   void PrintForward() const
   {
      Node* currentNode=head;
      for (unsigned int i=0;i<counts;i++)
      {
         cout<<currentNode->data<<endl;
         currentNode=currentNode->next;
      }
   };
   void PrintReverse() const
   {
      Node* currentNode=tail;
      for (unsigned int i=0; i<counts; i++)
      {
         cout<<currentNode->data<<endl;
         currentNode=currentNode->prev;
      }
   }
   void PrintForwardRecursive(const Node *node) const
   {
      if (node!=nullptr)
      {
         cout<<node->data<<endl;
         PrintForwardRecursive(node->next);
      }
   };         
   void PrintReverseRecursive(const Node *node) const
   {
      if (node!=nullptr)
      {
         cout<<node->data<<endl;
         PrintReverseRecursive(node->prev);
      }
   };
   unsigned int NodeCount() const
   {
      return (counts);
   };
   void FindAll(vector<Node *> &outData, const T&value) const
   {
      Node* currentNode=head;
      while(currentNode!=nullptr)
      {
         if (currentNode->data==value)
            outData.push_back(currentNode);
         currentNode=currentNode->next;
      }
   };  
   const Node *Find(const T &data) const
   {
      Node* currentNode=head;
      while(currentNode!=nullptr)
      {
         if (currentNode->data=data)
            return(currentNode);
         currentNode=currentNode->next;
      }
      return (nullptr);
   };
   Node *Find(const T &data)
   {
      Node* currentNode=head;
      while(currentNode!=nullptr)
      {
         if (currentNode->data==data)
            return(currentNode);
         currentNode=currentNode->next;
      }
      return (nullptr);
   };
   const Node * GetNode(int unsigned index) const
   {
      Node* currentNode=head;
      if (index>counts)
         throw(runtime_error("Index is out of range!"));
      for (unsigned int i=0; i<index; i++)
         currentNode=currentNode->next;
      return (currentNode);
   };
   Node * GetNode(int unsigned index)
   {
      Node* currentNode=head;
      if (index>counts-1)
         throw(runtime_error("Index is out of range!"));
      for (unsigned int i=0; i<index; i++)
         currentNode=currentNode->next;
      return (currentNode);
   };
   Node *Head()
   {
      return (head);
   };
   const Node *Head() const
   {
      return (head);
   };
   Node *Tail()
   {
      return (tail);
   };
   const Node *Tail() const
   {
      return (tail);
   };
   void AddHead(const T &data)
   {
      if (head==nullptr)
      {
         head=new Node;
         head->data=data;
         tail=head;
         counts++;
      }
      else
      {
         Node* currNode=new Node;
         currNode->data=data;
         head->prev=currNode;
         currNode->next=head;
         head=currNode;
         counts++;
      }
   };
   void AddTail(const T &data)
   {
      if (tail==nullptr)
      {
         tail=new Node;
         tail->data=data;
         head=tail;
         counts++;
      }
      else
      {
         Node* currNode=new Node;
         currNode->data=data;
         tail->next=currNode;
         currNode->prev=tail;
         tail=currNode;
         counts++;
      }
   };
   void AddNodesHead(const T *data, unsigned int count)
   {
      nums=count;
      for (int i=nums-1; i>=0; i--)
      {
         Node* currNode=new Node;
         currNode->data=data[i];
         head->prev=currNode;
         currNode->next=head;
         head=currNode;
         counts++;
      }
   };
   void AddNodesTail(const T *data, unsigned int count)
   {
      nums=count;
      for (int i=0; i<nums; i++)
      {
         Node* currNode=new Node;
         currNode->data=data[i];
         tail->next=currNode;
         currNode->prev=tail;
         tail=currNode;
         counts++;
      }
   };
   void InsertAfter(Node *node, const T &data)
   {
      Node* currNode=new Node;
      currNode->data=data;
      node->next->prev=currNode;
      currNode->prev=node;
      currNode->next=node->next;
      node->next=currNode;
      counts++;
   };
   void InsertBefore(Node *node, const T &data)
   {
      Node* currNode=new Node;
      currNode->data=data;
      node->prev->next=currNode;
      currNode->prev=node->prev;
      node->prev=currNode;
      currNode->next=node;
      counts++;
   };
   void InsertAt(const T &data, unsigned int index)
   {
      if (index==0)
         AddHead(data);
      else if (index==counts)
         AddTail(data);
      else
         InsertBefore(GetNode(index), data);      
   };   
   bool RemoveHead()
   {
      if (counts==0)
         return false;
      if (counts==1)
      {
         delete head;
      }
      else
      {
         Node* currentNode=head;
         head=head->next;
         currentNode->next=nullptr;
         head->prev=nullptr;
         delete currentNode;
      }
      counts--;
      return(true);
   };
   bool RemoveTail()
   {
      if (counts==0)
         return (false);
      if (counts==1)
      {
         delete tail;
      }
      else
      {
         Node* currentNode=tail;
         tail=tail->prev;
         currentNode->prev=nullptr;
         tail->next=nullptr;
         delete currentNode;
      }
      counts--;
      return(true);
   };
   unsigned int Remove(const T &data)
   {
      num=counts;
      counter=0;
      Node* currentNode=head;
      for (int i=0; i<num; i++)
      {
         if (currentNode->data==data)
         {
            currentNode->prev->next=currentNode->next;
            Node* preel=currentNode;
            currentNode=currentNode->prev;
            delete preel;
            counts--;
            counter++;
         }
         currentNode=currentNode->next;
      }
      return(counter);
   };
   bool RemoveAt(int index)
   {
      nums=counts;
      if (counts==0)
         return (false);
      if (index>nums-1)
         return (false);
      Node *currentNode = GetNode(index);
      Node *otherCurrent = GetNode(index);
      currentNode->prev->next=currentNode->next;
      currentNode=currentNode->prev;
      delete otherCurrent;
      counts--;
      return (true);
   };
   void Clear()
   {
      for (unsigned int i=0;i<counts;i++)
      {
         Node* currentNode=head;
         head=head->next;
         delete currentNode;
      }
      counts=0;
      head=nullptr;
      tail=nullptr;
   };   
   const T & operator[](unsigned int index) const
   {
      if (index>=counts)
         throw (runtime_error("Error! Invalid index"));
      else
         return(GetNode(index)->data);
   };
   T & operator[](unsigned int index)
   {
      if (index>=counts)
         throw (runtime_error("Error! Invalid index"));
      else
         return(GetNode(index)->data);
   };
   bool operator==(const LinkedList<T> &rhs) const
   {
      if (counts!=rhs.counts)
         return (false);
      else
      {
         for (unsigned int i=0; i<rhs.counts; i++)
         {
            if (GetNode(i)->data!=rhs.GetNode(i)->data)
               return(false);
         }
         return(true);
      }
   }
   LinkedList<T> & operator=(const LinkedList<T> &rhs)
   {
      counts=rhs.counts;
      tail=new Node;
      tail->data=rhs.GetNode(0)->data;
      head=tail;
      for (unsigned int i=1;i<rhs.counts;i++)
      {
         Node* currNode=new Node;
         currNode->data=rhs.GetNode(i)->data;
         tail->next=currNode;
         currNode->prev=tail;
         tail=currNode;
      }
      return *this;
   };   
   LinkedList()
   {
      counts=0;
      head=nullptr;
      tail=nullptr;
   };
   LinkedList(const LinkedList<T> &list)
   {
      counts=list.counts;
      tail=new Node;
      tail->data=list.GetNode(0)->data;
      head=tail;
      for (unsigned int i=1;i<list.counts;i++)
      {
         Node* currNode=new Node;
         currNode->data=list.GetNode(i)->data;
         tail->next=currNode;
         currNode->prev=tail;
         tail=currNode;
      }
   };
   ~LinkedList()
   {
      for (unsigned int i=0;i<counts;i++)
      {
         Node* currentNode=head;
         head=head->next;
         delete currentNode;
      }
   };

};