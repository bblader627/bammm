/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * Time header file.
 *
 */

#ifndef TIME_H_
#define TIME_H_

#include <sys/time.h>
#include <ostream>

using namespace std;

namespace bammm
{
	class Time
	{
		private:
			unsigned int _seconds;
			unsigned int _uSeconds;

		public:
			Time();
			Time(unsigned int seconds, unsigned int uSeconds);
			virtual ~Time();

			/**
			 getSeconds
			 @Pre-Condition- No input
			 @Post-Condition- Returns _seconds
			 */
			unsigned int getSeconds() const;

			/**
			 getUSeconds
			 @Pre-Condition- No input
			 @Post-Condition- Returns _uSeconds
			 */
			unsigned int getUSeconds() const;

			/**
			 current
			 @Pre-Condition- No input
			 @Post-Condition- Returns the current Time
			 */
			static Time current();

			/**
			 operator+
			 @Pre-Condition- Takes in const Time& time
			 @Post-Condition- Performs and returns the result of an addition between two Time objects
			 */
			Time operator+(const Time& time) const;

			/**
			 operator-
			 @Pre-Condition- Takes in const Time& time
			 @Post-Condition- Performs and returns the result of a subtraction between two Time objects
			 */
			Time operator-(const Time& time) const;
	};

	/**
	 operator<<
	 @Pre-Condition- Takes in a std::basic_ostream<charT, traits>& and a const Time&
	 @Post-Condition- The given time is passed to the given outStream
	 Note: Was implemented here due to issues compiling otherwise
	 */
	template<typename charT, typename traits>
	std::basic_ostream<charT, traits>& operator<<(
			std::basic_ostream<charT, traits>& outStream, const Time& time)
	{
		int oldFill(outStream.fill());
		int oldwidth(outStream.width());

		outStream << time.getSeconds() << '.';
		outStream.fill('0');
		outStream.width(6);
		outStream << time.getUSeconds();

		outStream.fill(oldFill);
		outStream.width(oldwidth);

		return outStream;
	}
}

#endif
