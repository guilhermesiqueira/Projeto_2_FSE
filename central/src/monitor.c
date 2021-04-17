#include <monitor.h>

Output _output;
Input _input;

void monitor()
{
    _output.lamp1 = 0;
    _output.lamp2 = 0;
    _output.lamp3 = 0;
    _output.lamp4 = 0;
    _output.ac1 = 0;
    _output.ac2 = 0;
    _output.alarm = 0;

    _input.abr1 = 0;
    _input.abr2 = 0;
    _input.abr3 = 0;
    _input.abr4 = 0;
    _input.abr5 = 0;
    _input.abr6 = 0;
    _input.pres1 = 0;
    _input.pres2 = 0;
}

Output get_output()
{
    return _output;
}

Input get_input()
{
    return _input;
}

void set_input(int code)
{
    if (code == 1)
    {
        _input.abr1 = _input.abr1 ? 0 : 1;
    }
    if (code == 2)
    {
        _input.abr2 = _input.abr2 ? 0 : 1;
    }
    if (code == 3)
    {
        _input.abr3 = _input.abr3 ? 0 : 1;
    }
    if (code == 4)
    {
        _input.abr4 = _input.abr4 ? 0 : 1;
    }
    if (code == 5)
    {
        _input.abr5 = _input.abr5 ? 0 : 1;
    }
    if (code == 6)
    {
        _input.abr6 = _input.abr6 ? 0 : 1;
    }
    if (code == 7)
    {
        _input.pres1 = _input.pres1 ? 0 : 1;
    }
    if (code == 8)
    {
        _input.pres2 = _input.pres2 ? 0 : 1;
    }
}