//DAVID PREFONTAINE
//

//PROBLEM 7 A OF FINAL

//REWRITING THE PROGRAM WITHOUT GOTOS OR BREAKS

#define TRUE 1
#define FALSE 0

int main(){
    int i,j, comp_flag;

    j = -3;
    i = 0;
    comp_flag = TRUE;

    while (i < 3 && comp_flag){
        if ((j+2) == 2 || (j+2) == 3)
            j--;
        else if ((j+2) == 0)
            j+=2;
        else
            j = 0;

        if (j > 0)
            comp_flag = FALSE;

        j = 3 - i;

        i++;
    }

    return 0;
}
