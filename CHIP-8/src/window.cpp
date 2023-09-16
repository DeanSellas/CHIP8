#include "window.h"

namespace CHIP8
{
    bool Window::CreateWindow()
    {
        this->window = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->GetWindowWidth() * this->GetScaleFactor(), this->GetWindowHeight() * this->GetScaleFactor(), 0);
        if(!this->window)
        {
            SDL_Log("Failed to Create Window: %s", SDL_GetError());
            return false;
        }
        return true;
    }

    bool Window::CreateRenderer()
    {
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        if(!this->renderer)
        {
            SDL_Log("Failed to Create Renderer: %s", SDL_GetError());
            return false;
        }
        return true;
    }

    void Window::ClearScreen()
    {
        SDL_RenderClear(this->renderer);
    }
    void Window::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
    }

} // namespace CHIP8