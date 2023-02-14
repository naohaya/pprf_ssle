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
    string commit(uint32_t, int);
    bool verify(string, string);
    string b2s(uint32_t);


};

/*
* Function for bit commitment. 
* rand is a random value to commit 
* b is a bit to be committed. 
*/
string Commitment::commit(uint32_t rand, int b){
  const double prob = 0.6;
  uint32_t key;
  uint32_t result;

  rbs::generator gen(prob);
  key = gen(); // generate a random key

  if (b) {
    result = rand; // replace to pprf(rand)

  } else{
    result = rand ^ key; // replace to pprf(rand)
  }


    return b2s(result);
}

bool Commitment::verify(string bits, string rand) {
  uint32_t input = stoi(bits);
  uint32_t rvalue = stoi(rand);
  uint32_t result;

  result = rvalue; // temporary

//  result = pprf(rand);
  if (result == input) {
    return true;
  } else {
    return false;
  }

}

std::string Commitment::b2s(uint32_t bs) {
  std::stringstream ss;
  for (int i = 0; i < 32; i++) {
    ss << ((bs & (1 << (32 - i - 1))) ? 1 : 0);
  }
  return ss.str();
}


/**
 * for test 
*/
int main(int argc, char *argv[]) {
  uint32_t rand = 0b01000111111011101111; 
  Commitment com = Commitment();
  cout << "commit: " << com.commit(rand, 1) << endl;
  cout << "commit: " << com.commit(rand, 0) << endl; // XOR result



}
