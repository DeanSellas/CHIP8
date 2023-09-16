/**
 * @file window.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pch.h"

namespace CHIP8
{

    class Window
    {
    private:
        uint32_t m_windowHeight, m_windowWidth;
        uint32_t m_scaleFactor;
    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

        Window(uint32_t w = 64, uint32_t h = 32, uint32_t sf = 20)
        {
            m_scaleFactor = sf;
            m_windowWidth = w;
            m_windowHeight = h;
            window = nullptr;
        };
        ~Window()
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
        }

        bool CreateWindow();
        bool CreateRenderer();

        void ClearScreen();
        void SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        uint32_t GetWindowWidth() { return m_windowWidth; }
        uint32_t GetWindowHeight() { return m_windowHeight; }
        uint32_t GetScaleFactor() { return m_scaleFactor; }
    };
} // namespace CHIP8
