import java.lang.*;
import java.util.Scanner;
public class ShowDouble {
    public static void main (String[]args)
    {
        System.out.println("It's shows your double number:");
        double nums []= new double[5] ;
        Scanner s1 = new Scanner (System.in);
        System.out.println("Enter your Double Numbers:");
        for(int i=0;  i<nums.length; i++ )
        {
            nums[i] = s1.nextDouble();
        }
        double value = s1.nextDouble();
        System.out.println("This  your Double Numbers:");
        for(double num : nums )
        {
            System.out.println(num + " ");
        }

        double min = nums[0];
        double max = nums[0];

        for ( int i =1 ; i< nums.length; i++){
            if(nums[i]< min ){
                min = nums[i];

            }
            if(nums[i]>max){
                max = nums[i];
            }
            System.out.println("Min Value:" + min);
            System.out.println("Max value: " + max);
        }
    }
    
}
