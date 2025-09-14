/*
  Timer.h - Simple timer to check elapsed time
  
 MIT License

Copyright (c) 2021 Peter Kaleja

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Arduino.h>

#pragma once

/**
@brief Simple timer class
*/
class Timer
{
public:
    /**
     * @brief Constructor.
     * @param defaultTimeSpan Default time span in milliseconds to be tested.
     */
    Timer(unsigned long defaultTimeSpan);

    /**
     * @brief This should be called to test if specified time span has elapsed
     * since the last restart. Function returns false if the time span has not
     * elapsed yet. Function returns true if the time span elapsed and timer is
     * restarted.
     * @param timeSpan - Time span in milliseconds to be checked. If zero then
     * default time span (used in constructor) will be used.
     * @return true when specified time span has elapsed, false otherwise
     */
    bool elapsed(unsigned long timeSpan = 0);
    
    /**
     * @brief Query last update time
     * @return last update time
     */
    unsigned long lastUpdateTime() const
    {
        return m_lastUpdateTime;
    }

    /**
     * @brief Restart the timer
     */
    void restart()
    {
        m_lastUpdateTime = millis();
    }

    /**
     * @brief Set default time span.
     * @param defaultTimeSpan - default time span milliseconds to set
     * (it must be a non-zero value)
     */
    void setDefaultTimeSpan(unsigned long defaultTimeSpan)
    {
        m_defaultTimeSpan = defaultTimeSpan ? defaultTimeSpan : 1;
    }

private:
    unsigned long m_lastUpdateTime;
    unsigned long m_defaultTimeSpan;
};
