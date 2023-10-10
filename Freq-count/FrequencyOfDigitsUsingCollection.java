import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
 
public class FrequencyOfDigitsUsingCollection
{   
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
         
        System.out.println("Enter the number :");
         
        int inputNumber = sc.nextInt();
         
        //Creating a HashMap 
        HashMap<Integer, Integer> digitCountMap = new HashMap<Integer, Integer>();
         
        while (inputNumber != 0)
        {
            //Get the lastDigit of input number
            int lastDigit = inputNumber % 10;
             
            if(digitCountMap.containsKey(lastDigit))
            {
                //If lastDigit is already present in the map, incrementing its frequency by 1
                 
                digitCountMap.put(lastDigit, digitCountMap.get(lastDigit)+1);
            }
            else
            {
                //If lastDigit is not present in the map, inserting lastDigit into map with 1 as its value
                digitCountMap.put(lastDigit, 1);
            }
             
            //Removing the lastDigit from inputNumber 
            inputNumber = inputNumber / 10;
        }
         
        //Printing digits and their frequency
        System.out.println("===================");
         
        System.out.println("Digits : Frequency");
         
        System.out.println("===================");
         
        Set<Integer> keys = digitCountMap.keySet();
         
        for (Integer key : keys) 
        {
            System.out.println("   "+key+"   :   "+digitCountMap.get(key));
        }
    }
}