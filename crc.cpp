#include "crc.h"
#include <filesystem>
#include <thread>
using std::uint16_t;
using namespace std;


namespace crc{
    string alp = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digit = "0123456789";
    vector<string> brute_dict;
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

    unsigned int crc::CRC32_function(unsigned char *buf, unsigned long len)
    {
        unsigned long crc_table[256];
        unsigned long crc;
        for (int i = 0; i < 256; i++)
        {
            crc = i;
            for (int j = 0; j < 8; j++)
                crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
            crc_table[i] = crc;
        };
        crc = 0xFFFFFFFFUL;
        while (len--)
            crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
        return crc ^ 0xFFFFFFFFUL;
    }

//возвращание конечного CRC32. Достаточно вызвать эту функцию и указать имя файла, для которого будет произведён расчёт
    unsigned int crc::calculate_crc(string password)
    {
        return CRC32_function((unsigned char*) const_cast<char *>(password.c_str()), password.size());
    }

    pair<string, bool> crc::brute_force_dict(unsigned int hash_password){
        fstream fin("/home/peter/CLionProjects/CRC_HACK2/cmake-build-debug/500-worst-passwords2.txt");
        string candidate_pwd;
        string res;
        if (!fin.is_open()){
            cerr << "file doesn't open " << endl;
        }
        while (getline(fin, candidate_pwd)){
            if (calculate_crc(candidate_pwd) == hash_password){

                res = candidate_pwd;
            }
        }
        bool pwd_exist = false;
        if (!res.empty()) pwd_exist = true;
        std::filesystem::path cwd = std::filesystem::current_path();
//        cout << "current directory is " <<  cwd << endl;
        return make_pair(res, pwd_exist);
    }

    string crc::brute_force(unsigned int known_hash){
        string str = "";
        string ans;
        for (int i = 1; i < 4; ++i){
            make_word(str, i);
            for (int j = 0; j < brute_dict.size(); ++j){
                if (calculate_crc(brute_dict[j]) == known_hash){
                    ans = brute_dict[j];
                }
            }
            if (ans != "") return ans;
            brute_dict.clear();
        }
        return ans;
    }
    void crc::make_word(string s, int len){
        if (!len){
            brute_dict.push_back(s);
        }
        else
            for (int i = 0; i < alp.size(); ++i){
                make_word(s + alp[i], len - 1);
            }
    }
    string crc::mask_brute(unsigned int known_hash, string& rule, int count, string str ){
        if (calculate_crc(str) == known_hash){
            return str;
        }
        else if (count == rule.size()) return "";
        else{
            string dict;
            string ans;
            if (rule[count] == 'l') dict = lower;
            if (rule[count] == 'u') dict = upper;
            if (rule[count] == 'd') dict = digit;
            for (int i = 0; i < dict.size(); ++i){
                string res = mask_brute(known_hash, rule, count + 1, str + dict[i]);
                if (!res.empty()) {
                    ans = res;
                }
            }
            return ans;
        }
    }
    string crc::help_mask_brute_parallel(unsigned int known_hash, string& rule, int count, string str, int nmb_of_thread, int numCPU){
        if (calculate_crc(str) == known_hash){
            return str;
        }
        else if (count == rule.size()) return "";
        else{
            string dict;
            string ans;
            if (rule[count] == 'l') dict = lower;
            if (rule[count] == 'u') dict = upper;
            if (rule[count] == 'd') dict = digit;
            if (!count){
                for (int i = ((int)dict.size() * (nmb_of_thread - 1)) / numCPU; i < (dict.size() * nmb_of_thread) / numCPU; ++i){
                    string res = help_mask_brute_parallel(known_hash, rule, count + 1, str + dict[i], nmb_of_thread, numCPU);
                    if (!res.empty()) {
                        ans = res;
                    }
                }
                return ans;
            }
            else{
                for (int i = 0; i < dict.size(); ++i){
                    string res = help_mask_brute_parallel(known_hash, rule, count + 1, str + dict[i], nmb_of_thread, numCPU);
                    if (!res.empty()) {
                        ans = res;
                    }
                }
                return ans;
            }

        }
    }
    string crc::mask_brute_parallel(unsigned int known_hash, string rule, int count, string str ){
        int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
        std::vector<std::thread> threads;
        string password;
        for (int i = 0; i < numCPU - 1; ++i){
            threads.emplace_back([=,&password](){password += help_mask_brute_parallel(known_hash, const_cast<string &>(rule), count, str, i, numCPU);});
        }
        password += help_mask_brute_parallel(known_hash, const_cast<string &>(rule), count, str, numCPU, numCPU);
        for (int i = 0; i < threads.size(); ++i)
            if (threads[i].joinable())
                threads[i].join();
        return password;
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

