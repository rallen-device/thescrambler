//
//  TextChatHelp_AUTOGEN.cpp
//  TheScrambler
//
//  Created by Richard Allen on 27/03/2021.
//  Copyright © 2021 Swn. All rights reserved.
//

#include "TextChatHelp.h"
#include "TextChatStructure_AUTOGEN.h"

TextChatHelp::TextChatHelp()
{
    
}

TextChatHelp::~TextChatHelp()
{
    
}

std::string TextChatHelp::printHelp(bool verbose)
{
    char buf [2048];
    memset(buf, 0, 2048);
    char tmp [512];
    memset(tmp, 0, 512);
    std::string effect;
    
    sprintf(tmp, "Printing the help\r\n");
    strcat(buf, tmp);
    
    for (int index = 0; index < CHAT_STRUCT_LEN; index++)
    {
        S_TEXT_CHAT localstruct = chatstruct[index];
        if (localstruct.name.compare(NULL_STRING) != 0)
        {
            effect = localstruct.name;
            sprintf(tmp, "%s - %s\r\n", localstruct.name.c_str(), localstruct.desc.c_str());
            strcat(buf, tmp);
        }
        else if (localstruct.command.compare(NULL_STRING) != 0)
        {
            sprintf(tmp, "  %s %s ", effect.c_str(), localstruct.command.c_str());
            strcat(buf, tmp);
            if (localstruct.arguments.compare(NULL_STRING) != 0)
            {
                sprintf(tmp, "%s ", localstruct.arguments.c_str());
                strcat(buf, tmp);
            }
            sprintf(tmp, "\n");
            strcat(buf, tmp);
        }
        else if (localstruct.arguments.compare(NULL_STRING) != 0)
        {
            sprintf(tmp, "    %s\r\n", localstruct.arguments.c_str());
            strcat(buf, tmp);
        }
    }
    
    return buf;
}
