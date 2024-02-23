#include<iostream>
using namespace std;

    //these are our universal variables
    char places[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int row;
    int column;
    char tokken='X';
    int digit=0;
    bool tieCheck = false;
    string p1=" ";
    string p2=" ";

void printGame(){
	
	cout<<endl<<endl;
    
    cout<<"            |       |     "<<endl;
    cout<<"         "<<places[0][0]<<"  |   "<<places[0][1]<<"   |  "<<places[0][2]<<"  "<<endl;
    cout<<"       _____|_______|_____"<<endl;
    cout<<"            |       |     "<<endl;
    cout<<"         "<<places[1][0]<<"  |   "<<places[1][1]<<"   |  "<<places[1][2]<<"  "<<endl;
    cout<<"       _____|_______|_____"<<endl;
    cout<<"            |       |     "<<endl;
    cout<<"         "<<places[2][0]<<"  |   "<<places[2][1]<<"   |  "<<places[2][2]<<"  "<<endl;
    cout<<"            |       |     "<<endl;

    }
void inputGame(){
    
    if (tokken=='X')
    {
        cout<<endl<<p1<<" enter the number of spot: ";
        cin>>digit;
    }
    if (tokken=='O')
    {
        cout<<endl<<p2<<" enter the number of spot: ";
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
    }
	if(digit<1 || digit > 9){
        cout<<"The Number Is Not On Valid!!!"<<endl;
        digit=0;
        cin.clear();
        cin.ignore();
        inputGame();
        printGame();
    }

//Condition to Check Wether the place is empty then filling it and then changing sign for next person.

    if(tokken=='X' && places[row][column] != 'X' && places[row][column] !='O'){
        places[row][column]='X';
        tokken='O';
    }
    else if(tokken=='O' && places[row][column] != 'X' && places[row][column] !='O'){
        places[row][column]='O';
        tokken='X';
    }else if((tokken=='X' || tokken=='O')&&(places[row][column] == 'X' || places[row][column] =='O')) {
        cout<<"The number is already takken. Try Another One: "<<endl;
        inputGame();
        printGame();
    }
    
}


bool checkWinner(){
    for (int i = 0; i < 3; i++)
    {
        if(places[i][0]==places[i][1] &&places[i][0]==places[i][2]){
            return true;
        }
        else if(places[0][i]==places[1][i]&&places[0][i]==places[2][i]){
        	return true;
		}
    }
    if(places[0][0]==places[1][1] && places[0][0]==places[2][2]){
        return true;
    }
    else if( places[0][2]==places[1][1] && places[0][2]==places[2][0]){
    	return true;
	}

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(places[i][j] !='X'&& places[i][j]!='O'){
            	cout<<"TIC TAC TOE"<<endl<<endl;
                return false;
            
            }
            }
        }
	tieCheck=true;
    return true;
        
    }
    



int main(){

    cout<<"What is Name Of Player One(Only First Name): \n";
    cin>>p1;
    cout<<"What is Name Of Player Two(Only First Name): \n";
    cin>>p2;
    cout<<endl<<p1<<" Is Player One. He will have the First Turn"<<endl;
    cout<<endl<<p2<<" Is Player Two. He will have the Second Turn"<<endl;
    system("CLS");

    while(!checkWinner()){
        printGame();
        inputGame();
        checkWinner();
        system("CLS");

    }
    printGame();
    if(tokken=='X' && tieCheck==false){
        cout<<p2<<" Win!!"<<endl;
    }
    else if(tokken=='O' && tieCheck==false){
        cout<<p1<<" Win!!"<<endl;
    }else{
        cout<<"The game Is Draw!!!!!!"<<endl;
    }
    cout<<endl<<"THANKS FOR PLAYING......."<<endl;
}
