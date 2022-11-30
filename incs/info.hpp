#ifndef INFO_HPP
# define INFO_HPP

# include "../libs/raylib/src/raylib.h"
# include "button.hpp"
# include "camera.hpp"
# include "instruction.hpp"
# include <vector>

# ifndef SIZE_FACTOR
#  define SIZE_FACTOR 8
# endif

using namespace std;

typedef enum _ScreenSize {
	screenWidth		= 192*SIZE_FACTOR,
	screenHeight	= 108*SIZE_FACTOR
}	ScreenSize;

typedef struct	_Memory {
	unsigned int	address;
	unsigned int	value;
}	Memory;

class Info {
	public:
		Camera2D				camera;
		Button					button;
		vector<Instruction>		instructions;
		unsigned int			registerValues[32];
		vector<Memory>			memoryValues;
		vector<unsigned int>	st;
		
		// TODO: add pipeline registers to info

		Info(void);
		Info(const char *textSegment, const char *dataSegment);
		~Info(void);
};

#endif