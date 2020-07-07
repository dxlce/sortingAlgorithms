import java.util.Random;


//Divide and conquer function
class functionSearch
{
    public static void main (String[] args)
    {
        int a[] = {21, 4, 5, 2, 6, 10, 16};
        int target = 6;
        searchArray obj = new searchArray();

        System.out.println(obj.search(a, target));
    }
}

class searchArray
{
    int search(int a[], int target)
    {
        int n = a.length;

        int hi, lo, guess;
        boolean found;
        int place = 0;
        hi = n-1;
        lo = 0;
        found = false;

        while (!found && (lo <= hi))
        {
            guess = split(lo, hi);
            if (a[guess] == target)
            {
                place = guess;
                found = true;
            }
            else
            {
                if (a[guess] < target)
                {
                    lo = guess + 1;
                }
                else
                {
                    hi = guess - 1;
                }
            }

            System.out.println(guess);
        }

        return place;

    }

    int split (int lo, int hi)
    {
        Random random = new Random();

        int place = random.nextInt((hi - lo) + 1) + lo;
        return place;
    }
}