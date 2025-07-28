#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum enRockPaperScissor {Rock = 1, Paper = 2, Scissor = 3};
enum enYesOrNo {y=1,Y=1,n=0,N=0};

struct stGameInfo
{
    short Rounds = 0;
    short ComputerWins = 0;
    short PlayerWins = 0;
    short DrawTimes = 0;
};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

short ReadPlayerChoice(short &PlayerChoice)
{
    cout << "Pleas choose [1]Rock, [2]Paper, [3]Scissor ? ";
    cin >> PlayerChoice;

    return PlayerChoice;
}

short ReadComputerChoice(short &ComputerChoice)
{
    ComputerChoice = RandomNumber(1,3);
    return ComputerChoice;
}

enRockPaperScissor GetPlayerChoice()
{
    short PlayerChoice = 0;
    ReadPlayerChoice(PlayerChoice); 
    
    if (PlayerChoice == 1)
        return enRockPaperScissor::Rock;
    else if (PlayerChoice == 2)
        return enRockPaperScissor::Paper;
    else if (PlayerChoice == 3)
        return enRockPaperScissor::Scissor;
    else
        return enRockPaperScissor::Rock; 
}

enRockPaperScissor GetComputerChoice()
{
    short ComputerChoice = 0;
    ReadComputerChoice(ComputerChoice);
    
    if (ComputerChoice == 1)
        return enRockPaperScissor::Rock;
    else if (ComputerChoice == 2)
        return enRockPaperScissor::Paper;
    else if (ComputerChoice == 3)
        return enRockPaperScissor::Scissor;
    else
        return enRockPaperScissor::Rock;
}

string PrintPlayerChoice(enRockPaperScissor playerChoice)
{
    switch (playerChoice)
    {
        case enRockPaperScissor::Rock: return "Player choice: Rock";
        case enRockPaperScissor::Paper: return "Player choice: Paper";
        case enRockPaperScissor::Scissor: return "Player choice: Scissor";
        default: return "Player choice: Invalid";
    }
}

string PrintComputerChoice(enRockPaperScissor computerChoice)
{
    switch (computerChoice)
    {
        case enRockPaperScissor::Rock: return "Computer choice: Rock";
        case enRockPaperScissor::Paper: return "Computer choice: Paper";
        case enRockPaperScissor::Scissor: return "Computer choice: Scissor";
        default: return "Computer choice: Invalid";
    }
}

string PrintRoundWinner(enRockPaperScissor computerChoice, enRockPaperScissor playerChoice,stGameInfo &Info)
{
    if (computerChoice == playerChoice)
    {
        ++Info.DrawTimes;
         return "Draw";
    }
    
    if ((computerChoice == enRockPaperScissor::Rock && playerChoice == enRockPaperScissor::Scissor) ||
        (computerChoice == enRockPaperScissor::Paper && playerChoice == enRockPaperScissor::Rock) ||
        (computerChoice == enRockPaperScissor::Scissor && playerChoice == enRockPaperScissor::Paper))
    {
        ++Info.ComputerWins;
         return "Computer wins";
    }
    else
    {
        ++Info.PlayerWins;
        return "Player wins";
    }
}

short AskForRounds()
{
    short rounds;

    cout << "Pleas enter how many rounds you want to play 1 to 10 ? ";
    cin >> rounds;

    return rounds;
}

char AskIfPlayerWantsToPlayAgain()
{
    char Awnser;

    cout << "Do you want to Play again ? ";
    cin >> Awnser;

    return Awnser;
}

enYesOrNo GetAwnser()
{
    char TheAwnser = AskIfPlayerWantsToPlayAgain();

    if (TheAwnser == 'Y' || TheAwnser == 'y')
    return enYesOrNo::Y;

    else
    return enYesOrNo::N;
}

void clearScreen()
{    
    cout << "\x1B[2J\x1B[H";
}

void PrintResult(stGameInfo Info)
{
    cout << "\t--------------------------------------------------------\n\n";
    cout << "\t\t       +++ G a m e O v e r +++\n";
    cout << "\t--------------------------------------------------------\n\n";
    cout << "\t-------------------[ Game Results ]---------------------\n\n";
    cout << "\tGame Rounds        : " << Info.Rounds << "\n";
    cout << "\tPlayer won times   : " << Info.PlayerWins << "\n";
    cout << "\tComputer won times : " << Info.ComputerWins << "\n";
    cout << "\tDraw times         : " << Info.DrawTimes << "\n";
    if (Info.PlayerWins > Info.ComputerWins)
    cout << "\tFinle winner       : Player \n";
    else if (Info.ComputerWins > Info.PlayerWins)
    cout << "\tFinle winner       : Computer \n";
    else 
    cout << "\tFinle winner       : No Winner \n\n";
    cout << "\t--------------------------------------------------------\n\n";
}   

void StartGame(stGameInfo Info)
{
   do
   {
     clearScreen();    

     short Rounds = AskForRounds();

     for (int i = 0; i < Rounds; i++)
     {
        cout <<"\n----------------------------Round["<<i+1<<"]---------------------------\n\n";
        enRockPaperScissor PlayerChoice = GetPlayerChoice();
        enRockPaperScissor ComputerChoice = GetComputerChoice();
        cout << PrintPlayerChoice(PlayerChoice) << "\n";
        cout << PrintComputerChoice(ComputerChoice) << "\n";
        cout << PrintRoundWinner(ComputerChoice,PlayerChoice,Info) << "\n";
         ++Info.Rounds;
        cout <<"\n---------------------------------------------------------------\n\n";   
     }
   PrintResult(Info);
   } while (GetAwnser() == enYesOrNo::Y);
   
}

int main()
{
     srand((unsigned)time(NULL));
     stGameInfo Info;
     StartGame(Info);

    return 0;
}