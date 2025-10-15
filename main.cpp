#include "include/modules.hpp"
#include <string>


int main() {
    std::string S = "0002020"; // 136
    Four number(S);
    Four num_2("0000123"); // 27

    std::cout << "Numbers:\n";
    num_2.Print();
    number.Print();

    Four copy_construct(number);
    copy_construct.Print();


    Four init_list_1 = {'2', '2', '0', '1'}; // 161
    init_list_1.Print();
    // Реализовать метод копирования
    Four cop = copy_construct.Copy(init_list_1);
    cop.Print();

    // Four resV = init_list_1.Add(number);
    // resV.Print();

    // Four result = num_2.Add(number); // 2203
    // Four answ = number.Substract(num_2); // 1231
    // std::cout << num_2.Less(number) << "\n";

    return 0;
}