#include "TableCipher.h"

using namespace std;

void check(const string& Text, const string& key)
{
	try {
		string cipherText;
		string decryptedText;
		
		if (key.empty())
		{
            throw cipher_error("Empty key");
        }
        
        if (stoi(key) > 1) 
        {
            TableCipher cipher(stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
            
			cout<<"key="<<key<<endl;
			cout << "Encrypted text: " << cipherText << endl;
            cout << "Decrypted text: " << decryptedText << endl;
		}
		else
		{
			throw cipher_error(std::string("Invalid key ")+key);
		}
	
 	} 
 	
 	catch (const cipher_error & e) 
 	{
 		cerr<<"Error: "<<e.what()<<endl;
 	}
 	
 	 cout << "" << endl;
}

int main()
{
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","0");
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","");
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","5");
    check("thequikbrownfoxjumpsovertherlazydog","5");
    check("Быстрая Бурая Лиса Перепрыгивает Через Ленивую Собаку","5");
    check("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG","150");
    check("123456789","5");
}
