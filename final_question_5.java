//DAVID PREFONTAINE
//

//PROBLEM 5 OF FINAL


//This is not meant to be a complete program, merely rewriting a fragment in Java without goto's

i = 1;
while (i <= n && j <= n){
	j = 1;
	
	while (j <= n && x[i][j] == 0){
		j++;
	}
	
	if (j > n)
		System.out.println("The first all-zero row is: " + j);
	else 
		i++;
}