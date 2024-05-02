#include <iostream>
using namespace std;

class encrypt_decrypt
{
public:

    void encryption(char message[100], int key) {
        
        int i;
        char ch;

        for (i = 0; message[i] != '\0'; ++i) {
            ch = message[i];

            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            } 
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }

        cout << "Encrypted Message = " << message;

    }

    void decryption(char message[100], int key) {

        int i;
        char ch;

        for (i = 0; message[i] != '\0'; ++i) {
            ch = message[i];

            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if (ch < 'a') {
                    ch = 'z' - ('a' - ch) + 1;
                }
                message[i] = ch;
            } 
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if (ch < 'A') {
                    ch = 'Z' - ('A' - ch) + 1;
                }
                message[i] = ch;
            }
        }

        cout << "Decrypted Message = " << message;
    }
};

class choose : public encrypt_decrypt {

public:
    choose() {
        char message[100], ch;
        int key;

        cout << "Enter Message: ";
        cin.getline(message, 100);

        cout << "Enter a Key (a number between 1 to 25) : ";
        cin >> key;

        cout << "Enter 'e' if you want to Encrypt the Message and 'd' if you want to Decrypt the Message: ";
        cin >> ch; 

        if (ch == 'e') {
            encryption(message, key);
        }

        else if (ch == 'd') {
            decryption(message, key);
        }
        
    }

    ~choose() {
        cout << endl << "This was Caesar Cipher Project by Brinda." << endl;
    }
};

int main() {
    
    choose cc1;

    return 0;
}