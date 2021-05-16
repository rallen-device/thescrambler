//
//  TextChatHandler.hpp
//  TheScrambler
//
//  Created by Richard Allen on 24/03/2021.
//  Copyright © 2021 Swn. All rights reserved.
//

#ifndef TEXTCHATHANDLER_H
#define TEXTCHATHANDLER_H

#pragma once

#include "../PluginProcessor.h"
#include "TextChatHelp.h"

struct S_INCOMING_TEXT
{
    std::string effect;
    std::string command;
    std::string arg0;
    std::string arg1;
    std::string function;
    E_TEXT_COMMAND_TYPE type;
    std::string max;
    std::string min;
};

#define STRING_GOOD "!@£$£@!"

class TextChatHandler
{
public:
    TextChatHandler();
    ~TextChatHandler();
    String processTextInput(String input);
    std::string checkInputValid ();
    std::string printHelp();
    S_INCOMING_TEXT incomingText;
    
private:
    TextChatHelp tcHelp;
};

#endif
