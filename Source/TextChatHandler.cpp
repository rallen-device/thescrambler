//
//  TextChatHandler.cpp
//  TheScrambler
//
//  Created by Richard Allen on 24/03/2021.
//  Copyright © 2021 Swn. All rights reserved.
//

#include "TextChatHandler.h"

TextChatHandler::TextChatHandler ()
{
    
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
    
    std::cout << '[';
    for (int index = 0; index < spacesindexlen; index++)
    {
        std::cout << spacesindex[index];
        std::cout << ' ';
    }
    std::cout << ']';
    std::cout << "\n\r";
    
    return "Hello";
}
