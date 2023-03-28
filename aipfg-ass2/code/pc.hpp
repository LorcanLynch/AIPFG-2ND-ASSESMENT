#ifndef _PC_HPP_
#define _PC_HPP_

#include "sprite.hpp"
#include "game-manager.hpp"
#include <string>

namespace aipfg
{

class PC : public Sprite
{
public:
  PC(GameManager&, Sprite&, const std::string&);

  void update();
  void draw();
  

  std::string name_;

  float speed_{ 120.0f };
  GameManager& gm_;
};

} // namespace aipfg

#endif // _PC_HPP_
