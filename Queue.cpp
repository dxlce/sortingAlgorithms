#include <iostream>
#include <cassert>
using namespace std;

template <class BaseData>
class QNode
{
    public:
        BaseData queueData;
        QNode *link;

        QNode();
        ~QNode();
};

template <class BaseData>
QNode<BaseData>::QNode()
{
    queueData = 0;
    link = NULL;
}

template <class BaseData>
QNode<BaseData>::~QNode()
{
    queueData = 0;
    link = NULL;
}

template <class BaseData>
class Queue
{
    public:
        QNode<BaseData> *currentNode;
        QNode<BaseData> *head;
        Queue();
        Queue(int size);
        ~Queue();

        BaseData front();
        bool empty();
        bool full();

        void enqueue (const BaseData &item);
        void dequeue();

        void print();

        int numNodes;
        int currentPos;
        int maxQueueSize = -1;
};

template <class BaseData>
Queue<BaseData>::Queue()
{
    currentPos = 0;
    numNodes = 0;
    currentNode = 0;
}

template <class BaseData>
Queue<BaseData>::Queue(int size)
{
    maxQueueSize = size;
    currentPos = 0;
    numNodes = 0;
    currentNode = 0;
}

template <class BaseData>
Queue<BaseData>::~Queue()
{
    QNode<BaseData> *temp;
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

template <class BaseData>
BaseData Queue<BaseData>::front()
{
    currentNode = head;
    currentPos = 1;

    return (currentNode->queueData);
}

template <class BaseData>
bool Queue<BaseData>::empty()
{
    bool isEmpty = false;

    if (numNodes == 0)
    {
        isEmpty = true;
    }
    return isEmpty;
}

template <class BaseData>
bool Queue<BaseData>::full()
{
    bool isFull = false;

    if (numNodes == maxQueueSize)
    {
        isFull = true;
    }
    return isFull;
}

template <class BaseData>
void Queue<BaseData>::enqueue(const BaseData &item)
{
    assert(!full());
    QNode <BaseData> *p;
    p = new QNode<BaseData>;
    p->queueData = item;
    
    if (numNodes == 0)
    {
        p->link = NULL;
        head = p;
    }
    else
    {
        if (currentPos == numNodes)
        {
            currentNode->link = p;
            p->link = NULL;
        }
        else
        {
            while (currentNode->link != NULL)
            {
                currentNode = currentNode->link;
                currentPos++;
            }
            currentNode->link = p;
            p->link = NULL;
        }
        
        
    }

    ++numNodes;
    ++currentPos;
    currentNode = p;

}

template <class BaseData>
void Queue<BaseData>::dequeue()
{
    assert(!empty());
    currentNode = head;
    currentPos = 1;

    QNode<BaseData> *p = currentNode;

    head = currentNode->link;
    currentNode = head;

    delete p;
    --numNodes;
}

template <class BaseData>
void Queue<BaseData>::print()
{
    QNode<BaseData> *p = head;

    while (p != NULL)
    {
        cout << "value: " << p->queueData << endl;
        p = p->link;
    }
}