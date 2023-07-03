#include <iostream>
#include <stack>
using namespace std;

#define log(x) cout << x << " ";

int main()
{
    stack<int> tempStack;
    int countDigits = 0;
    int sumVal = 0;
    const int arrCount = 16;
    long long inputCardNum;
    cin >> inputCardNum;

    while (inputCardNum > 0) {
        int digit = inputCardNum % 10;
        inputCardNum /= 10;
        tempStack.push(digit);

        // record size
        countDigits++;
    }

    // check count of digits
    if (countDigits != 16) {
        log("Card number has to be 16 digits!")
        return 0;
    }
    
    // Luhn's Algorithm
    for (int i = 1; i <= arrCount; ++i) {
        // in case of odd index (1, 3, 5, ..)
        if (i % 2 == 1) {
            // multiply by 2
            int checkVal = tempStack.top() * 2;
            if (checkVal > 9) {
                sumVal += checkVal - 10 + 1;
            }
            else {
                sumVal += checkVal;
            }
            
        }
        else {
            sumVal += tempStack.top();
        }

        // pop out top digit from stack
        tempStack.pop();


        log("\ncurrent sumVal is: ");
        log(sumVal);
    }

    // check card validity
    if (sumVal % 10 == 0) {
        log("Card Number is VALID!")
    }
    else {
        log("Card Number in NOT valid!")
    }

    return 0;
}