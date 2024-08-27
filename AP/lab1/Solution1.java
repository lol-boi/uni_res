import java.util.Scanner;
class Solution1{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter the val n: ");
		int num = scanner.nextInt();
		for(int i = 1; i<= num; i++){
			for(int j = 0; j<num-i; j++){
				System.out.print("    ");
			}	
			for(int j = 1; j<=i; j++){
				System.out.print(j);
				System.out.print("       ");
			}	
			System.out.println();
		}
		for(int i = num; i>0; --i){
			for(int j = num; j>i-1; j--){
				System.out.print("    ");
			}
			for(int j=1; j<i; j++){
				System.out.print(j);
				System.out.print("   ");
			}
			for(int j = i-2; j>0; --j){
				System.out.print(j);
				System.out.print("   ");
			}
			System.out.println();
			  
		}
	}
}
