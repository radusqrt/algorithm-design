import java.util.Scanner;
import java.util.Stack;

public class StackDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);//declaring a scanner for taking input from user
		Stack<Integer> stck=new Stack<Integer>();//using inbuilt stack class 
		System.out.println("Enter how many elements you want to insert into the stack");
		int n=sc.nextInt();
		
		System.out.println("Enter "+ n + " elements"); 
		for(int i=0;i<n;i++)
		{
			stck.push(sc.nextInt());//pushing elements into the stack
		}
		
		System.out.println("Printing stack elements");
		while(!stck.empty())
		{
			System.out.println(stck.pop()); //it will pop the element from the stack and print it.
		}
	}

}
