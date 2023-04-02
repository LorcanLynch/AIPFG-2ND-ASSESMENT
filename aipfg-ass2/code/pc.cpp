#include "pc.hpp"
#include "sprite.hpp"
#include "game-manager.hpp"

#include <string>

namespace aipfg
{
    

    PC::PC(GameManager& gm, Sprite& sprite, const std::string& name)
        : Sprite{ sprite }, name_{ name }, gm_{ gm }
{
  gm_.pc_ = this;
}
    
void PC::update()
{
  animation_on_ = false;
 
  if (!gm_.text_box_)
  {
    if (IsKeyDown(KEY_DOWN))
    {
      posn_.y += speed_ * GetFrameTime();
      set_state("down");
    }
    if (IsKeyDown(KEY_UP))
    {
      posn_.y -= speed_ * GetFrameTime();
      set_state("up");
    }
    if (IsKeyDown(KEY_LEFT))
    {
      posn_.x -= speed_ * GetFrameTime();
      set_state("left");
    }
    if (IsKeyDown(KEY_RIGHT))
    {
      posn_.x += speed_ * GetFrameTime();
      set_state("right");
    }
    if (IsKeyDown(KEY_SPACE))
    {
        gm_.ChangeScene(1);
       
       

    }
  }
 
  Sprite::update();
;
}

void PC::draw() { Sprite::draw();  }

} // namespace aipfg
