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

    //test the task 1 stack and queue
    std::cout << "===================================" << std::endl;
    cout << "Test task 1 : stack and queue(by kyle)" << endl;
    std::cout << "===================================" << std::endl;
    //reuse previous characters

    actionTestCharacter1->addAction(3);
    actionTestCharacter1->addAction(1);
    actionTestCharacter1->addAction(3);
    actionTestCharacter1->addAction(0);
    actionTestCharacter1->addAction(2);
    actionTestCharacter1->addAction(0);

    //these should not be added
    actionTestCharacter1->addAction(4);
    actionTestCharacter1->addAction(-1);
    
    Buff testBuffOne;
    testBuffOne.name_ = "Ballz";
    testBuffOne.turns_ = 2;

    Buff testBuffTwo;
    testBuffTwo.name_ = "Deez";
    testBuffTwo.turns_ = 3;

    Buff testBuffThree;
    testBuffThree.name_ = "Nuts";
    testBuffThree.turns_ = 1;

    actionTestCharacter2->addBuff(testBuffOne);
    actionTestCharacter2->addBuff(testBuffTwo);
    actionTestCharacter2->addBuff(testBuffThree);


    //enum Action {BUFF_Heal, BUFF_MendMental, ATT_Strike, ATT_ThrowTomato};
    //              0           1               2           3

    cout << "Action test" << endl;
    actionTestCharacter1->printActionQueue();
    cout << endl;

    cout << "buff test" << endl;
    actionTestCharacter2->printBuffStack();
    cout << endl;

    cout << "repeat test(make sure the stack and queue clone didnt mess up)" << endl;

    cout << "Action test 2" << endl;
    actionTestCharacter1->printActionQueue();
    cout << endl;

    cout << "buff test 2" << endl;
    actionTestCharacter2->printBuffStack();
    cout << endl;


    //===========================================================================
    //task 2 modifications
    //===========================================================================

    //test the task 2 simple comparisons, setters and getters
    std::cout << "===================================" << std::endl;
    cout << "Test task 2 : simple comparisons, setters and getters" << endl;
    std::cout << "===================================" << std::endl;

    //list of shit to test
    /*

    void setMainCharacter(Character * pCharacter);
    Character * getMainCharacter() const;
    
    bool levelIsLess(const Character * pLeftCharacter, const Character * pRightCharacter) const;
    bool levelIsGreater(const Character * pLeftCharacter, const Character * pRightCharacter) const;
    bool vitalityIsLess(const Character * pLeftCharacter, const Character * pRightCharacter) const;
    bool vitalityIsGreater(const Character * pLeftCharacter, const Character * pRightCharacter) const;
    
    */

    Tavern * simpleTestTavern = new Tavern();

    //Character(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false);

    //greater dude
    Character * simpleTestCharacterOne = new Character("simpOne", "HUMAN", 5, 5, 5, false);
    
    //less dude
    Character * simpleTestCharacterTwo = new Character("simpTwo", "HUMAN", 1, 1, 1, false);

    simpleTestTavern->enterTavern(simpleTestCharacterOne);
    simpleTestTavern->enterTavern(simpleTestCharacterTwo);

    simpleTestTavern->setMainCharacter(simpleTestCharacterOne);
    cout << "Main Character is: " << endl;
    simpleTestTavern->getMainCharacter()->display();    
    cout << endl;

    simpleTestTavern->setMainCharacter(simpleTestCharacterTwo);
    cout << "Main Character is: " << endl;
    simpleTestTavern->getMainCharacter()->display();    
    cout << endl;

    //main character setter and getter good, now test the comparison functions

    //all outputs should be true, false
    cout << "Level Is Less:" << endl;
    cout << simpleTestTavern->levelIsLess(simpleTestCharacterTwo, simpleTestCharacterOne) << endl;
    cout << simpleTestTavern->levelIsLess(simpleTestCharacterOne, simpleTestCharacterTwo) << endl;
    cout << endl;

    cout << "Level Is Greater:" << endl;
    cout << simpleTestTavern->levelIsGreater(simpleTestCharacterOne, simpleTestCharacterTwo) << endl;
    cout << simpleTestTavern->levelIsGreater(simpleTestCharacterTwo, simpleTestCharacterOne)<< endl;
    cout << endl;

    cout << "vitality Is Less:" << endl;
    cout << simpleTestTavern->vitalityIsLess(simpleTestCharacterTwo, simpleTestCharacterOne) << endl;
    cout << simpleTestTavern->vitalityIsLess(simpleTestCharacterOne, simpleTestCharacterTwo) << endl;
    cout << endl;

    cout << "Level Is Greater:" << endl;
    cout << simpleTestTavern->vitalityIsGreater(simpleTestCharacterOne, simpleTestCharacterTwo) << endl;
    cout << simpleTestTavern->vitalityIsGreater(simpleTestCharacterTwo, simpleTestCharacterOne) << endl;
    cout << endl;


    //===========================================================================
    //task 2 modifications - task 2 combat queue creation
    //===========================================================================   

    //test the task 2 simple comparisons, setters and getters
    std::cout << "===================================" << std::endl;
    cout << "Test task 2 : task 2 combat queue creation" << endl;
    std::cout << "===================================" << std::endl;

    //test using the enemeis csv

    Tavern * actionQueueTestTavern = new Tavern("enemies.csv");

    //check to see if the param construct worked
    cout << "Original characters in this tavern" << endl;
    actionQueueTestTavern->displayCharacters();
    cout << endl;

    //now lets test creating the combat queue
    //first lets print just to double check that it's empty
    cout << "Combat Queue should be empty" << endl;
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    std::cout << "===================================" << std::endl;
    //now we create combat queue
    cout << "Combat queue creation and default filter" << endl;

    actionQueueTestTavern->createCombatQueue();
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    cout << "print the same queue again to make sure nothing has changed and the print isnt deleting the queue" << endl;
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    std::cout << "===================================" << std::endl;
    cout << "Test task 2 : task 2 combat filters" << endl;
    std::cout << "===================================" << std::endl;

    //lvl asc
    cout << "Level asscend" << endl;
    actionQueueTestTavern->createCombatQueue("LVLASC");
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    cout << "Level descend" << endl;
    actionQueueTestTavern->createCombatQueue("LVLDES");
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    cout << "HP asscend" << endl;
    actionQueueTestTavern->createCombatQueue("HPASC");
    actionQueueTestTavern->printCombatQueue();
    cout << endl;

    cout << "HP descend" << endl;
    actionQueueTestTavern->createCombatQueue("HPDES");
    actionQueueTestTavern->printCombatQueue();
    cout << endl;
}