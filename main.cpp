#include <iostream>
#include "gtest/gtest.h"
#include <boost/crc.hpp>      // for boost::crc_basic, boost::crc_optimal
#include <boost/cstdint.hpp>
#include <boost/core/typeinfo.hpp>
#include <string>
#include <cassert>
#include <typeinfo>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using std::uint16_t;
using namespace std;
#include "crc.h"

int main(int argc, char* argv[]) {
    crc::crc crc_hash;
    string password;
    cout  << crc_hash.calculate_crc("girla") << endl;
    cout << "hello from main file !" << endl;
    cout << crc_hash.brute_force(crc_hash.calculate_crc("girl")) << endl;
    string type = argv[1];
    cout << "type is " << type << endl;
    unsigned int hash = stoul(argv[2]);
    if (type == "-0"){
        password = crc_hash.brute_force_dict(hash).first;
    }
    else if (type == "-1"){
        cout << "if len of password greater than 6 brute force take a long time" << endl;
//        cout << "estimated time is " <<
        password = crc_hash.brute_force(hash);
    }
    else if (type == "-2"){
        string rule = argv[3];
        rule.erase(std::remove(rule.begin(), rule.end(), 'a'), rule.end());
        cout << "rule after erase ? is " << rule << endl;
        auto start = high_resolution_clock::now();
        password = crc_hash.mask_brute(hash, rule);
        auto stop = high_resolution_clock::now();
        cout << "without parallel time for hacking hash " << duration_cast<seconds>(stop - start).count() << endl;
        start = high_resolution_clock::now();
        password = crc_hash.mask_brute_parallel(hash, rule);
        stop = high_resolution_clock::now();
        cout << "using parallel time for hacking hash " << duration_cast<seconds>(stop - start).count() << endl;
    }
    else{
        cout << "please specify the type of cracking approach:" << endl;
        cout << "-0 - using dictionary" << endl;
        cout << "-1 - using straightforward brute force" << endl;
        cout << "-2 - using mask for bruteforce" << endl;
    }
    cout << "Hash successfully cracked " << "password is " << password << endl;
    return 0;
}
