#ifndef PRIMENUMBERDETECTOR_H
#define PRIMENUMBERDETECTOR_H

#include "logging.h"

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <pcosynchro/pcothread.h>

class PrimeNumberDetectorInterface
{
public:
    virtual bool isPrime(uint64_t number) = 0;
};

class PrimeNumberDetector : public PrimeNumberDetectorInterface
{
public:
    bool isPrime(uint64_t /*number*/) override;
};

class PrimeNumberDetectorMultiThread : public PrimeNumberDetectorInterface
{
public:
    PrimeNumberDetectorMultiThread(size_t /*nbThreads*/);

    bool isPrime(uint64_t /*number*/) override;
private:
    size_t nbThreads;

    bool hasDividerBeenFound = false;

    void checkPrimeThreaded(uint64_t number, size_t offset);
};

#endif // PRIMENUMBERDETECTOR_H
