#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("Classifies Temperature Breach according to Cooling Type") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,25) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,25) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,25) == NORMAL);
}
TEST_CASE("Check and Alert") {
  BatteryCharacter BtrChar;
  BtrChar.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, BtrChar, 30);
  checkAndAlert(TO_EMAIL, BtrChar, 30);
  checkAndAlert(TO_EMAIL, BtrChar, -10);
  checkAndAlert(TO_EMAIL, BtrChar, 40);
}
