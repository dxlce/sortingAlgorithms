
class sortArray
{
    void sort(int a[])
    {
        int n = a.length;

        for (int i = 1; i < n; ++i)
        {
            int key = a[i];
            int j = i - 1;
            
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j]; 
                j = j - 1; 
            } 
            a[j + 1] = key; 
            
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

public class insertionSort
{
    public static void main (String[] args)
    {
        int a[] = {12, 11, 5, 2, 7};
        
        sortArray obj = new sortArray();
        obj.sort(a);
        obj.printArray(a);

    }
}
