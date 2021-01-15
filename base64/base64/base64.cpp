#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

std::string encodeBase64(char* inputstring)
{
    char outputstring[480];
    int inputLen = (int)strlen(inputstring);
    int i = 0;
    int j = 0;
    for (i = 0; i < 480; ++i)
    {
        outputstring[i] = 0;
    }
    int bin[360][8];
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (i = 0; i < 360; ++i)
    {
        for (j = 0; j < 8; ++j)
        {
            bin[i][j] = 0;
        }
    }

    i = 0;
    j = 0;
    while ((i < inputLen) && (i < 360))
    {
        for (j = 0; j < 8; ++j)
        {
            bin[i][j] = inputstring[i] % 2;
            inputstring[i] = inputstring[i] / 2;
        }
        for (j = 0; j < 4; ++j)
        {
            int taburetka = bin[i][j];
            bin[i][j] = bin[i][7 - j];
            bin[i][7 - j] = taburetka;
        }
        ++i;
    }




    i = 0;
    j = 0;
    int ioutput = 0;

    while (i < inputLen-2)
    {
        int ch;
        ch = 32 * bin[i][0] + 16 * bin[i][1] + 8 * bin[i][2] + 4 * bin[i][3] + 2 * bin[i][4] + bin[i][5];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i][6] + 16 * bin[i][7] + 8 * bin[i + 1][0] + 4 * bin[i + 1][1] + 2 * bin[i + 1][2] + bin[i + 1][3];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i + 1][4] + 16 * bin[i + 1][5] + 8 * bin[i + 1][6] + 4 * bin[i + 1][7] + 2 * bin[i + 2][0] + bin[i + 2][1];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i + 2][2] + 16 * bin[i + 2][3] + 8 * bin[i + 2][4] + 4 * bin[i + 2][5] + 2 * bin[i + 2][6] + bin[i + 2][7];
        outputstring[ioutput] = base64[ch];
        ++ioutput;

        ++i;
        ++i;
        ++i;
    }
    if (inputLen - i == 2)
    {
        int ch;
        ch = 32 * bin[i][0] + 16 * bin[i][1] + 8 * bin[i][2] + 4 * bin[i][3] + 2 * bin[i][4] + bin[i][5];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i][6] + 16 * bin[i][7] + 8 * bin[i + 1][0] + 4 * bin[i + 1][1] + 2 * bin[i + 1][2] + bin[i + 1][3];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i + 1][4] + 16 * bin[i + 1][5] + 8 * bin[i + 1][6] + 4 * bin[i + 1][7] + 2 * bin[i + 2][0] + bin[i + 2][1];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        outputstring[ioutput] = '=';
        ++ioutput;

        ++i;
        ++i;
    }
    if (inputLen - i == 1)
    {
        int ch;
        ch = 32 * bin[i][0] + 16 * bin[i][1] + 8 * bin[i][2] + 4 * bin[i][3] + 2 * bin[i][4] + bin[i][5];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        ch = 32 * bin[i][6] + 16 * bin[i][7] + 8 * bin[i + 1][0] + 4 * bin[i + 1][1] + 2 * bin[i + 1][2] + bin[i + 1][3];
        outputstring[ioutput] = base64[ch];
        ++ioutput;
        outputstring[ioutput] = '=';
        ++ioutput;
        outputstring[ioutput] = '=';
        ++ioutput;

        ++i;
    }

    
    return outputstring;
}














std::string decodeBase64(char* inputstring)
{
    char outputstring[360];
    int inputLen = (int)strlen(inputstring);
    int i = 0;
    int j = 0;
    for (i = 0; i < 360; ++i)
    {
        outputstring[i] = 0;
    }
    int bin[480][6];
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (i = 0; i < 480; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            bin[i][j] = 0;
        }
    }

    i = 0;
    j = 0;
    
    while ((i < inputLen) && (i < 480))
    {
        if ((inputstring[i] >= 66) && (inputstring[i] <= 90))
        {
            inputstring[i] = inputstring[i] - 65;
        }
        else if ((inputstring[i] >= 97) && (inputstring[i] <= 122))
        {
            inputstring[i] = inputstring[i] - 71;
        }
        else if ((inputstring[i] >= 48) && (inputstring[i] <= 57))
        {
            inputstring[i] = inputstring[i]+4;
        }
        else if (inputstring[i] == '+')
        {
            inputstring[i] = 62;
        }
        else if (inputstring[i] == '/')
        {
            inputstring[i] = 63;
        }
        else if ((inputstring[i] == '=') || (inputstring[i] == 'A'))
        {
            inputstring[i] = 0;
        }
        for (j = 0; j < 6; ++j)
        {
            bin[i][j] = inputstring[i] % 2;
            inputstring[i] = inputstring[i] / 2;
        }
        for (j = 0; j < 3; ++j)
        {
            int taburetka = bin[i][j];
            bin[i][j] = bin[i][5 - j];
            bin[i][5 - j] = taburetka;
        }
        ++i;
    }





    i = 0;
    j = 0;
    int ioutput = 0;

    while (i < inputLen)
    {
        int ch;
        ch = 128 * bin[i][0] + 64 * bin[i][1] + 32 * bin[i][2] + 16 * bin[i][3] + 8 * bin[i][4] + 4 * bin[i][5] + 2 * bin[i+1][0] + bin[i + 1][1];
        outputstring[ioutput] = ch;
        ++ioutput;
        ch = 128 * bin[i+1][2] + 64 * bin[i + 1][3] + 32 * bin[i + 1][4] + 16 * bin[i + 1][5] + 8 * bin[i + 2][0] + 4 * bin[i + 2][1] + 2 * bin[i + 2][2] + bin[i + 2][3];
        outputstring[ioutput] = ch;
        ++ioutput;
        ch = 128 * bin[i + 2][4] + 64 * bin[i + 2][5] + 32 * bin[i + 3][0] + 16 * bin[i + 3][1] + 8 * bin[i+3][2] + 4 * bin[i + 3][3] + 2 * bin[i + 3][4] + bin[i+3][5];
        outputstring[ioutput] = ch;
        ++ioutput;

        ++i;
        ++i;
        ++i;
        ++i;
    }


    return outputstring;
}