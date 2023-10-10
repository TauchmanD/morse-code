#include "mbed.h"
#include <string>

#define BLINKING_RATE     500ms
#define UNIT_DURATION     132ms


void display_morse(string message, DigitalOut led){
    for(int i = 0; i<message.length(); i++){
            if (message[i] == '.'){
                led=!led;
                ThisThread::sleep_for(UNIT_DURATION);
                led=!led;
            }
            else if (message[i] == '-'){
                led=!led;
                ThisThread::sleep_for(3*UNIT_DURATION);
                led=!led;
            }
            else if(message[i] == '/'){
                ThisThread::sleep_for(3*UNIT_DURATION);
            }
            else{
                ThisThread::sleep_for(3*UNIT_DURATION);
            }
            ThisThread::sleep_for(UNIT_DURATION);
        }
        ThisThread::sleep_for(8*UNIT_DURATION);
}

string encode_morse(string raw_input){
    for (auto& x : raw_input) { 
        x = tolower(x); 
    } 
    string message = "";
    for(int i = 0; i < raw_input.length(); ++i){
        switch(raw_input[i]){
            case 'a':
                message.append(".-");
                break;
            case 'b':
                message.append("-...");
                break;
            case 'c':
                message.append("-.-.");
                break;
            case 'd':
                message.append("-..");
                break;
            case 'e':
                message.append(".");
                break;
            case 'f':
                message.append("..-.");
                break;
            case 'g':
                message.append("--.");
                break;
            case 'h':
                message.append("....");
                break;
            case 'i':
                message.append("..");
                break;
            case 'j':
                message.append(".---");
                break;
            case 'k':
                message.append("-.-");
                break;
            case 'l':
                message.append(".-..");
                break;
            case 'm':
                message.append("--");
                break;
            case 'n':
                message.append("-.");
                break;
            case 'o':
                message.append("---");
                break;
            case 'p':
                message.append(".--.");
                break;
            case 'q':
                message.append("--.-");
                break;
            case 'r':
                message.append(".-.");
                break;
            case 's':
                message.append("...");
                break;
            case 't':
                message.append("-");
                break;
            case 'u':
                message.append("..-");
                break;
            case 'v':
                message.append("...-");
                break;
            case 'w':
                message.append(".--");
                break;
            case 'x':
                message.append("-..-");
                break;
            case 'y':
                message.append("-.--");
                break;
            case 'z':
                message.append("--..");
                break;
            case ' ':
                message.append("/");
                break;
        }
        message.append(" ");
    }
    return message;
}