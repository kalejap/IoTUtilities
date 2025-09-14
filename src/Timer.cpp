/*
  Timer.cpp - Simple timer to check elapsed time
  
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
#include "Timer.h"

Timer::Timer(unsigned long defaultTimeSpan) :
    m_lastUpdateTime(0),
    m_defaultTimeSpan(defaultTimeSpan)
{
}

bool Timer::elapsed(unsigned long timeSpan)
{
    unsigned long nowMillis = millis();
    unsigned long timeElapsed = nowMillis - m_lastUpdateTime;
    if (timeElapsed < (timeSpan ? timeSpan : m_defaultTimeSpan))
        return false;

    m_lastUpdateTime = nowMillis;
    return true;
}
