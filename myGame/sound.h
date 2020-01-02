#ifndef GAMESOUND__H
#define GAMESOUND__H
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class GameSound
{
private:
    Mix_Music *music;
    int volume;
    int currentSound;

    int audioRate;
    int audioChannels;
    int audioBuffers;
    // std::vector<Mix_Chunk *> sounds;
    // std::vector<int> channels;

public:
    void getKnightHitSound();
    GameSound();
    ~GameSound();
    void startMusic();
    void stopMusic();     // stop all sounds
    void toggleMusic();   // toggle music on/off
    void operator[](int); // play the indexed sound

    //Rule of three
    GameSound(const GameSound &) = delete;
    GameSound &operator=(const GameSound&) = delete;
    
    std::vector<Mix_Chunk *> sounds;
    std::vector<int> channels;
};
#endif