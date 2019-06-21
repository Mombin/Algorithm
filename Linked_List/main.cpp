#include <iostream>
#include <cstdlib>

using namespace std;

class Invalid_Index_Exception{};

template<typename T>
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

template<typename T>
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


int main()
{
    LinkedList<int> LL;
    LL.insert(0, 1); cout << LL << endl;
    LL.insert(1, 2); cout << LL << endl;
    LL.insert(2, 3); cout << LL << endl;
    LL.insert(0, 4); cout << LL << endl;
    LL.insert(0, 5); cout << LL << endl;
    LL.insert(5, 6); cout << LL << endl;
    LL.insert(4, 7); cout << LL << endl;
    LL.insert(1, 8); cout << LL << endl;
    LL.erase(4); cout << LL << endl;
    LL.erase(0); cout << LL << endl;
    LL.erase(5); cout << LL << endl;
    LL.insert(3, 9); cout << LL << endl;
    LL.erase(1); cout << LL << endl;
    LL.insert(1, 10); cout << LL << endl;
    return 0;
}
