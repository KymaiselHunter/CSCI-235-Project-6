/*
CSCI235 Fall 2023
Project 3 - Tavern Class
Georgina Woo
June 20 2023
Taven.cpp declares the Tavern class along with its private and public members
*/
#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}



/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
    Tavern::Tavern(const std::string& filename)
    {
      std::ifstream fin(filename);
      std::string line;
      std::getline(fin, line);
      std::string name, race, string_vitality, string_armor, string_level, string_enemy;
      int vitality, armor, level;
      bool enemy;
      
      while(std::getline(fin, line))
      {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, race, ',');

        std::getline(iss, string_vitality, ',');
        std::istringstream(string_vitality) >> vitality;

        std::getline(iss, string_armor, ',');
        std::istringstream(string_armor) >> armor;

        std::getline(iss, string_level, ',');
        std::istringstream(string_level) >> level;

        std::getline(iss, string_enemy, ',');
        std::istringstream(string_enemy) >> enemy;
        Character* character = new Character(name, race, vitality, armor, level, enemy);
        enterTavern(character);
      }
    }


/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}







/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index]->getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }

  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}


/**
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {
    items_[i]->display();
  }
}


/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {
      items_[i]->display();
    }
  }
}






/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}


//===========================================================================
//task 2 modifications - task 2 public functions
//===========================================================================   

/**
    @param: a Character pointer 
    @post: sets the Tavern's main character to the pointer that is given
*/
void Tavern::setMainCharacter(Character * pCharacter)
{
  main_character_ = pCharacter;
}

/**
  @return: a pointer to the main character in the Tavern, nullptr if there is no main character
*/
Character * Tavern::getMainCharacter() const
{
  return main_character_;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(const Character * pLeftCharacter, const Character * pRightCharacter) const
{
  if(pLeftCharacter->getLevel() < pRightCharacter->getLevel()) return true;
  else return false;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's level is greater than the rhs Character's level
*/
bool Tavern::levelIsGreater(const Character * pLeftCharacter, const Character * pRightCharacter) const
{
  if(pLeftCharacter->getLevel() > pRightCharacter->getLevel()) return true;
  else return false;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is less than the rhs Character's vitality
*/
bool Tavern::vitalityIsLess(const Character * pLeftCharacter, const Character * pRightCharacter) const
{
  if(pLeftCharacter->getVitality() < pRightCharacter->getVitality()) return true;
  else return false;
}

/**
  @param: two Character pointers
  @return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(const Character * pLeftCharacter, const Character * pRightCharacter) const
{
  if(pLeftCharacter->getVitality() > pRightCharacter->getVitality()) return true;
  else return false;
}



//===========================================================================
//task 2 modifications - task 2 combat queue creation
//===========================================================================   

//combat queue stuff
//everything else before this are relatively easy and will be used for the follwoing methods
//

#include <algorithm>

/**
  @pre  : The combat queue should be emptied before the characters are added to the queue
  @param  : A string reference to a sorting filter with a default value of "NONE"
  @post   : With default filter "NONE": add every character marked as an enemy to the combat queue
    : With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
    : With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
    : With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
    : With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
void Tavern::createCombatQueue(const std::string &pFilter)
{
  while(!combat_queue_.empty())
  {
    combat_queue_.pop();
  }

  //temp enemy Array to retrieve all enemies from tavern to later sort
  std::vector<Character*> enemyArray;
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->isEnemy()) enemyArray.push_back(items_[i]);  
    if(enemyArray.size() == this->num_enemies_) break;
  }

  //sort based on filter, if not any of these, do not sort
  if(pFilter == "LVLASC")
  {
    std::sort(enemyArray.begin(), enemyArray.end(), [this](const Character * pLeftCharacter, const Character * pRightCharacter)
    {
        return this->levelIsLess(pLeftCharacter, pRightCharacter);
    });
  }
  else if(pFilter == "LVLDES")
  {
    std::sort(enemyArray.begin(), enemyArray.end(), [this](const Character * pLeftCharacter, const Character * pRightCharacter)
    {
        return this->levelIsGreater(pLeftCharacter, pRightCharacter);
    });
  }
  else if(pFilter == "HPASC")
  {
    std::sort(enemyArray.begin(), enemyArray.end(), [this](const Character * pLeftCharacter, const Character * pRightCharacter)
    {
        return this->vitalityIsLess(pLeftCharacter, pRightCharacter);
    });
  }
  else if(pFilter == "HPDES")
  {
    std::sort(enemyArray.begin(), enemyArray.end(), [this](const Character * pLeftCharacter, const Character * pRightCharacter)
    {
        return this->vitalityIsGreater(pLeftCharacter, pRightCharacter);
    });
  }

  //push the sorted array elements to the queue
  for(int i = 0; i < enemyArray.size(); i++)
  {
    combat_queue_.push(enemyArray[i]);
  }
  

}

/**
  @post   : returns a pointer to the Character at the front of the Combat Queue. 
          : If there are no characters in the queue, return nullptr
*/
Character * Tavern::getTarget() const
{
  return combat_queue_.front();
}

/**
  @post : Prints the details of each character in the combat queue in the following form:
        : [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue() const
{
  //steal code from my print character action queue

  std::queue<Character *> temp = combat_queue_;

  //std::cout << "Action Queue from front to back" << std::endl;
  while(!temp.empty())
  {
      temp.front()->display();

      temp.pop();
  }
  
  //std::cout << "End of Action Queue\n" << std::endl;
}