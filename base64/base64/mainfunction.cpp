#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


int main() {

    char inputuncodestring[360];
    cout << "Input the uncoding string for encode, please (max 360 symbols): " << endl << endl;
    cin.getline((char*)inputuncodestring, 360);
    cout << "Encode string: " << encodeBase64(inputuncodestring) << endl << endl;

    char inputencodestring[480];
    cout << "Input the encoding string for decode, please (max 480 symbols): " << endl << endl;
    cin.getline((char*)inputencodestring, 360);
    cout << "Decode string: " << decodeBase64(inputencodestring) << endl << endl;
}