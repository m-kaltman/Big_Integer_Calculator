//-----------------------------------------------------------------------------
//  A test client for the BigInteger ADT
// Matthew Kaltman,mkaltman
// 2022 Spring CSE101 PA6
// BigIntegerTest.cpp
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"
#include"List.h"

using namespace std;

int main()
{

//CLIENT+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

string s1 = "9063574346363325007361058";

string s2 = "+4597814412658653960738664";

BigInteger A = BigInteger(s1);
BigInteger B = BigInteger(s2);


BigInteger Check = BigInteger("82148379932055374148087897957410048849885174879364");
BigInteger F = A*A;



if(!(F == Check))
{
  cout <<endl<<F <<endl;
  cout<<endl << "A*A failed" <<endl;
}


 Check = BigInteger("21139897373251643090844048049647865537964504504896");
 F = B*B;



if(!(F == Check))
{
  cout <<endl<<B<<endl;
  cout << "B*B failed"<<endl;
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//    string check1 = "-123445";
//    string check2 = "-00000";
//    string s1 = "9128734667000004389234563456345619187236478";
//    //string s2 = "-330293847502398475";
//    string s3 = "9876545439000000000000000200000000000006543654365346534";
//  string s4 = "9876545439000000000000000100000000000006543654365346534";
// string s5 = "98765454390000000000000000000000000000065436543";
//    //string s6 = "9876545439000000000000000000000000000006543";
//    string add1 = "120000040000000000000303";
//    string add2 = "120000040000000000000303";
//    string add3 = "456732";
//    string add4 = "123446";
//    string add5 = "-123446";
//    string add6 = "-456732";

//    string add7 = "97867463";
//    string add8 = "7";


// // // BigInteger N;
// //   BigInteger A = BigInteger(s1);
// //   BigInteger B = BigInteger(s3);
// //   BigInteger Q = BigInteger(check1);
// //   BigInteger Z = BigInteger(check2);
// //   BigInteger QQ = BigInteger("-00000000000041085449");
// //                                //0000000010
//   BigInteger ADD1 = BigInteger(add1);
//   BigInteger ADD2 = BigInteger(add2);

//   BigInteger ADD3 = BigInteger(add3);
//   BigInteger ADD4 = BigInteger(add4);

//   BigInteger ADD5 = BigInteger(add3);
//   BigInteger ADD6 = BigInteger(add5);

//   BigInteger ADD7 = BigInteger(add6);
//   BigInteger ADD8 = BigInteger(add3);
//   ADD8.negate();

//   BigInteger ADD9 = BigInteger(add7);
//   BigInteger ADD10 = BigInteger(add8);

//   BigInteger ADD11 = BigInteger("12345");
//   BigInteger ADD12 = BigInteger("-54321");

//    BigInteger ADD13 = BigInteger("0000");

//    BigInteger ADD14 = BigInteger(s5);
//    BigInteger ADD15 = BigInteger(s4);


//    cout << "-------------------------CONSTRUCTOR / DESTRUCTOR TESTS------------------------------------" <<endl <<endl;

//    cout << "A = " << A << endl;
//    cout << "sign(A) = " << A.sign() <<endl;
//    cout << endl << "B = " << B << endl;
//    cout << "sign(B) = " << B.sign() <<endl;
//    cout << endl <<  "Q = " << Q << endl;
//    cout << "sign(Q) = " << Q.sign() <<endl;
//    cout << endl <<  "Z = " << Z << endl;
//    cout << "sign(Z) = " << Z.sign() <<endl;
//    cout << endl;
    // cout << "ADD13 = " << ADD13 << endl;
    // cout << "sign(ADD13) = " << ADD13.sign() << endl;

//    cout << "-------------------------------------------------------------------------------------------"<< endl << endl;

//    cout << "------------------------------------NEGATE TESTS-------------------------------------------" <<endl <<endl;

//    A.negate();
//    B.negate();
//    Q.negate();
//    Z.negate();
  

//    cout << "A = " << A << endl;
//    cout << "sign(A) = " << A.sign() <<endl;
//       A.negate();

//    cout << "A = " << A << endl;
//    cout << "sign(A) = " << A.sign() <<endl;

//    cout << endl << "B = " << B << endl;
//    cout << "sign(B) = " << B.sign() <<endl;
//    cout << endl <<  "Q = " << Q << endl;
//    cout << "sign(Q) = " << Q.sign() <<endl;
//    cout << endl <<  "Z = " << Z << endl;
//    cout << "sign(Z) = " << Z.sign() <<endl;
//    cout << endl;

//    cout << "-------------------------------------------------------------------------------------------"<< endl << endl;



  // cout << "-------------------------ADD TESTS---------------------------------------------------------" <<endl <<endl;

    // BigInteger ADD_RESULT;
   //  cout <<"ADDRESULT = " <<  ADD_RESULT  << endl;
  //   cout << "ADDRESULT SIGN = " << ADD_RESULT.sign();

  //   cout << "ADDTEST1_RESULT ("<< ADD1 << " + "<< ADD2 <<" SHOULD BE 240000080000000000000606) ==> " << ADD_RESULT << endl;

  //    ADD_RESULT = ADD3 + ADD4;

   
  //   cout << "ADDTEST2_RESULT ("<< ADD3 << " + "<< ADD4 <<" SHOULD BE 580,178) ==> "  << ADD_RESULT << endl;

  //    ADD_RESULT = ADD5 + ADD6;

  //  cout << "ADDTEST3_RESULT ("<< ADD5 << " + "<< ADD6 <<" SHOULD BE 333,286) ==> " << ADD_RESULT << endl;

  //    ADD_RESULT = ADD6 + ADD5;

  //   cout << "ADDTEST4_RESULT ("<< ADD6 << " + "<< ADD5 <<" SHOULD BE 333,286) ==> " << ADD_RESULT << endl;
  //    ADD_RESULT = ADD6 + ADD7;

  //   cout << "ADDTEST5_RESULT ("<< ADD6 << " + "<< ADD7 <<" SHOULD BE -580,178) ==> " << ADD_RESULT << endl;

    //  ADD_RESULT = ADD5 + ADD8;

    // cout << "ADDTEST6_RESULT ("<< ADD5 << " + "<< ADD8 <<" SHOULD BE 0) ==> " << ADD_RESULT << endl;

    // ADD_RESULT = ADD5 + ADD8;

    // cout << "ADDTEST7_RESULT ("<< ADD6 << " + "<< ADD4 <<" SHOULD BE 0) ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD9 + ADD10;

//     cout << "ADDTEST8_RESULT ("<< ADD9 << " + "<< ADD10 <<" SHOULD BE 97,867,470) ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD11 + ADD12;

//     cout << "ADDTEST9_RESULT ("<< ADD11 << " + "<< ADD12 <<" SHOULD BE -41,976) ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD12 + ADD11;

//    cout << "ADDTEST10_RESULT ("<< ADD12 << " + "<< ADD11 <<" SHOULD BE -41,976) ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD5 + ADD13;

//    cout << "ADDTEST11_RESULT ("<< ADD5 << " + "<< ADD13 <<" SHOULD BE " << ADD5 <<") ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD12 + ADD13;

//    cout << "ADDTEST12_RESULT ("<< ADD12 << " + "<< ADD13 <<" SHOULD BE " << ADD12 << ") ==> " << ADD_RESULT << endl;

//    ADD_RESULT = ADD13 + ADD5;

//    cout << "ADDTEST13_RESULT ("<< ADD13 << " + "<< ADD5 <<" SHOULD BE " << ADD5 <<") ==> " << ADD_RESULT << endl;

//     ADD_RESULT = ADD13 + ADD12;

//    cout << "ADDTEST14_RESULT ("<< ADD13 << " + "<< ADD12 <<" SHOULD BE " << ADD12 << ") ==> " << ADD_RESULT << endl;
       
// cout <<"-----------------------------------------------------------------------------------------" << endl << endl;

// cout << "-------------------------MAKE ZERO TESTS------------------------------------------------" <<endl <<endl;

// cout << "A before makeZero : " << A << endl;
// A.makeZero();
// cout << "A after makeZero : " << A << endl;

// cout <<"-----------------------------------------------------------------------------------------" << endl << endl;


//  cout << "-----------------------------SUBTRACT TESTS-----------------------------------------------" << endl << endl;

//   BigInteger SUB1 = BigInteger("0");
//   BigInteger SUB2 = BigInteger("-3824499847278323183438583484249");
//   BigInteger SUB3 = BigInteger("123456789");
//   BigInteger SUB4 = BigInteger("0");
//   BigInteger SUB5 = BigInteger("987654321439528835727253546457");
//   BigInteger SUB6 = BigInteger("-987654321439528835727253546457");
//   BigInteger SUB7 = BigInteger("-8765437253546457");
//   BigInteger SUB_RESULT;



//   SUB_RESULT = SUB1 - SUB2;
  
//   cout << "SUBTEST1_RESULT ("<< SUB1 << " - "<< SUB2 << " SHOULD BE 3824499847278323183438583484249 ) ==> " << SUB_RESULT << endl;
  
//   SUB_RESULT = SUB1 - SUB3;

//   cout << "SUBTEST2_RESULT ("<< SUB1 << " - "<< SUB3 << " SHOULD BE -123456789) ==> " << SUB_RESULT << endl;

//   SUB_RESULT = SUB1 - SUB4;

//   cout << "SUBTEST3_RESULT ("<< SUB1 << " - "<< SUB4 << " SHOULD BE 0) ==> " << SUB_RESULT << endl;

//   SUB_RESULT = SUB3 - SUB5;

//   cout << "SUBTEST4_RESULT ("<< SUB3 << " - "<< SUB5 << " SHOULD BE -987654321439528835727130089668) ==> " << SUB_RESULT << endl;

//   SUB_RESULT = SUB5 - SUB3;

//   cout << "SUBTEST5_RESULT ("<< SUB5 << " - "<< SUB3 << " SHOULD BE 987654321439528835727130089668) ==> " << SUB_RESULT << endl;

//   SUB_RESULT = SUB3 - SUB2;

//   cout << "SUBTEST6_RESULT ("<< SUB3 << " - "<< SUB2 << " SHOULD BE 3824499847278323183438706941038) ==> " << SUB_RESULT << endl;

//   SUB_RESULT = SUB5 - SUB2;

//   cout << "SUBTEST7_RESULT ("<< SUB5 << " - "<< SUB2 << " SHOULD BE 4812154168717852019165837030706) ==> " << SUB_RESULT << endl;  

//   SUB_RESULT = SUB2 - SUB3;

//   cout << "SUBTEST8_RESULT ("<< SUB2 << " - "<< SUB3 << " SHOULD BE -3824499847278323183438706941038) ==> " << SUB_RESULT << endl;  
 
//   SUB_RESULT = SUB2 - SUB5;

//   cout << "SUBTEST9_RESULT ("<< SUB2 << " - "<< SUB5 << " SHOULD BE -4812154168717852019165837030706) ==> " << SUB_RESULT << endl;
  
//   SUB_RESULT = SUB7 - SUB6;

//   cout << "SUBTEST10_RESULT ("<< SUB7 << " - "<< SUB6 << " SHOULD BE 987654321439520070290000000000) ==> " << SUB_RESULT << endl;  
 
//   SUB_RESULT = SUB6 - SUB2;

//   cout << "SUBTEST11_RESULT ("<< SUB6 << " - "<< SUB2 << " SHOULD BE 2836845525838794347711329937792) ==> " << SUB_RESULT << endl;    


// cout << "-------------------------------------------------------------------------------------------" <<endl <<endl;


// cout << "------------------------------------MULT TESTS---------------------------------------------"<< endl <<endl;

// BigInteger MULT_RESULT;
// BigInteger MULT1 = BigInteger("9128734667000004389234563456345619187236478");
// BigInteger MULT2 = BigInteger("9876545439000000000000000200000000000006543654365346534");


// MULT_RESULT = MULT1 * MULT2;

// cout << "MULTTEST1_RESULT ("<< MULT1 << " * "<< MULT2 << ") ==> " << MULT_RESULT << endl;


// cout << "-------------------------------------------------------------------------------------------" <<endl << endl;

// cout << "---------------------------------EQUIVALENCY TESTS-----------------------------------------"<< endl <<endl;



//       cout << "(A==B) = " << ((A==B)?"True":"False") << endl;
//       cout << "(ADD4==ADD4) = " << ((ADD4==ADD4)?"True":"False") << endl;
//       cout << "(A==A) = " << ((A==A)?"True":"False") << endl;


//       cout << "(A<B)  = " << ((A<B)? "True":"False") << endl;
//       cout << "(A<=B) = " << ((A<=B)?"True":"False") << endl;
//       cout << "(A>B)  = " << ((A>B)? "True":"False") << endl;
//       cout << "(A>=B) = " << ((A>=B)?"True":"False")  << endl;

// cout << "-------------------------------------------------------------------------------------------" <<endl << endl;



//    // cout << "E = " << E << endl;
//    // cout << "F = " << F << endl;
//    // cout << "G = " << G << endl;
//    // cout << "H = " << H << endl;
//    // cout << "(G==H) = " << ((G==H)?"True":"False") << endl;
//    // cout << "I = " << I << endl << endl;

//    // cout << endl;

//    // A += B;
//    // B -= C;
//    // C *= D;
//    // cout << "A = " << A << endl;
//    // cout << "B = " << B << endl;
//    // cout << "C = " << C << endl;
//    // cout << endl;

//    // cout << A*B*C*D*F*G*H << endl << endl;

//    // cout << endl;

//    // // test exceptions
//    // try{
//    //    BigInteger J = BigInteger("");
//    // }catch( std::invalid_argument& e ){
//    //    cout << e.what() << endl;
//    //    cout << "   continuing without interruption" << endl;
//    // }
//    // try{
//    //    BigInteger J = BigInteger("+");
//    // }catch( std::invalid_argument& e ){
//    //    cout << e.what() << endl;
//    //    cout << "   continuing without interruption" << endl;
//    // }
//    // try{
//    //    BigInteger J = BigInteger("12329837492387492837492$4982379487293847");
//    // }catch( std::invalid_argument& e ){
//    //    cout << e.what() << endl;
//    //    cout << "   continuing without interruption" << endl;
//    // }
//    // try{
//    //    BigInteger J = BigInteger("5298374902837409+82734098729287349827398");
//    // }catch( std::invalid_argument& e ){
//    //    cout << e.what() << endl;
//    //    cout << "   continuing without interruption" << endl;
//    // }

//    cout << endl;

 //  return EXIT_SUCCESS;
}

