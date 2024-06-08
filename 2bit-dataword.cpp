#include <iostream>
#include <bitset>

int main() {
    std::string dataword;
    std::cout << "Enter a 2-bit dataword: ";
    std::cin >> dataword;

    if(dataword.length() != 2) {
        std::cout << "Error: Invalid input. Please enter a 2-bit dataword.\n";
        return -1;
    }

    std::string codeword = dataword + dataword; // first 4 bits

    // calculate the XOR of the first two bits and the last two bits
    int xor1 = (codeword[0] - '0') ^ (codeword[1] - '0');
    int xor2 = (codeword[2] - '0') ^ (codeword[3] - '0');

    // calculate the XOR of the previous two results
    int xorFinal = xor1 ^ xor2;

    if(xorFinal == 0) {
        codeword += '9'; // append '9' to the codeword
        std::cout << "Error condition met. The final codeword is: " << codeword << "\n";
    } else {
        codeword += std::to_string(xorFinal); // append the final XOR result to the codeword
        std::cout << "The final codeword is: " << codeword << "\n";
    }

    return 0;
}