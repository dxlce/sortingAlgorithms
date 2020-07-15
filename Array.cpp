template <class IndexType, class BaseData>
class Array
{
    private:
        BaseData *arrayData;
        int loIndex, hiIndex;
        bool outOfRange(IndexType i);

    public:
        Array(IndexType lo, IndexType hi);

        Array();

        void assign(IndexType i, const BaseData &val);

        BaseData retrieve
    
}

//Implementations of operations for the Array class

#include <assert.h>

template <class IndexType, class BaseData>
Array<IndexType, BaseData>::Array(IndexType lo, IndexType hi)
{
    arrayData = new BaseData[hi - lo + 1];
    assert(arrayData != 0);

    loIndex = lo;
    hiIndex = hi;
}

template <class IndexType, class BaseData>
Array<IndexType, BaseData>::Array()
{
    delete [] arrayData;
}

template <class IndexType, class BaseData>
bool Array<IndexType, BaseData>::outOfRange(IndexType i)
{
    if ((i < loIndex ) || (i > hiIndex))
    {
        cerr << "Index " << i << " out of range" << endl;
        return(true);
    }
    else
    {
        return(false);
    }
}

template <class IndexType, class BaseData>
void Array<IndexType, BaseData>::assign(IndexType i, const BaseData &val)
{
    assert(!outOfRange(i));
    arrayData[i - loIndex] = val;
}

template <class IndexType, class BaseData>
BaseData Array<IndexType, BaseData>::retrieve(IndexType i)
{
    assert(!outOfRange(i));
    return(arrayData[i - loIndex]);
}