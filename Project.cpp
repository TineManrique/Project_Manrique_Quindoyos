#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string.h>


#include "Project.h"

using namespace std;

Project::Project()
{
    //ctor
}

Project::~Project()
{
    //dtor
}
//1st
void Project::multiple_of_3_and_5()
{
    int i=0, sum=0;

    cout << "Calculating ......... \n\n\n";

    for (i=0; i<1000; i++)
    {
        if (i%3==0 || i%5==0)
        {
            sum=sum+i;
        }
    }
        cout << "\a\a\aThe sum of the multiples (not exceeding 1000) of 3 and 5 is: " << sum << endl ;
}
//2nd
void Project::even_fibonacci()
{
    int first=1,second=2,sum=0;
    int evensum=2;

    cout << "Calculating ......... \n\n\n";

    while((first+second)<4000000)
    {
        sum=first+second;
        first=second;
        second=sum;

        if (sum%2==0)
        {
            evensum+=sum;
        }
    }
        cout << "\a\a\aThe sum of all even numbers in the fibonacci series is: " << evensum <<endl;
}
//3rd
void Project::largest_prime_factor()
{
    long long number = 600851475143;
    long long halfNumber = number/2;
    long long sum =1;
    long digit=0;

    cout << "Calculating ......... \n\n\n";

    for(digit = 3; digit <= halfNumber; digit += 2)
    {
        if(number%digit == 0)
        {
            sum *=digit;
                if(sum == number)
                {
                    cout << "\a\a\aThe largest prime factor of 600851475143 is: " << digit <<endl;
                    break;
                }
        }
    }
}
//4th
void Project::largest_palindrome_product()
{
    int biggestProduct = 0, val1=0, val2=0, thisProduct=0;

    cout << "Calculating ......... \n\n\n";

    for(val1=999; val1>=100; --val1)
        {
        for(val2=999; val2>=100; --val2)
        {
            thisProduct = val1 * val2;

            if(thisProduct > biggestProduct)
            {
                stringstream strProduct;
                string strProductReverse;

                strProduct << val1*val2;

                strProductReverse = strProduct.str();
                reverse(strProductReverse.begin(), strProductReverse.end());

                if(strProduct.str() == strProductReverse)
                {
                    biggestProduct = thisProduct;
                }
            }
        }
    }
        cout << "\a\a\aThe largest palindromic product of two three-digit numbers is: " << biggestProduct << endl;
}
//5th
void Project::smallest_multiple()
{
    int num = 20, counter = 0;

    cout << "Calculating ......... \n\n\n";

    while(counter == 0)
    {
        if ((num%2) == 0 && (num%3) == 0 && (num%4) == 0    && (num%5) == 0 && (num%6) == 0
        && (num%7) == 0 && (num%8) == 0 && (num%9) == 0 && (num%10) == 0 && (num%11) == 0 && (num%12) ==0
        && (num%13) == 0 && (num%14) == 0 && (num%15) == 0 && (num%16) == 0 && (num%17) == 0 && (num%18)==0
        && (num%19) == 0    && (num%20) == 0)
        {
            counter =  1;
            cout<< "\a\a\aThe smallest positive number that is divisible from 1 to 20 is: " << num <<endl;
        }
            num++;
    }
}
//6th
void Project::sum_square_diff()
{
    int sum1=0, sum2=0, i=0, difference=0;

    cout << "Calculating ......... \n\n\n";

    for (i=0;i<=100;i++)
    {
        sum1 += i;
        sum2 += i*i;
    }
        sum1 = sum1*sum1;
        difference = sum1 - sum2;
        cout << "\a\a\a";
        cout << "The square of the sum of 100 natural numbers is: " << sum1 <<endl;
        cout << "The sum of the square of 100 natural numbers is: " << sum2 <<endl;
        cout << "The difference is: " << difference <<endl;
}

bool Project::isPrime(long long num)
{
    long long i=0;

    for(i=2;(i<=sqrt(num));i++)
    {
        if(num%i==0)
        {
        return false;
        }
    }
        return true;
}
//7th
void Project::onethousandfirst_prime()
{
    unsigned long long int i=1,count=1;

    cout << "Calculating ......... \n\n\n";

    while(count<10001)
    {
        i += 2;
        if(isPrime(i)==true)
        {
            count ++;
        }
    }
        cout << "\a\a\aThe 10001st prime number is: " << i <<endl;
}
//8th
void Project::largest_product_in_series()
{
    int numbers[1000];
    int temp = 1;
    int max_start= 0;
    int maxProduct = 0;
    ifstream number_file( "projectnum8.txt" );
    int i = 0;

    cout << "Calculating ......... \n\n\n";

    while(!number_file.eof())
    {
        if (number_file.peek()=='\n')
        {
            number_file.get();
        }
        else
        {
            numbers[i++] = number_file.get() - '0';
        }
    }
    number_file.close();

    i = 0;
    int j;

    while(i <= (995)) //Since the number of elements is 1000 and you will test 5 consecutive numbers everytime
    {
        for ( j = 0; j < 5; j++ )
        {
            temp *= numbers[ i + j ];
        }
        if ( temp > maxProduct )
        {
            maxProduct = temp;
            max_start = i;
        }
        i++;
        temp = 1;
    }
        cout << "\a\a\a";
        cout << "The greatest product of the five consecutive digits is: " << maxProduct <<endl;
        cout << "It starts at: " << max_start<<endl;
        cout << "The numbers are: ";
        for (i=0;i<5;i++)
        {
        cout << numbers[ max_start + i ] << " ";
        }
        cout <<endl;
}

int Project::checkTriplet(int a, int b, int c)
{
    if ((a * a) + (b* b) == (c* c))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Project::checkAdd(int a, int b, int c, int num)
{
    num = 1000;

    if ((a + b + c) == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//9th
void Project::special_pytho_triplet()
{
    Project proj;
    int a = 1;
    int b = 1;
    int c = 1;
    char checkFound= 0;

    cout << "Calculating ......... \n\n\n";

    for (a=1;a<1000;a++)
    {
        for (b=1;b<1000;b++)
        {
            for (c=1;c<1000;c++)
            {
                if (proj.checkAdd(a,b,c,1000))
                {
                    if (proj.checkTriplet(a,b,c))
                    {
                        checkFound= 1;
                        break;
                    }
                }
            }
        if (checkFound)
        {
            break;
        }
        }
    if (checkFound)
    {
        break;
    }

    }
    if (checkFound)
    {
        cout << "\a\a\a";
        cout << "The triple is:\n a = " << a << "\n b = " << b << "\n c = " << c  <<endl;
        cout << "The product of a, b & c is: " << (a * b * c) <<endl;
    }
    else
    {
        cout << "\a\a\a";
        cout << "The triple is = " << 1000 << " was not found!" <<endl;
    }
}
//10th
void Project::summation_of_primes()
{
    long sqrtnum = sqrt(2000000);
    int num=1;
	long long total=2;
	int divisor;
    bool prime = true ;

    cout << "Calculating ......... \n\n\n" <<endl;

	while (num<2000000)
	{
        prime=true;
        if (num<=1)
        {
            prime = false;
        }
        else if(num==2||num==3)
        {
            prime = true;
        }
        else if (num%2==0)
        {
            prime = false;
        }
        else
        {
            for(divisor=3; divisor <sqrtnum;divisor=divisor+2)
            {
                if (num==divisor)
                {
                    prime=true;
                }
                else if (num%divisor==0)
                {
                    prime=false;
                    break;
                }
            }
        }
    if (prime==true)
    {
        total=total+num;
    }
        num=num+2;
    }
        cout<< "\a\a\aThe summation of all prime numbers less than 2,000,000 is: " << total <<endl;
}
//11th
void Project::largest_product_grid()
{
    int array[20][20]= //The grid of elements is 20 by 20
    {
        { 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
        {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0},
        {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
        {52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
        {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
        {24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
        {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
        {67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21},
        {24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
        {21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95},
        {78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
        {16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57},
        {86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
        {19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40},
        { 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
        {88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
        { 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
        {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
        {20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
        { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48},
    };

    long long highest=0;
    long long test=0;
    int one=0,two=0,three=0,four=0;
    int i=0,j=0;

    cout << "Calculating ......... \n\n\n";

    //Checking horizontally for the highest element
    for(i=0; i<20; i++)
    {
        for(j=0; j<17; j++)
        {
            test=(array[i][j]*array[i][j+1]*array[i][j+2]*array[i][j+3]);
            if(test>highest)
            {
                highest=test;
                one=array[i][j];
                two=array[i][j+1];
                three=array[i][j+2];
                four=array[i][j+3];
            }
        }
    }
    //Checking vertically for the highest element
    for(i=0; i<17; i++)
    {
        for(j=0; j<20; j++)
        {
            test=(array[i][j]*array[i+1][j]*array[i+2][j]*array[i+3][j]);

            if(test>highest)
            {
                highest=test;
                one=array[i][j];
                two=array[i+1][j];
                three=array[i+2][j];
                four=array[i+3][j];
            }
        }
    }
    //Checking diagonally (right) for the highest element
    for(i=3; i<20; i++)
    {
        for(j=0; j<17; j++)
        {
            test=(array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][i-3]);

            if(test>highest)
            {
                highest=test;
                one=array[i][j];
                two=array[i-1][j-1];
                three=array[i-2][j-2];
                four=array[i-3][j-3];
            }
        }
    }
    //Checking diagonally (left) for the highest element
    for(i=0; i<17; i++)
    {
        for(j=0; j<17; j++)
        {
            test=(array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3]);

            if(test>highest)
            {
                highest=test;
                one=array[i][j];
                two=array[i+1][j-1];
                three=array[i+2][j-2];
                four=array[i+3][j-3];
            }
        }
    }
        cout<< "\a\a\aThe largest product of the four adjacent numbers ("
        << one << "," << two << "," << three << "," << four << ") is: " << highest <<endl;
}
//12th
void Project::divisible_triangular_number()
{
    int divisors = 0;
    long triangle_num = 0;
    long i = 0;
    int j = 0;

    cout << "Calculating ......... " <<endl;
    cout << "This may take few seconds.....\n\n\n";

    for(i = 1; ; i++)
    {
        triangle_num = triangle_num + i;
        for(j = 1; j < sqrt(triangle_num); j++)
        {
            if((triangle_num % j) == 0)
            {
                divisors += 2;
            }
        }
        if(triangle_num == (sqrt(triangle_num) * sqrt(triangle_num)))
        {
            divisors++;
        }
        if (divisors > 500)
        {
            cout << "\a\a\aThe first triangle number which has over 500 divisors is " << triangle_num << " with " << divisors << " divisors.\n";
            break;
        }
            divisors = 0;
    }
}
//13th
void Project::largest_sum()
{
    long temp = 0;
    long carry[50] = {0};
    int k = 49,z = 49;
    int x = 0, y = 0;
    long answer[50] = {0};
    int data[100][50] ={ //There is a 100 by 50 elements
                        {  3, 7 ,1, 0, 7, 2, 8, 7, 5, 3, 3, 9, 0, 2, 1, 0, 2, 7, 9, 8, 7, 9, 7, 9, 9, 8, 2, 2, 0, 8, 3, 7, 5, 9, 0, 2, 4, 6, 5, 1, 0, 1, 3, 5, 7, 4, 0, 2, 5, 0} ,
                        {  4, 6, 3, 7, 6, 9, 3, 7, 6, 7, 7, 4, 9, 0, 0, 0, 9, 7, 1, 2, 6, 4, 8, 1, 2, 4, 8, 9, 6, 9, 7, 0, 0, 7, 8, 0, 5, 0, 4, 1, 7, 0, 1, 8, 2, 6, 0, 5, 3, 8}  ,
                        {  7, 4, 3, 2, 4, 9, 8, 6, 1, 9, 9, 5, 2, 4, 7, 4, 1, 0, 5, 9, 4, 7, 4, 2, 3, 3, 3, 0, 9, 5, 1, 3, 0, 5, 8, 1, 2, 3, 7, 2, 6, 6, 1, 7, 3, 0, 9, 6, 2, 9}  ,
                        {  9, 1, 9, 4, 2, 2, 1, 3, 3, 6, 3, 5, 7, 4, 1, 6, 1, 5, 7, 2, 5, 2, 2, 4, 3, 0, 5, 6, 3, 3, 0, 1, 8, 1, 1, 0, 7, 2, 4, 0, 6, 1, 5, 4, 9, 0, 8, 2, 5, 0}  ,
                        {  2, 3, 0, 6, 7, 5, 8, 8, 2, 0, 7, 5, 3, 9, 3, 4, 6, 1, 7, 1, 1, 7, 1, 9, 8, 0, 3, 1, 0, 4, 2, 1, 0, 4, 7, 5, 1, 3, 7, 7, 8, 0, 6, 3, 2, 4, 6, 6, 7, 6}  ,
                        {  8, 9, 2, 6, 1, 6, 7, 0, 6, 9, 6, 6, 2, 3, 6, 3, 3, 8, 2, 0, 1, 3, 6, 3, 7, 8, 4, 1, 8, 3, 8, 3, 6, 8, 4, 1, 7, 8, 7, 3, 4, 3, 6, 1, 7, 2, 6, 7, 5, 7}  ,
                        {  2, 8, 1, 1, 2, 8, 7, 9, 8, 1, 2, 8, 4, 9, 9, 7, 9, 4, 0, 8, 0, 6, 5, 4, 8, 1, 9, 3, 1, 5, 9, 2, 6, 2, 1, 6, 9, 1, 2, 7, 5, 8, 8, 9, 8, 3, 2, 7, 3, 8}  ,
                        {  4, 4, 2, 7, 4, 2, 2, 8, 9, 1, 7, 4, 3, 2, 5, 2, 0, 3, 2, 1, 9, 2, 3, 5, 8, 9, 4, 2, 2, 8, 7, 6, 7, 9, 6, 4, 8, 7, 6, 7, 0, 2, 7, 2, 1, 8, 9, 3, 1, 8}  ,
                        {  4, 7, 4, 5, 1, 4, 4, 5, 7, 3, 6, 0, 0, 1, 3, 0, 6, 4, 3, 9, 0, 9, 1, 1, 6, 7, 2, 1, 6, 8, 5, 6, 8, 4, 4, 5, 8, 8, 7, 1, 1, 6, 0, 3, 1, 5, 3, 2, 7, 6}  ,
                        {  7, 0, 3, 8, 6, 4, 8, 6, 1, 0, 5, 8, 4, 3, 0, 2, 5, 4, 3, 9, 9, 3, 9, 6, 1, 9, 8, 2, 8, 9, 1, 7, 5, 9, 3, 6, 6, 5, 6, 8, 6, 7, 5, 7, 9, 3, 4, 9, 5, 1}  ,
                        {  6, 2, 1, 7, 6, 4, 5, 7, 1, 4, 1, 8, 5, 6, 5, 6, 0, 6, 2, 9, 5, 0, 2, 1, 5, 7, 2, 2, 3, 1, 9, 6, 5, 8, 6, 7, 5, 5, 0, 7, 9, 3, 2, 4, 1, 9, 3, 3, 3, 1}  ,
                        {  6, 4, 9, 0, 6, 3, 5, 2, 4, 6, 2, 7, 4, 1, 9, 0, 4, 9, 2, 9, 1, 0, 1, 4, 3, 2, 4, 4, 5, 8, 1, 3, 8, 2, 2, 6, 6, 3, 3, 4, 7, 9, 4, 4, 7, 5, 8, 1, 7, 8}  ,
                        {  9, 2, 5, 7, 5, 8, 6, 7, 7, 1, 8, 3, 3, 7, 2, 1, 7, 6, 6, 1, 9, 6, 3, 7, 5, 1, 5, 9, 0, 5, 7, 9, 2, 3, 9, 7, 2, 8, 2, 4, 5, 5, 9, 8, 8, 3, 8, 4, 0, 7}  ,
                        {  5, 8, 2, 0, 3, 5, 6, 5, 3, 2, 5, 3, 5, 9, 3, 9, 9, 0, 0, 8, 4, 0, 2, 6, 3, 3, 5, 6, 8, 9, 4, 8, 8, 3, 0, 1, 8, 9, 4, 5, 8, 6, 2, 8, 2, 2, 7, 8, 2, 8}  ,
                        {  8, 0, 1, 8, 1, 1, 9, 9, 3, 8, 4, 8, 2, 6, 2, 8, 2, 0, 1, 4, 2, 7, 8, 1, 9, 4, 1, 3, 9, 9, 4, 0, 5, 6, 7, 5, 8, 7, 1, 5, 1, 1, 7, 0, 0, 9, 4, 3, 9, 0}  ,
                        {  3, 5, 3, 9, 8, 6, 6, 4, 3, 7, 2, 8, 2, 7, 1, 1, 2, 6, 5, 3, 8, 2, 9, 9, 8, 7, 2, 4, 0, 7, 8, 4, 4, 7, 3, 0, 5, 3, 1, 9, 0, 1, 0, 4, 2, 9, 3, 5, 8, 6}  ,
                        {  8, 6, 5, 1, 5, 5, 0, 6, 0, 0, 6, 2, 9, 5, 8, 6, 4, 8, 6, 1, 5, 3, 2, 0, 7, 5, 2, 7, 3, 3, 7, 1, 9, 5, 9, 1, 9, 1, 4, 2, 0, 5, 1, 7, 2, 5, 5, 8, 2, 9}  ,
                        {  7, 1, 6, 9, 3, 8, 8, 8, 7, 0, 7, 7, 1, 5, 4, 6, 6, 4, 9, 9, 1, 1, 5, 5, 9, 3, 4, 8, 7, 6, 0, 3, 5, 3, 2, 9, 2, 1, 7, 1, 4, 9, 7, 0, 0, 5, 6, 9, 3, 8}  ,
                        {  5, 4, 3, 7, 0, 0, 7, 0, 5, 7, 6, 8, 2, 6, 6, 8, 4, 6, 2, 4, 6, 2, 1, 4, 9, 5, 6, 5, 0, 0, 7, 6, 4, 7, 1, 7, 8, 7, 2, 9, 4, 4, 3, 8, 3, 7, 7, 6, 0, 4}  ,
                        {  5, 3, 2, 8, 2, 6, 5, 4, 1, 0, 8, 7, 5, 6, 8, 2, 8, 4, 4, 3, 1, 9, 1, 1, 9, 0, 6, 3, 4, 6, 9, 4, 0, 3, 7, 8, 5, 5, 2, 1, 7, 7, 7, 9, 2, 9, 5, 1, 4, 5}  ,
                        {  3, 6, 1, 2, 3, 2, 7, 2, 5, 2, 5, 0, 0, 0, 2, 9, 6, 0, 7, 1, 0, 7, 5, 0, 8, 2, 5, 6, 3, 8, 1, 5, 6, 5, 6, 7, 1, 0, 8, 8, 5, 2, 5, 8, 3, 5, 0, 7, 2, 1}  ,
                        {  4, 5, 8, 7, 6, 5, 7, 6, 1, 7, 2, 4, 1, 0, 9, 7, 6, 4, 4, 7, 3, 3, 9, 1, 1, 0, 6, 0, 7, 2, 1, 8, 2, 6, 5, 2, 3, 6, 8, 7, 7, 2, 2, 3, 6, 3, 6, 0, 4, 5}  ,
                        {  1, 7, 4, 2, 3, 7, 0, 6, 9, 0, 5, 8, 5, 1, 8, 6, 0, 6, 6, 0, 4, 4, 8, 2, 0, 7, 6, 2, 1, 2, 0, 9, 8, 1, 3, 2, 8, 7, 8, 6, 0, 7, 3, 3, 9, 6, 9, 4, 1, 2}  ,
                        {  8, 1, 1, 4, 2, 6, 6, 0, 4, 1, 8, 0, 8, 6, 8, 3, 0, 6, 1, 9, 3, 2, 8, 4, 6, 0, 8, 1, 1, 1, 9, 1, 0, 6, 1, 5, 5, 6, 9, 4, 0, 5, 1, 2, 6, 8, 9, 6, 9, 2}  ,
                        {  5, 1, 9, 3, 4, 3, 2, 5, 4, 5, 1, 7, 2, 8, 3, 8, 8, 6, 4, 1, 9, 1, 8, 0, 4, 7, 0, 4, 9, 2, 9, 3, 2, 1, 5, 0, 5, 8, 6, 4, 2, 5, 6, 3, 0, 4, 9, 4, 8, 3}  ,
                        {  6, 2, 4, 6, 7, 2, 2, 1, 6, 4, 8, 4, 3, 5, 0, 7, 6, 2, 0, 1, 7, 2, 7, 9, 1, 8, 0, 3, 9, 9, 4, 4, 6, 9, 3, 0, 0, 4, 7, 3, 2, 9, 5, 6, 3, 4, 0, 6, 9, 1}  ,
                        {  1, 5, 7, 3, 2, 4, 4, 4, 3, 8, 6, 9, 0, 8, 1, 2, 5, 7, 9, 4, 5, 1, 4, 0, 8, 9, 0, 5, 7, 7, 0, 6, 2, 2, 9, 4, 2, 9, 1, 9, 7, 1, 0, 7, 9, 2, 8, 2, 0, 9}  ,
                        {  5, 5, 0, 3, 7, 6, 8, 7, 5, 2, 5, 6, 7, 8, 7, 7, 3, 0, 9, 1, 8, 6, 2, 5, 4, 0, 7, 4, 4, 9, 6, 9, 8, 4, 4, 5, 0, 8, 3, 3, 0, 3, 9, 3, 6, 8, 2, 1, 2, 6}  ,
                        {  1, 8, 3, 3, 6, 3, 8, 4, 8, 2, 5, 3, 3, 0, 1, 5, 4, 6, 8, 6, 1, 9, 6, 1, 2, 4, 3, 4, 8, 7, 6, 7, 6, 8, 1, 2, 9, 7, 5, 3, 4, 3, 7, 5, 9, 4, 6, 5, 1, 5}  ,
                        {  8, 0, 3, 8, 6, 2, 8, 7, 5, 9, 2, 8, 7, 8, 4, 9, 0, 2, 0, 1, 5, 2, 1, 6, 8, 5, 5, 5, 4, 8, 2, 8, 7, 1, 7, 2, 0, 1, 2, 1, 9, 2, 5, 7, 7, 6, 6, 9, 5, 4}  ,
                        {  7, 8, 1, 8, 2, 8, 3, 3, 7, 5, 7, 9, 9, 3, 1, 0, 3, 6, 1, 4, 7, 4, 0, 3, 5, 6, 8, 5, 6, 4, 4, 9, 0, 9, 5, 5, 2, 7, 0, 9, 7, 8, 6, 4, 7, 9, 7, 5, 8, 1}  ,
                        {  1, 6, 7, 2, 6, 3, 2, 0, 1, 0, 0, 4, 3, 6, 8, 9, 7, 8, 4, 2, 5, 5, 3, 5, 3, 9, 9, 2, 0, 9, 3, 1, 8, 3, 7, 4, 4, 1, 4, 9, 7, 8, 0, 6, 8, 6, 0, 9, 8, 4}  ,
                        {  4, 8, 4, 0, 3, 0, 9, 8, 1, 2, 9, 0, 7, 7, 7, 9, 1, 7, 9, 9, 0, 8, 8, 2, 1, 8, 7, 9, 5, 3, 2, 7, 3, 6, 4, 4, 7, 5, 6, 7, 5, 5, 9, 0, 8, 4, 8, 0, 3, 0}  ,
                        {  8, 7, 0, 8, 6, 9, 8, 7, 5, 5, 1, 3, 9, 2, 7, 1, 1, 8, 5, 4, 5, 1, 7, 0, 7, 8, 5, 4, 4, 1, 6, 1, 8, 5, 2, 4, 2, 4, 3, 2, 0, 6, 9, 3, 1, 5, 0, 3, 3, 2}  ,
                        {  5, 9, 9, 5, 9, 4, 0, 6, 8, 9, 5, 7, 5, 6, 5, 3, 6, 7, 8, 2, 1, 0, 7, 0, 7, 4, 9, 2, 6, 9, 6, 6, 5, 3, 7, 6, 7, 6, 3, 2, 6, 2, 3, 5, 4, 4, 7, 2, 1, 0}  ,
                        {  6, 9, 7, 9, 3, 9, 5, 0, 6, 7, 9, 6, 5, 2, 6, 9, 4, 7, 4, 2, 5, 9, 7, 7, 0, 9, 7, 3, 9, 1, 6, 6, 6, 9, 3, 7, 6, 3, 0, 4, 2, 6, 3, 3, 9, 8, 7, 0, 8, 5}  ,
                        {  4, 1, 0, 5, 2, 6, 8, 4, 7, 0, 8, 2, 9, 9, 0, 8, 5, 2, 1, 1, 3, 9, 9, 4, 2, 7, 3, 6, 5, 7, 3, 4, 1, 1, 6, 1, 8, 2, 7, 6, 0, 3, 1, 5, 0, 0, 1, 2, 7, 1}  ,
                        {  6, 5, 3, 7, 8, 6, 0, 7, 3, 6, 1, 5, 0, 1, 0, 8, 0, 8, 5, 7, 0, 0, 9, 1, 4, 9, 9, 3, 9, 5, 1, 2, 5, 5, 7, 0, 2, 8, 1, 9, 8, 7, 4, 6, 0, 0, 4, 3, 7, 5}  ,
                        {  3, 5, 8, 2, 9, 0, 3, 5, 3, 1, 7, 4, 3, 4, 7, 1, 7, 3, 2, 6, 9, 3, 2, 1, 2, 3, 5, 7, 8, 1, 5, 4, 9, 8, 2, 6, 2, 9, 7, 4, 2, 5, 5, 2, 7, 3, 7, 3, 0, 7}  ,
                        {  9, 4, 9, 5, 3, 7, 5, 9, 7, 6, 5, 1, 0, 5, 3, 0, 5, 9, 4, 6, 9, 6, 6, 0, 6, 7, 6, 8, 3, 1, 5, 6, 5, 7, 4, 3, 7, 7, 1, 6, 7, 4, 0, 1, 8, 7, 5, 2, 7, 5}  ,
                        {  8, 8, 9, 0, 2, 8, 0, 2, 5, 7, 1, 7, 3, 3, 2, 2, 9, 6, 1, 9, 1, 7, 6, 6, 6, 8, 7, 1, 3, 8, 1, 9, 9, 3, 1, 8, 1, 1, 0, 4, 8, 7, 7, 0, 1, 9, 0, 2, 7, 1}  ,
                        {  2, 5, 2, 6, 7, 6, 8, 0, 2, 7, 6, 0, 7, 8, 0, 0, 3, 0, 1, 3, 6, 7, 8, 6, 8, 0, 9, 9, 2, 5, 2, 5, 4, 6, 3, 4, 0, 1, 0, 6, 1, 6, 3, 2, 8, 6, 6, 5, 2, 6}  ,
                        {  3, 6, 2, 7, 0, 2, 1, 8, 5, 4, 0, 4, 9, 7, 7, 0, 5, 5, 8, 5, 6, 2, 9, 9, 4, 6, 5, 8, 0, 6, 3, 6, 2, 3, 7, 9, 9, 3, 1, 4, 0, 7, 4, 6, 2, 5, 5, 9, 6, 2}  ,
                        {  2, 4, 0, 7, 4, 4, 8, 6, 9, 0, 8, 2, 3, 1, 1, 7, 4, 9, 7, 7, 7, 9, 2, 3, 6, 5, 4, 6, 6, 2, 5, 7, 2, 4, 6, 9, 2, 3, 3, 2, 2, 8, 1, 0, 9, 1, 7, 1, 4, 1}  ,
                        {  9, 1, 4, 3, 0, 2, 8, 8, 1, 9, 7, 1, 0, 3, 2, 8, 8, 5, 9, 7, 8, 0, 6, 6, 6, 9, 7, 6, 0, 8, 9, 2, 9, 3, 8, 6, 3, 8, 2, 8, 5, 0, 2, 5, 3, 3, 3, 4, 0, 3}  ,
                        {  3, 4, 4, 1, 3, 0, 6, 5, 5, 7, 8, 0, 1, 6, 1, 2, 7, 8, 1, 5, 9, 2, 1, 8, 1, 5, 0, 0, 5, 5, 6, 1, 8, 6, 8, 8, 3, 6, 4, 6, 8, 4, 2, 0, 0, 9, 0, 4, 7, 0}  ,
                        {  2, 3, 0, 5, 3, 0, 8, 1, 1, 7, 2, 8, 1, 6, 4, 3, 0, 4, 8, 7, 6, 2, 3, 7, 9, 1, 9, 6, 9, 8, 4, 2, 4, 8, 7, 2, 5, 5, 0, 3, 6, 6, 3, 8, 7, 8, 4, 5, 8, 3}  ,
                        {  1, 1, 4, 8, 7, 6, 9, 6, 9, 3, 2, 1, 5, 4, 9, 0, 2, 8, 1, 0, 4, 2, 4, 0, 2, 0, 1, 3, 8, 3, 3, 5, 1, 2, 4, 4, 6, 2, 1, 8, 1, 4, 4, 1, 7, 7, 3, 4, 7, 0}  ,
                        {  6, 3, 7, 8, 3, 2, 9, 9, 4, 9, 0, 6, 3, 6, 2, 5, 9, 6, 6, 6, 4, 9, 8, 5, 8, 7, 6, 1, 8, 2, 2, 1, 2, 2, 5, 2, 2, 5, 5, 1, 2, 4, 8, 6, 7, 6, 4, 5, 3, 3}  ,
                        {  6, 7, 7, 2, 0, 1, 8, 6, 9, 7, 1, 6, 9, 8, 5, 4, 4, 3, 1, 2, 4, 1, 9, 5, 7, 2, 4, 0, 9, 9, 1, 3, 9, 5, 9, 0, 0, 8, 9, 5, 2, 3, 1, 0, 0, 5, 8, 8, 2, 2}  ,
                        {  9, 5, 5, 4, 8, 2, 5, 5, 3, 0, 0, 2, 6, 3, 5, 2, 0, 7, 8, 1, 5, 3, 2, 2, 9, 6, 7, 9, 6, 2, 4, 9, 4, 8, 1, 6, 4, 1, 9, 5, 3, 8, 6, 8, 2, 1, 8, 7, 7, 4}  ,
                        {  7, 6, 0, 8, 5, 3, 2, 7, 1, 3, 2, 2, 8, 5, 7, 2, 3, 1, 1, 0, 4, 2, 4, 8, 0, 3, 4, 5, 6, 1, 2, 4, 8, 6, 7, 6, 9, 7, 0, 6, 4, 5, 0, 7, 9, 9, 5, 2, 3, 6}  ,
                        {  3, 7, 7, 7, 4, 2, 4, 2, 5, 3, 5, 4, 1, 1, 2, 9, 1, 6, 8, 4, 2, 7, 6, 8, 6, 5, 5, 3, 8, 9, 2, 6, 2, 0, 5, 0, 2, 4, 9, 1, 0, 3, 2, 6, 5, 7, 2, 9, 6, 7}  ,
                        {  2, 3, 7, 0, 1, 9, 1, 3, 2, 7, 5, 7, 2, 5, 6, 7, 5, 2, 8, 5, 6, 5, 3, 2, 4, 8, 2, 5, 8, 2, 6, 5, 4, 6, 3, 0, 9, 2, 2, 0, 7, 0, 5, 8, 5, 9, 6, 5, 2, 2}  ,
                        {  2, 9, 7, 9, 8, 8, 6, 0, 2, 7, 2, 2, 5, 8, 3, 3, 1, 9, 1, 3, 1, 2, 6, 3, 7, 5, 1, 4, 7, 3, 4, 1, 9, 9, 4, 8, 8, 9, 5, 3, 4, 7, 6, 5, 7, 4, 5, 5, 0, 1}  ,
                        {  1, 8, 4, 9, 5, 7, 0, 1, 4, 5, 4, 8, 7, 9, 2, 8, 8, 9, 8, 4, 8, 5, 6, 8, 2, 7, 7, 2, 6, 0, 7, 7, 7, 1, 3, 7, 2, 1, 4, 0, 3, 7, 9, 8, 8, 7, 9, 7, 1, 5}  ,
                        {  3, 8, 2, 9, 8, 2, 0, 3, 7, 8, 3, 0, 3, 1, 4, 7, 3, 5, 2, 7, 7, 2, 1, 5, 8, 0, 3, 4, 8, 1, 4, 4, 5, 1, 3, 4, 9, 1, 3, 7, 3, 2, 2, 6, 6, 5, 1, 3, 8, 1}  ,
                        {  3, 4, 8, 2, 9, 5, 4, 3, 8, 2, 9, 1, 9, 9, 9, 1, 8, 1, 8, 0, 2, 7, 8, 9, 1, 6, 5, 2, 2, 4, 3, 1, 0, 2, 7, 3, 9, 2, 2, 5, 1, 1, 2, 2, 8, 6, 9, 5, 3, 9}  ,
                        {  4, 0, 9, 5, 7, 9, 5, 3, 0, 6, 6, 4, 0, 5, 2, 3, 2, 6, 3, 2, 5, 3, 8, 0, 4, 4, 1, 0, 0, 0, 5, 9, 6, 5, 4, 9, 3, 9, 1, 5, 9, 8, 7, 9, 5, 9, 3, 6, 3, 5}  ,
                        {  2, 9, 7, 4, 6, 1, 5, 2, 1, 8, 5, 5, 0, 2, 3, 7, 1, 3, 0, 7, 6, 4, 2, 2, 5, 5, 1, 2, 1, 1, 8, 3, 6, 9, 3, 8, 0, 3, 5, 8, 0, 3, 8, 8, 5, 8, 4, 9, 0, 3}  ,
                        {  4, 1, 6, 9, 8, 1, 1, 6, 2, 2, 2, 0, 7, 2, 9, 7, 7, 1, 8, 6, 1, 5, 8, 2, 3, 6, 6, 7, 8, 4, 2, 4, 6, 8, 9, 1, 5, 7, 9, 9, 3, 5, 3, 2, 9, 6, 1, 9, 2, 2}  ,
                        {  6, 2, 4, 6, 7, 9, 5, 7, 1, 9, 4, 4, 0, 1, 2, 6, 9, 0, 4, 3, 8, 7, 7, 1, 0, 7, 2, 7, 5, 0, 4, 8, 1, 0, 2, 3, 9, 0, 8, 9, 5, 5, 2, 3, 5, 9, 7, 4, 5, 7}  ,
                        {  2, 3, 1, 8, 9, 7, 0, 6, 7, 7, 2, 5, 4, 7, 9, 1, 5, 0, 6, 1, 5, 0, 5, 5, 0, 4, 9, 5, 3, 9, 2, 2, 9, 7, 9, 5, 3, 0, 9, 0, 1, 1, 2, 9, 9, 6, 7, 5, 1, 9}  ,
                        {  8, 6, 1, 8, 8, 0, 8, 8, 2, 2, 5, 8, 7, 5, 3, 1, 4, 5, 2, 9, 5, 8, 4, 0, 9, 9, 2, 5, 1, 2, 0, 3, 8, 2, 9, 0, 0, 9, 4, 0, 7, 7, 7, 0, 7, 7, 5, 6, 7, 2}  ,
                        {  1, 1, 3, 0, 6, 7, 3, 9, 7, 0, 8, 3, 0, 4, 7, 2, 4, 4, 8, 3, 8, 1, 6, 5, 3, 3, 8, 7, 3, 5, 0, 2, 3, 4, 0, 8, 4, 5, 6, 4, 7, 0, 5, 8, 0, 7, 7, 3, 0, 8}  ,
                        {  8, 2, 9, 5, 9, 1, 7, 4, 7, 6, 7, 1, 4, 0, 3, 6, 3, 1, 9, 8, 0, 0, 8, 1, 8, 7, 1, 2, 9, 0, 1, 1, 8, 7, 5, 4, 9, 1, 3, 1, 0, 5, 4, 7, 1, 2, 6, 5, 8, 1}  ,
                        {  9, 7, 6, 2, 3, 3, 3, 1, 0, 4, 4, 8, 1, 8, 3, 8, 6, 2, 6, 9, 5, 1, 5, 4, 5, 6, 3, 3, 4, 9, 2, 6, 3, 6, 6, 5, 7, 2, 8, 9, 7, 5, 6, 3, 4, 0, 0, 5, 0, 0}  ,
                        {  4, 2, 8, 4, 6, 2, 8, 0, 1, 8, 3, 5, 1, 7, 0, 7, 0, 5, 2, 7, 8, 3, 1, 8, 3, 9, 4, 2, 5, 8, 8, 2, 1, 4, 5, 5, 2, 1, 2, 2, 7, 2, 5, 1, 2, 5, 0, 3, 2, 7}  ,
                        {  5, 5, 1, 2, 1, 6, 0, 3, 5, 4, 6, 9, 8, 1, 2, 0, 0, 5, 8, 1, 7, 6, 2, 1, 6, 5, 2, 1, 2, 8, 2, 7, 6, 5, 2, 7, 5, 1, 6, 9, 1, 2, 9, 6, 8, 9, 7, 7, 8, 9}  ,
                        {  3, 2, 2, 3, 8, 1, 9, 5, 7, 3, 4, 3, 2, 9, 3, 3, 9, 9, 4, 6, 4, 3, 7, 5, 0, 1, 9, 0, 7, 8, 3, 6, 9, 4, 5, 7, 6, 5, 8, 8, 3, 3, 5, 2, 3, 9, 9, 8, 8, 6}  ,
                        {  7, 5, 5, 0, 6, 1, 6, 4, 9, 6, 5, 1, 8, 4, 7, 7, 5, 1, 8, 0, 7, 3, 8, 1, 6, 8, 8, 3, 7, 8, 6, 1, 0, 9, 1, 5, 2, 7, 3, 5, 7, 9, 2, 9, 7, 0, 1, 3, 3, 7}  ,
                        {  6, 2, 1, 7, 7, 8, 4, 2, 7, 5, 2, 1, 9, 2, 6, 2, 3, 4, 0, 1, 9, 4, 2, 3, 9, 9, 6, 3, 9, 1, 6, 8, 0, 4, 4, 9, 8, 3, 9, 9, 3, 1, 7, 3, 3, 1, 2, 7, 3, 1}  ,
                        {  3, 2, 9, 2, 4, 1, 8, 5, 7, 0, 7, 1, 4, 7, 3, 4, 9, 5, 6, 6, 9, 1, 6, 6, 7, 4, 6, 8, 7, 6, 3, 4, 6, 6, 0, 9, 1, 5, 0, 3, 5, 9, 1, 4, 6, 7, 7, 5, 0, 4}  ,
                        {  9, 9, 5, 1, 8, 6, 7, 1, 4, 3, 0, 2, 3, 5, 2, 1, 9, 6, 2, 8, 8, 9, 4, 8, 9, 0, 1, 0, 2, 4, 2, 3, 3, 2, 5, 1, 1, 6, 9, 1, 3, 6, 1, 9, 6, 2, 6, 6, 2, 2}  ,
                        {  7, 3, 2, 6, 7, 4, 6, 0, 8, 0, 0, 5, 9, 1, 5, 4, 7, 4, 7, 1, 8, 3, 0, 7, 9, 8, 3, 9, 2, 8, 6, 8, 5, 3, 5, 2, 0, 6, 9, 4, 6, 9, 4, 4, 5, 4, 0, 7, 2, 4}  ,
                        {  7, 6, 8, 4, 1, 8, 2, 2, 5, 2, 4, 6, 7, 4, 4, 1, 7, 1, 6, 1, 5, 1, 4, 0, 3, 6, 4, 2, 7, 9, 8, 2, 2, 7, 3, 3, 4, 8, 0, 5, 5, 5, 5, 6, 2, 1, 4, 8, 1, 8}  ,
                        {  9, 7, 1, 4, 2, 6, 1, 7, 9, 1, 0, 3, 4, 2, 5, 9, 8, 6, 4, 7, 2, 0, 4, 5, 1, 6, 8, 9, 3, 9, 8, 9, 4, 2, 2, 1, 7, 9, 8, 2, 6, 0, 8, 8, 0, 7, 6, 8, 5, 2}  ,
                        {  8, 7, 7, 8, 3, 6, 4, 6, 1, 8, 2, 7, 9, 9, 3, 4, 6, 3, 1, 3, 7, 6, 7, 7, 5, 4, 3, 0, 7, 8, 0, 9, 3, 6, 3, 3, 3, 3, 0, 1, 8, 9, 8, 2, 6, 4, 2, 0, 9, 0}  ,
                        {  1, 0, 8, 4, 8, 8, 0, 2, 5, 2, 1, 6, 7, 4, 6, 7, 0, 8, 8, 3, 2, 1, 5, 1, 2, 0, 1, 8, 5, 8, 8, 3, 5, 4, 3, 2, 2, 3, 8, 1, 2, 8, 7, 6, 9, 5, 2, 7, 8, 6}  ,
                        {  7, 1, 3, 2, 9, 6, 1, 2, 4, 7, 4, 7, 8, 2, 4, 6, 4, 5, 3, 8, 6, 3, 6, 9, 9, 3, 0, 0, 9, 0, 4, 9, 3, 1, 0, 3, 6, 3, 6, 1, 9, 7, 6, 3, 8, 7, 8, 0, 3, 9}  ,
                        {  6, 2, 1, 8, 4, 0, 7, 3, 5, 7, 2, 3, 9, 9, 7, 9, 4, 2, 2, 3, 4, 0, 6, 2, 3, 5, 3, 9, 3, 8, 0, 8, 3, 3, 9, 6, 5, 1, 3, 2, 7, 4, 0, 8, 0, 1, 1, 1, 1, 6}  ,
                        {  6, 6, 6, 2, 7, 8, 9, 1, 9, 8, 1, 4, 8, 8, 0, 8, 7, 7, 9, 7, 9, 4, 1, 8, 7, 6, 8, 7, 6, 1, 4, 4, 2, 3, 0, 0, 3, 0, 9, 8, 4, 4, 9, 0, 8, 5, 1, 4, 1, 1}  ,
                        {  6, 0, 6, 6, 1, 8, 2, 6, 2, 9, 3, 6, 8, 2, 8, 3, 6, 7, 6, 4, 7, 4, 4, 7, 7, 9, 2, 3, 9, 1, 8, 0, 3, 3, 5, 1, 1, 0, 9, 8, 9, 0, 6, 9, 7, 9, 0, 7, 1, 4}  ,
                        {  8, 5, 7, 8, 6, 9, 4, 4, 0, 8, 9, 5, 5, 2, 9, 9, 0, 6, 5, 3, 6, 4, 0, 4, 4, 7, 4, 2, 5, 5, 7, 6, 0, 8, 3, 6, 5, 9, 9, 7, 6, 6, 4, 5, 7, 9, 5, 0, 9, 6}  ,
                        {  6, 6, 0, 2, 4, 3, 9, 6, 4, 0, 9, 9, 0, 5, 3, 8, 9, 6, 0, 7, 1, 2, 0, 1, 9, 8, 2, 1, 9, 9, 7, 6, 0, 4, 7, 5, 9, 9, 4, 9, 0, 1, 9, 7, 2, 3, 0, 2, 9, 7}  ,
                        {  6, 4, 9, 1, 3, 9, 8, 2, 6, 8, 0, 0, 3, 2, 9, 7, 3, 1, 5, 6, 0, 3, 7, 1, 2, 0, 0, 4, 1, 3, 7, 7, 9, 0, 3, 7, 8, 5, 5, 6, 6, 0, 8, 5, 0, 8, 9, 2, 5, 2}  ,
                        {  1, 6, 7, 3, 0, 9, 3, 9, 3, 1, 9, 8, 7, 2, 7, 5, 0, 2, 7, 5, 4, 6, 8, 9, 0, 6, 9, 0, 3, 7, 0, 7, 5, 3, 9, 4, 1, 3, 0, 4, 2, 6, 5, 2, 3, 1, 5, 0, 1, 1}  ,
                        {  9, 4, 8, 0, 9, 3, 7, 7, 2, 4, 5, 0, 4, 8, 7, 9, 5, 1, 5, 0, 9, 5, 4, 1, 0, 0, 9, 2, 1, 6, 4, 5, 8, 6, 3, 7, 5, 4, 7, 1, 0, 5, 9, 8, 4, 3, 6, 7, 9, 1}  ,
                        {  7, 8, 6, 3, 9, 1, 6, 7, 0, 2, 1, 1, 8, 7, 4, 9, 2, 4, 3, 1, 9, 9, 5, 7, 0, 0, 6, 4, 1, 9, 1, 7, 9, 6, 9, 7, 7, 7, 5, 9, 9, 0, 2, 8, 3, 0, 0, 6, 9, 9}  ,
                        {  1, 5, 3, 6, 8, 7, 1, 3, 7, 1, 1, 9, 3, 6, 6, 1, 4, 9, 5, 2, 8, 1, 1, 3, 0, 5, 8, 7, 6, 3, 8, 0, 2, 7, 8, 4, 1, 0, 7, 5, 4, 4, 4, 9, 7, 3, 3, 0, 7, 8}  ,
                        {  4, 0, 7, 8, 9, 9, 2, 3, 1, 1, 5, 5, 3, 5, 5, 6, 2, 5, 6, 1, 1, 4, 2, 3, 2, 2, 4, 2, 3, 2, 5, 5, 0, 3, 3, 6, 8, 5, 4, 4, 2, 4, 8, 8, 9, 1, 7, 3, 5, 3}  ,
                        {  4, 4, 8, 8, 9, 9, 1, 1, 5, 0, 1, 4, 4, 0, 6, 4, 8, 0, 2, 0, 3, 6, 9, 0, 6, 8, 0, 6, 3, 9, 6, 0, 6, 7, 2, 3, 2, 2, 1, 9, 3, 2, 0, 4, 1, 4, 9, 5, 3, 5}  ,
                        {  4, 1, 5, 0, 3, 1, 2, 8, 8, 8, 0, 3, 3, 9, 5, 3, 6, 0, 5, 3, 2, 9, 9, 3, 4, 0, 3, 6, 8, 0, 0, 6, 9, 7, 7, 7, 1, 0, 6, 5, 0, 5, 6, 6, 6, 3, 1, 9, 5, 4}  ,
                        {  8, 1, 2, 3, 4, 8, 8, 0, 6, 7, 3, 2, 1, 0, 1, 4, 6, 7, 3, 9, 0, 5, 8, 5, 6, 8, 5, 5, 7, 9, 3, 4, 5, 8, 1, 4, 0, 3, 6, 2, 7, 8, 2, 2, 7, 0, 3, 2, 8, 0}  ,
                        {  8, 2, 6, 1, 6, 5, 7, 0, 7, 7, 3, 9, 4, 8, 3, 2, 7, 5, 9, 2, 2, 3, 2, 8, 4, 5, 9, 4, 1, 7, 0, 6, 5, 2, 5, 0, 9, 4, 5, 1, 2, 3, 2, 5, 2, 3, 0, 6, 0, 8}  ,
                        {  2, 2, 9, 1, 8, 8, 0, 2, 0, 5, 8, 7, 7, 7, 3, 1, 9, 7, 1, 9, 8, 3, 9, 4, 5, 0, 1, 8, 0, 8, 8, 8, 0, 7, 2, 4, 2, 9, 6, 6, 1, 9, 8, 0, 8, 1, 1, 1, 9, 7}  ,
                        {  7, 7, 1, 5, 8, 5, 4, 2, 5, 0, 2, 0, 1, 6, 5, 4, 5, 0, 9, 0, 4, 1, 3, 2, 4, 5, 8, 0, 9, 7, 8, 6, 8, 8, 2, 7, 7, 8, 9, 4, 8, 7, 2, 1, 8, 5, 9, 6, 1, 7}  ,
                        {  7, 2, 1, 0, 7, 8, 3, 8, 4, 3, 5, 0, 6, 9, 1, 8, 6, 1, 5, 5, 4, 3, 5, 6, 6, 2, 8, 8, 4, 0, 6, 2, 2, 5, 7, 4, 7, 3, 6, 9, 2, 2, 8, 4, 5, 0, 9, 5, 1, 6}  ,
                        {  2, 0, 8, 4, 9, 6, 0, 3, 9, 8, 0, 1, 3, 4, 0, 0, 1, 7, 2, 3, 9, 3, 0, 6, 7, 1, 6, 6, 6, 8, 2, 3, 5, 5, 5, 2, 4, 5, 2, 5, 2, 8, 0, 4, 6, 0, 9, 7, 2, 2} ,
                        {  5, 3, 5, 0, 3, 5, 3, 4, 2, 2, 6, 4, 7, 2, 5, 2, 4, 2, 5, 0, 8, 7, 4, 0, 5, 4, 0, 7, 5, 5, 9, 1, 7, 8, 9, 7, 8, 1, 2, 6, 4, 3, 3, 0, 3, 3, 1, 6, 9, 0}
                        };
    cout << "Calculating ......... \n\n\n";

    for (y = 49; y >= 0; y --)
    {
        temp = 0;
        for (x = 0; x < 100; x ++)
        {
            temp += data[x][y];
        }
            carry[z] = temp;
            z --;
    }
    for (z = 49; z >= 1; z --)
    {
        answer[k] = carry[z]%10;
        carry[z] /= 10;
        carry[z-1] += carry[z];
        k--;
    }
        answer[k] = carry[0];

    for (k = 0; k < 8; k++)
    {
        cout << answer[k];
    }
        cout << "\a\a\a" <<endl;
}
//14th
void Project::longest_collatz_sum()
{
    long numTerms = 0;
    long longestSeq = 1;
    long mostTerms  = 1;
    unsigned long count = 0;
    long i = 0;

    cout << "Calculating ......... \n\n\n";

    for(i = 999999; i > 1; i--)
    {
        numTerms = 1;
        count = i;
        while (count > 1)
        {
            numTerms++;
            if (count%2 == 0)
            {
                count = count/2;
            }
            else
            {
                count = 3*count + 1;
            }
        }
        if (numTerms > mostTerms)
        {
            mostTerms  = numTerms;
            longestSeq = i;
        }
    }
        cout << "\a\a\aThe starting number (not exceeding one million) that produces the longest chain is " << longestSeq << " which has " << mostTerms<< " terms.\n";
}
//15th
void Project::diophantine_reciprocals_a()
{
    long rows = 20;
    long blocks = 40;
    int num[20];
    int denom[20];
    int pos = 0, i = 0, j = 0;
    long long numerator = 1, denominator = 1, quotient = 0;

    cout << "Calculating ......... \n\n\n";

    for (i = blocks; i > rows; i--)
    {
        num[pos] = i;
        denom[pos] = i - 20;
        pos++;
    }
    for(i = 0; i < 20; i++)     //Test for factorization
    {
        for(j = 0; j < 20; j++)
        {
            if(num[i] % denom[j] == 0)
            {
                num[i] = num[i] / denom[j];
                denom[j] = 1;
            }
        }
    }
    for(i = 0; i < 20; i++)
    {
        numerator *= num[i];
        denominator *= denom[i];
        quotient = numerator / denominator;
    }
        cout << "\a\a\a";
        cout << "Numerator: " << numerator <<endl;
        cout << "Denominator: " << denominator << endl;;
        cout << "Quotient: " << quotient << endl;
}
//16th
void Project::power_digit_sum()
{
    int pow = 0, product = 0, hold = 0;
    int digits = 0;
    int sum_dig = 0;
    string total = "1";

    cout << "Calculating ......... \n\n\n";

    for (pow = 1; pow <= 1000; ++pow)
    {
        hold = 0;
        for (digits = total.length() - 1; digits >= 0; --digits)
        {
            product = (total[digits] - '0') * 2 + hold;
            if (product > 9)
            {
                hold = 1;
                product %= 10;
            }
            else
            {
                hold = 0;
            }
                total[digits] = '0' + product;
            if (digits == 0 && hold == 1)
            {
                total.insert(0, "1");
            }
        }
    }
    for (digits = 0; digits < total.length(); ++digits)
    {
        sum_dig += total[digits] - '0';
    }
        cout << "\a\a\a2^1000 is equal to: " << total.insert(0, "1") <<endl;
        cout << "The sum of these digits is: " << sum_dig << endl;
}
//17th
void Project::number_letter_counts()
{
    int letters[1000];
    int hundred = strlen("hundred");
    int thousand = strlen("thousand");
    int word_and = strlen("and");
    int i = 0, total =0;

    letters[0] = 0;	//Ignore the first index to make calculation simpler
    letters[1] = strlen("one");
    letters[2] = strlen("two");
    letters[3] = strlen("three");
    letters[4] = strlen("four");
    letters[5] = strlen("five");
    letters[6] = strlen("six");
    letters[7] = strlen("seven");
    letters[8] = strlen("eight");
    letters[9] = strlen("nine");
    letters[10] = strlen("ten");
    letters[11] = strlen("eleven");
    letters[12] = strlen("twelve");
    letters[13] = strlen("thirteen");
    letters[14] = strlen("fourteen");
    letters[15] = strlen("fifteen");
    letters[16] = strlen("sixteen");
    letters[17] = strlen("seventeen");
    letters[18] = strlen("eighteen");
    letters[19] = strlen("nineteen");
    letters[20] = strlen("twenty");
    letters[30] = strlen("thirty");
    letters[40] = strlen("forty");
    letters[50] = strlen("fifty");
    letters[60] = strlen("sixty");
    letters[70] = strlen("seventy");
    letters[80] = strlen("eighty");
    letters[90] = strlen("ninety");

    cout << "Calculating ......... \n\n\n";

    for(i=1; i<1000; i++)
    {
    if(i<20) //The length of the word of the numbers below 20 is already given
    {
        continue;
    }
    else if(i < 100)	//Determining if the number is less than 100 (but greater than or equal to 20)
    {
        if(i % 10 == 0) // If the number is divisible by 10, the length is already given
        {
            continue;
        }
        else    // If the number is not divisible by 10
        {
            letters[i] = letters[(i/10)*10] + letters[(i%10)]; //The first term determines the tens digit by performing some arithmetic,
        }                                                      // and the result is already given since it will be divisible by 10.
    }                                                          // To get the ones digit, get the modulus of 10, and it will result
    else	//Calculating hundreds                             // to only one digit which its length is already given
    {
        if((i%100)== 0) // If the number is divisible by 100
        {
            letters[i] = letters[(i/100)] + hundred;   // In the first term, you will get the corresponding length and adding the
        }                                              // length of the word 'hundred' because obviously, it's in hundreds
        else if ((i%100)>10 && (i%100)<20)
        { // If the tens and ones (combined) has already a corresponding length
            letters[i] = letters[(i/100)] + hundred + word_and + letters[(i%100)];

        }
        else // If the tens and ones can be treated separately
        {
            letters[i] = letters[(i/100)] + hundred + word_and + letters[((i%100)/10)*10] + letters[(i%10)];
        } // automatically adding the length of the words 'hundred' and 'and'
    }
    }
        letters[1000] = letters[1] + thousand;	//insert the 1000 automatically and of course the length of the word 'thousand'

    for(i=0; i<=1000; i++)
    {
        total += letters[i];	// Getting the total of all the lengths (no. of letters)
    }
        cout << "\a\a\aThe total number of letters if all the numbers from 1 to 1000 (including 1 and 1000)"
        "were written in words is: " << total <<endl;
}
//18th
#define num_triangle "projectnum18.txt"
const int MAX = 100;

void Project :: bigSum(int* j, int* k, int* count)
{
    for(int i = 0; i < *count; i++)
    {
        if( ( *(j+i) + *(k+i) ) > ( *(j+i) + *(k+i+1) ) )
        {
            *(j+i) =  ( *(j+i) + *(k+i) );
        }
        else
        {
             *(j+i) =  ( *(j+i) + *(k+i+1) );
        }
     }
}

void Project::max_path_sum_one()
{
    Project proj;
    char* lines;

    fstream infile(num_triangle);

    int* upRow;
    int* lowRow;
    int* row[MAX];
    static int numLines     = 0;

    cout << "Calculating ....... " <<endl;

    if(! infile.is_open() )
    {
        cout << "Could not open " << num_triangle << endl;
        exit(1);
    }

    while( !infile.eof() )
        {
        lines = new char[MAX+1];                //Get file lines into char[]s
        infile.getline(lines, MAX);

        if(strlen(lines) < 1 )                  //Get out if problems
            break;

        int len = strlen(lines) - numLines;     //Define int arrays of
        row[numLines] = new int[len];          //correct length (no spaces)

        int pos = 0;
        for(int i = 0; i < strlen(lines); i++)
        {
           if ( ' ' == lines[i])                //Convert to ints, skip space
           {
                row[numLines][pos] = static_cast<int>(lines[i+1]-48);
                row[numLines][pos] *= 10;
                row[numLines][pos] += static_cast<int>(lines[i+2]-48);
                i += 2;
            }
            else
            {
                row[numLines][pos] = static_cast<int>(lines[i]-48);
                row[numLines][pos] *= 10;
                row[numLines][pos++] += static_cast<int>(lines[i+1]-48);
                i += 2;
            }
        }
            numLines++;
        }
            infile.close();
            numLines--;

    cout << "\a\a\a" <<endl;
    while(numLines > 0)
    {
        lowRow = row[numLines];
        upRow = row[numLines-1];

        proj.bigSum(upRow, lowRow, &numLines);

        for(int i = 0; i < numLines; i++)
        {
            cout << *(upRow+i) << " ";
        }
            cout <<endl;
            numLines--;
    }
}
int Project::check_Days(int *month)
{
    if( (*month==1) || (*month==3) || (*month==5) || (*month==7) || (*month==8) || (*month==10) || (*month==12) ) //Jan, March, May, July, August, October, December
    {
        return 31;
    }
    else if ((*month==4) || (*month==6) || (*month==9) || (*month==11)) // April, June, September, November
    {
        return 30;
    }
    else // February
    {
        return 28;
    }
}
//19th
void Project::counting_sundays()
{
    Project proj;
    int i=0;
    int day=2;          // Sunday =1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday=5, Friday = 6, Saturday = 7
    int year=1901;      // Starting year
    int month=1;        // January = 1, February = 2, March = 3 ... December = 12
    int num_Sundays=0;
    int last_Day;
    int* Num_Days;

    cout << "Calculating ......... \n\n\n";

    for(year=1901;year<2001;year++)
    {
        for(month=1;month<13;month++)
        {
            if (proj.check_Days(&month)==31)
            {
                Num_Days=new int[31];
                last_Day=31;
            }
            else if(check_Days(&month)==30)
            {
                Num_Days=new int[30];
                last_Day=30;
            }
            else
            {
                if(year%4 == 0)         // leap year
                {
                    Num_Days=new int[29];
                    last_Day=29;
                }
                else
                {
                    Num_Days=new int[28];
                    last_Day=28;
                }
            }
            for(i=0;i<last_Day;i++)
            {
                *(Num_Days+i)=day++;
                if(day>6)
                {
                    day = day - 7;
                }
            }
            if(*Num_Days == 0)
            {
                num_Sundays++;
            }
        }
    }
        cout << "\a\a\aThe number of Sundays from January 1, 1901 to December 31, 2000 is: " << num_Sundays << endl;
}
//20th
void Project::factorial_digit_sum()
{
    int i = 0, j = 0;
    int sum_facto = 0;
    int array[1000] = {0};
    array[0] = 1;

    cout << "Calculating ......... \n\n\n";

    for (i = 1; i <= 100; i++)
    {
        for (j = 0; j < 1000; j++)
        {
            array[j] = array[j]*i;
        }
        for (j = 0; j < 1000; j++)
        {
            array[j+1] += (array[j])/10;
            array[j] = (array[j])%10;
        }
    }
    for (j = 0; j < 1000; j++)
    {
        sum_facto += array[j];
    }
        cout << "\a\a\aThe sum of the digits of 100! is: " << sum_facto <<endl;
}

//21st
void Project::names_scores()
{
    char n;
    string name="";
    long long score=0, sum = 0;
    vector<string> names;
    ifstream myFile("names.txt");

    cout << "Calculating ......... \n\n\n";

    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            n = myFile.get();
            if(isalpha(n))
            {
                name.push_back(n);
            }
            else
            {
                if(!name.empty())
                {
                    names.push_back(name);
                    name.clear();
                }
            }
        }
    }
        myFile.close();

    sort(names.begin(),names.end());

    for(int i=0;i<names.size();i++)
    {
        sum=0;
        for(int j=0;j<names[i].size();j++)
        {
            sum += (names[i][j]-64);
        }
            sum *= (i+1);
            score += sum;
    }
        cout<<"\a\a\aThe total of all the name scores in the file is: " << score <<endl;
}

//22nd
void Project::first_1000_digit_fibonacci()
{
    float first=1,second=1, hold=0;
    int digit=1, count=2;

    cout << "Calculating ......... \n\n\n";

    do
    {
        hold = first;
        first = second;
        second = hold + first;
        count++;

        if (second > 10)
        {
            second /= 10;
            first/=10;
            digit++;
        }
    }
    while (digit < 1000);
    {
        cout << "\a\a\aThe first term in the Fibonacci sequence to contain 1000 digits is: " << count <<endl;
    }
}

//23rd
int z;
int prime[6]={1,2,3,5,7,9};

int Project::trun(int a[], int m, int flag)
{
    Project proj;
    int i,sum=0,p=100,t=0;

    for(i=0;i<m;i++)
    {
        sum=sum*10+a[i];
        t=sum;
    }
    while(p/10<sum)
    {
        for(i=3;i<=sqrt(t);i+=2)
        {
            if(t%i==0)
            {
                return 0;
            }
        }
        if(flag==1)
        {
            break;
        }
            t = sum%p;
            p *= 10;
    }
        if(a[m-1]!=1&&a[m-1]!=9&&flag!=1)
        {
            z += sum;
        }
            return 1;
}
void Project::Con(int p[],int m)
{
    Project proj;
    int i=0,n=0,flag=0;

    for(i=0;i<6;i++)
    {
        if(i==1)
        {
            continue;
        }
            p[m]=prime[i];

            if(proj.trun(p,m+1,1)==1)
            {
                if(proj.trun(p,m+1,2)==1)
                {
                    n++;
                }
                    proj.Con(p,m+1);
            }
     }
}
int Project::truncatable_primes()
{
    Project proj;
    int i=0,p[50],k=0;

    cout << "Calculating ......... \n\n\n";

    for(i=1;i<5;i++)
    {
        p[k]=prime[i];
        proj.Con(p,k+1);
    }
        cout << "\a\a\aThe sum of the only eleven primes that are both truncatable from left to right and right to left is: " << z <<endl;
        return 0;
}
