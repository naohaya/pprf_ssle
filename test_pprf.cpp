#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "cmdline.h"
#include "pprf.h"

using namespace std;

/* Test code for using the class PPRF */
int main(int argc, char* argv[]){
    const uint64_t defaultSeed = 0x93064E905C127FE5;
    const uint64_t defaultHash = 0xA4BDE5C4A05E6256;
    const uint64_t defaultlcg = 0;
    int keySize = 0;

    uint64_t seed = defaultSeed; /* secret */
    uint64_t lcg = defaultlcg;
    uint64_t hash = defaultHash; /* key */
    uint64_t v = 0;
    string result;

    PPRF pr;
    
    //std::string in_seed;
    //std::string in_hash;

    /* for analyzing command line arguments */
    cmdline::parser cla;
    cla.add<string>("secret", 's', "secret value", false);
    cla.add<string>("key", 'k', "key value", false);
    cla.add("help", 0, "print usage");

    if(!cla.parse(argc, argv) || cla.exist("help")) {
        std::cout << cla.error_full() << cla.usage();
        return 0;
    }

    if (cla.exist("secret")) {
        //in_seed = argv[2]; //p.get<std::string>("secret"); 
        seed = pr.hexToDecimal(argv[2]);
    }

    if(cla.exist("key")) {
        /* hash = hexToDecimal(p.get<std::string>("key")); */
        //in_hash = argv[4];
        hash = pr.hexToDecimal(argv[4]);
    }

    

    cout << "secret: " << seed << endl;

    v = pr.prf(&seed, &lcg, &hash);

    cout << "key (decimal): " << v << endl; 

    result = pr.puncturing(v);

    cout << "punctured key: " << result << endl;


}