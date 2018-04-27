#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
    
private:
    //List that contains party goers in this birthday party
    std::list<std::string> partiers;
    
    //Constructor for creating a Birthday Party
    BirthdayParty() {}
    
    //Birthday class is a friend class of PartyFactory class
    friend class PartyFactory;
public:

    //Add a person to the party
    //Name is party goer's name
    PartyTicket * add(std::string name){
        //Add name to the front of "partiers" list
        partiers.push_front(name);
        
        //Get iterator to the front of the partiers list (points to first item in list)
        std::list<std::string>::iterator iterator = partiers.begin();
        
        //Create a new Birthday Party Ticket
        PartyTicket *BDTicket = NULL;
        BDTicket = new BirthdayPartyTicket(this, iterator);
        
        //Return the new Birthday Party Ticket
        return BDTicket; 
    }
    
    //List everyone currently in the party
    void list() {
        //Iterate through all of the people in the Birthday Party
        for (std::list<std::string>::iterator it = partiers.begin(); it != partiers.end(); it++) {
            //Output what the iterator is pointing to
            std::cout << *it << std::endl;
        }
    }
    
    //Remove the person identified by the iterator from the birthday party
    void remove(std::list<std::string>::iterator it){
        //Someone's getting out of hand -- kick them out
        //Erase the person that the iterator is pointing to
        partiers.erase(it);
    }

};

#endif
