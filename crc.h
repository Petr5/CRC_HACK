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
        string brute_force(unsigned int known_hash);
        string str_to_hex(string ascii);
        unsigned int calculate_crc(string password);
        pair<string, bool> brute_force_dict(unsigned int hash_password);
        string mask_brute(unsigned int known_hash, string& rule, int count = 0, string str = "");
        string mask_brute_parallel(unsigned int known_hash, string rule, int count = 0, string str = "");
        string help_mask_brute_parallel(unsigned int known_hash, string& rule, int count, string str, int nmb_of_thread, int numCPU);
        string brute_force_parallel(unsigned int known_hash);
    private:
        unsigned int CRC32_function(unsigned char *buf, unsigned long len);


    };
}



#endif //CRC_CRC_H
