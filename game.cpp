/*game idea:
A puzzle game where we use pointers and arrays to find the correct location needed
Exit mechanic: When you enter the correct location, it will exit
Movement mechanic : You enter an address and you go to that address
Puzzle 1: Enter the correct location and print you escaped
Puzzle 2: Need to go different locations to change the value to open or allow access to the exit
*/


#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int CurrPos=0;
int* CurrPointer=&CurrPos;
void Move(int* AddressToGo);
int* ConvertStringToAddress(string TextAddress);

int main(){
    int a=0;
    int b=1;
    CurrPointer=&a;
    cout<<"You at: "<<CurrPointer<<endl;
    int Puzzle1[2]={a,b};
    cout<<"Where would you like to go?"<<endl;
    cout<<"You can currently go :"<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<"Enter the address you would like to go to: "<<endl;
    string AddressInput;
    cin >> AddressInput;
    Move(ConvertStringToAddress(AddressInput));
    return 0;
}

int* ConvertStringToAddress(string TextAddress){
    uintptr_t addr;
    stringstream ss;
    ss<<hex<<TextAddress;
    ss>>addr;
    int* address = reinterpret_cast<int*>(addr);
    return address;
}

void Move(int* AddressToGo){
    cout<<"You were at: "<<CurrPointer<<endl;
    CurrPointer=AddressToGo;
    cout<<"You are now at: "<<CurrPointer<<endl;
    cout<<CurrPos<<endl;
    CurrPos=*CurrPointer;
    cout<<CurrPos;
}

void Puzzle1(){

}