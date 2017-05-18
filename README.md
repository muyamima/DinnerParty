# DinnerParty
Organisational aid for DinnerParties

DinnerParty is intented as an aid for organising "DinnerParties".

#### 1. DinnerParty
 Sometimes also called:
 > „Run and Dine“ (also „Run&Dine“), „Flying Dinner“ or „Switching Tables“. In German sometimes "Rudirockt" or simplified to "Rudi".

 Translated from [de.wikipedia.org](http://de.wikipedia.org/wiki/Running_Dinner)

 In the event teams are jumbled up and assigned timeslots and courses to prepare for themselves and two guest teams.
 Usually one of either starter, main course or dessert.
 In addition each team is then also provided with two addresses and timeslots for the other courses to which they are invited.
 Optionally at the end a big party can then be organised to meet all participants once more.

#### 2. Procedure
##### 1. Sign-up
 When registering Teams are required to enter:
  * A team name.
  * Contact information. A valid telephone number as well as a valid emailaddress.
  * Address for recieving guests. Optional extra directions. Floor, doornumbers, doorcodes, ...
  * Team members food and pet allergies.
  * Potential allergens present at the address. Pets that live there or have visited in the last couple of days.
  * Dietary requirements.
  
##### 2. Mixing

#### 3. Information handling
#####  1. Teams
 Teams consist of two people. Edge cases allow for up to two additional members.
 A Team consists of:
  * 2+(0-2) Members
  * Itinerary

##### 2. Member
 Member information is harvested from the team registration and have the following data tied to them:
  * Name.
  * Email address.
  * Telephone number.
  * Food allergie information.
  * Pet allergie information.
  * Dietary requirements.
  * Link to Team.
  
   
##### 3. Addresses
 Addresses information is harvested from the team registration and have the following data tied to them: 
  * Exact Address.
  * Optional extra information.
  * Potential allergens.
  * Link to member owning this address.

##### 4. Courses

#### X. Appendix
##### 1. regex Telephone number validation
 ```
   ^(((\+|0{2})\s?[1-9]\d{0,2})(\s?(\-\s?)?)\(?|0|\()(0\))?(0?[1-9](\d{1,4}?|(\d{1,2}\s\d{1,3})))(\s?(\-\s?)?)(\d{2,4}?\s?(\d{2,3}\s)*\d{2,5})$
 ```
