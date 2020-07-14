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