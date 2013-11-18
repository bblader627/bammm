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
 * DebugChannel header file.
 *
 */

#ifndef DEBUGCHANNEL_H_
#define DEBUGCHANNEL_H_

#include <iostream>
#include <sstream>

using namespace std;

class DebugChannel: public ostream
{
	private:
		class DebugChannelBuffer: public stringbuf
		{
			private:
				string _channelName;

			public:
				DebugChannelBuffer(const string& channelName) :
						_channelName(channelName)
				{
				}

				~DebugChannelBuffer()
				{
					pubsync();
				}

				/**
				 setMeleeWeapon
				 @Pre-Condition- No input
				 @Post-Condition- Overrides stringbuf's implementation of sync.
				 */
				int sync()
				{
					cout << _channelName << ": " << str();
					str("");
					return !cout;
				}
		};

	public:
		DebugChannel(const string& channelName) :
				ostream(new DebugChannelBuffer(channelName))
		{
		}

		~DebugChannel()
		{
			delete rdbuf();
		}
};

#endif
