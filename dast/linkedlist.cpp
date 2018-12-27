#include <iostream>

using namespace std;

template <class T>
class ListElement{
    public:
        ListElement( const T &value ): next( NULL ), data( value) {}
        ~ListElement() {}

        ListElement *getNext() const { return next; }
        const T value() const { return data; }
        void setNext( ListElement *elem ) { next = elem; }
        void setValue( int value ) { data = value; }
        
    private :
        ListElement *next;
        int data;
};

class IntElement{
    public:
        IntElement(int value): next(NULL), data(value) {}
        ~IntElement(){}

        IntElement *getNext() const { return next;}
        int value() const {return data;}
        void setNext(IntElement *elem) {next = elem;}
        void setValue(int value) {data = value;}
    private:
        IntElement *next;
        int data;
};

int main()
{ /*
    ListElement<int> node1(10);
    ListElement<int> node2(20);

    cout << node1.value() << endl;
    cout << node1.getNext() << endl;

    node1.setNext(&node2);
    
    cout << node1.value() << endl;
    cout << node1.getNext() << endl;
*/
    IntElement list1();
    IntElement list2(3);
    
    list2.setNext(list1.next);
    cout << list2.getNext();
    
    }








