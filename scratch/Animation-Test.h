// STL functions all have underscores

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

#define MAX_DISTANCE_PER_FRAME 5 // Should be a percentage of their speed

class Texture;

class Game{
    private:
        bool running;
    public:
        void start(); // Loads and runs
};

struct Sprite{
    std::string imageName;
    int xOffset, yOffset;
    int xSize, ySize;
};

struct Actor{
    int xPos, yPos;
    std::string spriteBase;
    std::string animationState;
    Actor(int x,int y): xPos(x), yPos(y){};
};

class Animation_Template{
    private:
        std::vector<std::pair<const std::string&, int>> sprites; // Might cause problems; first is sprite name, second is duration (ms)
        bool is_loop;
    public:
        void add_sprite(std::string name, int ms);
        int get_time_length(); // Returns the length of all sprites (in ms)
};

class Animation{
    private:
        const Animation_Template* temp;
        long timeStart; // Timestamp for when it started
    public:
        Animation(const Animation_Template*);
        void draw(int x, int y, long timeStamp); // Check if loop, and then if so then get_time_length() and add to timeStart; if timeStamp exceeds timeStart then re-start() the animation
        const std::string& get_current_sprite(long timeStamp);
        void start(long timeStamp); // Sets timeStart to input
};

class Display{
    public:
        void load_assets(){};
        void load_images();
        void load_spritesheets();
        void load_animation_templates();
        void draw_sprite(const std::string& spriteName, int x, int y);
        void draw_animation(Animation& animation, int x, int y);
        void create_screen(int width, int height);
        long get_current_timestamp();
    private:
        std::unordered_map<std::string, std::unique_ptr<Sprite>> sprites; // key, value; contains all sprites
        std::unordered_map<std::string, Texture*> images;
        std::unordered_map<std::string, std::unique_ptr<Animation_Template>> animation_templates;
        void load_image(const std::string& url, const std::string& imageName);
        void load_spritesheet(const std::string& imageName, const std::string& spriteName, int sprite_width, int sprite_height);
        void load_animation_template(const std::string& animationName, std::vector<std::pair<std::string, int>> sprites);
};

// Animation.draw() calls get_current_sprite() then takes that string and calls Display.draw_sprite()