#include "SingleLinkedList.H"

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
    this->Head=NULL;
}
template<class T>
SingleLinkedList<T>::SingleLinkedList(initializer_list<T> __l)
{
    Head=NULL;
    for(int i=0; i<__l.size(); i++)
    {

        T val = (*(__l.begin()+i));
        this->Insert(val);
    }

}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList & sll){

    Head=NULL;

    Node<T>*temp=sll.Head;
    while(temp!=NULL){

        this->Insert(temp->get_value());
        temp=temp->get_next();
    }

}

template<class T>
void SingleLinkedList<T>:: Sort(){

    const int size = this->Count();
    T arr[size];
    Node<T>*temp=Head;
    for(int i=0; i<size; i++)
    {
        arr[i] = temp->get_value();
        temp=temp->get_next();
    }
    temp=Head;
    sort(arr,arr+size);
    for(int i=0; i<size; i++)
    {
        temp->set_value(arr[i]);
        temp=temp->get_next();
    }

}



///Adds to the end of the list
template<class T>
bool SingleLinkedList<T>::Insert(T val)
{
    ///if the list was empty
    if(this->Head==NULL)
    {
        Head=new Node<T>(val);
    }
    ///if the list was not empty
    else
    {

        Node<T>*new_node=new Node<T>(val);
        Node<T>*temp=Head;
        while(temp->get_next()!=NULL)
        {
            temp=temp->get_next();
        }
        temp->set_next(new_node);
    }
    return true;
}

template<class T>
bool SingleLinkedList<T>::Empty()
{

    if(Head==NULL) return true;
    else return false;

}

template<class T>
void SingleLinkedList<T>::print()
{

    Node<T>*temp=Head;
    if(temp==NULL)
    {
        cout<<"list is empty"<<endl;
    }

    else
    {
        cout<<"List elements: ";
        while(temp!=NULL)
        {

            cout<<temp->get_value()<<" ";
            temp=temp->get_next();

        }
        cout<<endl;
    }

}

template<class T>
bool SingleLinkedList<T>:: Insert_Infront(T val)
{

    Node<T>*new_node = new Node<T>(val);
    new_node->set_next(Head);
    Head=new_node;
    return true;
}

template<class T>
int SingleLinkedList<T>:: Count()
{
    Node<T>*temp=Head;
    int counter=0;
    while(temp!=NULL)
    {

        counter++;
        temp=temp->get_next();

    }

    return counter;


}

template<class T>
void SingleLinkedList<T>:: Reverse()
{

    const int size = this->Count();
    T arr[size];
    Node<T>*temp=Head;
    for(int i=0; i<size; i++)
    {
        arr[i] = temp->get_value();
        temp=temp->get_next();
    }
    temp=Head;
    for(int i=size-1; i>=0; i--)
    {
        temp->set_value(arr[i]);
        temp=temp->get_next();
    }

}





template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{

    while(Head!=NULL)
    {
        Node<T>*temp=Head;

        Head=Head->get_next();
        delete temp;

    }

}


template class SingleLinkedList<int>;
template class SingleLinkedList<float>;
template class SingleLinkedList<long long>;
template class SingleLinkedList<long>;
template class SingleLinkedList<string>;
template class SingleLinkedList<char>;
template class SingleLinkedList<double>;
template class SingleLinkedList<long double>;
