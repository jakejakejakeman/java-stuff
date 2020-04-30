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
    int counts;
    LinkedList()
    {
        counts=0;
        head=nullptr;
        tail=nullptr;
    }
    void PrintForward()
    {
        Node* doNode=head;
        for (unsigned int i=0;i<counts;i++)
        {
            cout<<(i+1);
            cout<<doNode->data<<endl;
            doNode=doNode->next;
        }
    }
    void FindAll(const T&value)
    {
        bool fact=false;
        int counter=1;
        Node* currentNode=head;
        while(currentNode!=nullptr)
        {
            if (currentNode->data.find(value)!=string::npos)
            {
                cout<<counter;
                cout<<currentNode->data<<endl;
                fact=true;
            }
            if (currentNode->next==nullptr)
                break;
            currentNode=currentNode->next;
            counter++;
        }
        if (fact==false)
            cout<<"not found"<<endl;
    }
    Node * GetNode(int unsigned index)
    {
        Node* theNode=head;
        if (index>counts-1)
            throw(runtime_error("Index is out of range!"));
        for (unsigned int i=0; i<index; i++)
            theNode=theNode->next;
        return (theNode);
    }
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
    }
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
    }
    void InsertBefore(Node *node, const T &data)
    {
        Node* currNode=new Node;
        currNode->data=data;
        node->prev->next=currNode;
        currNode->prev=node->prev;
        node->prev=currNode;
        currNode->next=node;
        counts++;
    }
    void InsertAt(const T &data, unsigned int index)
    {
        if (index==0)
            AddHead(data);
        else if (index==counts)
            AddTail(data);
        else if (index>counts)
            return;
        else
            InsertBefore(GetNode(index), data);
    }
    bool RemoveAt(int index)
    {
        int nums=counts;
        if (counts==0)
            return (false);
        if ((counts==1)&&(index==0))
        {
            counts=0;
            head->next=nullptr;
            head=nullptr;
            tail->prev=nullptr;
            tail=nullptr;
            return(true);
        }
        if (index>nums-1)
            return (false);
        Node *currentNode = GetNode(index);
        if (currentNode->prev!=nullptr)
        {
            currentNode->prev->next=currentNode->next;
            if (currentNode->next!=nullptr)
                currentNode->next->prev=currentNode->prev;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        counts--;
        return (true);
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
    }
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
    }
    ~LinkedList()
    {
        for (unsigned int i=0;i<counts;i++)
        {
            Node* currentNode=head;
            head=head->next;
            delete currentNode;
        }
    }

};
//your line editor implementation here

int main()
{
    LinkedList<string> data;
    char bad='"';
    string line1;
    //your code to invoke line editor here
    cin>>line1;
    while (line1!="quit")
    {
        if (line1=="insertEnd")
        {
            string line2;
            getline(cin,line2);
            line2.erase(line2.begin()+1);
            line2.erase(line2.length()-1);
            data.AddTail(line2);
        }
        else if (line1=="insert")
        {
            int line2;
            string line3;
            cin>>line2;
            getline(cin,line3);
            line3.erase(line3.begin()+1);
            line3.erase(line3.length()-1);
            data.InsertAt(line3,line2-1);
        }
        else if (line1=="delete")
        {
            int line2;
            cin>>line2;
            data.RemoveAt(line2-1);
        }
        else if (line1=="edit")
        {
            int line2;
            string line3;
            cin>>line2;
            getline(cin,line3);
            line3.erase(line3.begin()+1);
            line3.erase(line3.length()-1);
            data.InsertAt(line3,line2-1);
            data.RemoveAt(line2);
        }
        else if (line1=="print")
            data.PrintForward();
        else if (line1=="search")
        {
            string line2;
            getline(cin,line2);
            line2.erase(line2.begin()+1);
            line2.erase(line2.length()-1);
            data.FindAll(line2);
        }
        else{}
        cin>>line1;
    }
}