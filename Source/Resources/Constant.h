#ifndef CONSTANT_H_
#define CONSTANT_H_

#ifndef NULL
#define NULL ((void*) 0)
#endif

#ifndef UINT
#define UINT
typedef unsigned int uint;
#endif

namespace bammm
{
	enum AllianceType
	{
		enemy = -1, neutral = 0, ally = 1
	};
}

#endif
