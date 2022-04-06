#include "Card.h"

int main(int argc,char **argv){
    ifstream Record("RecordCard.txt",ios::in);
    if(!Record){
        cout<<"The file could not be opened."<<endl;
        exit(1);
    }
    if(Record.get()!=EOF){
        Record.close();
        string answer;
        cout<<"Do you want to continue playing the last game?(Yes or No)"<<endl;
        while(cin>>answer){
            ifstream Record("RecordCard.txt",ios::in);
            if(!Record){
                cout<<"The file could not be opened."<<endl;
                exit(1);
            }
            if(answer=="Yes"){
                Card LastPoker;
                LastPoker.read();
                if(LastPoker.Endfun()){
                    return 0;
                }
                else{

                    LastPoker.Count();
                    break;
                }
            }
            else if(answer=="No"){
                ofstream Record("RecordCard.txt",ios::out);
                if(!Record){
                    cout<<"The file could not be opened."<<endl;
                    exit(1);
                }
                Record.close();
                break;
            }
            else{
                cout<<"Please enter Yes or No."<<endl<<"Do you want to continue playing the last game?(Yes or No)"<<endl;
            }
        }
    }
    else{
        cout<<"You have finished the last game."<<endl<<"Please enter a new game."<<endl;
    }
    system("pause");
    while(true){
        Card Poker;
        Poker.Firstplay();
        if(Poker.Endfun()){
            break;
        }
        Poker.Count();
        system("pause");
        system("cls");
    }
    return 0;
}
