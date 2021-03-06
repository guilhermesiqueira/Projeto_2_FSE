#include <monitoring.h>
#include <menu.h>
#include <client.h>
#include <stdio.h>
#include <csv.h>

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
    if (code == 21)
    {
        _input.abr1 = _input.abr1 ? 0 : 1;
    }
    if (code == 22)
    {
        _input.abr2 = _input.abr2 ? 0 : 1;
    }
    if (code == 26)
    {
        _input.abr3 = _input.abr3 ? 0 : 1;
    }
    if (code == 27)
    {
        _input.abr4 = _input.abr4 ? 0 : 1;
    }
    if (code == 28)
    {
        _input.abr5 = _input.abr5 ? 0 : 1;
    }
    if (code == 29)
    {
        _input.abr6 = _input.abr6 ? 0 : 1;
    }
    if (code == 6)
    {
        _input.pres1 = _input.pres1 ? 0 : 1;
    }
    if (code == 25)
    {
        _input.pres2 = _input.pres2 ? 0 : 1;
    }

    if ((_input.abr1 || _input.abr2 || _input.abr3 || _input.abr4 || _input.abr5 || _input.abr6 || _input.pres1 || _input.pres2) && _output.alarm)
    {
       print_alarm(1);
    } else {
        print_alarm(0);
    }
    

    print_entry(_input);
}

void set_output(int code)
{
    Output output = _output;
    if (code == 1)
    {
        _output.lamp1 = _output.lamp1 == 1 ? 0 : 1;
        Data data;
        char *command = "LAMP1";
        data.command = command;
        data.state = _output.lamp1;
        write_data(data);
    }
    if (code == 2)
    {
        _output.lamp2 = _output.lamp2 == 1 ? 0 : 1;
        Data data;
        char *command = "LAMP2";
        data.command = command;
        data.state = _output.lamp2;
        write_data(data);
    }
    if (code == 3)
    {
        _output.lamp3 = _output.lamp3 == 1 ? 0 : 1;
        Data data;
        char *command = "LAMP3";
        data.command = command;
        data.state = _output.lamp3;
        write_data(data);
    }
    if (code == 4)
    {
        _output.lamp4 = _output.lamp4 == 1 ? 0 : 1;
        Data data;
        char *command = "LAMP4";
        data.command = command;
        data.state = _output.lamp4;
        write_data(data);
    }
    if (code == 5)
    {
        _output.ac1 = _output.ac1 == 1 ? 0 : 1;
        Data data;
        char *command = "AC1";
        data.command = command;
        data.state = _output.ac1;
        write_data(data);
    }
    if (code == 6)
    {
        _output.ac2 = _output.ac2 == 1 ? 0 : 1;
        Data data;
        char *command = "AC2";
        data.command = command;
        data.state = _output.ac2;
        write_data(data);
    }
    if (code == 7)
    {
        _output.alarm = _output.alarm == 1 ? 0 : 1;
        Data data;
        char *command = "ALARM";
        data.command = command;
        data.state = _output.alarm;
        write_data(data);
        if (_output.alarm == 0)
        {
            print_alarm(0);
        }
    }

    print_data(_output);
    int port = -1;

    if (code == 1)
    {
        port = LAMP1;
    }
    if (code == 2)
    {
        port = LAMP2;
    }
    if (code == 3)
    {
        port = LAMP3;
    }
    if (code == 4)
    {
        port = LAMP4;
    }
    if (code == 5)
    {
        port = AC1;
    }
    if (code == 6)
    {
        port = AC2;
    }

    if (port != -1)
    {
        char response[16];
        char res;
        request_GPIO_toggle(port, response);
        sscanf(response, "%c", &res);

        if (res != 'G')
        {
            _output = output;
            print_data(_output);
        }
    }
}