//Doubly Circular
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
class DoublyCL
{
    private:
        struct node<T>* first;
        struct node<T>* last;
        int Count;
        
    public: 
        DoublyCL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No,int ipos);
        void DeleteAtPos(int ipos);
         int CountEven();
        int CountOdd();
        int DiffEvenOdd();
        int FindMax();
        int FindMin();
        int SumAll();
        int Average();
};
/*
Return_Value Class_Name :: Function_Name()
{

}
*/
template <class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    Count =0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T No)
{
    struct node<T>* newn=NULL;
    newn=new(struct node<T>);

    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        (first)->prev=newn;
        first=newn;
    }
    (last)->next=first;
    (first)->prev=last;

    Count++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T No)
{
    struct node<T>* newn=NULL;
    newn=new(struct node<T>);

    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;

    if((first==NULL) && (last==NULL))
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->prev=last;
        (last)->next=newn;
        last=newn;
    }
    (last)->next=first;
    (first)->prev=last;

    Count++;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    
    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        free(first);
        first=NULL;
        last==NULL;
    }
    else
    {
        first=(first)->next;
        delete((last)->next); // free((*Head)->prev);
        (first)->prev = last;
        (last)->next=first;
    }
    Count--;
} 

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first==NULL) && (last==NULL))
    {
        return;
    }
    else if(first==last)
    {
        delete(first);
        first=NULL;
        last==NULL;
    }
    else
    {
        last=(last)->prev;
        delete((last)->next);//free((*Head)->prev);
        (last)->next=first;
        (first)->prev=last;
    }
    Count--;
}

template <class T>
void DoublyCL<T> :: Display()
{
    cout << "Contents of LinkedList are : \n";
    if(first != NULL && last != NULL)
    {
        do
        {
            cout<<"| "<<first->data<<" | -> ";
            first=first->next;
        } while (first != last->next);
    }
    cout<<"\n";

}

template <class T>
int DoublyCL<T> :: CountNode()
{
    return Count;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T No,int ipos)
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
        struct node<T> * newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        struct node<T>* temp = first;
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
void DoublyCL<T> :: DeleteAtPos(int ipos)
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
        struct node<T>* temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        Count--;
    }
}

template<class T>
int DoublyCL<T>:: CountEven()
{
    int Count=0;
    struct node<T> * temp = first;

   if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            Count++;
        }
        temp = temp->next;

    } while (temp != first);
    return Count;

}
template<class T>
int DoublyCL<T>:: CountOdd()
{
    int Count=0;
    struct node<T> * temp = first;

   if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) % 2 != 0)
        {
            Count++;
        }
        temp = temp->next;

    } while (temp != first);
    return Count;

}
template<class T>
int DoublyCL<T>:: DiffEvenOdd()
{
    int Even=0;
    int Odd=0;
    int Diff=0;
    struct node<T> * temp = first;

   if (temp == NULL)
    {
        return Count;
    }

    do
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

    } while (temp != first);

    Diff=Even-Odd;

    return Diff;

}
template<class T>
int DoublyCL<T>:: FindMax()
{
    int Max=first->data;
    struct node<T> * temp = first->next;

    
    do{
        if (temp->data > Max)
        {
            Max=temp->data;
        }
        temp = temp->next;
    }while (temp != first);
    return Max;

}
template<class T>
int DoublyCL<T>:: FindMin()
{
    int Min=first->data;
    struct node<T> * temp = first->next;

    
    do{
        if (temp->data < Min)
        {
            Min=temp->data;
        }
        temp = temp->next;
    }while (temp != first);
    return Min;

}
template<class T>
int DoublyCL<T>:: SumAll()
{
    int Sum=0;
    struct node<T> * temp = first;

    
    do{
        Sum=Sum+temp->data;
        temp = temp->next;
    }while (temp != first);
    return Sum;

}
template<class T>
int DoublyCL<T>:: Average()
{
    int Sum=0;
    int Avg=0;

    struct node<T> * temp = first;

    
    do{
        Sum=Sum+temp->data;
        temp = temp->next;
    }while (temp != first);
    Avg=Sum/Count;
    return Avg;

}

int main()
{

    int iRet=0;
    DoublyCL<int>iobj;
    DoublyCL<float>fobj;
    DoublyCL<double>dobj;
    DoublyCL<char>cobj;

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

    iRet = iobj.CountEven();
    cout<<"Even Elements are : "<<iRet<<"\n";

    iRet = iobj.CountOdd();
    cout<<"Odd Elements are : "<<iRet<<"\n";

    iRet = iobj.DiffEvenOdd();
    cout<<"Difference EvenOdd Elements are : "<<iRet<<"\n";

     iRet=iobj.FindMax();
    cout<<"max Elements are :"<<iRet<<"\n";

     iRet=iobj.FindMin();
    cout<<"min Elements are :"<<iRet<<"\n";

    iRet=iobj.SumAll();
    cout<<"Sum of Elements are :"<<iRet<<"\n";

    iRet=iobj.Average();
    cout<<"Average of Elements are :"<<iRet<<"\n";



    /*
    DoublyCL obj;
    int iRet = 0;


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