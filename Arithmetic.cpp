/*

Matthew Kaltman, mkaltman
2022 Spring CSE101 PA6
Arithmetic.cpp

*/

#include <iostream>
#include <fstream>
#include <string>
#include "BigInteger.h"
#include "List.h"

using namespace std;

int main(int argc, char* argv[])
{

 fstream fin;
 ofstream fout;
 fin.open(argv[1]);
 string line;
 string in[2];
 int i = 0;
 if(!fin.is_open())
 {
     cout << "cant open file" << endl;
 }
 while(getline(fin,line))
 {
     if(line != "")
     {
     in[i] = line;
     i++;
     }
 }

fin.close();

fout.open(argv[2]);
BigInteger A = BigInteger(in[0]);
BigInteger B = BigInteger(in[1]);
BigInteger three = BigInteger("3");
BigInteger two = BigInteger("2");
BigInteger nine = BigInteger("9");
BigInteger sixteen = BigInteger("16");

// cout << A << endl << B << endl;
// cout <<A.sign() << endl << B.sign() << endl;

//A
fout  << A << endl << endl;
//fout << A.sign() << endl << endl;

//B
fout  << B << endl << endl;

BigInteger C;
C = A + B;

// A + B
fout  << C << endl << endl;

C = A - B;
//A - B
fout << C << endl << endl;

C = A - A;

//A - A
fout << C << endl << endl;

BigInteger D = three * A;
BigInteger F = two * B;

C = D - F;

//3A - 2B
fout << C << endl << endl;

C = A * B;
//AB
fout << C << endl << endl;

C = A * A;

//A^2

fout << C << endl << endl;

C = B* B;

//B^2
fout << C << endl << endl;

D = A * A; //A^2
D *= A; //A^3
D *= A; //A^4
D *= nine; //9A^4

F = B * B; //B^2
F *= B; // B^3
F *= B; // B^4
F *= B; //B^5
F *= sixteen; //16B^5
C = D + F;  //9A^4 + 16B^5;

fout << C << endl << endl;

fout.close();

    return EXIT_SUCCESS;
}
