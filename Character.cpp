/*
CSCI235 Fall 2023
Project 4 - Stew of the Day
Georgina Woo
June 29 2023
Character.cpp defines the constructors and private and public function implementation of the Character class
*/

#include "Character.hpp"

/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default enum value: NONE. 
    Default Vitality, Max Armor, and Level: 0.
*/
Character::Character():name_{"NAMELESS"},race_{NONE},vitality_{0},armor_{0},level_{0},enemy_{false}
{
}

/**
Parameterized constructor.
    @param      : The name of the character (a string in UPPERCASE)
    @param      : The race of the character (a string)
    @param      : The character's vitality (a non-negative integer) , with default value 0
    @param      : The character's max armor level (a non-negative integer), with default value 0
    @param      : The character's level (a non-negative integer), with default value 0
    @param      : A flag indicating whether the character is an enemy, with default value false
    @post       : The private members are set to the values of the corresponding parameters. 
                Hint: Notice the default arguments in the parameterized constructor.
                If the given parameters are invalid, the default values are used instead.
*/
Character::Character(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy) : Character()
{
    setName(name); // checks valid name
    setRace(race); // checks valid race
    (vitality >= 0) ? vitality_ = vitality: vitality_ = 0;
    (armor >= 0) ? armor_ = armor: armor_ = 0;
    (level >= 0) ? level_ = level: level_ = 0;
    enemy_ = enemy; 
}

 /**
    @param  : the name of the Character
    @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed. For example, attempting to create a character named "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
    : If the given parameter does not have any valid alphabetical characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string& name)
{
    std::string nameUpper = "";
    for(int i = 0; i<name.size();i++)
    {
        if(std::isalpha(name[i]))
        {
            nameUpper+= toupper(name[i]);
        }
    }
    if(nameUpper != "")
    {
        name_ = nameUpper;
    }
    else
    {
        name_ = "NAMELESS";
    }
}


/**
    @return : the name of the Character
*/
std::string Character::getName() const
{
    return name_;
}


/**
    @param  : the race of the Character (a string)
    @post   : sets the Character's race to the value of the parameter. Valid races: [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
            : If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string& race)
{
    
    if(race == "HUMAN")
    {
        race_ = HUMAN;
    }
    else if(race == "ELF")
    {
        race_ = ELF;
    }
    else if(race == "DWARF")
    {
        race_ = DWARF;
    }
    else if(race == "LIZARD")
    {
        race_ = LIZARD;
    }
    else if(race == "UNDEAD")
    {
        race_ = UNDEAD;
    }
    else
    {
        race_ = NONE;
    }
}


/**
    @return : the race of the Character (a string)
*/
std::string Character::getRace() const
{
    if (race_ == Race::HUMAN)
    {
        return "HUMAN";
    }
    else if (race_ == Race::ELF)
    {
        return "ELF";
    }
    else if (race_ == Race::DWARF)
    {
        return "DWARF";
    }
    else if (race_ == Race::LIZARD)
    {
        return "LIZARD";
    }
    else if (race_ == Race::UNDEAD)
    {
        return "UNDEAD";
    }
    else
    {
        return "NONE";
    }

}


/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
void Character::setVitality(const int& vitality)
{
    if (vitality >= 0)
    {
        vitality_ = vitality;
    }
}


/**
    @return : the value stored in vitality_
*/
int Character::getVitality() const
{
    return vitality_;
}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
void Character::setArmor(const int& armor)
{
    if (armor >= 0)
    {
        armor_ = armor;
    }
}


/**
    @return : the value stored in armor_
*/
int Character::getArmor() const
{
    return armor_;
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/
void Character::setLevel(const int& level)
{
    if (level >= 0)
    {
        level_ = level;
    }
}


/**
    @return : the value stored in level_
*/
int Character::getLevel() const
{
    return level_;
}

/**
    @post   : sets the enemy flag to true
*/
void Character::setEnemy()
{
    enemy_ = true;
}

/**
    @return true if the character is an enemy, false otherwise

Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
*/
bool Character::isEnemy() const
{
    return enemy_;
}



/**
        @param     	: A reference to the right hand side of the == operator.
        @return     : Returns true if the right hand side character is "equal", false otherwise. 									
                     Two characters are equal if they have the same name, same race, same level 									
                     and are either both an enemy or not.

        Note: By this definition, only some of the character's attributes must be equal for two characters to be deemed "equal".

        Example: In order for character1 to be == to character2 we only need:
        - The same name
        - The same race
         - The same level
        - They must either be both an enemy or not
*/
bool Character::operator==(const Character& rhs) const
{
    return(name_ == rhs.getName() && getRace() == rhs.getRace() && level_ == rhs.getLevel() && enemy_ == rhs.isEnemy());
}

/**
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
*/
bool Character::operator!=(const Character& rhs) const
{
    return(!(*this == rhs));
}

/**
 @post     : displays Character data in the form:
"[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
*/
void Character::display() const
{
    std::cout<<name_<<" is a Level "<<level_<<" "<<getRace()<<
    ". \nVitality: "<<vitality_<<
    "\nMax Armor: "<<armor_<<" \n"<<
    (enemy_ ? "They are an enemy.\n" : "They are not an enemy.\n");
}


//===========================================================================
//task 1 modifications
//===========================================================================
/** 
 * BUFF ACTIONS
 * 
 * heal 
 * mendMetal
 * 
 * */

/**
    @pre: This function is called to execute the Action BUFF_Heal
    @post: Increases the character's vitality by 2
*/
void Character::heal()
{
    this->setVitality(this->getVitality() + 2);
}

/**
    @pre: This function is called to execute the Action BUFF_MendMetal
    @post: Increases the character's armor by 2
*/
void Character::mendMetal()
{
    this->setArmor(this->getArmor() + 2);
}


/** 
 * ATTACK ACTIONS
 * 
 * strike
 * throwTomato
 * 
 * */

/**
    @pre: This function is called to execute the Action ATT_Strike
    @param: A pointer to a character target
    @post: Deals 2 points of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they lose 1 vitality point.
*/
void Character::strike(Character * pCharacter)
{
    //if the armor is 2 or more then just the armor is affected
    if(pCharacter->getArmor() >= 2) pCharacter->setArmor(pCharacter->getArmor()-2);
    else// if it's lower than 2, than the health will be affected as well
    {
        //loss of vitality depends on how much armor they have
        pCharacter->setVitality(pCharacter->getVitality() - (2 - pCharacter->getArmor()));

        //no matter what, armor will become 0 here
        pCharacter->setArmor(0);
    }
}

/**
    @pre: This function is called to  execute the Action ATT_ThrowTomato
    @param: A pointer to a character target
    @post: Deals 1 point of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they don't lose any vitality points. Your character gains 1 vitality point (as laughter is the best medicine).
*/
void Character::throwTomato(Character * pCharacter)
{
    //very similar to last method

    //if the armor is any armor, just armor will be affected
    //else means no armor, then health only affected
    if(pCharacter->getArmor() > 0) pCharacter->setArmor(pCharacter->getArmor()-1);
    else pCharacter->setVitality(pCharacter->getVitality() - 1);

    //always increase health by 1
    this->setVitality(this->getVitality() + 1);
}

//===========================================================================
//task 2 modifications(initial from first doing task 1)
//adding stuff to the queues
//===========================================================================
/**
    @pre: the int is within the enum(return false if not fullfilled)
    @param: An int reference for the correspoinding added action
    @post: adds action to the back of the action_queue_
    @return: if it is added sucessfully
*/
bool Character::addAction(const int &pAction)
{
    //if action int is not in scope, exit
    if(pAction > 3 || pAction < 0)
    {
        return false;
    }

    action_queue_.push(pAction);
    return true;
}

/**
    @param: reference to the buff being added
    @post: adds buff to the top of the buff_stack_
*/
void Character::addBuff(const Buff &pBuff)
{
    buff_stack_.push(pBuff);
}

//===========================================================================
//Kyle's Test methods
//===========================================================================
//two methods, one that prints the stack, one that prints the queue

/**
    @post: prints the entire stack by using copy constructor for a new stack, then popping all items while printing
    //top to bottom
*/
void Character::printBuffStack()
{
    std::stack<Buff> temp = buff_stack_;

    std::cout << "Buff stack from top to bottom" << std::endl;
    while(!temp.empty())
    {
        std::cout << " Buff: " << temp.top().name_ << " | Turns: " << temp.top().turns_ << std::endl; 
        temp.pop();
    }
    std::cout << "End of buff stack\n" << std::endl;
}

/**
    @post: prints the entire queue by using copy constructor for a new queue, then popping all items while printing
    //front to back
*/
void Character::printActionQueue()
{
    std::queue<int> temp = action_queue_;

    //enum Action {BUFF_Heal, BUFF_MendMental, ATT_Strike, ATT_ThrowTomato};
    //              0           1               2           3

    std::cout << "Action Queue from front to back" << std::endl;
    while(!temp.empty())
    {
        std::string tempName = "Out of bounds";
        if(temp.front() == 0) tempName = "Buff_Heal";
        else if(temp.front() == 1) tempName = "Buff_MendMental";
        else if(temp.front() == 2) tempName = "ATT_Strike";
        else if(temp.front() == 3) tempName = "ATT_ThrowTomato";

        std::cout << "Action Name: " << tempName << " | Action Number: " << temp.front() << std::endl;

        temp.pop();
    }
    
    std::cout << "End of Action Queue\n" << std::endl;
}

//===========================================================================
//task 2 modifications (while doing task 2)
//===========================================================================
/**
    @post: remove all  the actions in the action_queue_
*/
void Character::clearActionQueue()
{
    while(!action_queue_.empty())
    {
        action_queue_.pop();
    }
}

/**
    @pre: BuffStack is not empty
    @post: applies the buff and decrements a turn
    @return: string of the buff being applied
*/
std::string Character::applyBuff()
{
    if(buff_stack_.empty()) return "No Buff";

    std::string buffName = buff_stack_.top().name_;

    if(buff_stack_.top().name_ == "BUFF_Heal") this->heal();
    else if(buff_stack_.top().name_ == "BUFF_MendMeta") this->mendMetal();

    buff_stack_.top().turns_--;
    if(buff_stack_.top().turns_ <= 0) buff_stack_.pop();

    return buffName;
}

/**
    @return : bool if Buff stack is empty or not
*/
bool Character::isBuffStackEmpty()
{
    return buff_stack_.empty();
}

/**
    @return : bool if action_queue_ is empty
*/
bool Character::isActionQueueEmpty()
{
    return isActionQueueEmpty();
}
