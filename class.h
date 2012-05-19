#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <deque>
#define SIZE 1000
using namespace std;

class Encrypt
{
	char str[SIZE];
	unsigned len;
	deque <int> random_hold;
	deque <int>::iterator ptr;
public:
    void init_encrypt(void);
    void init_decrypt(void);
	void display (void);
void accept (void);
private:
	void encryptStr (void);
	void decryptStr (void);
};

void Encrypt::display(void)
{
	cout<< "String is: "<<str;
	cout<<endl;
}

void Encrypt::accept(void)
{
    cout<< "Enter the string: ";
    cin>>str;
    len=strlen(str);
    cout<<endl;
}

void Encrypt::encryptStr(void)
{
    int i,random;
    for(i=0;i<len;i++)
    {
        random=rand();
        str[i]=str[i]+random;
        random_hold.push_front(random);
    }
    str[i]='\0';
    cout<< "String Encrypted Successfully"<<endl;
}

void Encrypt::decryptStr(void)
{
    int i;
    int random;
    for(i=0;i<len;i++)
    {
        random=random_hold.back();
        random_hold.pop_back();
        str[i]=str[i]-random;
    }
    str[i]='\0';
    cout<< "String Decrypted Successfully"<<endl;
}

void Encrypt::init_encrypt(void)
{
    srand(time(NULL));
    encryptStr();
}

void Encrypt::init_decrypt(void)
{
    decryptStr();
}
#endif // CLASS_H_INCLUDED
