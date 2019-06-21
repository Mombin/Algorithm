class Invalid_Index_Exception;

template<typename T>
class ListNode
{
public:
    T value;
    ListNode<T> *next; // next node ptr, if last node, nullptr
    //constructor
    ListNode<T>();
    ListNode<T>(T value1, ListNode<T> *next1);
};

template<typename T>
class LinkedList
{
public:
    int size;
    ListNode<T> *head;

    LinkedList<T>(); //constructor
    ~LinkedList<T>(); //destructor

    void insert(int k, T value);
    void erase(int k);
    int search(T value);
};

template<typename T>
ostream& operator <<(ostream &out, const LinkedList<T> &LL);
