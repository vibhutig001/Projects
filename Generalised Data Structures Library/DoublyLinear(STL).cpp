//Doubly Linear STL
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        
        int Count;
        
    public: 
        DoublyLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No,int ipos);
        void DeleteAtPos(int ipos);
};
/*
Return_Value Class_Name :: Function_Name()
{

}
*/
template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    last = NULL;
    Count =0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    struct node <T>* newn=NULL;

    newn=new(struct node<T>);//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(first==NULL)//LL is Empty
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        (first)->prev=newn;
        first=newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    struct node <T> * newn=NULL;
    struct node <T> * temp=first;

    newn=new(struct node<T>);//20 byte
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;//#

    if(first==NULL)//LL is Empty
    {
        first=newn;
    }
    else
    {
        //type 2
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;//#
    }
    Count++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    
    if(first==NULL)
    {
        return ;
    }
    else if(((first)->next==NULL) && ((first)->prev==NULL))
    {
        delete(first);
        first=NULL;
    }
    else//#
    {
        first=(first)->next;
        delete((first)->prev);
        (first)->prev=NULL;
    }
    Count--;
} 

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp =first;

    if(first==NULL)
    {
        return ;
    }
    else if(((first)->next==NULL) && ((first)->prev==NULL))
    {
        delete(first);
        first=NULL;
    }
    else//#
    {
        //type 3
        while(temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    Count--;
}

template <class T>
void DoublyLL<T> :: Display()
{
    
    struct node <T>* temp = first; 

    cout << "Contents of LinkedList are : \n";
    cout << "NULL <=>";

    while (temp != NULL) {
        //cout<<"| %d | <=>"<<temp->data;
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int DoublyLL<T> :: CountNode()
{
    return Count;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T No,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(No);
    }
    else if(ipos == Count+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T>* newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        struct node <T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;

        temp->next=newn;
        newn->prev=temp;

        Count++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
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

        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;

        Count--;
    }
}

int main()
{
    DoublyLL<int>iobj;
    DoublyLL<float>fobj;
    DoublyLL<double>dobj;
    DoublyLL<char>cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
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


/*/
    obj.InsertFirst(111);
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
    
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105, 4);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";
*/
    return 0;
}