#include <iostream>

//DAVID PREFONTAINE
//

//PROBLEM 6 OF FINAL

//THIS IS THE APPROACH WITH ONLY NESTED COMPARISONS TO PUT INTO MAX, MID, AND MIN

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

    if (first > second){
        if (first > third){
            max_num = first;

            if (second > third){
                mid_num = second;
                min_num = third;
            } else {
                mid_num = third;
                min_num = second;
            }
        } else {
            max_num = third;
            mid_num = first;
            min_num = second;
        }
    } else {
        if (first > third){
            max_num = second;
            mid_num = first;
            min_num = third;
        } else {
            min_num = first;

            if (second > third){
                max_num = second;
                mid_num = third;
            } else {
                max_num = third;
                mid_num = second;
            }
        }
    }


    std::cout << "The max is: " << max_num << std::endl;
    std::cout << "The mid is: " << mid_num << std::endl;
    std::cout << "The min is: " << min_num << std::endl;

    return 0;
}
