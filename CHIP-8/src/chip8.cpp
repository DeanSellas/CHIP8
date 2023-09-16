/**
 * @file chip8.cpp
 * @author Dean Sellas (dean@deansellas.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "chip8.h"

namespace CHIP8
{
    bool CHIP8::Run()
    {
        while(this->GetState() != QUIT)
        {
            if(this->GetState() == PAUSE)
                continue;
            

            // User Input            
            this->PollEvents();
            // Instructions
            // ...

            //Delay to 60hz/60fps (16.6)
            SDL_Delay(GetClock()); // subtract by actual time elapsed

            SDL_RenderPresent(window.renderer);
        }

        return true;
    }

    void CHIP8::PollEvents()
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    SetState(QUIT);
                    return;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            this->SetState(QUIT);
                            return;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }

    void CHIP8::ClearScreen()
    {
        window.SetDrawColor(0, 0, 0, 0);
        window.ClearScreen();
    }
} // namespace CHIP8