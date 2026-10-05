/*
* <filename>
*
* decription: TODO: Provide a brief description of the program
*
* author: <Full name> <your.email@gmail.com>
*/
#include <stdio.h>

int main(void)
{
    printf("=== Loan Amortization Calculator ===\n");

    // TODO: You will need a way of storing user input
    double principal; 
    double annual_rate;
    double payment; 
    double monthly_rate; 
    double interest; 
    double principal_paid; 
    double balance; 
    double actual_payment; 
    int month = 1;
    // TODO: Print a prompt asking for user input
    // TODO: Read the user input
    // You can do this multiple times btw
    printf("Enter principal amount ($) -> ");
    scanf("%lf", &principal); 
    printf("Enter annual interest rate (%) -> "); 
    scanf("%lf", &annual_rate);
    printf("Enter monthly payment ($) -> ");
    scanf("%lf", &payment);
    // Is the annual rate the same as a monthly rate?
    monthly_rate = annual_rate / 12.0 / 100.0;
    // TODO: Calculate the portion of payment that belongs to the interest
    interest = principal * monthly_rate;
    // Should the monthly payment be less than or equal to the interest portion?
    if (payment <= interest) { 
        printf("Error: Monthly payment of %.2f is too low!\n", payment);
        printf("Minimum monthly payment must be greater than %.2f to cover interest\n", interest);
        return 0; }
    // Now calculate the interest portion, monthly payment and the principal portion
    // that will be made by the user until the whole loan is amortized
    // Remember, you do not know how many months it will take them to pay the loan, YOU DON'T NEED TO!
    balance = principal;
    while (balance > 0.0) {
        interest = balance * monthly_rate;
        actual_payment = payment; 
        if (actual_payment > balance + interest) { actual_payment = balance + interest;} 
        principal_paid = actual_payment - interest; balance = balance - principal_paid; 
        if (balance < 0.005) 
        { balance = 0.0; } 
        printf("Month -> %d; Payment -> $%.2f; Interest -> $%.2f; " "Principal -> $%.2f;
            Balance -> $%.2f\n", month, actual_payment, interest, principal_paid, balance);
        month++;
    } 
    return 0;
}




