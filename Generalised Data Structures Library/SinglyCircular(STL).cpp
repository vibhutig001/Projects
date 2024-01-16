//Singly Circular STL
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;
        
    public: 
        SinglyCL();
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
SinglyCL<T> :: SinglyCL()
{
    first = NULL;
    last = NULL;
    Count =0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T No)
{
    struct node<T> * newn=NULL;

    newn=new struct node<T>;

    newn->data=No;
    newn->next=NULL;

    if((first==NULL)&&(last==NULL))//LL empty
    {
        first=newn;
        last=newn;//#
        (last)->next=last;
    }
    else//LL contain atleast one node
    {
        newn->next=first;
        first=newn;
        (last)->next=first;
    }
    //(*Tail)->next=*Head;//#
    Count++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T No)
{
    struct node<T> * newn=NULL;
    newn=new (struct node<T>);

    newn->data=No;
    newn->next=NULL;

    if((first==NULL)&&(last==NULL))//LL empty
    {
        first=newn;
        last=newn;
        (last)->next=first;
    }
    else//LL contain atleast one node
    {
        (last)->next=newn;
        last=newn;
        (last)->next=first;
    }

    Count++;
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    //Case 1
    if(first == NULL && last == NULL)
    {
        return;
    }
    //Case 2
    else if(first == last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    //Case 3
    else
    {
        first=(first)->next;
        delete((last)->next);
        (last)->next=first;
    }
    Count--;
} 

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * temp =first;
    //Case 1
    if(first == NULL && last == NULL)
    {
        return;
    }
    //Case 2
    else if(first == last)
    {
        delete(first);
        first=NULL;
        last=NULL;
    }
    //Case 3
    else
    {
        while(temp->next != last)
        {
            temp=temp->next;
        }
        delete(last);
        last=temp;
        (last)->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T> :: Display()
{
    cout << "Elements of LinkedList are:" << endl;

    if ((first != NULL) && (last != NULL))
    {
        struct node<T> *temp = first;
        do
        {
            cout << temp->data << " ->\t";
            temp = temp->next;
        } while (temp != last->next);
        cout << "Address of First Node" << endl;
    }
}

template <class T>
int SinglyCL<T> :: CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T No,int iPos)
{
   
    if((iPos < 1) || (iPos > Count+1))
    {
        printf("Invalid Position");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==Count+1)
    {
        InsertLast(No);

    }
    else
    {   
        struct node<T> * newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    Count++;
}


template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
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
        struct node <T>* temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next=temp->next->next;
        delete(targatednode);

        Count--;
    }
}

int main()
{
    SinglyCL<int>iobj;
    SinglyCL<float>fobj;
    SinglyCL<double>dobj;
    SinglyCL<char>cobj;

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

    /*
    obj.DeleteFirst();
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    obj.InsertAtPos(105, 5);
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