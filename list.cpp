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
        ListNode<BaseData> *afterNode;

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

template <class BaseData>
void List<BaseData>::insertAfter(const BaseData &item)
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
            p->link = null;
        }
        else
        {
            currentNode->link = p;
            p->link = null;
        }
    }
    else
    {
        currentNode->link = p;
        p->link = afterNode;
    }

    ++numNodes;
    currentNode = p;
    
}

template <class BaseData>
void List<BaseData>::remove()

{
    ListNode<BaseData>*p, *temp;

    p = currentNode;

    //if current position of current node is 1
    if (currentPos == 1)
    {
        //assign head to the next node
        head = currentNode -> link;

        //set currentNode to head
        currentNode = head;
    }

    //if position of node is anywhere else
    else
    {

        //connect previous node to the node after currentNode
        previous->link = currentNode->link;
        
        //if there is a node following currentNode
        if (currentNode->link != null)
        {
            //set currentNode to the following node
            currentNode = currentNode->link
        }
        else
        {
            //set currentNode to previous
            currentNode = previous;

            //set temp to head
            temp = head;
            
            //while head is not equivalent to currentNode (ie. start from the start and go to there)
            while (temp->link != currentNode)
            {
                //link everything
                temp = temp->link;
            }

            //set previous to temp
            previous = temp;
            //fix current postiion 
            --currentPos
            
        }
        
        
    }

    //delete node
    delete p;
    --numNodes  
}

template <class BaseData>
void List<BaseData>::replace(const BaseData &item)
{
    
}