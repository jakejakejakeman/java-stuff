public class Factorial
{
    // Purely recursive function with no tail
    public static long pureRecursive (int n)
    {
        if (n<1)
            throw new IllegalArgumentException("Number is non-positive!");
        else if (n==1)
            return (n);
        else
            return (n * pureRecursive(n-1));
    }
    // Tail recursive method
    public static long tailRecursive (int n)
    {
        return (tail (1, n));
    }
    // Private method for the tail recursive method
    private static long tail(long mult, int n)
    {
        if (n<1)
            throw new IllegalArgumentException("Number is non-positive!");
        else if (n==1)
            return (mult*n);
        else
            return tail(mult*n,n-1);
    }
    // Unwound version of tail recursive method
    public static long iterative (int n)
    {
        long mult=1;
        while(true)
        {
            if (n<1)
                throw new IllegalArgumentException("Number is non-positive!");
            if (n==1)
                return (mult*n);
            mult=mult*n;
            n=n-1;
        }
    }

}
