#include <iostream>
using namespace std;

template <class BaseData>
class ListNode
{
    public:
        BaseData listData;
        ListNode *link = NULL;

        ListNode();
        ~ListNode();
        //void print();
};

template<class BaseData>
ListNode<BaseData>::ListNode()
{
    listData = 0;
    link = NULL;
}

template<class BaseData>
ListNode<BaseData>::~ListNode()
{
    listData = 0;
    link = NULL;
}
template<class BaseData>
class List
{
    protected:
        ListNode<BaseData> *head = NULL;
        ListNode<BaseData> *currentNode = NULL;
        ListNode<BaseData> *previous = NULL;
        ListNode<BaseData> *afterNode = NULL;

        int numNodes;
        int currentPos;

    public:
        List();
        ~List();

        void operator = (const List<BaseData> &source);
        void first();
        int last();
        void makeCurrent(int position);
        void next();

        void print();
        void printCurrent();
        int count();

        void add(const BaseData &item);
        void addHead(const BaseData &item);

        void remove(int position);
        int get(const BaseData &item);
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
        temp = currentNode->link;
    }
}

template<class BaseData>
void List<BaseData>::operator = (const List<BaseData> &source)
{
    this.currentNode = source.currentNode;
    this.head = source.head;
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
    ListNode<BaseData> *p;

    p = currentNode;

    while (currentNode->link != NULL)
    {
        currentNode = currentNode -> link;
        currentPos++;
    }

    return currentPos;
}

template <class BaseData>
void List<BaseData>::next()
{
    if (currentNode->link == NULL)
    {
        cout << "invalid" << endl;
    }
    else
    {
        currentNode = currentNode->link;
        currentPos++;
    }
 
}

template <class BaseData>
void List<BaseData>::print()
{
    ListNode<BaseData> *p = head;

    while (p != NULL)
    {
        cout << "value: " << p->listData << endl;
        p = p->link;
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
    ListNode<BaseData> *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }

    return count;
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
            p->link = NULL;
            head = p;
        }
        else
        {
            currentNode->link = p;
            p->link = NULL;
        }
    }
    else
    {
        afterNode = currentNode->link;
        currentNode->link = p;
        p->link = afterNode;
    }

    ++numNodes;
    ++currentPos;
    currentNode = p;
}

template <class BaseData>
void List<BaseData>::addHead(const BaseData &item)
{
    ListNode<BaseData> *p;
    p = new ListNode<BaseData>;

    p->listData = item;

    p->link = head;
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
        p = p->link;
        position--;
    }

    currentNode = p;
    
    if (currentPos == 1)
    {
        head = currentNode->link;
        currentNode = head;
    }

    else
    {
        int prevPosition = currentPos - 1;
        temp = head;
        while (prevPosition != 1)
        {
            temp = temp->link;
            prevPosition--;
        }

        previous = temp;

        previous->link = currentNode->link;

        //if there is a node following currentNode
        if (currentNode->link != NULL)
        {
            //set currentNode to the following node
            currentNode = currentNode->link;
        }

        else
        {
            //set currentNode to previous
            currentNode = previous;

            //set temp to head
            temp = head;
            
            //issue

            if (numNodes == 2)
            {
                currentNode = head;
            }
            else
            {
                //while head is not equivalent to currentNode (ie. start from the start and go to there)
                while (temp->link != currentNode)
                {
                    //link everything
                    temp = temp->link;
                }

                //set previous to temp
                previous = temp;
                //fix current postiion 
                --currentPos;
            }

        } 
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
        
        p = p->link;
        position++;
    }

    if (found == false)
    {
        position = -1;
    }

    return position;
}

