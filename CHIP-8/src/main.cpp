#include "pch.h"

#include <stdio.h>
#include <iostream>
#include "chip8.h"

bool sld_init(CHIP8::CHIP8 *chip)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Unable to Init SDL: %s", SDL_GetError());
        return false;
    }

    if(!chip->window.CreateWindow())
    {
        return false;
    }
    if(!chip->window.CreateRenderer())
    {
        return false;
    }
    SDL_Log("Initialized SDL");
    return true;
}

int main(int argc, char **argv)
{
    // Init SDL
    CHIP8::CHIP8 chip = CHIP8::CHIP8();

    if(!sld_init(&chip))
    {
        exit(EXIT_FAILURE);
    }

    chip.window.ClearScreen();

    chip.Run();

    SDL_Quit();
    exit(EXIT_SUCCESS);
}