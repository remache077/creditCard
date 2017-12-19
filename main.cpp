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
*****************************************************************/

#include <iostream>
//#include <string>
#include <stdio.h>
//#include <stdlib.h>
#include <sstream>
#include <cmath>
#define toDigit(c) (c-'0')

using namespace std;
const int ccSize = 16;


int checkValidCC (long long ccNum){

int ccArray[ccSize];
int remain=0;

std::stringstream ss;
ss << ccNum;
std::string ccNumStr = ss.str();
std::cout << ccNumStr << '\n';

// check right size of 16
if (ccNumStr.length() != ccSize)
{
    cout << "size of ccNumStr: " <<  ccNumStr.length() << '\n';
    return 0;
}

/*
Double the value of every second digit beginning from the right and place in array ccArray;
if the value is greater than 9 subtract 9 from and place this value in array
*/

int j;
for (int i=ccSize-1; i>=0; i--)
{
    j = toDigit(ccNumStr[i]);
    remain = i%2;
    if (remain == 0){
        if (j*2 > 9)
            ccArray[i]= j*2-9;
        else
            ccArray[i] = j*2;
        cout << ccArray[i];
    }
    else {
        ccArray[i] = j;
        cout << ccArray[i];
        //cout << "ccArray["<<i<<"]: " << ccArray[i] << '\n';
    }
}

// add array entries into sum variable
int sum=0;
for (int i=0; i<ccSize; i++) sum += ccArray[i];
cout << " sum: " << sum;

// Compute remainder and return true if zero remainder, otherwise return false.
double rem = 0;
rem = remainder( sum,10.0); cout << " remainder: " << rem << '\n';
if (rem == 0)
   return 1;
else
   return 0;
}





/*************************************************
*
*     main ()
*
**************************************************/


int main()
{

long long ccNum = 4012888888881881;
if (checkValidCC(ccNum))
   cout << "CC: " << ccNum<< " is a Valid CC"  << '\n';
else
   cout << "CC: " << ccNum << " is not a Valid CC" << '\n';
cout << '\n';


ccNum = 4012888888881882;
if (checkValidCC(ccNum))
   cout << "CC: " << ccNum<< " is a Valid CC"  << '\n';
else
   cout << "CC: " << ccNum << " is not a Valid CC" << '\n';
cout << '\n';


ccNum = 5262191094566162;
if (checkValidCC(ccNum))
   cout << "CC: " << ccNum<< " is a Valid CC"  << '\n';
else
   cout << "CC: " << ccNum << " is not a Valid CC" << '\n';
cout << '\n';

return 0;
}

