/*

Matthew Kaltman, mkaltman
2022 Spring CSE101 PA6
BigInteger.cpp

*/


#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath> 
#include "BigInteger.h"
#include "List.h"


const long base = 1000000000;
const int power = 9;

//Helper_Functions_prototypes-------------------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L);

// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void sumlist(List& S, List A, List B, int sgn);

// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().
int normalizeList(List& L);

// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult().
void shiftList(List& L, int p);

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
void scalarMultList(List& L, ListElement m);


//----------------------------------------------------------------------------

//Constructors/Destructors----------------------------------------------------

 // BigInteger()
 // Constructor that creates a new BigInteger in the zero state: 
 // signum=0, digits=().
 BigInteger::BigInteger()
 {
    signum = 0;
 }

 // BigInteger()
 // Constructor that creates a new BigInteger from the string s.
 // Pre: s is a non-empty string consisting of (at least one) base 10 digit
 // {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
 BigInteger::BigInteger(std::string s)
 {
 long len = s.length();
 int save = 1;
 if(len == 0)
 {
    throw std::invalid_argument("BigInteger: Constructor: empty string\n");
 }
  std::string sign = s.substr(0,1);

 if(s[0] == '-')
 {
     save = -1;
     s.erase(0,1);
     len = s.length();
 }
 else if (s[0] == '+')
 {
     save = 1;
     s.erase(0,1);
     len = s.length();
 }

     for(int i = 0; i < len; i++)
     {

         if(s[i] != '0')
         {
            signum = save;
            break;
             
         }  
         else
         {
             signum = 0;
         }
        
     }
    
 for(int i = 0; i < len; i++)
 {
     if(!isdigit(s[i]))
     {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
     }
 }

 int num_loops = len / power;
 int remainder = len % power;
 long insert;

 for(int i = 0; i < num_loops; i++)
 {

    insert = std::stol(s.substr(len-power, power));    
    s.erase(len-power,power);
    len = s.length();
    digits.insertAfter(insert);    
 }

 if(remainder != 0)
 {
 insert = std::stol(s.substr(0,remainder));
 digits.insertAfter(insert);
 }

 }

 // BigInteger()
 // Constructor that creates a copy of N.
 BigInteger::BigInteger(const BigInteger& N)
 {
    signum = N.signum;
    List L = N.digits;
    L.moveFront();
    while(L.position() < L.length())
    {
        digits.insertBefore(L.moveNext());

    }
    

 }

//-----------------------------------------------------------------------------  

//Acess_Functions--------------------------------------------------------------

 // sign()
 // Returns -1, 1 or 0 according to whether this BigInteger is positive, 
 // negative or 0, respectively.
 int BigInteger::sign() const
 {
    return signum;
 }

 // compare()
 // Returns -1, 1 or 0 according to whether this BigInteger is less than N,
 // greater than N or equal to N, respectively.
 
 int BigInteger::compare(const BigInteger& N) const
 {
    List A = digits;
    List B = N.digits;
    int A_sign = signum;
    int B_sign = N.sign();
    
    if(A_sign < B_sign)
    {
        return -1;
    }
    if(A_sign > B_sign)
    {
        return 1;
    }
    if(A_sign == B_sign)
    {

        if(A.length() > B.length())
        {
            return A_sign;
        }
        if(A.length() < B.length())
        {
            return A_sign * -1;
        }
        A.moveFront();
        B.moveFront();
        while( A.position() < A.length())
        {
            long a = A.peekNext();
            long b = B.peekNext();

        
            if(a == b)
            {
                
                A.moveNext();
                B.moveNext();
                continue;
            }
            else
            {
                if(a < b)
                {
                    return A_sign * -1;
                }
                if(a > b)
                {
                    return A_sign;
                }
            }
          A.moveNext();
          B.moveNext();
        }
    }

     return 0;

    

}
 



//-----------------------------------------------------------------------------

//Manipulation_Procedures------------------------------------------------------

void BigInteger::negate()
{
    signum *= -1;

}

void BigInteger::makeZero()
{
    digits.clear();
    signum = 0; 
}

//-----------------------------------------------------------------------------


//BigInteger_Arithmetic_Operations -------------------------------------------

    
 // add()
 // Returns a BigInteger representing the sum of this and N.
 BigInteger BigInteger::add(const BigInteger& N) const
 {
     List A,B,C;
     BigInteger result;
     //int equals = *this == N;
     int A_sign = this->signum;
     int B_sign = N.signum;
     A = this->digits;
     B = N.digits;

    if(A_sign == 0 && B_sign != 0)
    {
    result.digits = B;
    result.signum = B_sign;
    return result;
    }
    if(A_sign != 0 && B_sign == 0)
    {
    result.digits = A;
    result.signum = A_sign;
    return result;
    }
    if(A_sign == 0 && B_sign == 0)
    {
        return result;
    }
     //A+ B+ -> A+B
     if(A_sign == 1 && B_sign == 1)
     {
     //sign = 1;
     sumlist(C,A,B,B_sign);
     }

      //A+ B- -> A + (-B)
     if(A_sign == 1 && B_sign == -1)
     {
    //std::c//out << std::endl << C << std::endl;
     sumlist(C,A,B,B_sign);

      //std::cout << std::endl << C << std::endl;
     }

      //A- B+ ->  B + (-A)
     else if(A_sign == -1 && B_sign == 1 )
     {
   

     sumlist(C,B,A,A_sign);
     }
     else if(A_sign == 1 && B_sign == -1 )
     {
   
     sumlist(C,A,B,B_sign);
     }
     //A- B- 
     else if(A_sign == -1 && B_sign == -1)
     {
         sumlist(C,A,B,1);
         negateList(C);
     }
     
     result.signum = normalizeList(C);

     result.digits = C;

     return result;
 }

BigInteger BigInteger::sub(const BigInteger& N) const
{
 List A,B,C;
 BigInteger result;
 int sign;
 int equals = *this == N;
 int A_sign = this->signum;
 int B_sign = N.signum;
 A = this->digits;
 B = N.digits;
 
 if(A_sign == 0 && B_sign != 0)
    {
    result = N;
    result.signum = B_sign * -1;
    return result;
    }

    if(A_sign != 0 && B_sign == 0)
    {
      return *this;
    }
    if(A_sign == 0 && B_sign == 0)
    {
        return result;
    }
    if(A_sign == 1 && B_sign == 1)
    {
       
        if(equals)
        {
            return result;
        }
        //sumlist(C,A,B,-1);
        result.signum = -1;
        result.digits = B;
        return (*this).add(result);
        
    }
    if(A_sign == 1 && B_sign == -1)
    {
       sumlist(C,A,B,1);
       sign = 1;
    }
    if(A_sign == -1 && B_sign == 1)
    {
        result = N;
        BigInteger temp = *this;
        temp.signum = 1;
        result = temp.add(N);
        result.signum *= -1;
        return result;
    }
    if(A_sign == -1 && B_sign == -1)
    {
        BigInteger temp1 = *this;
        BigInteger temp2 = N;
        temp2.signum = 1;
        return (temp2.add(temp1));
        
    }
    result.signum = normalizeList(C);
    result.signum = sign;
    result.digits = C;
    return result;
    
}



   // mult()
   // Returns a BigInteger representing the product of this and N. 
   BigInteger BigInteger:: mult(const BigInteger& N) const
   {
       BigInteger result,hold;
       int sign;
       List A = digits;
       List B = N.digits;
       int A_sign = signum;
       int B_sign = N.signum;
       int shift = 0;
       long mult_val;
       hold.signum = A_sign;
       if(A_sign == 0 || B_sign == 0)
       {
           return result;
       }
       if(A_sign == -1 && B_sign == -1)
       {
           sign = 1;
       }
       if(A_sign == -1 && B_sign == 1)
       {
           sign = -1;
       }
       if(A_sign == 1 && B_sign == -1)
       {
           sign = -1;
       }
       if(A_sign == 1 && B_sign == 1)
       {
           sign = 1;
       }
       for(B.moveBack(); B.position() > 0; B.movePrev())
       {
           hold.digits = A;
           hold.signum = 1;
           result.signum = 1;
           shiftList(hold.digits,shift);
           mult_val = B.peekPrev();
           scalarMultList(hold.digits,mult_val);
           result = result.add(hold);
           result.signum = normalizeList(result.digits);
           shift++;
       }
       result.signum = sign;
       return result;
   }
//-----------------------------------------------------------------------------



//Other_Functions--------------------------------------------------------------

std::string BigInteger::to_string()
{
    std::string s = "";
    if(signum == 0)
    {
        return "0";
    }
    if(signum == -1)
    {
        s += "-";
    }
  
    int add_zero;
    std::string hold;
    for(digits.moveFront(); digits.position() < digits.length();digits.moveNext())
    {
        if(digits.position() != 0)
        {
        add_zero = power - std::to_string(digits.peekNext()).length();
        
        for(int i = 0; i < add_zero; i++)
        {
            hold+= "0";
        }

        }
       
        hold += std::to_string(digits.peekNext());
        
    }
    int pos = hold.find_first_not_of("0");
    hold.erase(0,pos);
    s += hold;
    return s;
}

//-----------------------------------------------------------------------------


//Helper_Functions-------------------------------------------------------------

void sumlist(List& S, List A, List B, int sgn)
{
    long A_val,B_val,S_val;
    A.moveBack();
    B.moveBack();
    S.clear();
    S.moveBack();

    while(A.position() > 0 && B.position() > 0 ) 
    {
        A_val = A.movePrev();
        B_val = B.movePrev();
        S_val = A_val + (B_val * sgn);
        S.insertAfter(S_val);

    }
    while(A.position() > 0)
    {
         A_val = A.movePrev();
         S.insertAfter(A_val);
    }
    while(B.position() > 0)
    {
         B_val = B.movePrev();
         S.insertAfter(B_val * sgn);

    }

}

void negateList(List& L) 
{
    for(L.moveFront(); L.position() < L.length(); L.moveNext())
    {
        long result_term;
        result_term = L.peekNext();
        L.setAfter(result_term * -1);
    }

}

int normalizeList(List& L)
{
    int carry = 0;
    int sign = 1;
    long set, num = 0;
   
    if(L.front() < 0)
    {
        negateList(L);
        sign = -1;

    }
    L.moveBack();
    while(L.position() > 1)
    {
        L.movePrev();
        num = L.peekNext();
        set = L.peekPrev();
        
        if(num > 0)
        {
            carry = num/base;
            L.setAfter(num % base);
            L.setBefore(set + (carry));
        }
        else if(num < 0)
        {
            carry = ((num/base) - 1)* -1;
            L.setAfter(((num + (carry * base))) % base);
            L.setBefore(set - (carry));
        }
    
    }
    L.moveFront();
    num = L.peekNext();
    if(num > base)
    {
        carry = num/base;
        L.setAfter(num%base);
        L.insertBefore(carry);
    }
  

    if(L.front() < 0)
    {
        normalizeList(L);   
    }
    // L.moveFront();
     int temp = sign;
    for(L.moveFront();L.position() < L.length(); L.moveNext())
    {
        if(L.peekNext() != 0)
        {
            return temp;
        }
        else
        {
            sign = 0;
        }
    }
   
    return sign;
 
}

// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult()
void shiftList(List& L, int p)
{
    L.moveBack();
    for(int i = 0; i < p; i++)
    {
        L.insertAfter(0);
    }
}

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
void scalarMultList(List& L, ListElement m)
{
    for(L.moveBack(); L.position() > 0; L.movePrev())
    {
        long set = L.peekPrev() * m;
        L.setBefore(set);
    }
}


//-----------------------------------------------------------------------------

//Overridden_Operators---------------------------------------------------------

std::ostream& operator<<( std::ostream& stream, BigInteger N )
{
    return stream << N.BigInteger::to_string();
}

bool operator==( const BigInteger& A, const BigInteger& B )
{
    int result;
    result = A.compare(B);
    if(result == 0)
    {
        return 1;
    }
    return 0;
}

bool operator<( const BigInteger& A, const BigInteger& B )
{
    int result;
    result = A.compare(B);
    if(result == -1)
    {
        return 1;
    }
    return 0;
}

bool operator<=( const BigInteger& A, const BigInteger& B )
{
    int result;
    result = A.compare(B);
    if(result == -1 || result == 0)
    {
        return 1;
    }
    return 0;
}

bool operator>( const BigInteger& A, const BigInteger& B )
{
    int result;
    result = A.compare(B);
    if(result == 1)
    {
        return 1;
    }
    return 0;
}

bool operator>=( const BigInteger& A, const BigInteger& B )
{
    int result;
    result = A.compare(B);
    if(result == 1 || result == 0)
    {
        return 1;
    }
    return 0;
}
BigInteger operator+( const BigInteger& A, const BigInteger& B )
{
    return A.add(B);
}

// operator+=()
// Overwrites A with the sum A+B. 
BigInteger operator+=( BigInteger& A, const BigInteger& B )
{
    A = A.add(B);
    return A;
}

BigInteger operator-( const BigInteger& A, const BigInteger& B )
{
    return A.sub(B);
}

// operator-=()
// Overwrites A with the difference A-B. 
BigInteger operator-=( BigInteger& A, const BigInteger& B )
{
    A = A.sub(B);
    return A;
}
// operator*()
// Returns the product A*B. 
BigInteger operator*( const BigInteger& A, const BigInteger& B )
{
    return A.mult(B);
}

   
// operator*=()
// Overwrites A with the product A*B. 
BigInteger operator*=( BigInteger& A, const BigInteger& B )
{
    A = A.mult(B);
    return A;
}




//-----------------------------------------------------------------------------