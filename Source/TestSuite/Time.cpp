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
 * Time cpp file.
 *
 */

#include "Time.h"

namespace bammm
{
	namespace
	{
		const unsigned int uSecondsPerSecond = 1000000;
	}

	Time::Time()
	{
		_seconds = 0;
		_uSeconds = 0;
	}

	Time::Time(unsigned int seconds, unsigned int uSeconds)
	{
		_seconds = seconds;
		_uSeconds = uSeconds;
	}

	Time::~Time()
	{
	}

	unsigned int Time::getSeconds() const
	{
		return _seconds;
	}

	unsigned int Time::getUSeconds() const
	{
		return _uSeconds;
	}

	Time Time::current()
	{
		struct timeval timeValue;
		gettimeofday(&timeValue, 0);

		return Time(timeValue.tv_sec, timeValue.tv_usec);
	}

	Time Time::operator+(const Time& time) const
	{
		unsigned int seconds = getSeconds() + time.getSeconds();
		unsigned int uSeconds = getUSeconds() + time.getUSeconds();

		if (uSeconds > uSecondsPerSecond)
		{
			++seconds;
			uSeconds -= uSecondsPerSecond;
		}

		return Time(seconds, uSeconds);
	}

	Time Time::operator-(const Time& time) const
	{
		if (time.getSeconds() > getSeconds()
				|| (time.getSeconds() == getSeconds()
						&& time.getUSeconds() > getUSeconds()))
			return Time();

		unsigned int seconds = getSeconds() - time.getSeconds();
		unsigned int uSeconds;

		if (time.getUSeconds() > getUSeconds())
		{
			--seconds;
			uSeconds = uSecondsPerSecond - (time.getUSeconds() - getUSeconds());
		}
		else
		{
			uSeconds = getUSeconds() - time.getUSeconds();
		}

		return Time(seconds, uSeconds);
	}
}
