#include <iostream>
//#include <string>
#include <stdio.h>
//#include <stdlib.h>
#include <sstream>
#include <cmath>
#define toDigit(c) (c-'0')

using namespace std;
const int ccSize = 16;


// pass array, its by reference
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

/*
int *p=0;
double d = 2.2;
int x = 7;
const int ASIZE = 7;
int array1[ASIZE][ASIZE];
int a2[ASIZE] = {0,1,2,3,4,5,6};

p = return_an_array(7);
for (int j=0; j<7; j++){
    cout << "address of ptr: " << p << endl;
    p++;
}

// function overload
f1(x);
cout << "x value in main1: " << x <<endl;
f1(d);
cout << "d value in main2: " << d <<endl;

/// arrays, for loops
int i;
for (i=0; i<ASIZE; i++) {
    for (int j=0; j<ASIZE; j++){
       array1[i][j] = 2147483647;
    }
}
int k = 0;
for (i=0; i<ASIZE; i++) {
    for (int j=0; j<ASIZE; j++){
       k++;
       cout << k << " array1[" << i << "][" << j <<"]: "<< array1[i][j] <<endl;
    }
}

for (i=0; i<ASIZE; i++){
     a2[i]= 5000;
     //cout << i << " a2[" << i << "]: "<< a2[i] <<endl;
}

/// array by reference, while loops
cout << "array by reference " << endl;
i=0;
while (i<ASIZE) {
    cout << i << " a2[" << i << "]: "<< a2[i] <<endl;
    i++;
    if (i > 4) break;
}


k = f2 (a2, ASIZE);

cout <<" do while loop " <<endl;
i=0;
do {
    i++;
    if (i<=3) continue;
    cout << i << " a2[" << i << "]: "<< a2[i] <<endl;

} while (i < ASIZE);

*/









/*************************************************
*
*     end main ()
*
**************************************************/













/*
cout<<"sizeof int my_2darray[1][1] " << sizeof(my_2darray)<<endl;
my_2darray b[3][2];
cout<<"sizeof  my_2darray b[3][2]" << sizeof(b)<<endl;
cout<<"sizeof  b+0 " << sizeof(b+0)<<endl;
cout<<"sizeof  *(b+0) " << sizeof(*(b+0))<<endl;
// the next line prints 0012FF4C
cout<<"The address of b is: "<<b<<endl;
cout<<"The address of b+1 is: "<<b+1<<endl;
cout<<"*(b+1) is: "<<*(b+1)<<endl<<endl;
cout<<"The address of &b is: "<<&b<<endl;
cout<<"The address of &b+1 is: "<<&b+1<<endl;
*/




// Print a chessboard #include <cstdlib> #include <iostream>

/*
       int i,j,k,l;
       typedef char box[5][7];
       box bb,wb,*board[8][8];
       //fill in bb=black box and wb=whitebox
               for(i=0;i<5;i++)
                for( j=0;j<7;j++)
                {  wb[i][j]=' ';
                   bb[i][j]=char(219);
                }
       //fill board with pointers to bb and wb in alternate positions
               for(i=0;i<8;i++)
                 for(j=0;j<8;j++)
                 if((i+j)%2==0)
                    board[i][j]=&wb;
                 else
                    board[i][j]=&bb;

       // print the board via the pointers in array board
       // first print upper border

               cout<<"     ";
                       for(i=0;i<7*8;i++)
                          cout<<'_';        cout<<endl;


       // now print the board
               for(i=0;i<8;i++)
                  for(k=0;k<5;k++)
                     {cout<<"     "<<char(179); //print left border

               for(j=0;j<8;j++)
                  for(l=0;l<7;l++)
                    cout<<(*board[i][j])[k][l];
               cout<<char(179)<<endl; // at end of line print bar and then newline
                               }

       //before exiting print lower border
               cout<<"     ";
               for(i=0;i<7*8;i++)
                  cout<<char(196);        cout<<endl;

      //  system("PAUSE");
      //  return EXIT_SUCCESS; }
*/


