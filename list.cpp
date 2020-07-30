template <class BaseData>
class ListNode
{
    public:
        BaseData listData;
        ListNode *link;
    
};

template<class BaseData>
class List
{
    protected:
        ListNode<BaseData> *head;
        ListNode<BaseData> *currentNode;
        ListNode<BaseData> *previous;

        int numNodes;
        int currentPos;

    public:
        List();
        List(List<BaseData> &initlist);
        ~List();

        void operator = (const List<BaseData> &source);
        void first();
        void last();
        void makeCurrent(int position);
        void prev();
        void next();

        BaseData examine();
        int current();
        int count();

        void insertBefore(const BaseData &item);
        void insertAfter(const BaseData &item);

        void remove();
        void replace(const BaseData &item);
};

template <class BaseData>
List<BaseData>::List()
{
    listArray = new Array<int, BaseData>(1, maxListSize);
    assert(listArray != 0);
    numnodes = 0;
    currentNode = 0;
}

template <class BaseData>
void List<BaseData>::insertBefore(const BaseData &item)
{
    //create new pointer
    ListNode<BaseData> *p;
    p = new ListNode<BaseData>;

    //assign contents of item to the node referenced by p
    p->listData = item;

    //if the current position of node is less than or equal to one (ie. inserting node at beginning of list)
    if (currentPos <= 1)
    {
        //assign head to p
        head = p;
        
        //current position is now one
        currentPos = 1;

        //if the number of nodes is zero (ie. the only node in the list is 'item') - link it to null
        if (numnodes == 0)
        {
            p->link = null;
        }

        //else: link p to currentNode
        else
        {
            p->link = currentNode;
        } 
    }

    //else
    else
    {
        //link p to current node
        p->link = currentNode;
        
        //link previous node to p
        previous->link = p;
    }

    //increase numNodes by one
    ++numNodes;
    currentNode = p;
    
}