/*
  StringUtil.h - String utilities for IoT projects.
  
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
#include <math.h>
#include <StringUtil.h>

const char pgm_Hash[] PROGMEM = "#";
const char pgm_jsonPropEnd[] PROGMEM = "\":";

#define PGM_READ_STRPTR pgm_read_dword

namespace StringUtil
{
    // format a number with leading zeros if needed
    void format(String& str, int number, int digits)
    {
        int d = digits, v = 10;
        while (--d > 0)
        {
            if (v > number)
                str += '0';
            v *= 10;
        }
            
        str.concat(number);
        yield();
    }

    void formatTime(String& str, const time_t& t)
    {
        format(str, hour(t));
        str += ':';
        format(str, minute(t));
        str += ':';
        format(str, second(t));
    }

    void formatDate(String& str, const time_t& t)
    {
        formatDate(str, day(t), month(t), year(t));
    }
    
    void formatDate(String& str, int day, int month, int year)
    {
        format(str, day);
        str += '.';
        format(str, month);
        str += '.';
        format(str, year, 4);
    }

    void formatValue(String& str, float value, const UnitData pgm_units[], size_t count, int digit)
    {
        float aValue = fabs(value);
        float factor = 0.0;

        for (size_t i = 0; i < count; i++)
        {
            if (i == count - 1)
            {
                str.replace(String(FPSTR(pgm_Hash)), String(value, digit));
                str.concat(FPSTR(PGM_READ_STRPTR(&(pgm_units[count - 1].pgm_unit_name))));
            }
            else
            {
                factor = pgm_read_float(&(pgm_units[i].factor));
                if (aValue >= factor)
                {
                    str.replace(String(FPSTR(pgm_Hash)), String(value/factor, digit));
                    str.concat(FPSTR(PGM_READ_STRPTR(&(pgm_units[i].pgm_unit_name))));
                    break;
                }
            }
        }
    }
    
    void printTime(Print& pr, const time_t& t)
    {
        String str;
        formatTime(str, t);
        pr.print(str);
    }
    
    void printDate(Print& pr, const time_t& t)
    {
        String str;
        formatDate(str, t);
        pr.print(str);
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, const String& value, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += F("\":\"");
        str += value;
        str += '\"';
        yield();
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, double value, int digits, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += FPSTR(pgm_jsonPropEnd);
        str += String(value, digits);
        yield();
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, int value, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += FPSTR(pgm_jsonPropEnd);
        str.concat(value);
        yield();
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, unsigned int value, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += FPSTR(pgm_jsonPropEnd);
        str.concat(value);
        yield();
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, long value, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += FPSTR(pgm_jsonPropEnd);
        str.concat(value);
        yield();
    }
    
    void addJSONObjProp(String& str, const __FlashStringHelper *propName, unsigned long value, bool isFirst)
    {
        if (!isFirst)
            str += ',';
    
        str += '\"';
        str.concat(propName);
        str += FPSTR(pgm_jsonPropEnd);
        str.concat(value);
        yield();
    }
}