#include "numword.h"

#include <string>
#include <assert.h> 


namespace chap01
{
    // ------------------------------------------------------
    // -- PRIVATE -------------------------------------------
    // ------------------------------------------------------

    void numword::setNumberData( uint64_t number )
    {
        _units = unitsOf( number);
        _tens = tensOf( number );
        _hundreds = hundredsOf( number );
    }

    std::string numword::words( uint64_t n, size_t level_index ) 
    {
        std::string result;
        // the part under 1000 of this number
        uint64_t smaller_split = n % 1000;

        if ( n >= 1000 )
        {
            numword temp;
            // the part 1000 and above of this number
            uint64_t larger_split = n/1000;
            result += temp.words(larger_split, level_index+1);

            // if the next "level" is 0, we can return the result by now since we don't want "zero" to appear
            if ( smaller_split == 0 ) return result;

            // we need to append a "," between levels (except on the last one - it depends)
            result += ", ";

        }
        // append the result from higher "levels" to this one's
        return result + convert( smaller_split ) + " " + LEVELS[level_index] ;
    }

    // ------------------------------------------------------
    // -- public --------------------------------------------
    // ------------------------------------------------------

    std::string numword::words( uint64_t n )
    {
        std::string result;
        // the part under 1000 of the original number
        uint64_t smaller_split = n % 1000;

        if ( n >= 1000 )
        {
            numword temp;
            // the part above and equal to 1000 of the number
            uint64_t larger_split = n/1000;
            // get the text for it
            result += temp.words( larger_split, 0);

            // if the remaining is 0
            if ( smaller_split == 0 ) return result;

            // if the remaining of the number is under 100 we want to add an 'and'
            result += smaller_split < 100 ? " and " : ", ";
        }
        // return the complete text
        return result + convert( smaller_split );

    }

    const std::string chap01::numword::convert( uint64_t n )
    {
        // this function is only used for numbers under 1000
        assert(n < 1000);
        // fill info about the units, tens and hundreds
        setNumberData(n);

        // return "zero" immediately
        if (n == 0) return UNITS[0];

        std::string result;
        std::string prefix; // can be "", "and" or "-"

        if (n >= 100)
        {
            result += UNITS[_hundreds] + " hundred";
            prefix = " and ";
        }

        if ( n >= 10 )
        {
            // if the number has no digit in the tens nor units, return
            if (_tens == 0 && _units == 0) return result;

            result += prefix; // append the "and" or ""

            // special case if the number is between 10 and 19
            if (_tens == 1) return result + TEENS[_units]; 

            if (_tens != 0)
            {
                result += TENS[_tens];
                prefix = "-";
            }
        }

        if (_units == 0) return result;

        result += prefix; // append "-" or ""
        result += UNITS[_units];
        return result;
    }
}