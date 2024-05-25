#include <stdio.h>

int main() {
    // 6 digit number var for pincode
    int pincode = 123456;

    // 12 digit number var for Aadhaar no.
    long long aadhaar_no = 123456789012;

    // 12 alphanumeric var for debit card serial no.
    char debit_card_serial_no[13] = "AB123CD456EF";

    // 3 digit var for age
    int age = 30;

    // 10 digit var for phone number
    long long phone_number = 9876543210;

    // Print the values
    printf("Pincode: %d\n", pincode);
    printf("Aadhaar No: %lld\n", aadhaar_no);
    printf("Debit Card Serial No: %s\n", debit_card_serial_no);
    printf("Age: %d\n", age);
    printf("Phone Number: %lld\n", phone_number);

    return 0;
}