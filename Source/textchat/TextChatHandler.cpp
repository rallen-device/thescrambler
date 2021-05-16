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
    std::string effect = NULL_STRING;
    std::string command = NULL_STRING;
    std::string arg0 = NULL_STRING;
    std::string arg1 = NULL_STRING;
    
    effect =  inputstring.substr(0, spacesindex[index]);
    index++;
    if (count == 0)
    {
        effect = inputstring;
    }
    if (index <= count)
    {
        command = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
        index++;
        if (index <= count)
        {
            arg0 = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
            index++;
            if (index <= count)
            {
                arg1 = inputstring.substr(spacesindex[index-1]+1, (spacesindex[index] - spacesindex[index-1] - 1));
            }
        }
    }
    
    if (effect == "Help")
    {
        return String (printHelp());
    }
    
    return String(effect + " " + command + " " + arg0 + " " + arg1 );
}

std::string TextChatHandler::printHelp()
{
    return tcHelp.printHelp(false);
}
