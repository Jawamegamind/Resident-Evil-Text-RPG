#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>

using namespace std;

void HUD(); //Declaring functions
void Combat();
void CombatHUD();
void CreateEntity();
void story();
void story1();
void story2();
void story3();
void story4();
void story5();
void story6();
void story7();
void story8();
void story9();
void story10();
void story11();
void storyend();
void character();
void speedoftext();
void LevelUp();
void CombatBossHUD();
void CombatBoss();


int level=1; //Declaring global variables
int xp=0;
int health=0;
int totalHealth=0;
int maxHealth=0;
int nextLevel=0;
int heal=0;
int entityxp=0;
int entitylevel=0;
int entityhp=0;
int strength=0;
int luck=0;
int stealth=0;
int textspeed=0;
int encounters=0;
int characterdamage=0;
int tyranthp=0;

string charactername=" ";
string EntityNames[]={"Zombie", "Licker", "Zombified Dog", "Mutated Arachanid"};//Entity array
int numberofentities=4;
string currententity=" ";

int main()
{
     cout << "--------------------" << " Resident Evil " << "--------------------" <<endl;
     speedoftext();
     story();
     character();
      int i=0;
      int j=0;
      int k=0;
      totalHealth=health;
      maxHealth=totalHealth;
      nextLevel=76;
      cout << "Entering the world of survival horror...";
      Sleep(600);
      system("cls");

      story1();
      HUD();
      return 0;


}

void story(void) //First segment of story
{

    int i=0;

    string story_text= "For the past couple weeks mysterious reports have been originating about attacks in the Arklay mountains.\nAs a member of the Special Tactics and Rescue Service you have been assigned to investigate these mysterious happenings.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);//Sleep function causes a delay between each character of a certain number of milliseconds (here identified by textspeed) through a loop
        i++;
    }
    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story1(void)//Second part of the story
{

    int i=0;

    string story_text= "You make it into the mansion designated for investigation. With you are Albert Wesker and S.T.A.R.S officer Rebecca\nChambers. You go over your current options and decide to split up to cover more ground.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void character(void)//A character choosing function which takes input from user and chooses appropriate character
{
string choice;
cout << "Choose your character to accompany you in the world of survival horror" <<endl;
 int i=0;
 int j=0;
 int k=0;
 string Chris= "Character Name: Chris Redfield\n"
                  "Strength=10\n"
                  "Stealth=5\n"
                  "Luck=5\n"
                  "Health=100\n";

                  while(Chris[i] != '\0')
                  {
                      cout << Chris[i];
                      Sleep(textspeed);
                      i++;
                  }
                  cout <<endl;

     string Leon= "Character Name: Leon Kennedy\n"
                  "Strength=8\n"
                  "Stealth=8\n"
                  "Luck=5\n"
                  "Health=85\n";

                  while(Leon[j] != '\0')
                  {
                      cout << Leon[j];
                      Sleep(textspeed);
                      j++;
                  }
                  cout <<endl;

     string Jill= "Character Name: Jill Valentine\n"
                  "Strength=6\n"
                  "Stealth=9\n"
                  "Luck=7\n"
                  "Health=80\n";

                  while(Jill[k] != '\0')
                  {
                      cout << Jill[k];
                      Sleep(textspeed);
                      k++;
                  }
                  cout <<endl;


cout<<"Enter c to choose Chris, l to choose Leon and j to choose Jill (lowercase only): ";
cin>>choice;
while (choice!="c" && choice!="l" && choice!="j") //Case of wrong input
    {
        cout<<"Enter the appropriate letter to choose your character: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
   }
while (cin.fail()){
        cout<<"Enter the appropriate letter to choose your character: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
}
if (choice=="c"){
    charactername="Chris";
    strength= 10;
    stealth=5;
    luck=5;
    health=100;
    cout<<endl;
    cout<<"You have chosen "<<charactername<<endl;
}
if (choice=="l"){
    charactername="Leon";
    strength= 8;
    stealth=8;
    luck=5;
    health=85;
    cout<<endl;
    cout<<"You have chosen "<<charactername<<endl;
}
if (choice=="j"){
    charactername="Jill";
    strength= 6;
    stealth=9;
    luck=7;
    health=80;
    cout<<endl;
    cout<<"You have chosen "<<charactername<<endl;
}
}

void HUD(void)//Function that shows character name, health, level, xp and helps to tranverse through the story
{
    Sleep(600);
    system("cls");
    int temp=rand()%100+1;
    cout << "Name: " << charactername <<endl;
    cout << "Health: " << totalHealth << endl;
    cout << "Level: " << level <<endl;
    cout << "Cummulative XP: " << xp <<endl;

    if(encounters==1)//These conditions initiate different story function based on the value of encounters
    {
        story2();
    }
    if(encounters==2)
    {
        story3();
    }
    if(encounters==3)
    {
        story4();
    }
    if(encounters==4)
    {
        story5();
    }
    if(encounters==5)
    {
        story6();
    }
    if(encounters==6)
    {
        story7();
    }
    if(encounters==7)
    {
        story8();
    }
    if(encounters==8)
    {
        story9();
    }
    if(encounters==9)
    {
        story10();
    }
    if(encounters==10)
    {
        story11();
    }
    if(encounters==11)//Initiates final boss sequence if value of encounters is equal to 11
    {
        CombatBoss();
    }
    if(encounters==12)//Initiates the story ending if the encounter value is equal to 12
    {
        storyend();
    }

    if(temp>=50)
    {
        CreateEntity();
        string tempname= EntityNames[rand()%numberofentities];//Random enemy generator that uses a random number generator to extract element in entity string array in the position of the generated number
        currententity=tempname;
        cout << "A " << currententity << " appears before you." <<endl;
        Sleep(800);
        Combat();
    }
    else//Condition if no entity is generated it increments encounter to make sure to go on to next part of the story
    {
        cout << "You encounter no hostiles and move forward." <<endl;
        Sleep(800);
        if(encounters==1)
        {
            encounters++;
        }
        else if(encounters==2)
        {
            encounters++;
        }
        else if(encounters==3)
        {
            encounters++;
        }
        else if(encounters==4)
        {
            encounters++;
        }
        else if(encounters==5)
        {
            encounters++;
        }
        else if(encounters==7)
        {
            encounters++;
        }
        else if(encounters==8)
        {
            {
                encounters++;
            }
        }
        HUD();
    }




}
void CreateEntity(void)
{
    entityhp=20;
    srand(time(0));
    entitylevel=(rand()%2)+level; //Entity level generator
    if(entitylevel==0)
    {
        entitylevel=(rand()%2)+level; //If level generated is 0 calls back the same functions until level is not 0
    }

    entityhp=(rand()%20)+0.6*totalHealth+5*(level+entitylevel); //Entity health generator
    if(entityhp==0)
    {
        entityhp=(rand()%20)+0.6*totalHealth+5*(level+entitylevel);  //Calls back the same function in case hp generated is 0
    }

    entityxp=entityhp; //Equals the xp generated to the health of the entity

}

void CombatHUD(void)//Interactive HUD displaying the healths and levels of both the character and the entity
{
 Sleep(600);
    system("cls");
    cout << "Name: " << charactername << "     |     " << "Infected: " << currententity <<endl;
    cout << "Health: " << totalHealth << "     |     " << "Infected HP: " << entityhp << endl;
    cout << "Level: " << level << "        |     " << "Infected Level: " << entitylevel << endl;
    cout << "Cummulative XP: " << xp <<endl;
}

void Combat(void)//Combat function
{
    CombatHUD();//Displays the combat HUD at the start
    string userchoice;//String to take in user choice
    characterdamage=6*level; //The user attack damage based on their level
    int entityattack=3*entitylevel+3*level; //The entity attack damage based on their level and the player's level

    if(totalHealth>=1 && entityhp>=1)//Attack sequence if both have sufficient health
    {
        cout << "1. Attack" <<endl;
        cout << "2. Block" <<endl;
        cout << "3. Run" <<endl;
        cin >> userchoice;

        if(userchoice=="1")//Attack sequence
        {
            cout << "Advancing to attack. Damage dealt to " << currententity << " is " << characterdamage <<endl;
            entityhp=entityhp-characterdamage;//Entity health decreasing
            Sleep(800);
            CombatHUD();

            if(entityhp>=1)
            {
                cout << currententity << " " << "is advancing to attack. Damage taken is " << entityattack << "." <<endl;
                totalHealth=totalHealth-entityattack;//Player health decreasing


                if(totalHealth<=0)
                {
                    totalHealth=0;
                    cout << "----------YOU ARE DEAD----------" <<endl;//Player dies if health falls past 0
                    exit(0);
                }
            }
            else if(entityhp<=0)//If player defeats entity
            {
                entityhp=0;
                encounters++;//Increments value of encounter
                LevelUp();//Levels Up
                Sleep(800);
                HUD();
                cout << charactername << " " << "successfully defeated " << currententity << " and gained " << entityxp << " experience points." <<endl;
            }
            Sleep(800);
            Combat();
        }
        else if(userchoice=="2")//Block sequence
        {
           int chanceofblock=rand()%4+1;//Chance of blocking

           if(chanceofblock>=2)
           {
               if(totalHealth<health)
               {
               heal=level*3;
               totalHealth=totalHealth+heal;//Healing if player blocks
               cout << charactername << " " << "blocked the incoming attack from " << currententity << " and restored " << heal << " " << "health." <<endl;
               Sleep(800);
               Combat();
               }
               else
               {
                   cout << charactername << " is already at full health." <<endl;//If health is at full capacity
                   Combat();
               }
           }
           else
           {
               totalHealth=totalHealth-entityattack;//If player fails to block
               cout << charactername << " " << "failed to block the incoming attack from " << currententity << " and took " << entityattack << " damage." <<endl;
               Sleep(800);
               Combat();
           }
        }
        else if(userchoice=="3")
        {
            int chanceofescaping,randomngen;
            randomngen=rand()%100+1;//Chance of escape
            chanceofescaping=randomngen*luck;
            if(chanceofescaping>=300)
            {
                cout << charactername << " " << "successfully managed to run away from " << currententity << "." <<endl;
                HUD();
            }
            else
            {
                int heavyentityattack=entityattack*2;//Heavy attack if player fails to escape
                totalHealth=totalHealth-heavyentityattack;
                cout << charactername << " " << "failed to run away from " << currententity << " and suffered " << heavyentityattack << " damage." <<endl;
                Sleep(800);
                Combat();
            }
        }
        else
        {
            cout << "Invalid choice, please enter again.";//Wrong input case
            Sleep(600);
            Combat();
        }
    }
    if(totalHealth<=0)//If player health falls past 0
    {
        totalHealth=0;
        cout << "----------YOU ARE DEAD----------" <<endl;
        exit(0);
    }
    if(entityhp<=0)//If entity dies
    {
        entityhp=0;
        encounters++;
        LevelUp();
        Sleep(800);
        HUD();
        cout << charactername << " " << "successfully defeated " << currententity << " and gained " << entityxp << " experience points." <<endl;

    }
}

void speedoftext(void)//Function to take in the input for the variable that determines the delay of text
{
    cout << "Enter the time delay(in milliseconds) for the text to appear of the screen: ";
    cin >> textspeed;
}

void LevelUp(void) //Levelling up function
{
    xp=xp+entityxp;

    if(xp>=nextLevel) //Initiates level up and increases stats and displays their updated values
    {
        level++;
        nextLevel=nextLevel*3/2;
        totalHealth=totalHealth+20;
        health=health+20;
        maxHealth=health;
        totalHealth=maxHealth;
        strength=strength+2;
        stealth=stealth+1;
        luck=luck+1;
        cout << charactername << " successfully leveled up. Current level is " << level << "." <<endl;
        cout << charactername << "'s following stats have improved: " <<endl;
        cout << "Strength: " << strength <<endl;
        cout << "Stealth: " << stealth <<endl;
        cout << "Luck: " << luck <<endl;
        cout << "Health: " << totalHealth <<endl;

        Sleep(1000);
        HUD();

    }
    else
    {
        cout << charactername << " successfully defeated " << currententity << " and gained " << entityxp << " experience points." <<endl;
        totalHealth=maxHealth;

    }
}

void story2(void) //Story segment containing choice
{

    int i=0;
    string choice;

    string story_text= "Following your encounter you end up in a passageway splitting off into 2 directions.\nAll of a sudden you hear a high pitched scream originating from the left passageway and simultaneously a gunshot noise\nis heard from the right passageway.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    cout << "You can either take the left passageway or the right one. Which one do you choose. Enter l for left and r for right." <<endl;
    cin >> choice;
    while (choice!="l" && choice!="r"){
        cout<<"Enter the appropriate letter to choose your character: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
}
while (cin.fail()){
        cout<<"Enter the appropriate letter to choose your character: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
}

if(choice=="l")
{
    encounters++;
}
else
{
    encounters=encounters+2;
}
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story3(void) //Story segment is l is choosen
{

    int i=0;

    string story_text= "You decide to advance in the left passageway in order to investigate the source of the high pitched scream.\nLittle do you know a licker slowly creeps up behind you and embeds it's claws into your torso.\nYou watch as everything around you turns into darkness as you slip into the void.";
    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    cout << "----------YOU ARE DEAD----------" <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
    exit(0);
}

void story4(void) //Story Segment is r is choosen
{

    int i=0;

    string story_text= "You decide to advance in the right passageway in order to investigate the source of the gunshot.\nUpon reaching the end of the passageway you find yourself into a courtyard and see Rebecca surrounded by a horde\nof zombies.\nYou immediately rush into action taking down enough zombies to allow the both of you to escape back into the mansion.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story5(void) //Story segment
{
     int i=0;

    string story_text= "Following your narrow escape from the horde you and Rebecca seek refuge in a room and gather your bearings.\nRebecca expresses her gratitude and the two of you discuss your strategy.\nThe two of you reach to the conclusion that finding Wesker is the best course of action.\nThe two of you emerge from the room ready to face what comes next and end this nightmare. ";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story6(void) //Another choice containing story path
{
     int i=0;
     string choice;

    string story_text= "Your search for Wesker takes you across the mansion as you take on hordes of infected.\nUpon reaching the courtyard you have 2 options.\nEither take the underground pathway or venture on ahead in the latter part of the mansion. ";


    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }

    cout <<endl;
    cout << "Which path will you take? Enter u to take the underground passageway or s to venture straight on ahead." <<endl;
    cin >> choice;


     while (choice!="u" && choice!="s")
        {
        cout<<"Enter the appropriate letter: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
        }
    while (cin.fail())
        {
        cout<<"Enter the appropriate letter: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
        }

        if(choice=="s")
        {
            encounters++;
        }
        else
        {
            encounters=encounters+2;
        }


    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story7(void) //Story path if player chooses s
{
     int i=0;

    string story_text= "You venture on ahead into the latter part of the mansion but as soon as you open the door a mutated plant specimen slams it's vines down effectively crushing you and Rebecca.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    cout << "----------YOU ARE DEAD----------" <<endl;
    exit(0);
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story8(void)
{
     int i=0;

    string story_text= "You are Rebecca take the underground passage and find yourselves in a labyrinth crawling with hostiles.\nFighting them off you eventually reach the entrance of what seems to be a concealed lab.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story9(void) //Story segment also containing a choice
{
     int i=0;

    string story_text= "You and Rebecca fight your way through the labyrinth and enter its underground lab.\nThere you find Wesker waiting for you.\nHe reveals to you that he has been acting as a double agent the whole time, and plans to release the Tyrant, a giant\nhumanoid supersoldier to terrorize the world.\nHe takes out a gun and aims at Rebecca, firing.";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    cout << "You can choose to save Rebecca by diving in front of her. Enter y for yes and n for no" <<endl;
    string choice;
    cin >> choice;
    while (choice!="y" && choice!="n"){//Wrong input case
        cout<<"Enter the appropriate letter to choose: ";
        cin.clear();
        string s;
        getline(cin,s);
        cin>>choice;
}

if(choice=="y")//Determining increase in value of encounters based on choice thus initiating appropriate story function
{
    encounters++;
}
else
{
    encounters=encounters+2;
}
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story10(void) //Sequence if player chooses y
{
     int i=0;

    string story_text= "You dive in front of the oncoming bullet and get struck in your upper leg, wounding you severely.\nRebecca shoots Wesker in the head, but not before he releases the Tyrant.\nWounded and limping you get up to face the Tyrant, your resolve stronger than ever,\nbut you being vulnerable to the Tyrant's attacks";

    while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    tyranthp=75*level;
    totalHealth=totalHealth/2;
    characterdamage=2*characterdamage;
    encounters=encounters+2;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void story11(void)//Sequence if player chooses n
{
     int i=0;

    string story_text= "The bullet hits Rebecca in the stomach, wounding her fatally.\nYou shoot Wesker in the head, but not before he releases\nthe Tyrant.\nRebecca dies in your arms,and you vow to avenge her.\nYou stand up to face the tyrant, feeling stronger than ever";

     while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    tyranthp=75*level;
    totalHealth=1.5*totalHealth;
    encounters++;
    system("pause");
    system("cls");
    cout << "Clearing console..."<<endl;
    Sleep(600);
}

void CombatBossHUD(void)//Interactive HUD for final fight(Same as combat function)
{
 Sleep(600);
    system("cls");
    cout << "Name: " << charactername << "   |   " << "Infected: TYRANT"<<endl;
    cout << "Health: " << totalHealth << "    |    " << "Infected HP: " << tyranthp<< endl;
    cout << "Level: " << level << "      |    " << "Infected Level: BOSS " << endl;
    cout << "Cummulative XP: " << xp <<endl;
}

void CombatBoss(void)//Battle function for final fight
{
    CombatBossHUD();
    int userchoice;
    int tyrantattack=level*8;

    if(totalHealth>=1 && tyranthp>=1)
    {
        cout << "1. Attack" <<endl;
        cout << "2. Block" <<endl;
        cin >> userchoice;

        if(userchoice==1)
        {
            cout << "Advancing to attack. Damage dealt to TYRANT" << " is " << characterdamage <<endl;
            tyranthp=tyranthp-characterdamage;
            Sleep(800);
            CombatBossHUD();

            if(tyranthp>=1)
            {
                cout << "TYRANT is advancing to attack. Damage taken is " << tyrantattack << "." <<endl;
                totalHealth=totalHealth-tyrantattack;


                if(totalHealth<=0)
                {
                    totalHealth=0;
                    cout << "----------YOU ARE DEAD----------" <<endl;
                    exit(0);
                }
            }
            else if(tyranthp<=0)
            {
                tyranthp=0;
                Sleep(800);
                cout << charactername << " " << "successfully defeated the TYRANT." <<endl;
                encounters++;
                HUD();
            }
            Sleep(800);
            CombatBoss();
        }
        else if(userchoice==2)
        {
           int chanceofblock=rand()%4+1;

           if(chanceofblock>=2)
           {
               if(totalHealth<health)
               {
               heal=level*5;
               totalHealth=totalHealth+heal;
               cout << charactername << " " << "blocked the incoming attack from TYRANT and restored " << heal << " " << "health." <<endl;
               Sleep(800);
               CombatBoss();
               }
               else
               {
                   cout << charactername << " is already at full health." <<endl;
                   CombatBoss();
               }
           }
           else
           {
               totalHealth=totalHealth-tyrantattack;
               cout << charactername << " " << "failed to block the incoming attack from TYRANT and took " << tyrantattack << " damage." <<endl;
               Sleep(800);
               CombatBoss();
           }
        }
        else
        {
            cout << "Invalid choice, please enter again.";
            Sleep(600);
            CombatBoss();
        }
    }
    if(totalHealth<=0)
    {
        totalHealth=0;
        cout << "----------YOU ARE DEAD----------" <<endl;
        exit(0);
    }
    if(tyranthp<=0)
    {
        tyranthp=0;
        Sleep(800);
        cout << charactername << " " << "successfully defeated the TYRANT." <<endl;
        encounters++;
        HUD();

    }
}

void storyend(void)//Ending of the rpg
{
     int i=0;

    string story_text= "Having defeated the tyrant, your body battered and bruised, you walk out of the mansion as the sun appears on the horizon.\nBreathing a sigh of relief you think that that is the end of the nightmare but little do you know that in Racoon City peculiar incidents have started to emerge...";

     while(story_text[i] != '\0')
    {
        cout << story_text[i];
        Sleep(textspeed);
        i++;
    }
    cout <<endl;
    cout << "Thank you for playing the game. We sincerely hope that you enjoyed it as much as we had fun making it. Until next time." <<endl;
    exit(0);
    Sleep(600);
}
