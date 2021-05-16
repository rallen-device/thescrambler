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

class TextChatHandler
{
public:
    TextChatHandler();
    ~TextChatHandler();
    String processTextInput(String input);
    std::string printHelp();
    
private:
    TextChatHelp tcHelp;
};

#endif
