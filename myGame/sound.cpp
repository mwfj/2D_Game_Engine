#include "sound.h"
#include <iostream>
#include <ctime>
#include <string>


GameSound::GameSound():
    music(NULL),
    volume(SDL_MIX_MAXVOLUME/5),
    currentSound(-1),
    audioRate(22050),
    audioChannels(2),
    audioBuffers(4096),
    sounds(),
    channels()
{
    if (Mix_OpenAudio(audioRate, MIX_DEFAULT_FORMAT, audioChannels,
                      audioBuffers)){
        throw std::string("Unable to open audio!");
    }
    music = Mix_LoadMUS("sound/Blackmoor Tides Loop.wav");
    if(!music){
        throw std::string("Couldn't load the background music");
    }
    startMusic();

    sounds.push_back(Mix_LoadWAV("sound/knight_hit_sound.wav"));
    sounds.push_back(Mix_LoadWAV("sound/deathKnight.wav"));
    sounds.push_back(Mix_LoadWAV("sound/deathZombie.wav"));
    for (unsigned int i = 0; i < sounds.size(); ++i){
        channels.push_back(i);
    }
    std::cout << "Music and Sound is loaded" << std::endl;
}

GameSound::~GameSound()
{
    std::cout<<"Clean up sound..."<<std::endl;
    std::clock_t start = std::clock();
    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    std::clock_t duration = std::clock() - start;
    std::cout << "Clean up took " << duration << " ticks\n";
}

void GameSound::operator[](int index)
{
    if (currentSound >= 0)
        Mix_HaltChannel(currentSound);
    currentSound = index;
    Mix_VolumeChunk(sounds[index], volume+10);
    channels[index] =
        Mix_PlayChannel(-1, sounds[index], 0);
}

void GameSound::startMusic(){
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music,-1);
}

void GameSound::stopMusic(){
    Mix_HaltMusic();
    Mix_FreeMusic(music);
}

void GameSound::toggleMusic(){
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
    else
    {
        Mix_PauseMusic();
    }
}