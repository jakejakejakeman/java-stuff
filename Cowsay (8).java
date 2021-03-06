import java.util.Scanner;

public class Cowsay
{
    private static void listCows(Cow[] cows, Cow[] fileCows)
    {
        // This shows the user the names of the available cows.
        System.out.print("Cows available: ");
        for (int i=0; i<cows.length; i++)
            System.out.print (cows[i].getName()+" ");
        System.out.println();
        System.out.print("File cows available: ");
        for (int i=0; i<fileCows.length; i++)
            System.out.print (fileCows[i].getName()+" ");
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
        Cow[] fileCows;
        cows=HeiferGenerator.getCows();
        fileCows=HeiferGenerator.getFileCows();
        Scanner scnr = new Scanner(System.in);
        String response = scnr.next();
        // If statements outline the different options available
        if (response.equals("-l")==true)
        {
            listCows(cows,fileCows);
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
                if ((findCow(response2, cows)) instanceof IceDragon)
                    System.out.println("This dragon cannot breathe fire.");
                else if ((findCow(response2, cows)) instanceof Dragon)
                    System.out.println("This dragon can breathe fire.");

            }
            else
                System.out.println("Could not find " + response2 + " cow!");
        }
        // Added to explore the FileCow objects
        else if (response.equals("-f")==true)
        {
            String response2 = scnr.next();
            String response3 = scnr.next();
            String response4 = scnr.nextLine();
            if ((findCow(response2, fileCows)!=null))
            {
                System.out.println(response3+response4);
                FileCow.getImage(findCow(response2, fileCows));
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
