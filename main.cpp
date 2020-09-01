#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Input_Handling.h"
#include <ctime>
#include <cstdlib>
#include "RivalAI.h"
#include "RivalAICommand.h"

using namespace std;

int main() {
    srand(time(NULL));

    cout << "ASCII Pokemon Game 2019" << endl;
    cout << "                                  ,'\\" << endl;
    cout << "     _.----.       ____         ,'  _\\   ___    ___     ____" << endl;
    cout << " _,-'       `.    |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
    cout << " \\     __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
    cout << "  \\    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
    cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
    cout << "    \\     ,-'/  / \\  \\   ,'   | \\/ / ,`.|         /  / \\ \\  |     |" << endl;
    cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
    cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
    cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
    cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;

    Model model;
    View view = View();
    model.ShowStatus();
    model.Display(view);
    view.clear();
    char response;
    cout << "To move, type m followed by the ID of the pokemon and the coordinates you want to move to. For example, m 1 20 20 will move pokemon 1 to location 20,20." << endl;
    cout << "Moving around generates Pokedollars, but costs stamina. If your stamina reaches 0, that pokemon can no longer be used." << endl;
    cout << "You can recover stamina at the cost of Pokedollars at the Pokemon Center ('c') or you can win money and experience points by training at the Pokemon Gym ('g')" << endl;
    cout << "Once your pokemon are sufficiently trained, you can go defeat rivals in the Battle Arena. " << endl;
    cout << "To enter the various buildings, use 'c', 'g', or 'a' followed by the ID of the pokemon, followed by the ID of the building. For example, c 1 1 will move pokemon 1 to center 1." << endl;
    cout << "While in the appropriate building, you can use 'r' to recover, 't' to train, or 'b' to battle. Use the letter following by the pokemon ID,"
            "followed by the amount of currency wanted." << endl;
    cout << "For example, r 1 10 will cause pokemon 1 to recover 10 health points if you are in the Pokemon Center and have enough Pokedollars. " << endl;
    cout << "While in battle, advancing the time will cause you to be prompted to choose a move. Select a number to use different moves!" << endl;
    cout << "All commands take time once entered, to advance the time by one step, use v, to advance it by five steps, use x. Use s to cancel commands." << endl;
    cout << "As a bonus, there is also a trading hub! Use 'h' to move to the hub, then 'j' followed by the pokemon ID to trade your pokemon for a new one. Remember your new pokemon might have a different ID!" << endl;
    cout << "Use 'q' to quit the game. " << endl;
    cout << "AI mode activates RivalAI, who will play the game much like you will. Try to level up before he does!" << endl;
    cout << "To win, beat all the gyms! Defeating rivals isn't necessary, but battles are fun! You'll lose if all your pokemon run out of stamina." << endl;
    cout << "Would you like to play in AI mode? ('y' or 'n') ";
    cin >> response;
    Point2D Loc;
    int ID1, ID2, x = 0, y = 0;
    int i = 1;
    unsigned int stamina_amount, unit_amount;
    char UserInput = ' ';
    char AI_Input = ' ';
    char Type = ' ';
    while (true) {
        cout << "Enter command: ";
        try {
            cin >> UserInput;
            if (cin.fail()) {
                throw Invalid_Input("Invalid input, please try again. ");
            }
            switch (UserInput) {
                case 'm':
                    cin >> ID1 >> Loc.x >> Loc.y;
                    model.ShowStatus();
                    GameCommand().DoMoveCommand(model, ID1, Loc);
                    model.Display(view);
                    break;
                case 'g':
                    cin >> ID1 >> ID2;
                    model.ShowStatus();
                    GameCommand().DoMoveToGymCommand(model, ID1, ID2);
                    model.Display(view);
                    break;
                case 'c':
                    cin >> ID1 >> ID2;
                    model.ShowStatus();
                    GameCommand().DoMoveToCenterCommand(model, ID1, ID2);
                    model.Display(view);
                    break;
                case 'a':
                    cin >> ID1 >> ID2;
                    model.ShowStatus();
                    GameCommand().DoMoveToArenaCommand(model, ID1, ID2);
                    model.Display(view);
                    break;
                case 'h':
                    cin >> ID1 >> ID2;
                    model.ShowStatus();
                    GameCommand().DoMoveToHubCommand(model, ID1, ID2);
                    model.Display(view);
                    break;
                case 's':
                    cin >> ID1;
                    model.ShowStatus();
                    GameCommand().DoStopCommand(model, ID1);
                    model.Display(view);
                    break;
                case 'r':
                    cin >> ID1 >> stamina_amount;
                    model.ShowStatus();
                    GameCommand().DoRecoverInCenterCommand(model, ID1, stamina_amount);
                    model.Display(view);
                    break;
                case 't':
                    cin >> ID1 >> unit_amount;
                    model.ShowStatus();
                    GameCommand().DoTrainInGymCommand(model, ID1, unit_amount);
                    model.Display(view);
                    break;
                case 'b':
                    cin >> ID1 >> ID2;
                    model.ShowStatus();
                    GameCommand().DoBattleCommand(model, ID1, ID2);
                    model.Display(view);
                    break;
                case 'v':
                    GameCommand().DoGoCommand(model, view);
                    break;
                case 'x':
                    GameCommand().DoRunCommand(model, view);
                    break;
                case 'n':
                    cin >> Type >> ID1 >> x >> y;
                    model.ShowStatus();
                    GameCommand().CreateNewObjectCommand(model, Type, ID1, x, y);
                    model.Display(view);
                    break;
                case 'j':
                    cin >> ID1;
                    model.ShowStatus();
                    GameCommand().DoTradeCommand(model, ID1);
                    model.Display(view);
                    break;
                case 'q':
                    cout << "Program terminated" << endl;
                    return 0;
                default:
                    throw Invalid_Input("Invalid input, please try again. ");
            }
        }
        catch (Invalid_Input &except) {
            cout << "ERROR: " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

        if (response == 'y') {
            Point2D Loc2; Loc2.x = rand() % 21; Loc2.y = rand() % 21;
            ID1 = '9';
            ID2 = (rand() % 2) + 1;
            if (UserInput == 'v' || UserInput == 'x') {
                if (UserInput == 's')
                    AI_Input = 's';
            }
                else {
                    AI_Input = model.GetRivalAIPtr('9')->AI_Controller();
                    cout << "The Rival AI chose " << AI_Input << "!" << endl;
                switch (AI_Input) {
                    case 'm':
                        RivalAICommand().DoMoveCommand(model, ID1, Loc2);
                        break;
                    case 'g':
                         RivalAICommand().DoMoveToGymCommand(model, ID1, ID2);
                        break;
                    case 'c':
                        RivalAICommand().DoMoveToCenterCommand(model, ID1, ID2);
                        break;
                    case 'a':
                        RivalAICommand().DoMoveToArenaCommand(model, ID1, 1);
                        break;
                    case 's':
                        RivalAICommand().DoStopCommand(model, ID1);
                        break;
                    case 'r':
                        stamina_amount = model.GetRivalAIPtr('9')->stamina_amount_finder();
                        RivalAICommand().DoRecoverInCenterCommand(model, ID1, stamina_amount);
                        break;
                    case 't':
                        unit_amount = model.GetRivalAIPtr('9')->training_unit_amount_finder();
                        RivalAICommand().DoTrainInGymCommand(model, ID1, unit_amount);
                        break;
                    case 'b':
                        RivalAICommand().DoBattleCommand(model, ID1, ID2);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}