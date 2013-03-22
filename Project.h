#include <vector>

#ifndef PROJECT_H
#define PROJECT_H

class Project
{
    public:
        Project();
        virtual ~Project();
        void multiple_of_3_and_5 ();
        void even_fibonacci();
        void largest_prime_factor();
        void largest_palindrome_product();
        void smallest_multiple();
        void sum_square_diff();
        void onethousandfirst_prime();
            bool isPrime(long long num);
        void largest_product_in_series();
        void special_pytho_triplet(void);
            int checkTriplet( int a, int b, int c );
            int checkAdd( int a, int b, int c, int num);
        void summation_of_primes();
        void largest_product_grid();
        void divisible_triangular_number();
        void largest_sum();
        void longest_collatz_sum();
        void diophantine_reciprocals_a();
        void power_digit_sum();
        void number_letter_counts();
        void max_path_sum_one();
            void bigSum(int*, int*, int*);
        void counting_sundays();
            int check_Days(int *month);
        void factorial_digit_sum();
        void names_scores();
        void first_1000_digit_fibonacci();
        int truncatable_primes();
            void Con(int p[],int m);
            int trun (int a[], int m, int flag);
    protected:
    private:
};


#endif // PROJECT_H
