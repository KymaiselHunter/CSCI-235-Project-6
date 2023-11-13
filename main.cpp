//
//  Main.cpp
//
//  Tests the rest of the class
//
//Name : Kyle Bautista
//Instructor : Dr. Tiziana Ligorio
//Project 5

//

#include <iostream>
using namespace std;

#include "Tavern.hpp"
#include "Character.hpp"

//first main tests task 1
int main()
{
    
    //===========================================================================
    //task 1 modifications
    //===========================================================================

    //test the task 1 actions
    std::cout << "===================================" << std::endl;
    cout << "Test task 1 : actions" << endl;
    std::cout << "===================================" << std::endl;

    //Character(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);
    Character * actionTestCharacter1 = new Character("ActionOne", "HUMAN", 10, 0, 3, false);
    Character * actionTestCharacter2 = new Character("ActionTwo", "ELF", 7, 1, 4, false);

    Tavern * actionsTestTavern = new Tavern();

    actionsTestTavern->enterTavern(actionTestCharacter1);
    actionsTestTavern->enterTavern(actionTestCharacter2);

    cout << "Base Tavern" << endl;
    actionsTestTavern->displayCharacters();
    cout << "\n"; 

    cout << "Action 1 mends mental, action 2 heals" << endl;
    actionTestCharacter1->mendMental();
    actionTestCharacter2->heal();
    actionsTestTavern->displayCharacters();
    cout << "\n"; 

    cout << "Action 2 throws tomato at action 1" << endl;
    actionTestCharacter2->throwTomato(actionTestCharacter1);
    actionsTestTavern->displayCharacters();
    cout << "\n"; 

    cout << "Action 1 and 2 strike each other" << endl;
    actionTestCharacter1->strike(actionTestCharacter2);
    actionTestCharacter2->strike(actionTestCharacter1);
    actionsTestTavern->displayCharacters();
    cout << "\n"; 

}