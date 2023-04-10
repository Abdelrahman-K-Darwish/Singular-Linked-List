#include <iostream>
#include "SingleLinkedList.H"
using namespace std;

int main()
{

    SingleLinkedList<int> SLL;
    SLL.Insert(1);
    SLL.Insert(5);
    SLL.Insert(3);
    SLL.Insert(2);
    SLL.Insert(4);
    SingleLinkedList<int> SLL2(SLL);
    SingleLinkedList<int> SLL3({1,5,6,4,8,9});
    SLL.Sort();
    SLL.print();
    cout<<endl<<SLL2<<endl;
    cout<<SLL2.front()<<" "<<SLL2.back()<<endl;
    SingleLinkedList<int> SLL4;
    int val = SLL4.front();
    SLL.remove(1);
    SLL.print();
    if(SLL.Search(2)){
        cout<<"2 was found"<<endl;
    }
    if(!SLL.Search(1)){
        cout<<"1 was deleted"<<endl;
    }



    return 0;
}
