#include <iostream>
#include "gtest/gtest.h"
#include <boost/crc.hpp>      // for boost::crc_basic, boost::crc_optimal
#include <boost/cstdint.hpp>
#include <boost/core/typeinfo.hpp>
#include <string>
#include <cassert>
#include <typeinfo>
#include <fstream>
using std::uint16_t;
using namespace std;
#include "crc.h"

int main(int argc, char* argv[]) {
    crc::crc crc_hash;
    cout  << crc_hash.calculate_crc("girl") << endl;
    cout << "hello from main file !" << endl;
//    cout << crc_hash.brute_force(crc_hash.calculate_crc("girl")) << endl;
    return 0;
}
