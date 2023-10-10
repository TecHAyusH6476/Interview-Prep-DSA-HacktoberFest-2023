import java.util.Scanner;
 
public class FrequencyOfDigits
{   
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
         
        //Taking inputNumber from the user
         
        System.out.println("Enter the number :");
         
        int inputNumber = sc.nextInt();
         
        //Creating an Array object to hold the frequency of corresponding digits
        int[] digitCount = new int[10];
         
        while (inputNumber != 0)
        {
            //Get the lastDigit of inputNumber
            int lastDigit = inputNumber % 10;
             
            //incrementing the lastDigit's count
            digitCount[lastDigit]++;
             
            //Removing the lastDigit from inputNumber
            inputNumber = inputNumber / 10;
        }
         
        //Printing digits and their frequency
        System.out.println("===================");
        System.out.println("Digits : Frequency");
        System.out.println("===================");
         
        for (int i = 0; i < digitCount.length; i++)
        {
            if(digitCount[i] != 0)
            {
                System.out.println("   "+i+"   :   "+digitCount[i]);
            }
        } 
    }
}