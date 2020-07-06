

public class selectionSort
{
    public static void main(String args[]) 
    { 
        sortArray obj = new sortArray(); 
        int a[] = {64, 5, 12, 22, 11}; 
        obj.sort(a); 
        System.out.println("Sorted array"); 
        obj.printArray(a); 
    } 
}

class sortArray
{
    void sort(int a[])
    {
        int n = a.length;

        for (int i = 0; i < n; i++)
        {
            int min = i;

            for (int j = i+1; j < n; j++)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }

            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
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
