#ifndef _TRANSITIONPOINT_HPP_
#define _TRANSITIONPOINT_HPP_

#include "sprite.hpp"
#include "game-manager.hpp"
#include "text-box.hpp"
#include "raylib-cpp.hpp"
#include <future>     // std::async
#include <functional> // std::ref
#include <iostream>

namespace aipfg
{

	class transition
	{
	public:
		transition(Vector2, int,int,GameManager&);
		void Update();
		GameManager& gm_;
		Vector2 posn_;
		int sIndex;
		int activeIndex;
	};

} // namespace aipfg

#endif // _NPC_HPP_#pragma once
