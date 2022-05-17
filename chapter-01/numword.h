#ifndef NUMWORD_GUARD
#define NUMWORD_GUARD

#include <string>

namespace chap01
{
    static std::string UNITS[] = 
        {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    static std::string TENS[] =
        {"ERROR", "ten", "twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};

    static std::string TEENS[] = 
        {TENS[1], "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    static std::string LEVELS[] = {"thousand", "million", "billion", "trillion", "quadrillon" };

    static auto hundredsOf = []( uint64_t n ) { return n / 100; };
    static auto tensOf = []( uint64_t n ) { return ( n - hundredsOf(n)*100 ) / 10; };
    static auto unitsOf = []( uint64_t n ) { return n - hundredsOf(n)*100 - tensOf(n)*10; };

    class numword 
    {
        uint64_t _units;
        uint64_t _tens;
        uint64_t _hundreds;
        
        void setNumberData( uint64_t number );
        std::string words( uint64_t n, size_t level_index );

    public:
        std::string words( uint64_t n );
        const std::string convert( uint64_t n);
    };
}

#endif // NUMWORD_GUARD