#include "../../framework/header.hpp"
#include "../../framework/common.hpp"

#include <iostream>
#include <string>

bool isDigit(char c)
{
  return '0' <= c && c <= '9';
}

bool isMinus(char c)
{
  return c == '-';
}

int myAtoi(string s)
{
  // process the string from the back to count the power of 10
  int power = 1;
  int parsedNumber = 0;

  int index = s.size() - 1;
  while (index >= 0)
  {
    if (isDigit(s[index]))
    {
      int verify = parsedNumber + (int)(s[index] - '0') * power;
      if (verify < parsedNumber)
      {
        return 2147483647;
      }
      else
      {
        parsedNumber = verify;
      }
      power *= 10;
    }
    else if (isMinus(s[index]))
    {
      parsedNumber *= -1;
    }

    index -= 1;
  }

  return parsedNumber;
}

TEST_CASE("myAtoi")
{
  REQUIRE(myAtoi("42") == 42);
  REQUIRE(myAtoi("   -42") == -42);
  REQUIRE(myAtoi("4193 with words") == 4193);
  REQUIRE(myAtoi("words and 987") == 0);
  REQUIRE(myAtoi("-91283472332") == -2147483648);
  REQUIRE(myAtoi("-2147483648") == -2147483648);
}