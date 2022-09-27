#include <gtest/gtest.h>

//
// Created by peter on 25.09.22.
//
TEST(EX_TEST, ex){
    EXPECT_EQ(1, 1);
}

#include "../crc.h"

TEST(CRC_CALC_TEST, CORRECT_VALUE){
    crc::crc crc_hash;
    unsigned int known_checksum = 1622266142;
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
    unsigned int known_checksum = 1622266142;
    string password = "ILove_MyCat";
    EXPECT_EQ(known_checksum, crc_hash->calculate_crc(password));

}
struct crc_state{
    unsigned int known_hash;
    string password;
    bool password_exist_in_dict;
};

struct BruteForceDictTest : crc_test, testing::WithParamInterface<crc_state>{
    BruteForceDictTest(){}
};

TEST_P(BruteForceDictTest, coorect_brute){
    auto as = GetParam();
    EXPECT_EQ(as.password, crc_hash->brute_force_dict(as.known_hash).first);
    EXPECT_EQ(as.password_exist_in_dict, crc_hash->brute_force_dict(as.known_hash).second);
}
INSTANTIATE_TEST_CASE_P(Default, BruteForceDictTest, testing::Values(
        crc_state{1622266142, "ILove_MyCat", true},
        crc_state{0x583, "", false},
        crc_state{1622266142, "ILove_MyCat", true},
        crc_state{2329541781, "jaguar", true}

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
    EXPECT_EQ("736466", my_crc.str_to_hex("sdf"));
    EXPECT_EQ("73616161", my_crc.str_to_hex("saaa"));
    EXPECT_EQ("3B", my_crc.str_to_hex(";"));

}

TEST(brute_force, correct_brute){
    crc::crc my_crc;
    EXPECT_EQ("girl", my_crc.brute_force(2579420686));
    EXPECT_EQ("time", my_crc.brute_force(1872009285));

}