/****************************************************************
*
* Summary:  validation algorithm for credit cards.
*           main() routine has 3 hard coded Card Numbers and
*           routine could easily be modified to prompt for CC number
* Date:     12/18/2017
* Author:   Marco Remache
* Modifications:
*   Date        version     Details
*   ----------  -------     -----------------------
*   12/18/2017  1.0         Initial version
*   12/22/2017  1.1         changed to use classes
*****************************************************************/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cmath>
//#define toDigit(c) (c-'0')
using namespace std;
const int ccSize = 16;


class checkValidCreditCard
{ private:
    long long int ccNum;
    int ccArray[ccSize];
  public:
    int checkValid();
    checkValidCreditCard(long long int ccNum);
   ~checkValidCreditCard() {};
};



checkValidCreditCard::checkValidCreditCard(long long int num)
{
    ccNum = num;
    cout << "ccNum:: " <<  ccNum << '\n';
}




int checkValidCreditCard::checkValid (){
// convert to str
std::stringstream ss;
ss << ccNum;
std::string ccNumStr = ss.str();
std::cout << "ccnumstr: " << ccNumStr << '\n';
/*
Double the value of every second digit beginning from the right and place in array ccArray;
if the value is greater than 9 subtract 9 from and place this value in array
*/
int j=0;
int remain;
cout << "ccArray:  " ;
for (int i=ccSize-1; i>=0; i--)
{
    char c = ccNumStr[i];
    j =  c - '0';
    remain = i%2;
    if (remain == 0){
        if (j*2 > 9)
            ccArray[i]= j*2-9;
        else
            ccArray[i] = j*2;
        //cout << ccArray[i];
    }
    else {
        ccArray[i] = j;
        //cout << ccArray[i];
    }
    cout << ccArray[i];
}
// add array entries into sum variable
int sum=0;
for (int i=0; i<ccSize; i++) sum += ccArray[i];
cout << '\n' << "sum: " << sum;
// Compute remainder and return true if zero remainder, otherwise return false.
double rem = 0;
rem = remainder( sum,10.0);
cout << " remainder: " << rem << '\n';
if (rem == 0)\
    cout << "CC is a Valid"  << '\n';
else
    cout << "CC is not a Valid CC" << '\n';
cout << '\n';
return 0;
}






/*************************************************
*
*     main ()
*
**************************************************/


int main()
{

checkValidCreditCard CC1(4012888888881881);
CC1.checkValid();


checkValidCreditCard CC2(4012888888881882);
CC2.checkValid();


return 0;
}

