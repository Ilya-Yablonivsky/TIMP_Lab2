#include <iostream>
#include <cctype>
#include <locale>

#include "modAlphaCipher.h"

using namespace std;

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        
        if (destructCipherText)
        {
        	cipherText.front() = towlower(cipherText.front());
        }
        
        decryptedText = cipher.decrypt(cipherText);
        wcout<<"key:"<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } 
    
    catch (const cipher_error & e) 
    {
        wcerr<<"Error: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    
    check(L"Быстрая Бурая Лиса Перепрыгивает Через Ленивую Собаку",L"ПРИМЕР");
    check(L"АБВГ", L"");
 	check(L"АБВГ", L"123");
    return 0;
}
