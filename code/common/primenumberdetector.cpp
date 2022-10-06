// Author(s) : Adrian Barreira Romero, Yann Merk

#include "primenumberdetector.h"

bool PrimeNumberDetector::isPrime(uint64_t number) {
    // Corner case
    if (number <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < sqrt(number); i++)
        if (number % i == 0)
            return false;

    return true;
}

PrimeNumberDetectorMultiThread::PrimeNumberDetectorMultiThread(size_t nbThreads) {
    // TODO
}

bool PrimeNumberDetectorMultiThread::isPrime(uint64_t number) {
    // TODO
    return false;
}
