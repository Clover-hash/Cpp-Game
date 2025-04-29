/*game idea:
A puzzle game where we use pointers and arrays to find the correct location needed
Exit mechanic: When you enter the correct location, it will exit
Movement mechanic : You enter an address and you go to that address
Puzzle 1: Enter the correct location and print you escaped
Puzzle 2: Need to go different locations to change the value to open or allow access to the exit
*/


#include <iostream>

using namespace std;

int CurrPos=0;
int* CurrPointer=&CurrPos;
void Move(int* AddressToGo);
int main(){
    int a=0;
    int b=1;
    int Puzzle1[2]={a,b};
    cout<<"Where would you like to go?"<<endl;
    cout<<"You can currently go :"<<endl;
    cout<<&a;
    cout<<&b;
    cout<<"Enter the address you would like to go to: ";
    string AddressInput;
    cin >> AddressInput;

    Move(AddressInput);
    return 0;
}

int* ConvertStringToAddress(string TextAddress){
    
}
void Move(int* AddressToGo){
    cout<<CurrPointer<<endl;
    CurrPointer=AddressToGo;
    cout<<CurrPointer<<endl;
    cout<<CurrPos<<endl;
    CurrPos=*CurrPointer;
    cout<<CurrPos;
}

void Puzzle1(){

}