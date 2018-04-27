#include "BirthdayPartyTicket.h"
#include "BirthdayParty.h"

/**
* Implements the leave method
*/
void BirthdayPartyTicket::leave() {
	//Implement leave for birthday parties
    //Down-cast base class to derived class
    BirthdayParty * actual_party = dynamic_cast<BirthdayParty *>(the_party);
    
    //Call remove BirthdayParty remove method to erase party goers identified by "me"
    actual_party->remove(me);
}
