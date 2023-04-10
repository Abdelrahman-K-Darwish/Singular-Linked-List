#include <iostream>
#include "SingleLinkedList.H"
using namespace std;

int main()
{

    int arr[]={2,3,4,1};
    SingleLinkedList<int> sll(arr);
    SingleLinkedList<int> sll2(sll);

    sll.Sort();
    sll.print();
    sll2.print();




    return 0;
}
