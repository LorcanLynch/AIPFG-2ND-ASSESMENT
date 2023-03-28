#ifndef _CurrentScene_HPP_
#define _CurrentScene_HPP_

#include "raylib-tileson.h"
#include "raylib-cpp.hpp"
namespace aipfg
{


	class CurrentMap
	{
	public:
		CurrentMap(Map);
		Map map__;
		void ChangeMap(const char*);
		void DrawMap_();
		void unloadMap();
		
		
	};

} // namespace aipfg

#endif // !1


