import java.util.ArrayList;
import java.util.Scanner;

//
//Frans 307
//

public class emirpPrime {
	
	public static void main(String[] args){
		
		//ask for user input
		System.out.println("Enter a number between 0 and 32,767");
		//Create array holding regular numbers.
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		//create array holding reversed numbers.
		ArrayList<Integer> numbersReversed = new ArrayList<Integer>();
		//create input scanner object
		Scanner userInput = new Scanner(System.in);
		//Initialising number to 1 so while loop works.
		int number = 1;
		//get user input until user says 0 or a number too small or big.
		while(number != 0){
			//get userinput number.
			number = userInput.nextInt();
			
			//Make sure number is not too big or too small, if it is, it wont get into the array/s.
			if(number < 0 || number > 32767){
				System.out.println("Number too big or too small");
			}
			//Skip so 0 wont record to the array.
			else if(number == 0){
				break;
			}
			else{
				//add input number to normal array
				numbers.add(number);
				//reverse input number and put into reversed arraay.
				int numberReversed = reverse(number);
				numbersReversed.add(numberReversed);
				
			}
			
			
			
		}
		//Close input console so no leakage happens.
		userInput.close();
		
		//Loop for printing all the numbers and if they are reversed or not.
		for(int i = 0; i < numbers.size(); i++ ){
			//Check whether the ith position in the array is a prime number.
			boolean isItPrime = primerCheck(numbers, i);
			boolean isItEmirp = false;
			
			if(isItPrime == true){
				//check whether the ith position in the reversed array is a prime number, if so, the number is an emirp.
				isItEmirp = primerCheck(numbersReversed, i);
			}
			if(isItEmirp == true){
				System.out.println(numbers.get(i) + " is an emirp.");
			}
			else if(isItPrime == true){
				System.out.println(numbers.get(i) + " is a prime.");
			}
			else{
				System.out.println(numbers.get(i) + " is not prime.");
			}
			//check if itself backwards is also a prime number.
			}
	}
	public static int reverse(int n) {
		//got reverse method from http://www.javawithus.com/programs/reversing-a-number 
		//could not figure out reverse number on my own.
	   int result = 0;
	   int rem;
	   
	   while (n > 0) {
		   rem = n % 10;
		   n = n / 10;
		   result = result * 10 + rem;
		  }
	   return n;
	}
	
	public static boolean primerCheck(ArrayList<Integer> number, int placement){
		
		boolean primeCheck = true;
		//transform number to a float so it is dividable to decimals.
		float realNumber = number.get(placement);
		//Divide number by every number from 0 to itself.
		for(int i = 2; i < realNumber; i++){
			//divide by i and compare it to rounded down same number divided by 1.
			if(realNumber / i == (int)(realNumber / i)){
				primeCheck = false;
				break;
			}
		}
		return primeCheck;
	}
	
	
}
