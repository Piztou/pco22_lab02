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

PrimeNumberDetectorMultiThread::PrimeNumberDetectorMultiThread(size_t nbThreads) : nbThreads(nbThreads) {
    // TODO
}

bool PrimeNumberDetectorMultiThread::isPrime(uint64_t number) {
    // Corner case
    if (number <= 1)
        return false;

    std::vector<PcoThread> threads;

    for(size_t i = 0; i < nbThreads; ++i) {
        threads.push_back(PcoThread(&PrimeNumberDetectorMultiThread::checkPrimeThreaded, this, number, i));
    }

    for(size_t i = 0; i < nbThreads; ++i) {
        threads[i].join();
    }

    return !hasDividerBeenFound;
}

void PrimeNumberDetectorMultiThread::checkPrimeThreaded(uint64_t number, size_t offset) {

    // Check from 2 to n-1
    for (int i = offset + 2; i < sqrt(number); i++)
        if (number % i == 0)
        {
            hasDividerBeenFound = true;
            return;
        }
}
