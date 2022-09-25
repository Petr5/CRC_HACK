//
// Created by peter on 25.09.22.
//

#ifndef CRC_CRC_H
#define CRC_CRC_H
#include <iostream>
#include "gtest/gtest.h"
#include <boost/crc.hpp>      // for boost::crc_basic, boost::crc_optimal
#include <boost/cstdint.hpp>
#include <boost/core/typeinfo.hpp>
#include <string>
#include <cassert>
#include <typeinfo>
#include <fstream>
using namespace std;
namespace crc{
    class crc{
    public:

        string str_to_hex(string ascii);
        uint16_t calculate_crc(string password);
        pair<string, bool> brute_force(uint16_t hash_password);
    };
}



#endif //CRC_CRC_H
