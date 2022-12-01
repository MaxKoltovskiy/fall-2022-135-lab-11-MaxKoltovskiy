#include <iostream>
#include "profile.h"
#include "network.h"

int main()
{
    Profile prof1("theodore", "Ted");
    std::cout<< "The username of this profile is \""<< prof1.getUsername()<< "\"\n";
    std::cout<< "The full name of this profile is \""<< prof1.getFullName()<< "\"\n";
    prof1.setDisplayName("Ted Stevens");
    std::cout<< "After changing the display name, the full name is \""<< prof1.getFullName()<< "\"\n";

    std::cout<< "\n-----------------------------------------------------------------------------------\n";

    Network netw;
    std::string usrname = "jefferson", dspname = "Jeffery";
    netw.addUser(usrname, dspname);
    std::cout<< "Added user to network with username \""<< usrname<< "\" and display name \""<< dspname<< "\"\n";

    usrname = "fgolberg", dspname = "Frank Goldberg";
    netw.addUser(usrname, dspname);
    std::cout<< "Added user to network with username \""<< usrname<< "\" and display name \""<< dspname<< "\"\n";

    std::cout<< "\n-----------------------------------------------------------------------------------\n";



}