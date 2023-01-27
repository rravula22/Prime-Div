#include <stdbool.h>

bool checkIfPrime(int t) {
    for(int i = 2; i <= t/2; i++) {
        if(t % i == 0) {
            return false;
        }
    } 
    return true;
}
