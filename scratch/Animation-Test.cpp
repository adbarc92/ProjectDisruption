#include "Animation-Test.h"

void Game::start(){}

void Animation_Template::add_sprite(std::string name, int ms){}

int Animation_Template::get_time_length(){}

void Animation::draw(int x, int y, long timeStamp){}

const std::string& Animation::get_current_sprite(long timeStamp){}

void Animation::start(long timeStamp){}

void Display::load_assets(){}

void Display::load_images(){}

void Display::load_spritesheets(){}

void Display::load_animation_templates(){}

void Display::draw_sprite(const std::string& spriteName, int x, int y){}

void Display::draw_animation(Animation& animation, int x, int y){}

void Display::create_screen(int width, int height){}

long Display::get_current_timestamp(){}

void Display::load_image(const std::string& url, const std::string& imageName){}

void Display::load_spritesheet(const std::string& imageName, const std::string& spriteName, int sprite_width, int sprite_height){}

void Display::load_animation_template(const std::string& animationName, std::vector<std::pair<std::string, int>> sprites){}