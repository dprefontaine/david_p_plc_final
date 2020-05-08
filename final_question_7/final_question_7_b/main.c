//DAVID PREFONTAINE
//

//PROBLEM 7 B OF FINAL

//REWRITING THE PROGRAM WITH IFS AND GOTOS

int main(){
    int i,j;

    j = -3;
    i = 0;

    loop:

    if ((j+2) == 2 || (j+2) == 3)
        j--;
    else if ((j+2) == 0)
        j+=2;
    else
        j = 0;

    if (j > 0)
        goto done;

    j = 3 - i;

    i++;
    if (i < 3)
        goto loop;

    done:

    return 0;
}
