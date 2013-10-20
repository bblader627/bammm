/**
 * @file time.cpp
 * @class Time
 * @brief Contains all functions related to time to be used by TestSuite for recording start, end, and duration time values.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#include "time.h"

using namespace std;

namespace bammm
{
    namespace
    {
        const unsigned int uSecondsPerSecond = 1000000;
    }

    /**
     * Time::Time()
     * Default constructor for Time object. Sets _sec and _usec to 0.
     */
    Time::Time()
    {
        _sec = 0;
        _usec = 0;
    }

    /**
     * Time::Time()
     * Constructor for Time object given two inputs for seconds and useconds.
     *
     * @param sec Seconds for the time.
     * @param usec Useconds for the time.
     */
    Time::Time(unsigned int sec, unsigned int usec)
    {
        _sec = sec;
        _usec = usec;
    }

    /**
     * Time::~Time()
     * Default destructor for Time object.
     */
    Time::~Time()
    {
    }

    /**
     * Time::getSeconds() const
     * Returns _sec.
     *
     * @return unsigned int
     */
    unsigned int Time::getSeconds() const
    {
        return _sec;
    }

    /**
     * Time::getUseconds() const
     * Returns _usec.
     *
     * @return unsigned int
     */
    unsigned int Time::getUseconds() const
    {
        return _usec;
    }

    /**
     * Time::current()
     * Returns the current time.
     *
     * @return Time
     */
    Time Time::current()
    {
        struct timeval timeValue;
        gettimeofday(&timeValue, 0);
        return Time(timeValue.tv_sec, timeValue.tv_usec);
    }

    /**
     * Time::operator+(const Time& time) const
     * Addition operator for two Time objects.
     *
     * @param time Time object to be added.
     * @return Time
     */
    Time Time::operator+(const Time& time) const
    {
        unsigned int sec = getSeconds() + time.getSeconds();
        unsigned int usec = getUseconds() + time.getUseconds();

        if (usec > uSecondsPerSecond)
        {
            ++sec;
            usec -= uSecondsPerSecond;
        }
        return Time(sec, usec);
    }

    /**
     * Time::operator-(const Time& time) const
     * Subtraction operator for two time objects.
     *
     * @param time Time object to be subtracted.
     * @return Time
     */
    Time Time::operator-(const Time& time) const
    {
        if (time.getSeconds() > getSeconds()
                || (time.getSeconds() == getSeconds()
                        && time.getUseconds() > getUseconds()))
            return Time();

        unsigned int sec = getSeconds() - time.getSeconds();
        unsigned int usec;

        if (time.getUseconds() > getUseconds())
        {
            --sec;
            usec = uSecondsPerSecond - (time.getUseconds() - getUseconds());
        }
        else
        {
            usec = getUseconds() - time.getUseconds();
        }
        return Time(sec, usec);
    }
}
