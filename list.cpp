#include <iostream>
using namespace std;

template <class BaseData>
class ListNode
{
    public:
        //contains the list data
        BaseData listData;

        //pointer link to link nodes
        ListNode *forwardLink = NULL;
        ListNode *backLink = NULL;
        //constructors
        ListNode();
        ~ListNode();

};

template<class BaseData>
ListNode<BaseData>::ListNode()
{
    listData = 0;
    forwardLink = NULL;
    backLink = NULL;
}

template<class BaseData>
ListNode<BaseData>::~ListNode()
{
    listData = 0;
    forwardLink = NULL;
    backLink = NULL;
}

//List class
template<class BaseData>
class List
{
    protected:
        ListNode<BaseData> *head = NULL; //pointer for head of list
        ListNode<BaseData> *currentNode = NULL; //pointer for current node
        ListNode<BaseData> *previous = NULL; //pointer for previous node
        ListNode<BaseData> *afterNode = NULL; //pointer for node after the current node

        int numNodes; //number of nodes
        int currentPos; //current position

    public:
        List(); //List constructor
        ~List(); //List destructor

        
        void first(); //jumps to head
        int last();   //jumps to tail
        void makeCurrent(int position); //make node current with position
        void next(); //goes to next node
        void prev(); //goes to previous node

        void print(); //prints out entire list
        void printCurrent(); //prints current list
        int count(); //counts number of nodes

        void add(const BaseData &item); //add element after currentNode
        void addHead(const BaseData &item); //add element as head

        void remove(int position); //remove node from position
        int get(const BaseData &item); //get position of first node
};


template <class BaseData>
List<BaseData>::List()
{
    currentPos = 0;
    currentNode = 0;
    numNodes = 0;
}

template <class BaseData>
List<BaseData>::~List()
{
    ListNode<BaseData> *temp;
    currentNode = head;
    currentPos = 1;
    temp = currentNode;
    numNodes = 0;
    for (int i = 1; i < numNodes; i++)
    {
        delete temp;
        temp = currentNode->forwardLink;
    }
}

//not sure if this works
template <class BaseData>
void List<BaseData>::first()
{
    currentNode = head;
    currentPos = 1;
}

template <class BaseData>
int List<BaseData>::last()
{
    currentNode = head->backLink;
    currentPos = numNodes;
    return numNodes;
}

template <class BaseData>
void List<BaseData>::next()
{
    currentNode = currentNode->forwardLink;
    if (currentPos == numNodes)
    {
        currentPos = 1;
    }
    else
    {
        currentPos++;
    }
    
}

template <class BaseData>
void List<BaseData>::prev()
{

    currentNode = currentNode->backLink;
    if (currentPos == 1)
    {
        currentPos = numNodes;
    }
    else
    {
        currentPos--;
    }
}

template <class BaseData>
void List<BaseData>::print()
{
    ListNode<BaseData> *p = head;
    int temp = numNodes;
    while (temp != 0)
    {
        cout << "value: " << p->listData << endl;
        p = p->forwardLink;

        temp--;
    }
}

template <class BaseData>
void List<BaseData>::printCurrent()
{
    ListNode<BaseData> *p = currentNode;

    cout << "value: " << p->listData << endl;
}

template <class BaseData>
int List<BaseData>::count()
{
    return numNodes;
}

template <class BaseData>
void List<BaseData>::add(const BaseData &item)
{
    //create new pointer
    ListNode<BaseData> *p;
    p = new ListNode<BaseData>;

    //assign contents of item to the node referenced by p
    p->listData = item;

    //if the current position is at the end of the list
    if (currentPos == numNodes)
    {
        if (numNodes == 0)
        {
            p->forwardLink = p;
            p->backLink = p;
            head = p;
        }
        else
        {
            currentNode->forwardLink = p;
            p->forwardLink = head;
            head->backLink = p;

            p->backLink = currentNode;
        }
    }
    else
    {
        afterNode = currentNode->forwardLink;
        currentNode->forwardLink = p;
        p->forwardLink = afterNode;

        p->backLink = currentNode;
        afterNode->backLink = p;
    }

    ++numNodes;
    ++currentPos;
    currentNode = p;
}

template <class BaseData>
void List<BaseData>::addHead(const BaseData &item)
{
    ListNode<BaseData> *p, *tail;
    p = new ListNode<BaseData>;
    p->listData = item;

    if (numNodes == 0)
    {
        p->forwardLink = p;
        p->backLink = p;
        
    }

    else
    {
        tail = head->backLink;
        head->backLink = p;
        p->forwardLink = head;
        p->backLink = tail;

        tail->forwardLink = p;
        
    }
    head = p;
    currentNode = head;
    currentPos = 1;
    numNodes++;
    
    

}

template <class BaseData>
void List<BaseData>::remove(int position)
{
    ListNode<BaseData>*p, *temp;

    p = head;

    currentPos = position;
    while (position != 1)
    {
        p = p->forwardLink;
        position--;
    }

    currentNode = p;

    temp = currentNode->backLink;
    temp->forwardLink = currentNode->forwardLink;
    temp = currentNode->forwardLink;
    temp->backLink = currentNode->backLink;

    if (currentPos == numNodes)
    {
        currentNode = currentNode->backLink;
        currentPos--;
    }
    else
    {
        currentNode = currentNode->forwardLink;
    }
    delete p;
    --numNodes;
    
}

template <class BaseData>
int List<BaseData>::get(const BaseData &item)
{
    ListNode<BaseData> *p = head;
    int position = 1;

    bool found = false;
    for (int i = 0; i < numNodes; ++i)
    {
        if (p->listData == item)
        {
            found = true;
            break;
        }
        
        p = p->forwardLink;
        position++;
    }

    if (found == false)
    {
        position = -1;
    }

    return position;
}

