

#include "sprite.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "game-manager.hpp"
#include "openai-helper.hpp"
#include "CurrentScene.hpp"
#include "raylib-tileson.h"
#include "raylib-cpp.hpp"
#include <string>     // std::string
#include <vector>     // std::vector
#include <numeric>    // std::iota
#include <iostream>   // std::cout

namespace aipfg
{
	CurrentMap::CurrentMap(Map map_) :map__{ map_ } {}
	void CurrentMap::ChangeMap(const char* MapLoc)
	{
		map__ = LoadTiled(MapLoc);
	}

	void CurrentMap::DrawMap_() { DrawTiled(map__, 0, 0, WHITE); }
	void CurrentMap::unloadMap() { UnloadMap(map__); }
	/*public:
		CurrentMap(Map map_) :map__{map_}{}
		
		Map map__;

		void ChangeMap(const char* MapLoc)
		{
			map__ = LoadTiled(MapLoc);
		}
		void DrawMap_() { DrawTiled(map__, 0, 0, WHITE); }
		void unloadMap() { UnloadMap(map__); }
	private:

		
	};*/
}