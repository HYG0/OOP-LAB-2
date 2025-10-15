#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <cstring>
#include <vector>


class Four {
private:
    u_int32_t dex;
    std::vector<u_char> fourth_vec;
    
public:
    Four();

    ~Four();

    Four(const Four& other);

    Four(const std::initializer_list<u_char> &lst);

    Four(const std::string &s);

    Four Add(Four& num);

    Four Substract(Four& num);

    Four AddAssign(Four& num);

    Four SubstractAssign(Four& num);

    Four Copy(Four& other);

    bool Equal(Four& num);

    bool More(Four& num);

    bool Less(Four& num);

    void Print();

    u_int32_t GetDex();



private:
    void Validation();

    u_int32_t DexRepresent(const std::vector<u_char>& v);

    void DeleteZero();

    void DexToFourth();
};