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

    //
    p->listData = item;
    if (currentPos <= 1)
    {
        head = p;
        currentPos = 1;
        if (numnodes == 0)
        {
            p->link = null;
        }
        else
        {
            p->link = currentNode;
        } 
    }
    else
    {
        p->link = currentNode;
        previous->link = p;
    }
    ++numNodes;
    currentNode = p;
    
}