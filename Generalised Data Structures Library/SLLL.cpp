
//Singly Linear STL
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
        int CountEven();
        int CountOdd();
        int DiffEvenOdd();
        int FindMax();
        int FindMin();
        int SumAll();
        int Average();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
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

void SinglyLL<T>::DeleteLast()
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

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}
template <class T>

void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}
template <class T>

void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

template<class T>
int SinglyLL<T>:: CountEven()
{
    int Count=0;
    struct node<T> * temp = first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            Count++;
        }
        temp = temp->next;
    }
    return Count;

}
template<class T>
int SinglyLL<T>:: CountOdd()
{
    int Count=0;
    struct node<T> * temp = first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            Count++;
        }
        temp = temp->next;
    }
    return Count;

}
template<class T>
int SinglyLL<T>:: DiffEvenOdd()
{
    int Even=0;
    int Odd=0;
    int Diff=0;
    struct node<T> * temp = first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            Even++;
        }
        else
        {
            Odd++;
        }
        temp = temp->next;
    }
    Diff=Even-Odd;
    return Diff;

}
template<class T>
int SinglyLL<T>:: FindMax()
{
    int Max=first->data;
    struct node<T> * temp = first->next;

    while (temp != NULL)
    {
        if (temp->data > Max)
        {
            Max=temp->data;
        }
        temp = temp->next;
    }
    return Max;

}
template<class T>
int SinglyLL<T>:: FindMin()
{
    int Min=first->data;
    struct node<T> * temp = first->next;

    while (temp != NULL)
    {
        if (temp->data < Min)
        {
            Min=temp->data;
        }
        temp = temp->next;
    }
    return Min;

}
template<class T>
int SinglyLL<T>:: SumAll()
{
    int Sum=0;
    struct node<T> * temp = first;

    while (temp != NULL)
    {
        Sum=Sum+temp->data;
        temp = temp->next;
    }
    return Sum;

}
template<class T>
int SinglyLL<T>:: Average()
{
    int Sum=0;
    i
    int Avg=0;

    struct node<T> * temp = first;

    while (temp != NULL)
    {
        Sum=Sum+temp->data;
        temp = temp->next;
    }
    Avg=Sum/Count;
    return Avg;

}

int main()
{
    int iRet=0;
    SinglyLL<int>iobj;
    SinglyLL<float>fobj;
    SinglyLL<double>dobj;
    SinglyLL<char>cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(22);
    iobj.InsertLast(54);
    iobj.InsertLast(101);

    cout<<"LinkedList of Integers :"<<"\n";
    iobj.Display();

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"LinkedList of Floats :"<<"\n";
    fobj.Display();

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    cout<<"LinkedList of Doubles :"<<"\n";
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"LinkedList of Character :"<<"\n";
    cobj.Display();


    iRet=iobj.CountEven();
    cout<<"Even Elements are :"<<iRet<<"\n";

     iRet=iobj.CountOdd();
    cout<<"Odd Elements are :"<<iRet<<"\n";

    iRet=iobj.DiffEvenOdd();
    cout<<"Difference Between Even Odd Elements are :"<<iRet<<"\n";

     iRet=iobj.FindMax();
    cout<<"max Elements are :"<<iRet<<"\n";

     iRet=iobj.FindMin();
    cout<<"min Elements are :"<<iRet<<"\n";

    iRet=iobj.SumAll();
    cout<<"Sum of Elements are :"<<iRet<<"\n";

    iRet=iobj.Average();
    cout<<"Average of Elements are :"<<iRet<<"\n";


    return 0;
}