#include <stdio.h>
#include <cs50.h>

int main(void)  {

/*---Retreiving card number --*/
    long long cc_number = 0;
    do {
        cc_number = get_long_long("Credit Card Number: ");
    }
    while(cc_number < 0);

/*--Testing for a valid number of digits: 13, 15 or 16--*/
    int count = 0;
    long long digits = cc_number;
    while(digits > 0) {
        digits = digits/10;
        count++;
    }
    if(count != 13 && count != 15 && count != 16) {
        printf("INVALID\n");
    }

/*--Turning each digit in the CC Number into a variable | preserving digits in originalnumber--*/
    int number[count];
    for(int i=0; i < count; i++){
        number[i] = cc_number%10;
        cc_number = cc_number/10;
    }

    int originalnumber[count];
    for(int i=0; i < count; i++){
        originalnumber[i] = number[i];
    }

/*--Selecting every other digit to be multiplied (starting at the last digit) and multiplying those numbers by two--*/
    if(count%2 == 0) {
        for (int i=0; i < count; i+=2){
            number[i] = number[i] * 2;
        }
    }

/*--Selecting every other digit (odd number)--*/
    else if (count%2 != 0) {
        for(int i=1; i < count; i+=2) {
            number[i] = number[i] * 2;
        }
    }

/*--Adding digits of the products with digits of unmultiplied numbers--*/
    int temp;
    int mid = 0;
    for (int i = 0; i < count; i++) {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        mid = mid + temp;
    }

/*--Checking that the numerical output could represent a valid card--*/
    if(mid % 10 != 0) {
        printf("INVALID\n");
    }

/*--Checking for card type by testing length of card number and first digit(s)--*/
    else if(mid % 10 == 0) {
        if(count == 13 && originalnumber[12] == 4) {
            printf ("VISA\n");
        }
        else if((count == 16) && (originalnumber[15] == 4)){
            printf ("VISA\n");
        }
        else if((count == 16) && (originalnumber[15] == 5) && (originalnumber[14] == 1 | originalnumber[14] == 2 | originalnumber[14] == 3 | originalnumber[14] == 4 | originalnumber[14] == 5)) {
            printf ("MASTERCARD\n");
        }
        else if((count == 15) && (originalnumber[14] == 3) && (originalnumber[13] == 4 | originalnumber[13] == 7)) {
            printf ("AMEX\n");
        }
        else {
            printf("INVALID\n");
        }
    }
}
