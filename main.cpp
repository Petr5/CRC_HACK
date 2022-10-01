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
//#define MULTITHREADING

void PRINT_USAGE(){
    cout << "SYNOPSIS\
       ./MainProgram [options] hash [mask|wordfiles|directories]" << endl;
    cout << "please specify the type of cracking approach:" << endl;
    cout << "-0 - using dictionary" << endl;
    cout << "-1 - using straightforward brute force" << endl;
    cout << "-2 - using mask for bruteforce" << endl;
}
#ifdef MULTITHREADING


int main(int argc, char* argv[]) {
     cout << "STARTED MULTITHREAD PROGRAM" << endl;
    crc::crc crc_hash;
    string password;
    if (argc == 1){
        PRINT_USAGE();
        return 0;
    }
    string type = argv[1];
    unsigned int hash = stoul(argv[2]);
    if (type == "-0"){
        password = crc_hash.brute_force_dict(hash).first;
    }
    else if (type == "-1"){
        cout << "if len of password greater than 6 brute force take a long time" << endl;
//        cout << "estimated time is " <<
        auto start = high_resolution_clock::now();
        password = crc_hash.brute_force_parallel(hash);
        auto stop = high_resolution_clock::now();
        cout << "using parallel time for hacking hash " << duration_cast<seconds>(stop - start).count() << endl;
    }
    else if (type == "-2"){
        string rule = argv[3];
        rule.erase(std::remove(rule.begin(), rule.end(), 'a'), rule.end());
        cout << "rule after erase ? is " << rule << endl;

        auto start = high_resolution_clock::now();
        password = crc_hash.mask_brute_parallel(hash, rule);
        auto stop = high_resolution_clock::now();
        cout << "using parallel time for hacking hash " << duration_cast<seconds>(stop - start).count() << endl;
    }
    else{
       PRINT_USAGE();
    }
    if (!password.empty()){
        cout << "Hash successfully cracked " << "password is " << password << endl;
    }
    else{
        cout << "Something went wrong, hash doesn't cracked" << endl;
    }
    return 0;
}

#else
int main(int argc, char* argv[]) {
    cout << "STARTED TRADITIONAL PROGRAM" << endl;
    crc::crc crc_hash;
    string password;
    if (argc == 1){
        PRINT_USAGE();
        return 0;
    }
    string type = argv[1];
    cout << "DEBUG: type is " << type << endl;
    unsigned int hash = stoul(argv[2]);
    if (type == "-0"){
        password = crc_hash.brute_force_dict(hash).first;
    }
    else if (type == "-1"){
        cout << "TIP: if len of password greater than 6 brute force take a long time" << endl;
//        cout << "estimated time is " <<
        auto start = high_resolution_clock::now();
        password = crc_hash.brute_force(hash);
        auto stop = high_resolution_clock::now();
        cout << "without multithreading time is required for hacking hash " << duration_cast<seconds>(stop - start).count() << " second" << endl;
    }
    else if (type == "-2"){
        string rule = argv[3];
        rule.erase(std::remove(rule.begin(), rule.end(), 'a'), rule.end());
        cout << "rule after erase ? is " << rule << endl;

        auto start = high_resolution_clock::now();
        password = crc_hash.mask_brute(hash, rule);
        auto stop = high_resolution_clock::now();
        cout << "without multithreading time is required for hacking hash " << duration_cast<seconds>(stop - start).count() << " second" << endl;
    }
    else{
       PRINT_USAGE();
    }
    if (!password.empty()){
        cout << "Hash successfully cracked " << "password is " << password << endl;
    }
    else{
        cout << "Something went wrong, hash doesn't cracked" << endl;
    }

    return 0;
}
#endif

