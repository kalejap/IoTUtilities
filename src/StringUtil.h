/*
  StringUtil.cpp - String utilities for IoT projects.
  
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

#ifndef StringUtil_h
#define StringUtil_h

#include <WString.h>
#include <TimeLib.h>
#include <Print.h>

//#define FLASH_MEM(A) reinterpret_cast<__FlashStringHelper *>((char*)A)

namespace StringUtil
{
    struct UnitData
    {
        const __FlashStringHelper * pgm_unit_name;
        const float factor;
    };

    void format(String& str, int number, int digits = 2);
    
    void formatTime(String& str, const time_t& t);

    void formatDate(String& str, const time_t& t);
    void formatDate(String& str, int day, int month, int year);

    void formatValue(String& str, float value,
                     const UnitData pgm_units[],
                     size_t count, int digit = 2);

    void printTime(Print& pr, const time_t& t);
    void printDate(Print& pr, const time_t& t);
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, const String& value, bool isFirst = false);
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, double value, int digits = 2, bool isFirst = false);
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, int value, bool isFirst = false);
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, unsigned int value, bool isFirst = false);
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, long value, bool isFirst = false);
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, unsigned long value, bool isFirst = false);
    
}

#endif // StringUtil_h
