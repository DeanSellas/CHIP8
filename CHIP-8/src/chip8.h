/**
 * @file chip8.h
 * @author Dean Sellas (dean@deansellas.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "window.h"

namespace CHIP8
{
    
    class CHIP8
    {
    private:
        const uint8_t m_clockDelay = 16; 
        enum State
        {
            QUIT,
            RUN,
            PAUSE
        };
        State m_state;

    public:
        Window window;

        CHIP8()
        {
            window = Window();
            m_state = RUN;
        }
        ~CHIP8()
        {
            window.~Window();
        }

        bool Run();
        void PollEvents();
        void ClearScreen();
        
        uint8_t GetClock() { return m_clockDelay; }
        
        void SetState(State s) { this->m_state = s; }
        State GetState() { return m_state; }
    };
} // namespace CHIP8
