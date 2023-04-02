
#ifndef _SCENE_HPP_
#define _SCENE_HPP_


#include "sprite.hpp"
#include "raylib.h"
#include "raylib-tileson.h"

namespace aipfg
{
	class scene
	{
	public:

		scene(Map, std::vector<Sprite*>);
		std::vector<Sprite*> all_game_chars{};
		Map map;

		void draw();
		void unload();



	};
}//namespace aipfg
#endif //_SCENE_HPP_
