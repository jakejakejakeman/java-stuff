import java.util.Scanner;

public class Cowsay
{
    private static void listCows(Cow[] cows)
    {
        // This shows the user the names of the available cows.
        System.out.print("Cows available: ");
        for (int i=0; i<cows.length; i++)
            System.out.print (cows[i].getName()+" ");
    }
    private static Cow findCow(String name, Cow[] cows)
    {
        // This finds the cow from the cow list based off the name inputted.
        for (int i=0; i<cows.length; i++)
            if (name.equals(cows[i].getName())==true)
                return(cows[i]);
            return null;
    }
    public static void main (String[] args)
    {
        Cow[] cows;
        cows=HeiferGenerator.getCows();
        Scanner scnr = new Scanner(System.in);
        String response = scnr.next();
        // If statements outline the different options available
        if (response.equals("-l")==true)
        {
            listCows(cows);
        }
        else if(response.equals("-n")==true)
        {
            String response2 = scnr.next();
            String response3 = scnr.next();
            String response4 = scnr.nextLine();
            if ((findCow(response2, cows)!=null))
            {
                System.out.println(response3+response4);
                System.out.println((findCow(response2, cows)).getImage());
            }
            else
                System.out.println("Could not find " + response2 + " cow!");
        }
        else
        {
            String response2 = scnr.nextLine();
            System.out.println(response+response2);
            System.out.println((findCow("heifer", cows).getImage()));
        }
    }
}
