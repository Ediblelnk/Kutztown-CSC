/**********************************************************************************************************

                                          The Haunted House Escape
                                             by Prof. Thiep Pham
                                                    CSC 240
                                                   March 2022
                                                 Project #2
                     
ABOUT THE GAME:
You were kidnapped, gagged, tied, blindfolded, and taken to an old decrepit tower in the backwoods. 
The place does not look familiar to you, but you have more urgent issues at hand. You could hear an eery 
howl coming from the nearby basement, and it is getting closer. Your instinct is to quickly get out of 
this place.  But how?

WARNING:
The game is a horror genre game and contains very explicit descriptions (rated: PG-13).
As such, under 13 should not be playing this game without parental consent and oversight!

PURPOSE:
Provide an intro to C# programming using an Interactive Fiction (IF) text-based game format.

*************************************************************************************************************/

using System;
class HauntedHouseEscape
{
  // Game variables declaration
  public static bool haveKnife;                           // Verify if the player has the weapon or not.  Defaulted to no/false.
  public static int knifeMaxDamage;                       // Set the maximum damage of the knife for randomize purposes. Zero being no damage.
  public static int fistMaxDamage;                        // Set the maximum damage of the player's fist. Zero being no damage.
  public static int playerMaxHealth;                      // Set the maximum health of the player.  This also set the level of difficulty of the game.
  public static int playerMinHealth;                      // Set the minimum health of the player. Falling below this level, the player will die.
  public static int playerCurrentHealth;                  // Set player's health to be maximum at the start of the game.
  public static int monsterClawDamage;                    // Set the maximum damage of the monster's claws for randomize purposes. Zero being no damage. 
  public static int monsterMaxHealth;                     // Set the maximum health of the monster.  This also set the level of difficulty of the game.
  public static int monsterMinHealth;                     // Set the minimum health of the monster. Falling below this level, the monster will die.
  public static int monsterCurrentHealth;                 // Set monster's health to be maximum at the start of the game.
  public static string[] inventoryList = new string[10];  // set inventory to have 10 items max.
  public static int currentInventoryCount;                // reset inventory number of items to zero.


  /////////////////////
  // RESET GAME DATA //
  /////////////////////
  static void resetGameData()
  {
    // Reset game data before restarting the game
    haveKnife = false;                     // Verify if the player has the weapon or not.  Defaulted to no/false.
    knifeMaxDamage = 10;                   // Set the maximum damage of the knife for randomize purposes. Zero being no damage.
    fistMaxDamage = 3;                     // Set the maximum damage of the player's fist. Zero being no damage.
    playerMaxHealth = 50;                  // Set the maximum health of the player.  This also set the level of difficulty of the game.
    playerMinHealth = 0;                   // Set the minimum health of the player. Falling below this level, the player will die.
    playerCurrentHealth = 50;              // Set player's health to be maximum at the start of the game.
    monsterClawDamage = 8;                 // Set the maximum damage of the monster's claws for randomize purposes. Zero being no damage. 
    monsterMaxHealth = 60;                 // Set the maximum health of the monster.  This also set the level of difficulty of the game.
    monsterMinHealth = 0;                  // Set the minimum health of the monster. Falling below this level, the monster will die.
    monsterCurrentHealth = 60;             // Set monster's health to be maximum at the start of the game.
    inventoryList = new string[10];        // set inventory to have 10 items max.
    currentInventoryCount = 0;             // reset inventory number of items to zero.
  }

  //////////////////
  // MAIN PROGRAM //
  //////////////////
  public static void Main()
  {
    resetGameData();    // This will does a refresh of the game data.
    theIntroduction();  // This will explain about the game to the player.
    theLibrary();       // This is where your character starts out.
  } // End of Main() 

  //////////////////////
  // THE INTRODUCTION //
  //////////////////////
  static void theIntroduction()
  {
    Console.Clear(); // This will clear the screen and move the cursor to the top-left of the screen
    Console.WriteLine();
    Console.WriteLine("The Haunted House Escape");
    Console.WriteLine("by Prof. Thiep Pham");
    Console.WriteLine("CSC 240");
    Console.WriteLine("Assignment #2");
    Console.WriteLine();
    Console.WriteLine("---------------------------------------------------------------------------------------------------------");
    Console.WriteLine("ABOUT THE GAME:");
    Console.WriteLine("You were kidnapped, gagged, tied, blindfolded, and taken to an old decrepit tower in the backwoods.");
    Console.WriteLine("The place does not look familiar to you, but you have more urgent issues at hand. You could hear an eery");
    Console.WriteLine("howl coming from the nearby basement, and it is getting closer. Your instinct is to quickly get out of");
    Console.WriteLine("this place.  But how?");
    Console.WriteLine("\nPossible commands: directions (N,S,E,W,NE,NW,SE,SW), take <item>, I/inventory, attack, and others.");
    Console.WriteLine("---------------------------------------------------------------------------------------------------------");
    Console.WriteLine();

    // Game rating warning //
    Console.WriteLine("WARNING:");
    Console.WriteLine("The game is a horror genre game and contains very explicit descriptions (rated: PG-13).");
    Console.WriteLine("As such, under 13 should not be playing this game without parental consent and oversight!\n");

    // Request for the character's name
    Console.Write("Please provide your character's name: ");
    string? characterName = Console.ReadLine();
    Console.WriteLine($"\nWelcome {characterName}!");

    Console.WriteLine($"\n{characterName},");
    Console.WriteLine("You woke up with a jarring headache.  You can feel the source of the pain pulsating from the back of");
    Console.WriteLine("your head. You touched the big lump, and it felt wet, which you presumed to be your blood.");
    Console.WriteLine("Your uncontrollable reaction to the pain can be heard echoed throughout the area. With your tied hands, ");
    Console.WriteLine("you struggled but successfully pulled off your blindfold. ");
    Console.WriteLine("\nIt took a moment to get your bearings, but you believe you are in some old musty library. ");
    Console.WriteLine("Broken ceramic vases, old books, and trash can cbe seen littered throughout the small dimly lit library.");
    Console.WriteLine("\nSuddenly, you hear a deep monstrosity of a moan coming from the south side of the library.  It must ");
    Console.WriteLine("have heard your outcry. You frantically used a nearby ceramic shard to cut the ropes which had bound ");
    Console.WriteLine("your hands and ankles.");
    Console.WriteLine("\nPress ENTER to continue");
    Console.ReadLine();
  } // End of theIntroduction()


  /////////////////
  // THE LIBRARY //
  /////////////////

  // Describe to the players what the library looks like. //
  static void theLibraryView()
  {
    Console.WriteLine("\n\nThe Library:");
    Console.WriteLine("-----------:");
    Console.WriteLine("You are in the library.  There are many scattered items in this room, from broken ceramic vases to old");
    Console.WriteLine("musty books.  Exits leading south to the basement, east, north, and west.\n");
  } //End of theLibraryView()

  // What the players can do when inside the library. //
  static void theLibrary()
  {
    theLibraryView();

    while (true)
    {
      Console.Write("\nWhat would you like to do next? ");
      string? playerRespond = Console.ReadLine();
      switch (playerRespond)
      {
        case "S":
        case "s":
        case "go south":
          Console.Write("\nYou will be fighting the beast to the death. Are you sure you are ready? "); // Provide the player a chance to back out.
          string? playerReady = Console.ReadLine();
          if ((playerReady == "Y") || (playerReady == "y") || (playerReady == "yes") || (playerReady == "YES"))
            theBasement();
          else
            Console.WriteLine("\nCome back when you are ready!\n");
          break;
        case "E":
        case "e":
        case "go east":
          theLivingroom();
          break;
        case "W":
        case "w":
        case "go west":
          theBedroom();
          break;
        case "N":
        case "n":
        case "go north":
          theKitchen();
          break;
        case "look":
          theLibraryView();
          break;
        case "inventory":
        case "I":
        case "i":
          inventory();
          break;
        default:
          Console.WriteLine($"\nSorry, but I do not understand what is ''{playerRespond}''.");
          break;
      } // end Switch
    } // End While
  } // End theLibrary()


  /////////////////////
  // THE LIVING ROOM //
  /////////////////////

  // Describe to the players what the living room looks like //
  static void theLivingroomView()
  {
    Console.WriteLine("\n\nThe Living room:");
    Console.WriteLine("---------------:");
    Console.WriteLine("You are in the living room.  You find broken furniture scattered throughout the room.  You found");
    Console.WriteLine("something that resembled human bones. Exits leading east and north-west.");
  } // End of theLivingroomView()

  // What the players can do when inside the living room. //
  static void theLivingroom()
  {
    theLivingroomView();

    while (true)
    {
      Console.Write("\nWhat would you like to do next?");
      string? playerRespond = Console.ReadLine();
      switch (playerRespond)
      {
        case "E":
        case "e":
        case "go east":
          theLibrary();
          break;
        case "NW":
        case "nw":
        case "go north-west":
          theKitchen();
          break;
        case "look":
          theLivingroomView();
          break;
        case "inventory":
        case "I":
        case "i":
          inventory();
          break;
        default:
          Console.WriteLine($"\nSorry, but I do not understand what is ''{playerRespond}''.");
          break;
      }
    }

  }   // End of theLivingroom()


  /////////////////
  // THE KITCHEN //
  /////////////////

  // Describe to the players what the kitchen looks like. //
  static void theKitchenView()
  {
    Console.WriteLine("\n\nThe Kitchen:");
    Console.WriteLine("-----------:");
    Console.WriteLine("You are in the kitchen.  As with other rooms, the place looks like a tornado has hit it. You found remains");
    Console.Write("of half-eaten human body parts. ");
    if (haveKnife != true)
    {
      Console.Write("Within the debris, you notice there is a wrapped note. ");  // After the player has picked up the knife, the section of text will not longer display to the player.
    }
    Console.Write("Exits leading south-east, south, and south-west.\n");
  } // End of theKitchenView()

  // What the players can do when inside the kitchen. //
  static void theKitchen()
  {
    theKitchenView();

    while (true)
    {
      Console.Write("\nWhat would you like to do next? ");
      string? playerRespond = Console.ReadLine();
      switch (playerRespond)
      {
        case "SE":
        case "se":
        case "go south-east":
          theLivingroom();
          break;
        case "SW":
        case "sw":
        case "go south-west":
          theBedroom();
          break;
        case "S":
        case "s":
        case "go south":
          theLibrary();
          break;
        case "take note":
          if (haveKnife == true) // If the player already have taken the knife, the game will say that it is already have been taken; otherwise, the player can pick up the knife (once)
          {
            Console.WriteLine("\nYou already have picked up the knife.  It is in your inventory!\n");
          }
          else // This section will only display once and never again.
          {
            Console.WriteLine("\nYou picked up the note and it read, ''Get out! Get out while you still can! It will hunt you down.");
            Console.WriteLine("Take this weapon to kill it.  Hurry!''  A knife was wrapped in the note.  This is no kitchen knife!");
            Console.WriteLine("The knife was big enough to be a dagger.  ");
            haveKnife = true;
            inventoryList[currentInventoryCount] = "dagger";
            currentInventoryCount++;
          }
          break;
        case "look":
          theKitchenView();
          break;
        case "inventory":
        case "I":
        case "i":
          inventory();
          break;
        default:
          Console.WriteLine($"\nSorry, but I do not understand what is ''{playerRespond}''.");
          break;
      }
    } // End theKitchen
  }   // End of theKitchen()

  /////////////////
  // THE BEDROOM //
  /////////////////

  // Describe to the players what the bedroom looks like. //
  static void theBedroomView()
  {
    Console.WriteLine("\n\nThe Bedroom:");
    Console.WriteLine("-----------:");
    Console.WriteLine("You are in the bedroom.  It looks like there was an epic battle in this room.  Dried blood splatters can be");
    Console.WriteLine("seen all over the room, including the ceiling.  Looks like the human lost this battle. Exits leading north-");
    Console.WriteLine("east and east.");
  } // End of theBedroomView()

  // What the players can do when inside the bedroom. //
  static void theBedroom()
  {
    theBedroomView();
    while (true)
    {
      Console.Write("\nWhat would you like to do next? ");
      string? playerRespond = Console.ReadLine();
      switch (playerRespond)
      {
        case "NE":
        case "ne":
        case "go north-east":
          theKitchen();
          break;
        case "E":
        case "e":
        case "go east":
          theLibrary();
          break;
        case "look":
          Console.WriteLine("You are in the bedroom.  It looks like there was an epic battle in this room.  Dried blood splatters can be");
          Console.WriteLine("seen all over the room, including the ceiling.  Looks like the human lost this battle. Exits leading north-");
          Console.WriteLine("east and east.");
          break;
        case "inventory":
        case "I":
        case "i":
          inventory();
          break;
        default:
          Console.WriteLine($"\nSorry, but I do not understand what is ''{playerRespond}''.");
          break;
      }
    } // End While

  } // End theBedroom()

  //////////////////
  // THE BASEMENT //
  //////////////////

  // Describe to the players what the basement looks like. //
  static void theBasementView()
  {
    Console.WriteLine("\n\nThe Basement:");
    Console.WriteLine("-----------:");
    Console.WriteLine("You are in the basement and engaging a battle with the beast. It will not let you escape.");
    Console.WriteLine("Your only choice is to fight the beast. An exit leading out, but the beast is blocking your exit.");
  } // End of theBasementView()

  // What the players can do when inside the basement. //
  static void theBasement()
  {
    Console.WriteLine("\n\nThe Basement:");
    Console.WriteLine("------------:");
    Console.WriteLine("You believe you have just walked into the dungeon of this horrid place.  You can barely see through the ");
    Console.WriteLine("dim-lit dungeon, but you believe you may have seen multiple mangled corpses scattered all over the");
    Console.WriteLine("floor. The stench of decaying corpses overtook you.  You choked on the fume, and your knees crumpled");
    Console.WriteLine("to the ground. You were unable to hold onto your stomach contents, and your contents joined the vile");
    Console.WriteLine("concoction. You raised your head and saw what you believe could be a door on the other side of this long");
    Console.WriteLine("corridor. You managed to pull yourself together and forced yourself upright.  Before you managed to");
    Console.WriteLine("take a step, from the corner of your left eye, you spotted a hulky mass stepped out from the darkness.  It was waiting");
    Console.WriteLine("for you all this time.  Before you had a chance to even turn your head, its claw slashed the left");
    Console.WriteLine("side of your face.  You can feel its talons dug deep into your cheek and raked across your face. The burning");
    Console.WriteLine("sensation and pain were unbearable, but you know you must fight this beast to get out of this dungeon.\n");

    Console.WriteLine("The battle to the death is about to begin!\n");
    Console.WriteLine($"Your stats: Player's current health = {playerCurrentHealth} out of {playerMaxHealth}");

    // NOTE: This and the following two lines of code do the same thing, but coded differently.  
    Console.WriteLine($"Monster's stat: Monster's current health = {monsterCurrentHealth} out of {monsterMaxHealth}");
    //     Console.WriteLine("Monster's stat: Monster's current health = "+monsterCurrentHealth+" out of "+monsterMaxHealth);
    //     Console.Write("Monster's stat: Monster's current health = "); Console.Write(monsterCurrentHealth); Console.Write(" out of "); Console.Write(monsterMaxHealth);

    if (haveKnife == true)
      Console.WriteLine("\nYou are also carrying a knife.\n");
    else
      Console.WriteLine("\nIt looks like you will engage the beast barehanded.  Good luck!\n");
    Console.WriteLine("-------------------------------------------------------------------------------------");
    Console.WriteLine("The monster ambushed you and therefore had the first attack.\n");

    // Run the battle scene
    theBattle();
  }  // End of theBasement()


  // The battle //
  static void theBattle()
  {
    Random rand = new Random();
    int monsterDamage;
    int playerDamage;
    bool gameOver = false;

    while (!gameOver)
    {
      monsterDamage = rand.Next(0, monsterClawDamage);   // This randomize the damage the monster did to your character.
      if (monsterDamage == 0)
        Console.WriteLine("\nIt totally missed you.\n");    // This was added for additional dialog.
      else
      {
        Console.Write($"It did {monsterDamage} points of claw damage to you. ");
        playerCurrentHealth = playerCurrentHealth - monsterDamage;  // Your health is reduced based on the damage.
        Console.WriteLine($"Your current health is now {playerCurrentHealth}.\n");
      }

      if (playerCurrentHealth < playerMinHealth)  // Verify if the health goes below minimum.  If not, continue with the battle.
      {
        gameOver = true;
        conclusionLost();
      }
      Console.WriteLine("-------------------------------------------------------------------------------------");

      Console.WriteLine("Press Enter key for your turn to attack! "); // This game is set to auto-fight.  

      Console.ReadLine();                   // However, this option can be changed to query for other commands, like retreat.
      if (haveKnife == true)  // Your character will do more damage with a knife than a fist.
      {
        playerDamage = rand.Next(0, knifeMaxDamage); // This will randomize the player's damage to the monster.
        if (playerDamage == 0)
          Console.WriteLine("\nYou totally missed the monster.\n");
        else
        {
          Console.WriteLine($"\nYou did {playerDamage} damage to the monster.");
          monsterCurrentHealth = monsterCurrentHealth - playerDamage; // monster health would be reduced accordingly.
          Console.WriteLine($"The monster's health is now {monsterCurrentHealth}.\n");
        }
      }
      else // Player attack monster with his/her fist.
      {
        playerDamage = rand.Next(0, fistMaxDamage); // This will randomize the player's damage to the monster.
        if (playerDamage == 0)
          Console.WriteLine("\nYou totally missed the monster.\n");
        else
        {
          Console.WriteLine($"\nYou did {playerDamage} damage to the monster.");
          monsterCurrentHealth = monsterCurrentHealth - playerDamage; // monster health would be reduced accordingly.
          Console.WriteLine($"The monster's health is now {monsterCurrentHealth}.\n");
        }
      }

      if (monsterCurrentHealth < monsterMinHealth) // Verify if the monster's health goes below minimum amount.
      {
        gameOver = true;
        conclusionWin();
      }
      else
      {
        Console.WriteLine("-------------------------------------------------------------------------------------");
        Console.WriteLine("\nPress Enter key for your the monster's turn to attack! "); // This game is set to auto-fight.  
        Console.ReadLine();                   // However, this option can be changed to query for other commands, like retreat.
      }
    } // While loop
  } // theBattle

  // Conclusion - LOST //
  static void conclusionLost()
  {
    Console.WriteLine("\n\nWith its massive two arms, it clapped them together and held onto your head like a device. It then proceeded ");
    Console.WriteLine("to pick you up off the floor and shook you violently. You can hear the crackling sounds of your neck and");
    Console.WriteLine("vertebrates. Your arms felt heavy and your body became limp. After it has satiated with your torture, it");
    Console.WriteLine("dropped your limp body onto the floor to join the other corpses. As you laid on the cold dirt floor and taking");
    Console.WriteLine("in your last breath, you realized why you were kidnapped. You recalled a rumor about a local cult who kidnaps the ");
    Console.WriteLine("locals and uses the victims as sacrifices to this “god”. This was not your lucky day. Everything went dark.\n");
    Console.WriteLine("\n\nYou have lost.\n");

    restartOption();
  } // End of conclusionLost()

  // Conclusion - WIN //
  static void conclusionWin()
  {
    Console.WriteLine("\nYou were able to find a weak spot of the beast and drove your knife deep into its carotid artery.  Its");
    Console.WriteLine("natural reaction was to swat your arm out of the way. However, you held onto your knife tightly and by ");
    Console.WriteLine("swatting,it ripped open its artery.  The beast violently stumbled back as green bile gushed out from its ");
    Console.WriteLine("artery soaking you and the dungeon walls and floor.  Within minutes, it lied on the dirt floor quaffing its ");
    Console.WriteLine("last breath of air. You stood there, shaken from the battle...\n ");
    Console.WriteLine("\n...A cool fresh air whiffed through the room through the bottom of the door exiting the dungeon. The air ");
    Console.WriteLine("rejuvenated you and gave you a second wind. You pulled yourself together and stumbled your way to the ");
    Console.WriteLine("exit and out of this horrid dungeon.\n");
    Console.WriteLine("\n\nYou have won!\n");

    restartOption();
  } // End of conclusionWin()


  /////////////
  // RESTART //
  /////////////
  static void restartOption()
  {
    string? playerReady, playerRespond;

    Console.Write("\nWould you like to restart this game? ");
    playerRespond = Console.ReadLine();
    if ((playerRespond == "Y") || (playerRespond == "y") || (playerRespond == "yes") || (playerRespond == "YES"))
    {
      Console.WriteLine("\n\nPlease press the Enter key to restart the game! ");
      playerReady = Console.ReadLine();
      // Run the Main program
      Main();
    }
    else
    {
      Console.Write("\nThank you for playing the Haunted House Escape!");
      gameCredits();
    }
  }

  //////////////////////
  // End game credits //
  //////////////////////
  static void gameCredits()
  {
    Console.WriteLine("\n\n===============================================================================");
    Console.WriteLine("     The Haunted House Escape");
    Console.WriteLine("     Designed and developed by Prof. Thiep N. Pham");
    Console.WriteLine("     Kutztown University Computer Science and Information Technology Department");
    Console.WriteLine("     for CSC 240, Project #2");
    Console.WriteLine("     Copyright © 2022");
    Console.WriteLine("===============================================================================\n\n");
    Environment.Exit(1); // Safely exit the program
  }

  //////////////////////////////////////////
  //            INVENTORY                 //
  // The players can see their inventory. //
  //////////////////////////////////////////
  static void inventory()
  {
    if (currentInventoryCount == 0)
      Console.WriteLine("\nYou currently are not carrying any items.\n");
    else
    {
      Console.WriteLine("\nCurrently you are carrying the following items:\n");
      for (int counter = 0; counter < currentInventoryCount; counter++)
        Console.WriteLine(" --> ", inventoryList[counter]);
    } // else
  } // End of inventory()
} //End of HauntedHouseEscape class