import java.util.Random;

class functionSearch
{
    public static void main (String[] args)
    {

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
        }

        return place;

    }

    int split (int lo, int hi)
    {
        Random random = new Random();

        int place = random
    }
}