/**
 * @file time.h
 * @class Time
 * @brief Contains all functions related to time to be used by TestSuite for recording start, end, and duration time values.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#ifndef TIME_H_
#define TIME_H_

#include <sys/time.h>
#include <ostream>

namespace bammm
{
    class Time
    {
        public:
            Time();
            Time(unsigned int sec, unsigned int usec);
            virtual ~Time();
            unsigned int getSeconds() const;
            unsigned int getUseconds() const;
            static Time current();
            Time operator+(const Time& time) const;
            Time operator-(const Time& time) const;

        private:
            unsigned int _sec;
            unsigned int _usec;
    };

    /**
     * std::basic_ostream<charT, traits>& operator<<()
     * Operator for outputing a Time object to a stream.
     *
     * @param os The output stream.
     * @param time The time object to be output.
     * @return template<typename charT, typename traits>
     */
    template<typename charT, typename traits>
    std::basic_ostream<charT, traits>& operator<<(
            std::basic_ostream<charT, traits>& os, const Time& time)
    {
        int old_fill(os.fill());
        int old_width(os.width());

        os << time.getSeconds() << '.';
        os.fill('0');
        os.width(6);
        os << time.getUseconds();

        os.fill(old_fill);
        os.width(old_width);

        return os;
    }
}

#endif /* TIME_H_ */
