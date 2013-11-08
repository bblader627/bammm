/**
 * @file debugchannel.h
 * @class DebugChannel
 * @brief Creates a channel for sending debug messages.
 * The output stream can be configured to output to the terminal, a file, or any other stream accepting output.
 * To use, a user creates a new DebugChannel object with a specific channel name.
 * They can then write to the stream using the << operator as normal.
 * @author: Bradley Crusco
 * @version 1.0 10/13/13
 */

#ifndef DEBUGCHANNEL_H_
#define DEBUGCHANNEL_H_

#include <iostream>
#include <sstream>

using namespace std;

class DebugChannel: public ostream
{
	private:
		/**
		 * @class DebugChannelBuffer
		 * @brief Derives from stringbuf, used as the buffer for the DebugChannel
		 * @author: Bradley Crusco
		 * @version 1.0 10/13/13
		 */
		class DebugChannelBuffer: public stringbuf
		{
			private:
				string _channelName;

			public:
				/**
				 * DebugChannelBuffer(const string& channelName)
				 * @brief Constructor for DebugChannelBuffer, takes an argument to specify channel name.
				 * @param channelName The name of the debug channel.
				 */
				DebugChannelBuffer(const string& channelName) :
						_channelName(channelName)
				{
				}
				/**
				 * ~DebugChannelBuffer()
				 * @brief Destructor for DebugChannelBuffer. Calls pubsync().
				 */
				~DebugChannelBuffer()
				{
					pubsync();
				}
				/**
				 * sync()
				 * @brief Method overrides stringbuf's implementation of sync.
				 * @return int
				 */
				int sync()
				{
					cout << _channelName << ": " << str();
					str("");
					return !cout;
				}
		};

	public:
		/**
		 * DebugChannel(const string& channelName)
		 * @brief Constructor for DebugChannel. Takes in a channelName and constructs an ostream object using a DebugChannelBuffer.
		 * @param channelName The name of the channel to pass to the DebugChannelBuffer constructor.
		 */
		DebugChannel(const string& channelName) :
				ostream(new DebugChannelBuffer(channelName))
		{
		}
		/**
		 * ~DebugChannel()
		 * @brief Destructor for DebugChannel, deletes the return value of rdbuf().
		 */
		~DebugChannel()
		{
			delete rdbuf();
		}
};

#endif /* DEBUGCHANNEL_H_ */
