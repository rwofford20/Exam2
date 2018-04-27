#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

/**
* DinnerParty is derived from Party
*/
class DinnerParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

	/**
	* Constructor for creating a DinnerParty
	*/
	DinnerParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
        
        //Add name to the front of room
        room.push_front(name);
        
        //Get iterator to the front of the room (points to the first item in the list)
        std:: list<std::string>::iterator iterator = room.begin();
        
        //Create a new Dinner Party ticket
        PartyTicket *DPTicket = NULL;
        DPTicket = new DinnerPartyTicket(this, iterator);
        
        //Return the new Dinner Party ticket
        return DPTicket;
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
        //(See functors project)
        //Iterate through all of the people at the party
        for (std::list<std::string>::iterator it = room.begin(); it != room.end(); it++) {
            //Output the person the iterator is pointing to
            std::cout << *it << std::endl;
        }
    }
 

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		//Someone's getting out of hand -- kick them out
        //Erase the person that the iterator is pointing to
       room.erase(it);
	}
    };
#endif
