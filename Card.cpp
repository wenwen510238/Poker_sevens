#include "Card.h"

void Card::SetColor(int color ){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
Card::Card(){
    suit["Spade"]=1;
    suit["Heart"]=2;
    suit["Club"]=3;
    suit["Diamond"]=4;
    ConvertNum[1]="Spade";
    ConvertNum[2]="Heart";
    ConvertNum[3]="Club";
    ConvertNum[4]="Diamond";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            index.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            screen[i][j]=52;
        }
    }
    memset(FoldTotal,0,sizeof(FoldTotal));
    srand(time(NULL));
    int number,face,c[4][13];
    for(int j=0;j<4;j++){
        for(int k=0;k<13;k++){
            c[j][k]=0;
        }
    }
    for(int Count=1;Count<=4;Count++){
        for(int k=1;k<=13;k++){
            number=(rand()%13)+1;
            face=(rand()%4)+1;
            while(c[face-1][number-1]==1){
                number=(rand()%13)+1;
                face=(rand()%4)+1;
            }
            c[face-1][number-1]=1;
            if(Count==1){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==2){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==3){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==4){
                player[Count-1].push_back(make_pair(face,number));
            }
        }
    }
    PrintHuman();
}
//-------------------------------------------------------------------------------------------------------------------
void Card::Spade(string a,int n){
	string S[13]= {"- - - - - -",
                   "|             |",
				   "|      *      |",
				   "|     ***     |",
				   "|   *******   |",
				   "| *********** |",
				   "|*************|",
				   "| **** * **** |",
				   "|      *      |",
				   "|     ***     |",
				   "|             |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<S[n]<<" "<<a;
        }
        else{
            cout<<S[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<S[n]<<a;
        }
        else{
            cout<<S[n];
        }
	}
}

void Card::Heart(string a,int n){
	string H[13]= {"- - - - - -",
                   "|             |",
				   "| ***     *** |",
				   "|****** ******|",
				   "|*************|",
				   "| *********** |",
				   "|  *********  |",
				   "|   *******   |",
				   "|    *****    |",
				   "|     ***     |",
				   "|      *      |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<H[n]<<" "<<a;
        }
        else{
            cout<<H[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<H[n]<<a;
        }
        else{
            cout<<H[n];
        }
	}
}

void Card::Club(string a,int n){
	string C[13]= {"- - - - - -",
                   "|             |",
				   "|     ***     |",
				   "|    *****    |",
				   "|    *****    |",
				   "| *********** |",
				   "|*************|",
				   "| **** * **** |",
				   "|      *      |",
				   "|     ***     |",
				   "|    *****    |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<C[n]<<" "<<a;
        }
        else{
            cout<<C[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<C[n]<<a;
        }
        else{
            cout<<C[n];
        }
	}
}

void Card::Diamond(string a,int n){
	string D[13]= {"- - - - - -",
                   "|             |",
				   "|      *      |",
				   "|     ***     |",
				   "|    *****    |",
				   "|   *******   |",
				   "|  *********  |",
				   "|   *******   |",
				   "|    *****    |",
				   "|     ***     |",
				   "|      *      |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<D[n]<<" "<<a;
        }
        else{
            cout<<D[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<D[n]<<a;
        }
        else{
            cout<<D[n];
        }
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
void Card::PrintHuman(){
    sort(player[0].begin(),player[0].end());
    cout<<"Your card: "<<endl;
    if(player[0].size()>7){
        for(int i=0;i<13;i++){
            for(int j=0;j<7;j++){
                switch(player[0][j].first){
                    case 1:
                        SetColor(15);
                        Spade(num[player[0][j].second],i);
                        break;
                    case 2:
                        SetColor(12);
                        Heart(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                    case 3:
                        SetColor(15);
                        Club(num[player[0][j].second],i);
                        break;
                    case 4:
                        SetColor(12);
                        Diamond(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                }
                cout<<setw(3)<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<13;i++){
            for(int j=7;j<player[0].size();j++){
                switch(player[0][j].first){
                    case 1:
                        SetColor(15);
                        Spade(num[player[0][j].second],i);
                        break;
                    case 2:
                        SetColor(12);
                        Heart(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                    case 3:
                        SetColor(15);
                        Club(num[player[0][j].second],i);
                        break;
                    case 4:
                        SetColor(12);
                        Diamond(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                }
                cout<<setw(3)<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<13;i++){
            for(int j=0;j<player[0].size();j++){
                switch(player[0][j].first){
                    case 1:
                        SetColor(15);
                        Spade(num[player[0][j].second],i);
                        break;
                    case 2:
                        SetColor(12);
                        Heart(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                    case 3:
                        SetColor(15);
                        Club(num[player[0][j].second],i);
                        break;
                    case 4:
                        SetColor(12);
                        Diamond(num[player[0][j].second],i);
                        SetColor(15);
                        break;
                }
                cout<<setw(3)<<" ";
            }
            cout<<endl;
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Card::Firstplay(){
   int k,n;
    string s;
    for(int i=0;i<4;i++){
        for(int j=0;j<player[i].size();j++){
            if(i==0){
                if(player[i][j].first==1 && player[i][j].second==7){
                    //PrintHuman();
                    cout<<"Please choose the card"<<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl
                    <<"(If you don't want to continue this game please enter 0.)"<<endl;
                    while(cin>>s){
                        if(s=="0"){
                            End=1;
                            break;
                        }
                        else{
                            cout<<"number(1~13): "<<endl<<"(If you don't want to continue this game please enter 0.)"<<endl;
                            cin>>n;
                            if(n==0){
                                End=1;
                                break;
                            }
                            else{
                                if(suit[s]==1 && n==7){
                                    screen[1][0]=6;
                                    player[0].erase(player[0].begin()+j);
                                    cout<<"You send Spade7."<<endl;
                                    k=0;
                                    break;
                                }
                                else{
                                    cout<<"Please choose the Spade 7."<<endl<<"number(1~13): "<<endl
                                    <<"(If you don't want to continue this game please enter 0.)"<<endl;
                                }
                            }
                        }
                    }
                }
            }
            else{
                if(player[i][j].first==1 && player[i][j].second==7){
                    screen[1][0]=6;
                    player[i].erase(player[i].begin()+j);
                    cout<<"Computer "<<i<<" sends Spade 7"<<endl;
                    k=i;
                    break;
                }
            }
            if(screen[1][0]==6) break;
        }
        if(screen[1][0]==6) break;
    }
//---------------------------------------------------------------------------------------------------------------------find Spade7
   for(int i=k+1;i<4;i++){
        if(decide(i)){
            srand(time(NULL));
            int Size=CanPlay[i].size();
            int card2=rand()%Size;
            pair<int,int> Choosecard(CanPlay[i][card2].first,CanPlay[i][card2].second);
            for(int j=0;j<player[i].size();j++){
                if(player[i][j].first==CanPlay[i][card2].first && player[i][j].second==CanPlay[i][card2].second){
                    player[i].erase(player[i].begin()+j);
                    cout<<"Computer "<<i<<" sends: "<<ConvertNum[CanPlay[i][card2].first]<<" "<<CanPlay[i][card2].second<<endl;
                    Save(Choosecard);
                    CanPlay[i].clear();
                }
            }
        }
        else{
            int Min=14;
            int position;
            for(int j=0;j<Fold[i].size();j++){
                if(Fold[i][j].second<Min){
                    Min=Fold[i][j].second;
                    position=j;
                }
            }
            for(int j=0;j<player[i].size();j++){
                if(player[i][j].first==Fold[i][position].first && player[i][j].second==Fold[i][position].second){
                    FoldTotal[i]+=player[i][j].second;
                    player[i].erase(player[i].begin()+j);
                    Fold[i].clear();
                    cout<<"Computer "<<i<<" folds card"<<endl;
                }
            }
        }
    }
    Print();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Card::run(){//call decide()
    int n;
    string s;
    for(int i=0;i<4;i++){
        if(!player[i].empty()){
            int flag=0;
            if(i==0){
                if(decide(i)){
                    cout<<"Please choose card"<<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl
                    <<"(If you don't want to continue this game please enter 0.)"<<endl;
                    while(cin>>s){
                        if(s=="0"){
                            End=1;
                            break;
                        }
                        else{
                            cout<<"number(1~13): "<<endl<<"(If you don't want to continue this game please enter 0.)"<<endl;
                            cin>>n;
                            if(n==0){
                                End=1;
                                break;
                            }
                            else{
                                for(int j=0;j<player[0].size();j++){
                                    for(int k=0;k<CanPlay[0].size();k++){
                                        if(CanPlay[0][k].first==suit[s] && CanPlay[0][k].second==n && player[0][j].first==suit[s] && player[0][j].second==n){
                                            player[0].erase(player[0].begin()+j);
                                            CanPlay[0].clear();
                                            flag=1;
                                            pair<int,int> a(suit[s],n);
                                            Save(a);
                                            break;
                                        }
                                    }
                                }
                                if(flag==1){
                                    system("cls");
                                    break;
                                }
                                else{
                                        cout<<"Wrong card!"<<endl;
                                    cout<<"Please choose the card again"<<endl<<"suit: "<<endl
                                    <<"(If you don't want to continue this game please enter 0.)"<<endl;
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<"Please choose a card to fold"<<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl
                    <<"(If you don't want to continue this game please enter 0.)"<<endl;//fold card
                    while(cin>>s){
                        if(s=="0"){
                            End=1;
                            break;
                        }
                        else{
                            cout<<"number(1~13): "<<endl<<"(If you don't want to continue this game please enter 0.)"<<endl;
                            cin>>n;
                            if(n==0){
                                End=1;
                                break;
                            }
                            else{
                                pair<int,int> a(suit[s],n);
                                if(FoldCard(a)){
                                    for(int j=0;j<player[0].size();j++){
                                        if(player[0][j].first==suit[s] && player[0][j].second==n){
                                            FoldTotal[0]+=n;
                                            player[0].erase(player[0].begin()+j);
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(flag==1) break;
                                else{
                                    cout<<"Wrong card!"<<endl;
                                    cout<<"Please choose the card again"<<endl<<"suit: "<<endl
                                    <<"(If you don't want to continue this game please enter 0.)"<<endl;
                                    if(flag==1) break;
                                }
                            }
                        }
                    }
                }
                if(End==1){
                    ofstream Record("RecordCard.txt",ios::out);
                    for(int i=0;i<4;i++){
                        Record<<player[i].size()<<" ";
                        for(int j=0;j<player[i].size();j++){
                            Record<<player[i][j].first<<" "<<player[i][j].second<<" ";
                        }
                        Record<<FoldTotal[i]<<" ";
                    }
                    for(int i=0;i<3;i++){
                        for(int j=0;j<4;j++){
                            if(screen[i][j]!=52){
                                Record<<screen[i][j]<<" ";
                            }
                        }
                    }
                    Record.close();
                    return 0;
                }
            }
//---------------------------------------------------------------------------------------------------------------------//人出牌結束
            else{
                if(decide(i)){
                    int Max=0;
                    int position;
                    for(int j=0;j<CanPlay[i].size();j++){
                        if(CanPlay[i][j].second>Max){
                            Max=CanPlay[i][j].second;
                            position=j;
                        }
                    }
                    for(int j=0;j<player[i].size();j++){
                        if(player[i][j].first==CanPlay[i][position].first && player[i][j].second==CanPlay[i][position].second){
                            player[i].erase(player[i].begin()+j);
                            pair<int,int> ChooseCard(CanPlay[i][position].first,CanPlay[i][position].second);
                            cout<<"Computer "<<i<<" sends: "<<ConvertNum[CanPlay[i][position].first]<<" "<<CanPlay[i][position].second<<endl;
                            CanPlay[i].clear();
                            Save(ChooseCard);
                        }
                    }
                }
                else{
                    int Min=14;
                    int position;
                    for(int j=0;j<Fold[i].size();j++){
                        if(Fold[i][j].second<Min){
                            Min=Fold[i][j].second;
                            position=j;
                        }
                    }
                    for(int j=0;j<player[i].size();j++){
                        if(player[i][j].first==Fold[i][position].first && player[i][j].second==Fold[i][position].second){
                            FoldTotal[i]+=player[i][j].second;
                            player[i].erase(player[i].begin()+j);
                            cout<<"Computer "<<i<<" folds card"<<endl;
                            Fold[i].clear();
                        }
                    }
                }
            }
        }
    }
    Print();
    ifstream Record("RecordCard.txt",ios::in);
    if(!Record){
        cout<<"The file could not be opened."<<endl;
        exit(1);
    }
}//主程式
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Card::read(){
    ifstream Record("RecordCard.txt",ios::in);
    int Size,point[4],indexValue,first,second;
    for(int i=0;i<4;i++){
        player[i].clear();
        Record>>Size;
        for(int j=0;j<Size;j++){
            Record>>first>>second;
            player[i].push_back(make_pair(first,second));
        }
        Record>>FoldTotal[i];
    }
    while(Record>>indexValue){
        if((indexValue)%13<6){
            switch((indexValue)/13){
                case 0: screen[2][0]=indexValue; break;
                case 1: screen[2][1]=indexValue; break;
                case 2: screen[2][2]=indexValue; break;
                case 3: screen[2][3]=indexValue; break;
            }
        }
        else if((indexValue)%13==6){
            switch((indexValue)/13){
                case 0: screen[1][0]=indexValue; break;
                case 1: screen[1][1]=indexValue; break;
                case 2: screen[1][2]=indexValue; break;
                case 3: screen[1][3]=indexValue; break;
            }
        }
        else if((indexValue)%13>6){
            switch((indexValue)/13){
                case 0: screen[0][0]=indexValue; break;
                case 1: screen[0][1]=indexValue; break;
                case 2: screen[0][2]=indexValue; break;
                case 3: screen[0][3]=indexValue; break;
            }
        }
    }
    Record.close();
    Print();
}
//-------------------------------------------------------------------------------------------------------------------------------
bool Card::Endfun(){
    if(End==1){
        return true;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
bool Card::decide(int a){
    for(int i=0;i<player[a].size();i++){
        int havecard=0;
        for(int j=0;j<4;j++){
            if(screen[1][j]==52  && player[a][i].first==j+1 && player[a][i].second==7){
                CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                havecard=1;
                break;
            }
//----------------------------------------------------------------------------------------------=7
            else if(screen[1][j]!=52){
                if(screen[0][j]==52 && player[a][i].first==j+1 && player[a][i].second==8){
                    CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                    havecard=1;
                    break;
                }
                else if(screen[0][j]!=52 && player[a][i].first==j+1){
                    if((screen[0][j]+2)%13==0  && player[a][i].second==13){
                        CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                        havecard=1;
                        break;
                    }
                    else if(player[a][i].second==(screen[0][j]+1)%13+1 && player[a][i].second!=1){
                        CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                        havecard=1;
                        break;
                    }

                }
//------------------------PrintHuman();---------------------------------------------------------------------->7
                if(screen[2][j]==52 && player[a][i].first==j+1 && player[a][i].second==6){
                    CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                    havecard=1;
                    break;
                }
                else if(screen[2][j]!=52 && player[a][i].first==j+1 && player[a][i].second==(screen[2][j]+1)%13-1){
                    CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                    havecard=1;
                    break;
                }
//-----------------------------------------------------------------------------------------------<7
            }
        }
        if(havecard==0){
            Fold[a].push_back(make_pair(player[a][i].first,player[a][i].second));
        }
    }
    if(!CanPlay[a].empty()){
        return true;
    }
    else{
        return false;
    }
}//判斷是否可出牌
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Card::Save(pair<int,int> deck){
    //int flag=1;
    for(int i=0;i<4;i++){
        if(deck.first==i+1){
            if(screen[1][i]==52 && deck.second==7){
                screen[1][i]=i*13+6;
            }
            else if(screen[1][i]!=52){
                if(screen[0][i]==52 && deck.second==8){
                    screen[0][i]=i*13+7;
                }
                else if(screen[0][i]!=52){
                    if((screen[0][i]+1)%13==0 && deck.second==13){
                        screen[0][i]=i*13+12;
                    }
                    else if(deck.second==(screen[0][i]+1)%13+1 && deck.second!=1){
                        screen[0][i]=i*13+(deck.second-1);
                    }

                }ifstream Record("RecordCard.txt",ios::in);
    if(!Record){
        cout<<"The file could not be opened."<<endl;
        exit(1);
    }
                if(screen[2][i]==52 && deck.second==6){
                    screen[2][i]=i*13+5;
                }
                else if(screen[2][i]!=52 && deck.second==(screen[2][i]+1)%13-1){
                    screen[2][i]=i*13+(deck.second-1);
                }
            }
        }
    }
}//出牌
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Card::FoldCard(pair<int,int> deck){
    int flag=0;
    for(int i=0;i<player[0].size();i++){
        if(deck.first==player[0][i].first && deck.second==player[0][i].second){
            flag=1;;
        }
    }
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}//蓋牌
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Card::Count(){
    string winner[11]={" ***   *******************   *** ",
                       "*    * ******************* *    *",
                       "*     *********************     *",
                       " *     *******************     * ",
                       "   *   *******************   *   ",
                       "      *  ***************  *      ",
                       "         * *********** *         ",
                       "              *****              ",
                       "               ***               ",
                       "            *********            ",
                       "            *********            "};
    cout<<"You fold "<<FoldTotal[0]<<" points"<<endl;
    for(int i=1;i<4;i++){
        cout<<"Computer "<<i<<" folds "<<FoldTotal[i]<<" points"<<endl;
    }
    cout<<endl;
    int Min=200;
    for(int i=0;i<4;i++){
        if(FoldTotal[i]<Min){
            Min=FoldTotal[i];
        }
    }
    if(Min==FoldTotal[0]){
        for(int i=0;i<11;i++){
            cout<<winner[i]<<endl;
        }
        cout<<"You are a winner!!!"<<endl;
    }
    else{
        cout<<"You are a loser!!!"<<endl;
    }
    ofstream Record("RecordCard.txt",ios::out);
    if(!Record){
        cout<<"The file could not be opened."<<endl;
        exit(1);
    }
    Record.close();
}//數最後剩下牌的點數
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Card::Print(){
    cout<<"Card on the screen :"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<13;j++){
            for(int k=0;k<4;k++){
                if(screen[i][k]!=52){
                    switch(index[screen[i][k]].first){
                        case 1:
                            SetColor(15);
                            Spade(num[index[screen[i][k]].second],j);
                            break;
                        case 2:
                            SetColor(12);
                            Heart(num[index[screen[i][k]].second],j);
                            SetColor(15);
                            break;
                        case 3:
                            SetColor(15);
                            Club(num[index[screen[i][k]].second],j);
                            break;
                        case 4:
                            SetColor(12);
                            Diamond(num[index[screen[i][k]].second],j);
                            SetColor(15);
                            break;
                    }
                    cout<<setw(3)<<" ";
                }
                else{
                    cout<<setw(18)<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    if(!player[0].empty()){
        PrintHuman();
        run();
    }
}
