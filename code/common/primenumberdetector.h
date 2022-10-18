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
    /** Number of thread that runs
     *  Initiated with the constructor, read continually by the child threads
    */
    size_t nbThreads;

    /** Has a divider for the number be found by a thread
     *  Always reset to false before runs by the parent thread
     *  Written to true by a child thread when it has found a matching number
     *  Read by all child threads to prematuraly stop the execution if another
     *      thread has already found the solution
     */
    bool hasDividerBeenFound = false;

    /**
     * @brief sets hasDividerBeenFound to true if a divider is found
     * Starts checking at 2+offset, jumps by nbThreads to check all possible
     * numbers accross threads
     * @param number The potential prime number to test
     * @param offset this thread's offset, to spread the work accross threads
     */
    void checkPrimeThreaded(uint64_t number, size_t offset);
};

#endif // PRIMENUMBERDETECTOR_H
