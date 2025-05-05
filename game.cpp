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
#include <array>


using namespace std;

int CurrPos=0;
int* CurrPointer=&CurrPos;
void Move(int* AddressToGo);
int* ConvertStringToAddress(string TextAddress);
int* DisplayMoves(array<int*,4> moves);
array<array<int,3>,3> PuzzleGenerator();
array<int*,4> CheckAvailableMoves(int* CurrPos,array<array<int*,3>,3> arr);



int main(){



    //initialize the array and the pointer============================
    cout<<"You at: "<<CurrPointer<<endl;
    array<array<int,3>,3> arr = PuzzleGenerator();
    CurrPointer=&arr[0][0];
    //================================================================

    int i = 0;
    while (true){
        //display the array=============
        cout<<"Where would you like to go?"<<endl;
        cout<<"You can currently go :"<<endl;
        array<array<int*,3>,3> arrAdressess;


        cout<<"======================="<<endl;   
        for (int I=0; I<3; I++){
            for (int J=0; J<3; J++){

                // for debugging purposes
                //cout<<"Location of " <<arr[I][J]<<" : "<<&arr[I][J]<<" \n";
                //========================

                arrAdressess[I][J]=&arr[I][J];
            }
        }
        CurrPos=*CurrPointer;

        //=============================

        int* AddressInput=DisplayMoves(CheckAvailableMoves(CurrPointer,arrAdressess));
        Move(AddressInput);
        CurrPointer=AddressInput;
        if (CurrPos==0){
            cout<<"You escaped!"<<endl;
            break;}

    }
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
    cout<<"================================================="<<endl;
    cout<<"You were "<<CurrPos<<" moves away from reaching"<<endl;
    cout<<"================================================="<<endl;
    CurrPos=*CurrPointer;
    cout<<"You are "<<CurrPos<<" moves away from reaching"<<endl;
    cout<<"================================================="<<endl;
}

array<array<int,3>,3> PuzzleGenerator() {
    return     {{
        {4,3,2},
        {3,2,1},    
        {2,1,0},
    }};
}

int* DisplayMoves(array<int*,4> moves){
    int* upcoords=moves[0];
    int* downcoords=moves[1];
    int* leftcoords=moves[2];
    int* rightcoords=moves[3];
    if (upcoords==nullptr||downcoords==nullptr||leftcoords==nullptr||rightcoords==nullptr){
        if(upcoords!=nullptr){
            cout<<"up"<<endl;
        }
        if(downcoords!=nullptr){
            cout<<"down"<<endl;
        }
        if(leftcoords!=nullptr){
            cout<<"left"<<endl;
        }
        if (rightcoords!=nullptr){
            cout<<"right"<<endl;
        }
    }else{
        cout<<"up"<<endl;
        cout<<"down"<<endl;
        cout<<"left"<<endl;
        cout<<"right"<<endl;
    }
        
    
    string move;
    cout<<"======================="<<endl;
    cout<<"MOVES :"<<endl;
    cout<<"            ^            "<<endl;
    cout<<"         "<<upcoords<<endl;
    cout<<" "<<endl;
    cout<<"<                       >"<<endl; 
    cout<<leftcoords<<"        "<<CurrPointer<<"    "<<rightcoords<<endl;
    cout<<" "<<endl;
    cout<<"            v            "<<endl;
    cout<<"         "<<downcoords<<endl;
    cout<<" "<<endl;
    cout<<"======================="<<endl;
    cout<<"What move will you play? : "<<endl;
    cin>>move;


    if (move=="up"|| move=="UP"|| move=="Up"){
        return upcoords;
    }else if (move=="down"|| move=="DOWN"|| move=="Down"){
        return downcoords;
    }else if (move=="left"|| move=="LEFT"|| move=="Left"||move=="l"|| move=="L"){
        return leftcoords;
    }else if (move=="right"|| move=="RIGHT"|| move=="Right"||move=="r"|| move=="R"){
        return rightcoords;
    }else{
        cout<<"Invalid move"<<endl;
        return nullptr;
    }
}

array<int*,4> CheckAvailableMoves(int* CurrPos,array<array<int*,3>,3> arr){
    array <int*,4> moves; //0=up,1=down,2=left,3=right
    
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (arr[i][j]==CurrPos){     //find the current position of the player

                //check what moves they can make
                int t=0;
                while(t<=5){
                    try{
                        moves[0]=arr[i-1][j]; //up
                        moves[1]=arr[i+1][j]; //down
                        moves[2]=arr[i][j-1]; //left
                        moves[3]=arr[i][j+1]; //right
                    }catch (out_of_range& e){
                        e.what();
                        //catch the out of range error and set the move to nullptr
                        if (t==0){
                            moves[0]=nullptr; //up
                        }
                        else if (t==1){
                            moves[1]=nullptr; //down
                        }
                        else if (t==2){
                            moves[2]=nullptr; //left
                        }
                        else if (t==3){
                            moves[3]=nullptr; //right
                        }
                        
                    }
                    t=t+1;
                }
                //check if the moves are valid and set them to nullptr if they are not
                for (int i=0;i<4;i++){
                    if (moves[i]==CurrPos){
                        moves[i]=nullptr;
                    }
                }
                
                //checks if any of the moves are assigned to an address that is not in the array
                for (int i=0;i<4;i++){
                    if (moves[i]!=nullptr){
                        for (int j=0;j<3;j++){
                            for (int k=0;k<3;k++){
                                if (moves[i]==arr[j][k]){
                                    moves[i]=arr[j][k];
                                }
                            }
                        }
                    }else{
                        moves[i]=nullptr;
                    }
                }
            }
        }
    }
    return moves;
}