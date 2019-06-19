#include <iostream>
#include <cstdlib>

using namespace std;

class Invalid_Index_Exception{};

template<Typename T>
class ListNode
{
public:
    T value;
    ListNode<T> *next; // next node ptr, if last node, nullptr

    //constructor
    ListNode<T>():
        next(nullptr){}
    ListNode<T>(T value1, ListNode<T> *next1):
        value(value1), next(next1){}
};

template<Typename T>
class LinkedList
{
public:
    int size;
    ListNode<T> *head;

    //constructor
    LinkedList<T>():
        size(0), head(nullptr){}

    //destructor
    ~LinkedList<T>()
    {
        ListNode<T> *t1 = head, *t2;
        while(t1!=nullptr)
        {
            t2=t1->next;
            delete t1;
            t1 = t2;
        }
    }

    void insert(int k, T value)
    {
        try
        {
            if(k<0||k>size) throw Invalid_Index_Exception();
            if(k==0) head=new ListNode<T>(value, head);
            else
            {
                ListNode<T> *dest = head;
                for(int i=0; i<k-1; i++) dest = dest->next;
                dest->next = new ListNode<T>(value, dest->next);
            }
            size++;
        }
    }

};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
