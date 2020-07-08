public class shellSort
{
    public static void main (String[] args)
    {

    }
}

class sortArray
{
    void segmentedInsertionSort(int a[], int k)
    {
        int j, m, n;
        boolean done;

        n = a.length;

        //Insert element from index m in approrpiate slot in its segment

        for (m = k; m < n; ++m)
        {
            j = m;
            done = false;

            //when j-kth element precedes jth element, jth is appropriately positioned in its segment

            while ((j >= k) && !done)
            {
                if (a[j] < a[j-k])
                {
                
                }
            }
        }
    }
}