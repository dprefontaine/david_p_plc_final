#include <iostream>

//DAVID PREFONTAINE
//

//PROBLEM 6 OF FINAL

//THIS IS THE APPROACH WITHOUT NESTED COMPARISONS TO PUT INTO MAX, MID, AND MIN

int main(int args, char* argv[]){
    int first, second, third;
    int max_num, mid_num, min_num;

    std::cout << "Input three different numbers" << std::endl;
    std::cout << "First:  ";
    std::cin >> first;
    std::cout << "Second: ";
    std::cin >> second;
    std::cout << "Third:  ";
    std::cin >> third;

    //NOW DETERMINING MAX
    if (first > second && first > third){
        max_num = first;
    } else if (second > third){
        max_num = second;
    } else {
        max_num = third;
    }

    //DETERMINING MID
    if ((first < second && first > third) ||
        (first > second && first < third)){
        mid_num = first;
    } else if ((second < first && second > third) ||
               (second > first && second < third)){
        mid_num = second;
    } else {
        mid_num = third;
    }

    //DETERMINING MIN
    if (first < second && first < third){
        min_num = first;
    } else if (second < third){
        min_num = second;
    } else {
        min_num = third;
    }

    std::cout << "The max is: " << max_num << std::endl;
    std::cout << "The mid is: " << mid_num << std::endl;
    std::cout << "The min is: " << min_num << std::endl;

    return 0;
}
