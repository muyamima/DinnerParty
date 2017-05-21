# DinnerParty
Organisational aid for DinnerParties

#### Table of Content
---
 * [DinnerParty Definition](https://github.com/muyamima/DinnerParty#1-dinnerparty-definition)
 * [Procedure](https://github.com/muyamima/DinnerParty#2-procedure)
 * [Information handling](https://github.com/muyamima/DinnerParty#3-information-handling)
 * [Appendices](https://github.com/muyamima/DinnerParty#x-appendices)

#### 1. DinnerParty Definition
---
 Sometimes also called:
 > „Run and Dine“ (also „Run&Dine“), „Flying Dinner“ or „Switching Tables“. In German sometimes "Rudirockt" or simplified to "Rudi".

 Translated from [de.wikipedia.org](http://de.wikipedia.org/wiki/Running_Dinner)

 In the event teams are jumbled up and assigned timeslots and courses to prepare for themselves and two guest teams.
 Usually one of either starter, main course or dessert.
 In addition each team is then also provided with two addresses and timeslots for the other courses to which they are invited.
 Optionally at the end a big party can then be organised to meet all participants once more.

#### 2. Procedure
---
##### 1. Sign-up
 When registering, Teams are required to enter:
  * A team name.
  * Member name(s).
  * Contact information. A valid telephone number as well as a valid emailaddress.
  * Address for recieving guests. Optional extra directions. Floor, doornumbers, doorcodes, ...
  * Team members food and pet allergies.
  * Potential allergens present at the address. Pets that live there or have visited in the last couple of days.
  * Dietary requirements.
  
##### 2. Information Check
 The applications are read and checked for missing information or duplicates according to:
  * Similar first name and / or last name.
  * Similar address.
  * Similar Telephone number.
  
 If conflict, user input is required to procede.
  * Enter missing information.
  * Remove entry with missing information.
  * Remove duplicate.
 
##### 3. Mixing
 Special requests and constraints can be specified.
  * Assure certain meetings.
  * Assure certain destinations.
  * Prevent certain meetings.
  * Prevent certain destinations.
 
 Mixing produces a set of itineraries that are to be followed by each corresponding team.
 Assembling takes place within these constraints:
  * Pet allergy teams can **NOT** be assigned to courses with that specific allergen.
  * Avoid food allergy and dietary requirements accumulation in meetings.
  * Avoid food allergy and dietary requirements accumulation along itineraries.
  * Singles are coupled where possible to make new teams. Left over singles, if present, are attached to random combinatory team if present or random team signup.
  * Left over teams are teamed up with a random team for main course and join random starters and desserts.
  
   |Teams cases|Left over Teams|
   |---|---|
   |NoTeams % 3 = 0| . . .|
   |1|\* . .|
   |2|\* \* .|
   
   |Singles cases| Left over singles|
   |---|---|
   |NoMembers % 6 = 0| . . .|
   |1|-. . .|
   |2|-- . .|
   |3|---. .|
   |4|---- .|
   |5|-----.|

#### 3. Information handling
---
#####  1. Teams
 Teams consist of two people. Edge cases allow for up to two additional members.
 A Team consists of:
  * 2+(0-1) Members
  * Itinerary

##### 2. Member
 Member information is harvested from the team registration and have the following data tied to them:
  * Name.
  * Email address.
  * Telephone number.
  * Food allergy information.
  * Pet allergy information.
  * Dietary requirements.
  * Link to Team.
     
##### 3. Addresses
 Addresses information is harvested from the team registration and have the following data tied to them: 
  * Exact Address.
  * Optional extra information.
  * Potential allergens.
  * Link to member owning this address.

##### 4. Courses

#### X. Appendices
---
##### 1. regex Telephone number validation
 ```regex
   ^(((\+|0{2})\s?[1-9]\d{0,2})(\s?(\-\s?)?)\(?|0|\()(0\))?(0?[1-9](\d{1,4}?|(\d{1,2}\s\d{1,3})))(\s?(\-\s?)?)(\d{2,4}?\s?(\d{2,3}\s)*\d{2,5})$
 ```
