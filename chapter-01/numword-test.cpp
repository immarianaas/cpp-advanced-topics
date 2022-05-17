// based on numword-test.cpp by Bill Weinman <http://bw.org/>

#include <cstdio>
#include <inttypes.h>
#include <iostream>
#include <assert.h> 
#include "numword.h"
using namespace std;

int main() {
    chap01::numword nw;
    uint64_t n;

    std::cerr << "0\t" <<       nw.words( 0 ) << std::endl;
    std::cerr << "1\t" <<       nw.words( 1 ) << std::endl;
    std::cerr << "2\t" <<       nw.words( 2 ) << std::endl;
    std::cerr << "10\t" <<      nw.words( 10 ) << std::endl;
    std::cerr << "15\t" <<      nw.words( 15 ) << std::endl;
    std::cout << "20\t" <<      nw.words( 20 ) << std::endl;
    std::cout << "35\t" <<      nw.words( 35 ) << std::endl;
    std::cout << "100\t" <<     nw.words( 100 ) << std::endl;
    std::cout << "120\t" <<     nw.words( 120 ) << std::endl;
    std::cout << "900\t" <<     nw.words( 900 ) << std::endl;
    std::cout << "999\t" <<     nw.words( 999 ) << std::endl;
    
    std::cout << std::endl;

    std::cout << "1000\t" <<     nw.words( 1000 ) << std::endl;
    std::cout << "1001\t" <<     nw.words( 1001 ) << std::endl;
    std::cout << "1020\t" <<     nw.words( 1020 ) << std::endl;
    std::cout << "1023\t" <<     nw.words( 1023 ) << std::endl;
    std::cout << "1234\t" <<     nw.words( 1234 ) << std::endl;

    std::cout << "123000123\t" <<     nw.words( 123000123 ) << std::endl;
    std::cout << "123000023\t" <<     nw.words( 123000023 ) << std::endl;


    std::cout << "1000000001\t" <<     nw.words( 1000000001 ) << std::endl;
    std::cout << "999999999999999999\t" <<     nw.words( 999999999999999999 ) << std::endl;


    assert( nw.words( 999999999999999999 ) == "nine hundred and ninety-nine quadrillon, nine hundred and ninety-nine trillion, nine hundred and ninety-nine billion, nine hundred and ninety-nine million, nine hundred and ninety-nine thousand, nine hundred and ninety-nine" );
    assert( nw.words( 123000023 ) == "one hundred and twenty-three million and twenty-three" );
    return 0;
}

