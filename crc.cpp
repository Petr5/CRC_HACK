#include "crc.h"
using std::uint16_t;
using namespace std;


namespace crc{
    string crc::str_to_hex(string ascii){
        char const hex_chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        string res;
        for( int i = 0; i < ascii.size(); ++i )
        {
            char const byte = ascii[i];

            res += hex_chars[ ( byte & 0xF0 ) >> 4 ];
            res += hex_chars[ ( byte & 0x0F ) >> 0 ];
        }
        return res;
    }

    uint16_t crc::calculate_crc(string password){

        unsigned char* data = new unsigned char[password.size()];
        for (int i = 0 ; i < password.size(); ++i){
            data[i] = password[i];
//            cout << data[i] << endl;
        }
        std::size_t const    data_len = sizeof( data ) / sizeof( data[0] );
        boost::crc_basic<16>  crc_ccitt1( 0x1021, 0xFFFF, 0, false, false );
        crc_ccitt1.process_bytes( data, data_len );
        uint16_t res = crc_ccitt1.checksum();
        return res;
    }

    pair<string, bool> crc::brute_force(uint16_t hash_password){
        fstream fin("500-worst-passwords2.txt");
        string candidate_pwd;
        string res;
        if (!fin.is_open()){
            cout << "file doesn't open " << endl;
        }
        while (getline(fin, candidate_pwd)){
            if (calculate_crc(candidate_pwd) == hash_password){

                res = candidate_pwd;
            }
        }
        bool pwd_exist = false;
        if (!res.empty()) pwd_exist = true;
        return make_pair(res, pwd_exist);
    }
};





























//
//
//#include <boost/crc.hpp>      // for boost::crc_basic, boost::crc_optimal
//#include <boost/cstdint.hpp>  // for boost::uint16_t
//
//#include <algorithm>  // for std::for_each
//#include <cassert>    // for assert
//#include <cstddef>    // for std::size_t
//#include <iostream>   // for std::cout
//#include <ostream>    // for std::endl
//
//
//// Main function
//int
//main ()
//{
//    // This is "123456789" in ASCII
//    unsigned char const  data[] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
//                                    0x38, 0x39 };
//    std::size_t const    data_len = sizeof( data ) / sizeof( data[0] );
//
//    // The expected CRC for the given data
//    boost::uint16_t const  expected = 0x29B1;
//
//    // Simulate CRC-CCITT
//    boost::crc_basic<16>  crc_ccitt1( 0x1021, 0xFFFF, 0, false, false );
//    crc_ccitt1.process_bytes( data, data_len );
//    assert( crc_ccitt1.checksum() == expected );
//
//    // Repeat with the optimal version (assuming a 16-bit type exists)
//    boost::crc_optimal<16, 0x1021, 0xFFFF, 0, false, false>  crc_ccitt2;
//    crc_ccitt2 = std::for_each( data, data + data_len, crc_ccitt2 );
//    assert( crc_ccitt2() == expected );
//
//    std::cout << "All tests passed." << std::endl;
//    return 0;
//}

