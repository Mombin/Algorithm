#include <iostream>
#include <cstdlib>
#include "Linked_List.h"

using namespace std;

Linked_List::Invalid_Index_Exception{};

template<typename T>
Linked_List::ListNode
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

template<typename T>
Linked_List::LinkedList
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
        catch(Invalid_Index_Exception e)
        {
        	cout << "잘못된 인덱스입니다."<<endl;
        	exit(2);
		}
    }

    void erase(int k)
    {
        try
        {
            if(k<0||k>=size) throw Invalid_Index_Exception();
            if(k==0)
            {
                ListNode<T> *tmp= head->next;
                delete head;
                head = tmp;
            }
            else
            {
                ListNode<T> *dest = head, *tmp;
                for(int i=0; i<k-1; i++) dest = dest->next;
                tmp = dest->next->next;
                delete dest->next;
                dest->next = tmp;
            }
            size--;
        }
        catch(Invalid_Index_Exception e)
        {
        	cout << "잘못된 인덱스입니다."<<endl;
        	exit(2);
		}
    }
    int search(T value)
    {
    	ListNode<T> *temp = head;
    	for(int i=0;i<size;i++)
    	{
    		if(temp->value == value) return i;
    		temp = temp->next;
		}
		return -1;
	}
};

template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL)
{
    ListNode<T> *tmp = LL.head;
    out << '[';
    for(int i=0; i<LL.size;i++)
    {
        out << tmp->value;
        tmp = tmp->next;
        if(i<LL.size-1) out << ", ";
    }
    out << ']';
    return out;
}
