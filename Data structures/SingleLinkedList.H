#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include "Node.H"


using namespace std;

template<class T>
class SingleLinkedList
{
public:
    ///default constructor
    SingleLinkedList();
    ///parameterized constructor with a list
    SingleLinkedList(initializer_list<T> __l);
    ///parameterized constructor with an array
    template <std::size_t N>
    SingleLinkedList(const T(&arr)[N]){
        int size = this->array_size(arr);
        Head=NULL;
        for(int i=0;i<size;i++){
            this->Insert(arr[i]);
        }
    }
    ///sort function using an array
    void Sort();


    ///Copy constructor
    SingleLinkedList(const SingleLinkedList &);
    ///destructor
    ~SingleLinkedList();
    ///print
    void print();
    ///Insertion
    bool Insert(T);
    ///check if the list is empty
    bool Empty();
    ///return the number of elements in the SLL
    int Count();
    ///Insertion an element to the start of the List
    bool Insert_Infront(T);
    ///Reverse
    void Reverse();

    template <std::size_t N>
    constexpr std::size_t array_size(const T(&)[N]){ return N; }

    ///cout operator overloading
    template<class U>
    friend ostream& operator<< (ostream& out,  const SingleLinkedList<U>& sll);
protected:
    Node<T>*Head;
};

template<class T>
ostream& operator <<(ostream& out, const SingleLinkedList<T>& sll)
{

    Node<T>*temp=sll.Head;

    while(temp!=NULL)
    {

        out<<temp->get_value()<<" ";
        temp=temp->get_next();

    }
    return out;
}





#endif // SINGLELINKEDLIST_H
