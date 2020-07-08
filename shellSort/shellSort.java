public class shellSort
{
    public static void main (String[] args)
    {
        int a[] = {14, 12, 4, 56, 2, 1};

        sortArray obj = new sortArray();
        obj.segmentedInsertionSort(a);

        obj.printArray(a);
    }
}

class sortArray
{
    void segmentedInsertionSort(int a[])
    {


        int n = a.length;

        //Insert element from index m in approrpiate slot in its segment

        for (int gap = n/2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i+=1)
            {
                int temp = a[i];

                int j;
                for (j = i; j >= gap && a[j-gap] > temp; j-= gap)
                {
                    a[j] = a[j-gap];
                }

                a[j] = temp;
            }
        }
    }

    void printArray(int a[])
    {
        int n = a.length;

        for (int i = 0; i < n; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

}