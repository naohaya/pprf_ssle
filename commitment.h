#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <iomanip>
#include "randbit.hpp"

using namespace std;

class Commitment{
public:
    string commit(string, int);
    string commit(uint32_t, int);
    bool verify(string, string);
    string b2s(uint32_t);


};


