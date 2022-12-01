#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
TEST_CASE("Profile"){
    Profile one;
    Profile two("profile", "Person");

    CHECK(one.getUsername() == "");
    CHECK(two.getUsername() == "profile");

    CHECK(one.getFullName() == " (@)");
    CHECK(two.getFullName() == "Person (@profile)");

    one.setDisplayName("one");
    two.setDisplayName("two");
    CHECK(one.getFullName() == "one (@)");
    CHECK(two.getFullName() == "two (@profile)");

}
TEST_CASE("Network"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == 1);
    CHECK(nw.addUser("mario1", "Mario1") == 1);

    CHECK(nw.addUser("mario", "Mario2") == 0);
    CHECK(nw.addUser("mario 2", "Mario2") == 0);
    CHECK(nw.addUser("mario-2", "Mario2") == 0);

    for(int i = 2; i < 20; i++)
        nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)); 
    CHECK(nw.addUser("yoshi", "Yoshi") == 0);

}
TEST_CASE("Following"){
    Network nw;
    nw.addUser("yoshi", "Yoshi");
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");

    nw.follow("yoshi", "mario");
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi","yoshi");

    CHECK(nw.isfollowing("yoshi", "mario") == true);
    CHECK(nw.isfollowing("mario", "yoshi") == false);
    CHECK(nw.isfollowing("mrio", "luigi") == false);

}