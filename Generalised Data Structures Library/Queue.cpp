//Queue
#include<iostream>
using namespace std;

template <class T>

struct node
{
    T data;
    struct node * next;
};
/*
typedef struct node NODE
typedef struct node* PNODE
*/
template <class T>

class Queue
{
    private:
        struct node<T> * first;
        
        int Count;
        
    public: 
        Queue();
        void Push(T No);
        void Pop();
        void Display();
        int CountNode();
};
template <class T>

Queue<T>:: Queue()
{
    first = NULL;
    
    Count =0;
}
template <class T>

void Queue<T> :: Push(T no)
{
    struct node<T> * Temp  = first;

    struct node<T> * newn =NULL;
    newn=new(struct node<T>);
    newn->data=no;
    newn->next=NULL;
   

    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp -> next;
        }
        Temp->next = newn;
    }
    Count++;
}
template <class T>

void Queue<T>::Pop()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}
template <class T>
void Queue<T>::Display() {
    struct node<T>* temp = first;

    cout << "Elements of the linked list are : \n";

    while (temp != NULL) 
    { // Type 1
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "NULL \n";
}
template <class T>

int Queue<T>::CountNode()
{
    return Count;
}
int main()
{
    Queue<int> iobj;
    Queue<float> fobj;
    int iRet = 0;

    iobj.Push(111);
    iobj.Push(101);
    iobj.Push(51);
    iobj.Push(21);
    iobj.Push(11);

    
    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    iobj.Pop();
    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
///////////////////////////////////////
    fobj.Push(111.1);
    fobj.Push(10.1);
    fobj.Push(51.9);
    fobj.Push(21.5);
    fobj.Push(11.1);

    
    fobj.Display();

    iRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    fobj.Pop();
    fobj.Display();

    iRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";


    return 0;
}