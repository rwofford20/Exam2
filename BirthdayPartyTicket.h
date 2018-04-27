#ifndef _BIRTHDAY_PARTY_TICKET_H_
#define _BIRTHDAY_PARTY_TICKET_H_

#include <list>
#include <string>
#include "Party.h"
#include "PartyTicket.h"

class BirthdayPartyTicket : public PartyTicket
{
private:
    //Create a pointer to a Party object that this ticket is associated with
    Party * the_party;
    //Create an iterator containing the party goer this ticket is associated with
    std::list<std::string>::iterator me;
    
public:
    //Constructor for creating a BirthdayPartyTicket
    //Parameters are the party which the ticket belongs to and the party goer the ticket is associated with
    BirthdayPartyTicket(Party *the_party, std::list<std::string>::iterator &me) : the_party(the_party), me(me) {}
    
    //Allows the party goer (me) to leave the party (the_party)
    void leave();
};

#endif
