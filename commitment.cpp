/**
 * This class is for bit commitment protocol by Naor.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <iomanip>
#include "randbit.hpp"

using namespace std;

class Commitment{
public:
    string commit(uint8_t);


};

string commit(uint8_t value){
    const double prob = 0.6;
    uint32_t key;

    rbs::generator gen(prob);
    key = gen();

    return b2s(key);
}

uint8_t verify(string bits) {

}

std::string b2s(uint32_t bs) {
  std::stringstream ss;
  for (int i = 0; i < 32; i++) {
    ss << ((bs & (1 << (32 - i - 1))) ? 1 : 0);
  }
  return ss.str();
}

