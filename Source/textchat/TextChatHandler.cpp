//
//  TextChatHandler.cpp
//  TheScrambler
//
//  Created by Richard Allen on 24/03/2021.
//  Copyright © 2021 Swn. All rights reserved.
//

#include "TextChatHandler.h"
#include "TextChatHelp.h"

TextChatHandler::TextChatHandler ()
{
    tcHelp = TextChatHelp();
}
TextChatHandler::~TextChatHandler ()
{
    
}

String TextChatHandler::processTextInput(String input)
{
    std::cout << input.toStdString();
    std::cout << "\n\r";
    
    int spacesindexlen = 10;
    int spacesindex[spacesindexlen];
    int spacesindexindex = 0;
    
    for (int index = 0; index < spacesindexlen; index++)
    {
        spacesindex[index] = 0;
    }
    
    input = input.trim();
    std::string inputstring = input.toStdString();
    
    for (int index = 0; index < inputstring.length(); index++)
    {
        if (inputstring[index] == ' ')
        {
            spacesindex[spacesindexindex] = index;
            spacesindexindex++;
        }
    }
    int count = 0;
    std::cout << '[';
    for (int index = 0; index < spacesindexlen; index++)
    {
        std::cout << spacesindex[index];
        if (spacesindex[index] != 0)
        {
            count++;
        }
        std::cout << ' ';
    }
    std::cout << ']';
    std::cout << "\n\r";
    
    int index = 0;
    incomingText.effect = NULL_STRING;
    incomingText.command = NULL_STRING;
    incomingText.arg0 = NULL_STRING;
    incomingText.arg1 = NULL_STRING;
    incomingText.function = NULL_STRING;
    incomingText.type = CMD_NOT_CMD;
    incomingText.max = NULL_STRING;
    incomingText.min = NULL_STRING;
    
    incomingText.effect =  inputstring.substr(0, spacesindex[index]);
    index++;
    if (count == 0)
    {
        incomingText.effect = inputstring;
    }
    if (index <= count)
    {
        incomingText.command = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
        index++;
        if (index <= count)
        {
            incomingText.arg0 = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
            index++;
            if (index <= count)
            {
                incomingText.arg1 = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
            }
        }
    }
    
    if (incomingText.effect == "help")
    {
        return String (printHelp());
    }
    
    std::string inputvalidstring = checkInputValid();
    
    if (inputvalidstring == STRING_GOOD)
    {
        return incomingText.function;
    }
        
    
    return inputvalidstring;
}

std::string TextChatHandler::checkInputValid ()
{
    std::string s = "";
    bool effectgood = false;
    for (int index = 0; index < CHAT_STRUCT_LEN; index++)
    {
        if (incomingText.effect == chatstruct[index].name)
        {
            effectgood = true;
        }
    }
    
    bool commandgood = false;
    for (int index = 0; index < CHAT_STRUCT_LEN; index++)
    {
        if (incomingText.command == chatstruct[index].command)
        {
            commandgood = true;
            incomingText.function = chatstruct[index].func;
            incomingText.type = chatstruct[index].type;
            incomingText.max = chatstruct[index].max;
            incomingText.min = chatstruct[index].min;
        }
    }
    
    bool argsgood = false;
    if (incomingText.type == CMD_NULL)
    {
        s = STRING_GOOD;
        argsgood = true;
    }
    else if (incomingText.type == CMD_DIGIT)
    {
        if (incomingText.max.find(' ') != std::string::npos)
        {
            
        }
        else
        {
            if (atoi( incomingText.arg0.c_str()) > atoi( incomingText.min.c_str()) &&
                atoi( incomingText.arg0.c_str()) < atoi( incomingText.max.c_str()))
            {
                s = STRING_GOOD;
                argsgood = true;
            }
        }
    }
    else if (incomingText.type == CMD_SEL)
    {
        bool selectswitch = false;
        for (int index = 0; index < CHAT_STRUCT_LEN; index++)
        {
            if ((chatstruct[index].command == incomingText.command) &&
                (chatstruct[index-1].name == incomingText.effect))
            {
                selectswitch = true;
            }
            else if ((selectswitch == true) && (chatstruct[index].command != NULL_STRING))
            {
                selectswitch = false;
            }
            if (selectswitch == true)
            {
                if (incomingText.arg0 == chatstruct[index].arguments)
                {
                    s = STRING_GOOD;
                    argsgood = true;
                }
            }
        }
    }
    
    if (argsgood == false)
    {
        if (incomingText.type != CMD_SEL)
        {
            s = "Arguments out of range, must be within: " + incomingText.min + " and " + incomingText.max;
        }
        else
        {
            s = "Argument does not match what it should, check help to see what it should be";
        }
    }
    
    
    if (effectgood == false)
    {
        s = "Command for " + incomingText.effect + " does not exist, try again or type 'help'";
    }
    
    if (effectgood == false)
    {
        s = "No effect input, try again or type 'help'";
    }
    
    return s;
}

std::string TextChatHandler::printHelp()
{
    return tcHelp.printHelp(false);
}
