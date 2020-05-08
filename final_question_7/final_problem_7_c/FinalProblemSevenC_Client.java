package final_problem_7_c;

//DAVID PREFONTAINE
//

//PROBLEM 7 C OF FINAL

//REWRITING THE PROGRAM IN JAVA WITHOUT SWITCH

public class FinalProblemSevenC_Client {
	public static void main(String[] args) {
		int j, temp;
		
		j = -3;
		
		for (int i = 0; i < 3; i++) {
			temp = j + 2;
			
			if (temp == 3 || temp == 2) {
				j--;
			} else if (temp == 0) {
				j += 2;
			} else {
				j = 0;
			}
			
			if (j > 0)
				break;
			
			j = 3-i;
		}
	}
}
