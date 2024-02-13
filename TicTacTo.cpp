#include<iostream>
using namespace std;

    //these are our universal variables
    char places[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int row;
    int column;
    char tokken='X';
    bool tie=false;
    string p1=" ";
    string p2=" ";

void funtionone(){
    
    cout<<"     |       |     "<<endl;
    cout<<"  "<<places[0][0]<<"  |   "<<places[0][1]<<"   |  "<<places[0][2]<<"  "<<endl;
    cout<<"_____|_______|_____"<<endl;
    cout<<"     |       |     "<<endl;
    cout<<"  "<<places[1][0]<<"  |   "<<places[1][1]<<"   |  "<<places[1][2]<<"  "<<endl;
    cout<<"_____|_______|_____"<<endl;
    cout<<"     |       |     "<<endl;
    cout<<"  "<<places[2][0]<<"  |   "<<places[2][1]<<"   |  "<<places[2][2]<<"  "<<endl;
    cout<<"     |       |     "<<endl;

    }
void functiontwo(){
    int digit;
    if (tokken=='X')
    {
        cout<<p1<<" enter the number of spot: ";
        cin>>digit;
    }
    if (tokken=='0')
    {
        cout<<p2<<" enter the number of spot: ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
     if(digit==2){
        row=0;
        column=1;
    }
     if(digit==3){
        row=0;
        column=2;
    }
     if(digit==4){
        row=1;
        column=0;
    }
     if(digit==5){
        row=1;
        column=1;
    }
     if(digit==6){
        row=1;
        column=2;
    }
     if(digit==7){
        row=2;
        column=0;
    }
     if(digit==8){
        row=2;
        column=1;
    }
     if(digit==9){
        row=2;
        column=2;
    }else if(digit<1 || digit > 9){
        cout<<"The Number Is Not On Chart!!!"<<endl;
    }

//Condition to Check Wether the place is empty then filling it and then changing sign for nect person.

    if(tokken=='X' && places[row][column] != 'X' && places[row][column] !='0'){
        places[row][column]='X';
        tokken='0';
    }
    else if(tokken=='0' && places[row][column] != 'X' && places[row][column] !='0'){
        places[row][column]='0';
        tokken='X';
    }else{
        cout<<"There is No Empty Space"<<endl;
        functiontwo();
        funtionone();
    }
    
}

//Check Wether a player have won the game or not.

bool functionthree(){
    for (int i = 0; i < 3; i++)
    {
        if(places[i][0]==places[i][1] &&places[i][0]==places[i][2] || places[0][i]==places[1][i]&&places[0][i]==places[2][i]){
            return true;
        }
    }
    if(places[0][0]==places[1][1] && places[0][0]==places[2][2] || places[0][2]==places[1][1] && places[0][2]==places[2][0]){
        return true;
    }
//check wether the game is ended:
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(places[i][j] !='X'&&places[i][j]!='0'){
                return false;
            }
        }
        
    }
//check wether the game is draw:
    tie=true;
    return false;

}
int main(){

    cout<<"What is Name Of Player One: \n";
    cin>>p1;
    cout<<"What is Name Of Player Two: \n";
    cin>>p2;
    cout<<endl<<p1<<" Is Player One. He will have the First Turn"<<endl;
    cout<<endl<<p2<<" Is Player Two. He will have the Second Turn"<<endl;

    while(!functionthree()){
        funtionone();
        functiontwo();
        functionthree();
         system("CLS");

    }
    funtionone();
    if(tokken=='X' && tie==false){
        cout<<p2<<" Wins!!"<<endl;
    }
    else if(tokken=='0' && tie==false){
        cout<<p1<<" Wins!!"<<endl;
    }else{
        cout<<"The game Is Draw!!"<<endl;
    }
}
