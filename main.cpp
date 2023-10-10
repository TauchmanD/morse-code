#include "mbed.h"
#include <algorithm>
#include <string>
#include "morse.h"

//Made with <3 by Denis Tauchman, Jan Sodomka, Martin Šimon, Jiří Šeps

void init(DigitalOut led){
    led = 0;
}
void exit(DigitalOut led){
    led = 0;
}


int main()
{
    string message = encode_morse("sos");
    DigitalOut led(LED1);

    //init func
    init(led);

    //Main code
    while (true) {
        display_morse(message, led);
    }

    //exit func
    exit(led);
}


