#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Function to check if a sequence is valid
bool isValid(const vector<int>& numeros, bool allowRemoval = false) {
    bool fixed = false;  // Flag to track if we've removed one element
    for (int i = 1; i < numeros.size(); i++) {
        if (abs(numeros[i] - numeros[i - 1]) > 3 || (numeros[i] < numeros[i - 1] && !allowRemoval)) {
            if (allowRemoval && !fixed) {
                fixed = true;  // Allow removal of one bad level
            } else {
                return false;  // Invalid sequence
            }
        }
    }
    return true;
}

int main() {
    string linha;
    int safe = 0;

    while (getline(cin, linha)) {
        istringstream aux(linha);
        int numero;
        vector<int> numeros;

        // Read all numbers into the vector
        while (aux >> numero) {
            numeros.push_back(numero);
        }

        // If the sequence is already valid without removing anything, it's safe
        if (isValid(numeros)) {
            safe++;
            continue;
        }

        // Try to remove one bad level and check if the sequence becomes valid
        bool isSafe = false;
        for (int i = 0; i < numeros.size(); i++) {
            vector<int> newSeq = numeros;
            newSeq.erase(newSeq.begin() + i);  // Remove the ith element
            if (isValid(newSeq, true)) {  // Check if the sequence is valid after removal
                isSafe = true;
                break;
            }
        }

        if (isSafe) {
            safe++;
        }
    }

    cout << safe << "\n";
    return 0;
}