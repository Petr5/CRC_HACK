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

TEST(CRC_CALC_TEST, CORRECT_VALUE){
    crc::crc crc_hash;
    uint16_t known_checksum = 0x583E;
    string password = "ILove_MyCat";
    EXPECT_EQ(known_checksum, crc_hash.calculate_crc(password));

}


struct crc_test : testing::Test{
    crc::crc* crc_hash;
    crc_test(){
        crc_hash = new crc::crc;
    }
    ~crc_test(){
        delete crc_hash;
    }
};
TEST_F(crc_test, CORRECT_VALUE){
    uint16_t known_checksum = 0x583E;
    string password = "ILove_MyCat";
    EXPECT_EQ(known_checksum, crc_hash->calculate_crc(password));

}
struct crc_state{
    uint16_t known_hash;
    string password;
    bool password_exist_in_dict;
};

struct BruteForceCrcTest : crc_test, testing::WithParamInterface<crc_state>{
    BruteForceCrcTest(){}
};

TEST_P(BruteForceCrcTest, coorect_brute){
    auto as = GetParam();
    EXPECT_EQ(as.password, crc_hash->brute_force(as.known_hash).first);
    EXPECT_EQ(as.password_exist_in_dict, crc_hash->brute_force(as.known_hash).second);
}
INSTANTIATE_TEST_CASE_P(Default, BruteForceCrcTest, testing::Values(
        crc_state{0x583E, "ILove_MyCat", true},
        crc_state{0x583, "", false},
        crc_state{0x583E, "ILove_MyCat", true},
        crc_state{0x1607, "jaguar", true}

));

//struct ASCII_TO_HEX : crc_test, testing::WithParamInterface<crc_state>{
//    ASCII_TO_HEX(){
//    }
//};
//
//struct convert_state{
//    string ascii;
//    string hex;
//};

TEST(ASCII_TO_HEX, coorect_convert){
//    auto as = GetParam();
    crc::crc my_crc;
    cout <<  my_crc.str_to_hex("sdf") << endl;
    EXPECT_EQ("736466", my_crc.str_to_hex("sdf"));
    EXPECT_EQ("73616161", my_crc.str_to_hex("saaa"));
    EXPECT_EQ("3B", my_crc.str_to_hex(";"));

}


int main(int argc, char* argv[]) {
    crc::crc crc_hash;
    uint16_t known_checksum = 0x1021;
    string password = "jaguar";
//    cout << "Hash for password " << password << " is " <<  crc_hash.calculate_crc(password) << endl;
//    cout << "BruteForce Attack cracking hash is " << known_checksum << "cracked password is " << crc_hash.brute_force(known_checksum) << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
