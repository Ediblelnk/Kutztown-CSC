﻿/*
  The Grid of Sins
  by Peter Schaefer
  CSC 240
  March 2023
  Project #2
                     
ABOUT THE GAME:
You were exploring a cave, when all of a sudden, you get hit on the head from behind, rendering you unconscious. 
When you wake up, you are in a dungeon room with a dim light. It is clear you need to get out of this place, but 
through what doors must you venture through in order to find an exit?

WARNING:
This game is a horror game. It contains explicit descriptions and mature themes (rated: PG-13).
As such, under 13 should not be playing this game without parental consent and oversight!

PURPOSE:
Provide an intro to C# programming using an Interactive Fiction (IF) text-based game format.
*/

using System;
using System.Collections.Generic;

/*
Collection of game script lines, separated from the logic for easier understanding of how each room works
*/
class Script
{
  public static string decisionSeparator =
  "=============================\n";

  public static string introduction =
  "The Grid of Sins" +
  "\nby Peter Schaefer" +
  "\nCSC 240" +
  "\nProject #2" +
  "\n=============================";

  public static string warning =
  "CONTENT WARNING: This game is a horror game. It contains explicit descriptions and mature themes." +
  "\nRATING: PG-13, TV-M" +
  "\n=============================";

  public static string preNamePrompt =
  "Character name: ";

  public static string postNamePrompt =
  "=============================";

  public static string aboutGame =
  "GAME INFORMATION" +
  "\nYou were exploring a cave, when all of a sudden, you get hit on the head from behind, rendering you unconscious. When " +
  "\nyou wake up, you are in a dungeon room with a dim light. It is clear you need to get out of this place, but through what " +
  "\ndoors must you venture through in order to find an exit?" +

  "\n\nCommands: enter [room name], go [full cardinal direction], yes, no, inventory, attack, look, etc." +

  "\n\n[Generally, you will be able to type a sentence, which will be checked for keywords to determine the command input]" +
  "\n=============================\n\n";

  public static string inputError =
  "\nSorry, that choice had no relevant keywords. Please Try Again.";

  public static string keyError =
  "\nSorry, you do not have the required keys to do this action. Find the keys and then come back.";

  public static string deathMsg =
  "\nYOU HAVE DIED. " +

  "\n\nYour corpse will be forever lost to the dungeon, held in company with the humanoids and dark magic beings " +
  "living here.";

  public static string winMsg =
  "YOU HAVE WON!" +
  "\n\nCongratulations, you have escaped the dungeon. I hope you enjoyed!";

  public static string credits =
  "----------------------------------------------" +
  "\n| Grid of Sins                               |" +
  "\n| Designed and Implemented by Peter Schaefer |" +
  "\n| CSC 240, Project #2, March 2023            |" +
  "\n----------------------------------------------";

  /*
  This is the Regret room script. This is the starting room, so not much is happening
  */
  public class roomR3GR37
  {
    public static string initial =
    "\nYou find yourself in a small, dark dungeon-like chamber. The walls are made of cold, gray stone, and the only light comes " +
    "\nfrom a dim light bulb, which hangs from a thin cable. The air in the room is thick, and a sense of dread hangs in it.";

    public static string flashlight =
    "\n\nThere is a flashlight on the ground in the one corner of the dungeon.";

    public static string look =
    "\n You look around the room, and see that the walls are made of the same rock from the cave you remember being in before this. " +
    "\nYou likely have not been taken far away, or been out for terribly long.";

    public static string previous =
    "\nThis is the room you started in. It is a small, dark dungeon-like chamber. The walls are made of cold, gray stone, and the " +
    "\nonly light comes from a dim light bulb, which hangs from a thin cable. The air in the room is thick, and a sense of dread " +
    "\nhangs in it.";

    public static string navigation =
    "\nThere are two thick wooden doors: one is marked as \"PR1D3\" (North), while the other is marked as \"6R33D\" (East). ";
  }

  /*
  This is the Pride room script. This room has a mirror that will kill the player if looked into long enough.
  */
  public class roomPR1D3
  {
    public static string initial =
    "\nYou open the door marked as \"PR1D3\". You are greeted with a room lit with glittering lights and walls adorned with rainbow " +
    "\ncolors. You feel inspired, as if everything you ever wanted to do was suddenly within your reach. You can hear the sound of " +
    "\nlaughter and music, and it fills you with joy. You can't help but smile from the feeling of accomplishment." +
    "\n\nIn the center of the room is a mirror, with a highly decorated and carved frame.";

    public static string navigation =
    "\nThere are three thick wooden doors: one is marked as \"R3GR37\" (South), another is marked as \"LU57\" (East), and the third " +
    "\nis marked as \"3NV7\" (North).";

    public static string lookAtMirror1 =
    "\nYou gaze into the ornate mirror. You are greeted with prideful images of yourself, images of you accomplishing all of your goals.";

    public static string lookAtMirror2 =
    "\nYou continue to look at the mirror. It is enchanting, and you become increasingly interested in what is shown. The mirror continues " +
    "\nto change between different successful versions of yourself.";

    public static string lookAtMirror3 =
    "\nYou continue to look at the mirror. You are enthralled by the pride and confidence it gives you. \n\nWithin moments, you are trapped " +
    "\nin your own vanity and unable to look away. You are held captive by the mirror, completely oblivious to the room around you. As you " +
    "\nare distracted by the mirror, a monster steps into the room. It stands over seven feet tall, with a muscular, humanoid body. It is " +
    "\ncovered in matted fur. Its eyes are a bright, glowing red, and its mouth is filled with razor-sharp teeth that glisten in the dim " +
    "\nlight. As it approaches you, you smell its foul breath, a mixture of decay and sulfur. It makes your stomach turn, but you simply " +
    "\ncan't look away from the mirror. " +

    "\n\nThe monster's attack is swift and brutal. With lightning-fast reflexes, it lunges towards you, its razor-sharp claws extended and " +
    "\nready to strike. You feel its claws slice through your flesh, tearing through muscle and bone, but the mirror demands attention. It " +
    "\ncontinues its assault, slashing and biting at you. You can feel your strength draining away as the monster attacks, leaving you " +
    "\ngasping for breath. In a matter of seconds, it is over, and you are left lying on the ground, bloodied and broken. Your eyes are " +
    "\nstill glued to the mirror as you bleed out.";

    public static string previous =
    "\nYou are in the \"PR1D3\" Room. The glittering lights and wall are still flashing with colors, although less intense than when you " +
    "\nentered the room the first time. The laughter and music are muted, as if coming from a few rooms away." +
    "\n\nThe mirror is still in the room, complete with its carved frame.";
  }

  /*
  This is the Greed room script. This room requires the player to take the item that is less valuable: the golden glasses.
  */
  public class room6R33D
  {
    public static string initial =
    "\nYou open the door market with \"6R33D\". You enter the room, and every surface is covered in shiny gold plating. There are gold tables " +
    "\nwith gold plates and chalices sat at each place, with a plush gold chair. Every inch of the room is filled with luxurious items, each " +
    "\nmore expensive than the last. " +

    "\n\nThere is a pedestal off to the side of the room. Sat on a golden pillow on this pedestal are two objects: a pair of glasses made of " +
    "\ngold, and a necklace made of rubies. You do not see any doors in the room, not even the one you had entered through.";

    public static string rubyNecklace =
    "\nYou take the ruby necklace and put it on. Suddenly the entire room is filled with a large metallic sound. As you look around the room, " +
    "\nyou see all the gold artifacts in the room start to shake. The shaking continues, until the entire room is rumbling. As the shaking " +
    "\nprogresses, the items start to duplicate themselves: at first slow, but at an ever increasing pace. You look around, but there is " +
    "\nnothing that you can do to prevent the wave of golden items from crushing you." +

    "\n\nYou wonder what you could have done differently as the golden objects crush and lacerate your body, killing you.";

    public static string goldenGlasses =
    "\nYou take the golden glasses and put them on. As your eyes adjust, you see that every object that was once golden is now made of rotting " +
    "\nwood. There are maggots in the chalices. You are glad you didn't touch anything." +

    "\n\nAlong with everything else changing, you notice there now are three doors: one is marked as \"R3GR37\" (West), another is marked as " +
    "\n\"LU57\" (North), and the third is marked as \"5107H\" (East).";

    public static string previous =
    "\nYou are in the \"6R33D\" Room. There are rotting wooden tables with rotting wooden bowls filled with maggots, rotting wood cups, and hard " +
    "\nrotting chairs." +

    "\n\nThere are three thick wooden doors: one is marked as \"R3GR37\" (West), another is marked as \"LU57\" (North), and the third is marked " +
    "\nas \"5107H\" (East).";
  }

  /*
  This is the Envy room script. This is the offer of the gun, dagger, and the silver key. You need the silver key.
  */
  public class room3NV7
  {
    public static string initial =
    "\nYou open the door marked as \"3NV7\". As the door opens, you see a withered hand place its fingers on the door and pull it fully open." +

    "\n\nAs you slowly step forward into the room, a withering humanoid emerges from the shadows, holding three items: a gun, a dagger, and a " +
    "\nsilver key.";

    public static string offerGun =
    "\nThe first item is a gun, which it holds out towards you with a toothy grin. It whispers, \"Take it, and gain the power to end anyone who " +
    "\nstands in your way.\"";

    public static string acceptGunDead =
    "\nYou reach for the gun, but before you can grab it the humanoid snatches it away and aims it at your head. Its laughter echoes through " +
    "\nthe room as it pulls the trigger, ending your life in an instant.";

    public static string acceptGunAlive =
    "\nYou reach for the gun, and the humanoid sneers and puts it in your hand. It curls your fingers around the handle. \"Enjoy,\" it says.";

    public static string rejectGun =
    "\nYou refuse the first offer of the gun, and the humanoid sneers at you and says, \"As you wish, but you'll regret it.\"";

    public static string offerDagger =
    "\nThe shadowy figure then offers you a dagger, holding it out with a twisted grin. \"This blade will give you the power to cut down anyone " +
    "\nwho stands in your way,\" it says.";

    public static string acceptDaggerDead =
    "\nYou reach for the dagger, but the humanoid quickly takes it back and plunges it into your chest. Its laughter fills the room as you " +
    "\ncollapse to the ground, lifeless.";

    public static string acceptDaggerAlive =
    "\nYou reach for the dagger, and the humanoid lets out a low, rumbling chuckle. He then turns the handle of the dagger around, and places " +
    "\nit in your hand. \"Use it wisely.\"";

    public static string rejectDagger =
    "\nYou refuse the second offer of the dagger, the humanoid's expression turns to one of annoyance. It mutters under its breath before offering " +
    "\nyou the key.";

    public static string offerKey =
    "\"Take this key, and you'll unlock the power to overcome your greatest challenge,\" it says in a more subdued tone.";

    public static string rejectKey =
    "\nYou refuse the offer of the key. The humanoid's eyes narrow in anger. \"You fool!\" it hisses. \"You'll regret this decision.\" Suddenly, " +
    "\nit lunges towards you with lightning speed, and before you can react, it sinks its razor-sharp teeth into your neck, draining your life " +
    "\nforce. As you collapse to the ground, the humanoid's laughter fills the room, satisfied that it has claimed another victim.";

    public static string acceptKey =
    "\nYou reach out for the key, and the humanoid nods in approval and hands it to you. As it does so, it whispers into your ear: \"With this " +
    "\nkey, a path will be revealed, where power and peril shall be unsealed\", before suddenly turning into dust and disappearing. You are " +
    "\nleft alone in the room, wondering what the key unlocks and just what the rest of this labyrinth holds for you.";

    public static string previous =
    "\nYou are in the \"3NV7\" room. The dust of the humanoid which offered you a gun, a dagger, and a key is still there. You wonder what " +
    "\nwould have happened if you had taken the gun and dagger.";

    public static string navigation =
    "\nThere are two thick wooden doors: one is marked as \"PR1D3\" (South), while the other is marked as \"61U770N7\" (East).";
  }

  /*
  This is the Lust room script. This room poses no danger to the player. This room has an offer of a meaningless vial.
  */
  public class roomLU57
  {
    public static string initial =
    "\nYou open the door marked \"LU57\", and you enter a near empty room. There is a torch flickering on one wall, casting shadows which dance " +
    "\naround the room. Suddenly, a beautiful woman appears before you. Her long hair flows around her shoulders, and her eyes twinkle in the " +
    "\ndim light. She is holding a small vial, filled with a strange pink liquid. She offers it to you, claiming it symbolizes love, through " +
    "\nwhich all things are possible.";

    public static string acceptVial =
    "\nYou reach out to grab it, but before you can, the woman transforms into a grotesque monster with razor-sharp claws and teeth. You stumble " +
    "\nback, your heart pounding in fear, as the monster lunges at you, intent on tearing you apart. However, just as she is about to rip you to " +
    "\nshreds, she evaporates into the air, but not before she was able to get a couple scratches in. You catch your breath, gripping your scratches." +

    "\n\nYou look around, and realize you dropped the vial when the woman had jumped at you. The pink liquid is oozing all over the floor, mixed " +
    "\nwith the broken glass from the vial.";

    public static string rejectVial =
    "\nYou firmly decline the vial, but the woman refuses to accept your answer. She keeps insisting that you take the vial, growing increasingly " +
    "\ninsistent and desperate. You continue to reject her, and her beauty slowly fades; she transforms into a hideous witch." +

    "\n\nHer hair turns brittle and gray, her skin wrinkles and sags, and her eyes grow dull and lifeless. She withers away into nothingness, " +
    "\nleaving you alone in the dungeon, shaking with relief.";

    public static string navigation =
    "\nThere are four thick wooden doors: one is marked as \"PR1D3\" (West), another is marked as \"61U770N7\" (North), the third is marked as " +
    "\n\"6R33D\" (South), while the fourth \"4C3D14\" (East).";

    public static string previous =
    "\nYou open the door to the \"LU57\" room. There is a torch flickering on one wall, casting shadows which dance around the room.";

    public static string acceptedVial =
    "\nYou see the mix of broken glass and pink liquid from when you accepted the offer of the woman.";
  }

  /*
  This is the Sloth room script. This room contains trapped furniture that needs to be sat in to get the bronze key.
  */
  public class room5107H
  {
    public static string initial =
    "\nYou open the door marked \"5107H\", and are greeted with a dimly lit room, with cold stone walls. You notice something unusual in the " +
    "\ncenter of the room: a set of comfortable-looking furniture arranged neatly." +

    "\n\nWhen you inspect closer, you see the furniture is made of plush leather and soft cushions. You see something shiny wedged in the cushion " +
    "\nof one chair, but you are not sure what it is. You are drawn to sit in it.";

    public static string sitChair =
    "\nYou approach cautiously and sit down on one of the chairs, and sink into its comforting embrace." +

    "\n\nSuddenly, you hear a loud click. The chair's arms have snapped shut, trapping you. Panic sets in as you struggle to break free. You look " +
    "\naround and see the shiny object wedged in the cushion of the chair you are trapped in. You might be able to grab it if you try hard enough.";

    public static string reachObject =
    "\nYou angle your feet up on the chair enough to pry the shiny object out of the cushion. You are able to see it is a bronze key, and notice " +
    "\nthat there is a small keyhole on the arm of the chair, right beside your hand." +

    "\n\nYou realize that the key must be the only way out of this trap, and need to put the key into the chair. You struggle to orientate your " +
    "\nbody so that the key fits into the keyhole, but eventually you are able to get it." +

    "\n\nYou insert the key and turn it, and it gives a releasing click. The chair's grip on you loosens, and you are able to get up. You grab " +
    "\nthe bronze key.";

    public static string navigation =
    "\nThere are two thick wooden doors: one is marked as \"6R33D\" (West), while the other is marked as \"4C3D14\" (North).";

    public static string previousSat =
    "\nThis is the \"5107H\" room; it is a dimly lit room, with cold stone walls. It has a set of comfortable-looking furniture arranged " +
    "\nneatly in the center of the room, which you had previously sat in.";

    public static string previousNoSat =
    "\nThis is the \"5107H\" room; it is a dimly lit room, with cold stone walls. It has a set of comfortable-looking furniture arranged " +
    "\nneatly in the center of the room, which has a shiny object in the cushion of one chair. You are still drawn to it";
  }

  /*
  This is the Gluttony room script. This room contains poisonous food, that should NOT be eaten.
  */
  public class room61U770N7
  {
    public static string entrance =
    "\nAs you enter the \"61U770N7\" Room, your nostrils are met with the intoxicating  aroma of food. There are tables and tables of food " +
    "\nand drink around you. Your stomach growls with hunger and your mouth is dry with thirst." +

    "\n\nThere are three thick wooden doors: one is marked as \"3NV7\" (West), another is marked as \"LU57\" (South), and the third is marked " +
    "\nas \"WR47H\" (East).";

    public static string ateFood =
    "\nYou decide to give in to your hunger and thirst and start to consume the food at a rapid rate. You shovel food into your mouth, barely " +
    "\neven giving your tongue a chance to taste it, in a desperate attempt to fill your stomach." +

    "\n\nSuddenly, you feel a sharp pain in your stomach, and you collapse to the ground. You realize, too late, that the food has been poisoned. " +
    "\nAs life fades from your eyes, you ask yourself what you could have done differently.";
  }

  /*
  This is the Acedia room script. This is the room from which the player will eventually escape.
  */
  public class room4C3D14
  {
    public static string entrance =
    "\nYou open the \"4C3D14\" door and are greeted with a pristine stone box of a room. The walls are completely smooth, and the floor is flat " +
    "\nas can be. The only thing in the room not in pristine condition is in the very center of the room: a protrusion coming out from the center " +
    "\nof the floor. There is a rusty hatch on the protrusion, held shut with a lock." +

    "\n\nYou approach the hatch. As you inspect it, you see that the lock has three keyholes." +

    "\n\nThere are three thick wooden doors: one is marked as \"WR47H\" (North), another is marked as \"LU57\" (West), and the third is marked as " +
    "\n\"5107H\" (South). What would you like to do?";

    public static string threeKeys1 =
    "\nYou grab the three keys you have collected: the bronze key, the silver key, and the gold key and place them into the lock at the center of " +
    "\nthe room. You hear the lock click open, and you are able to release it from holding the hatch." +

    "\n\nYou grab the rusty hatch and use all your might to flip it open. It reveals a ladder, built into the floor, going down unto the depths below. " +
    "\nYou don't know what it might hold, but it surely must  be better than the hell that you just went through." +

    "\n\nYou mount the ladder, and start descending into the darkness. As you descend, you start to hear the sound of a search party. You hear your name " +
    "\nbeing called; people are searching for you! As you continue going down, you are able to see their search lights shining up at you.";

    public static string foundYou(string name)
    {
      return name + ", is that you? Oh my god, it is you! We are so glad we have found you!";
    }

    public static string threeKeys2 =
    "\nYour heart races with excitement and gratitude as you make your way towards the sound of their voices. As you emerge from the ladder and rejoin " +
    "\nyour friends, you feel overwhelmed with gratitude and a renewed sense of appreciation for your life.";
  }

  /*
  This is the Wrath room script. This room has a giant boss battle with a huge wolf. It helps very much to have the gun.
  */
  public class roomWR47H
  {
    public static string initial =
    "\nAs you open the door marked \"WR47H\", you hear a low, rumbling growl come from the dark room. You open your eyes wide and try to get a good " +
    "\nlook at the shadowy room. Your eyes scan until you spot a huge wolf, its gray fur bristling like a porcupine, glaring at you with stone blue " +
    "\neyes. It opens its maw, and you see a huge row of razor-sharp teeth, sharpened to a point.";

    public static string previousFlee =
    "\nYou enter the \"WR47H\" room. The wolf is still there, making a low rumbling growl at you from the far corner of the dungeon room.";

    public static string previousFight =
    "\nYou enter the \"WR47H\" room. The wolf's lifeless corpse is still there. There are now flies sucking on the wolf's eyeballs and tongue.";

    public static string fightOrFlee =
    "\nIt seems that you have two options: fight it or flee.";

    public static string playerDeath =
    "\nYou put up a good fight, but you are no match against its powerful jaws, and its robust build. The beast overpowers you, unleashing its gruesome " +
    "\nwrath. You feel its sharp claws and teeth dig into your flesh, tearing you apart in a violent display.";

    public static string wolfDeath =
    "\nThe wolf attempts to go for another strike, but it collapses onto the floor, choking and wheezing. You watch as the wolf slowly loses its life, " +
    "\nbloodied and battered. Right before its corpse relaxes, it spits out a golden key. You wait until you are sure that the beast is dead, and you " +
    "\ngrab the golden key.";

    public static string navigation =
    "\nThere are two thick wooden doors: one is marked as \"61U770N7\" (West), while the other is marked as \"4C3D14\" (South).";

    /*
    This class contains attacks that happen when you have the GUN in your inventory
    */
    public class gunAttacks
    {
      public static string prepare =
      "\nFueled by the rush of adrenaline from a life or death scenario, you attempt to defend yourself as the beast looms closer. You grab your gun " +
      "\nthat you got from the humanoid in the \"3NVY\" room and aim it at the beast.";

      public static string heavy =
      "\nYou fire the gun with a loud CRACK, and strike the wolf in the skull, causing it to let out a huge bellowing cry. Blood oozes out of the " +
      "\nraw wound.";

      public static string medium =
      "\nYou fire the gun with a loud CRACK, and strike the wolf in the hind quarters. It releases a furious snarl, and lunges towards you.";

      public static string weak =
      "\nYou fire the gun with a loud CRACK, and graze the wolf's back. It barely even notices the impact, and goes in for an attack.";

      public static string miss =
      "\nYou fire the gun, but you completely miss the wolf. Hearing the loud noise causes the wolf to become even angrier.";
    }

    /*
    This class contains attacks that happen when you have the DAGGER in your inventory
    */
    public class daggerAttacks
    {
      public static string prepare =
      "\nYou pull your dagger out and point it towards the wolf, preparing for the collision between you two.";

      public static string heavy =
      "\nYou thrust the dagger in the direction of the wolf's chest. Your blade finds its mark, and pulls apart the thick hide protecting this " +
      "\nbeast, revealing the pulsing and bloody inside of its chest. The wolf lets out a meek whimper, then opens in maw, revealing a huge row " +
      "\nof jagged teeth.";

      public static string medium =
      "\nCaught in an imbalanced position, you point the dagger towards the wolf. The dagger strikes the side of the wolf's shoulder, causing " +
      "\nit to wince in pain. However, the beast soon recovers and goes in for a strike.";

      public static string weak =
      "\nTired, you attempt to stab the wolf, but you only inflict a minor cut in the wolf's hide. Indifferent, the wolf goes in to murder its " +
      "\nattacker: you.";

      public static string miss =
      "\nYou attempt to harm the wolf using the dagger, but it doesn't work at all. You don't even penetrate the wolf's hide, and only serve to " +
      "\nincrease its desire to rip you to shreds.";
    }

    /*
    This class contains attacks that happen when you have no weapons in your inventory
    */
    public class fistAttacks
    {
      public static string prepare =
      "\nWith nothing but your fists, you prepare to fight the wolf.";

      public static string medium =
      "\nYou pull your fist back and plunge it forward. You connect with the side of the beast's skull, but the wolf merely shakes it off and " +
      "\nlunges towards you.";

      public static string weak =
      "\nYou attempt to punch the wolf, but your punch doesn't have enough oomph behind it, and makes a mild thump when it connects with the " +
      "\nwolf. The wolf barely notices, and continues its assault on your body.";

      public static string miss =
      "\nYou attempt to punch the wolf, but your arm easily gets redirected out of the way by the wolf's violent movements.";
    }

    /*
    This class contains attacks that happen when the wolf attacks the player
    */
    public class wolfAttacks
    {
      public static string prepare =
      "\nThe wolf advances towards you, determined to eliminate the living thing in front of it. It lets out a huge howl.";

      public static string heavy =
      "\nThe wolf lunges at you with its muscular body. It quickly clamps down on your flesh, inflicting a deep wound in your gut. You scream " +
      "\nin pain.";

      public static string medium =
      "\nThe wolf strikes you with a quick swipe of its paw, creating a deep gash in your arm as it does so.";

      public static string weak =
      "\nThe wolf advances and attempts to take a chunk out of your person. However, you are able to react and flex your body out of the way " +
      "\nenough to just endure some mild scratches and impacts.";

      public static string miss =
      "\nThe wolf staggers back, catching its breath. You are able to get another attack in before it strikes.";
    }
  }
}

class GridOfSin
{
  //this keeps track of the rooms which the player has and hasn't been to in order to use the correct prompts.
  private static Dictionary<string, bool> roomsExplored = new Dictionary<string, bool>(9);

  //this keeps track of if the player has accepted the vial from the woman in the LUST room
  private static bool acceptedVial = false;

  //this keeps track of if the player has sat in the chair in the SLOTH room.
  private static bool satInChair = false;

  //this keeps track of if the player has killed the wolf in the WRATH room.
  private static bool wolfDead = false;

  //this is how much health the wolf has, which is much more than the player health.
  private static int wolfHealth = 200;

  //this is the maximum amount of damage that the wolf can do in a single attack
  private static int wolfDamage = 36;

  //this is a reference for the different damages the player can do depending on which weapon they are in possession of
  private static Dictionary<string, int> weaponDamage = new Dictionary<string, int>(3) { { "gun", 76 }, { "dagger", 60 }, { "fist", 40 } };

  //this keeps track of the player inventory
  private static List<string> playerInventory = new List<string>();

  //this is how much health the player has to begin with
  private static int playerHealth = 100;

  //the name of the player
  private static string playerName = "";

  //variable to determine the input of the player
  private static string playerChoice = "";



  /*
  This is the MAIN function of the program. It sets up the variables, prints the introduction, and starts the player in the right room.
  */
  public static void Main()
  {
    setGameData();
    introduction();
    roomR3GR37();
  }

  /*
  resets variables the might have changed during the previous session
  */
  private static void setGameData()
  {
    roomsExplored = setRoomsExplored();     //sets all the rooms to unexplored
    acceptedVial = false;                   //default to not have taken the vial
    satInChair = false;                     //default to not have sat in the chair
    wolfDead = false;                       //default to have the wolf alive until killed
    wolfHealth = 200;                       //reset the wolf's health
    playerInventory = new List<string>();   //reset the player's inventory
    playerHealth = 100;                     //reset the player's health
  }


  /*
  Helper function to reset all of the rooms to unexplored
  */
  private static Dictionary<string, bool> setRoomsExplored()
  {
    Dictionary<string, bool> ret = new Dictionary<string, bool>(9);
    string[] rooms = { "R3GR37", "PR1D3", "6R33D", "3NV7", "LU57", "5107H", "61U770N7", "4C3D14", "WR47H" };
    foreach (string room in rooms)
    {
      ret.Add(room, false);
    }

    return ret;
  }


  /*
  Helper function to print the player's current inventory
  */
  private static void printInventory()
  {
    Console.WriteLine("\nCurrent Inventory\n=================");
    foreach (string item in playerInventory)
    {
      Console.WriteLine("-  " + item);
    }
    Console.WriteLine("=================");
  }


  /*
  Prints the introduction to the game
  */
  private static void introduction()
  {
    Console.Clear();  //clear console for better immersion
    Console.WriteLine(Script.introduction);
    Console.WriteLine(Script.warning);

    Console.Write(Script.preNamePrompt);
    playerName = Console.ReadLine() ?? "Bob";
    Console.WriteLine(Script.postNamePrompt);

    Console.WriteLine(Script.aboutGame);
  }


  /*
  Gets and returns the player's input using the passed prompt. CONVERTS ALL INPUT INTO UPPERCASE, SO COMMANDS ARE NOT CASE-SENSITIVE
  */
  private static string getChoice(string prompt)
  {
    Console.Write("\n\n" + prompt + "  ");
    return (Console.ReadLine() ?? "").ToUpper();
  }

  /*
  This is the room the player starts in. There is not much to do except look around and go into a different room
  */
  private static void roomR3GR37()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (roomsExplored["R3GR37"])
    {
      Console.WriteLine(Script.roomR3GR37.previous);
    }
    else
    {
      Console.WriteLine(Script.roomR3GR37.initial);
      roomsExplored["R3GR37"] = true;
    }
    if (!playerInventory.Contains("Flashlight"))
    {
      Console.WriteLine(Script.roomR3GR37.flashlight);
    }

    Console.WriteLine(Script.roomR3GR37.navigation);

    //gets input from the player to determine what they want to do
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("PR1D3") || playerChoice.Contains("NORTH"))
      {
        roomPR1D3();
      }
      else if (playerChoice.Contains("6R33D") || playerChoice.Contains("EAST"))
      {
        room6R33D();
      }
      else if (playerChoice.Contains("LOOK"))
      {
        Console.WriteLine(Script.decisionSeparator);
        Console.WriteLine(Script.roomR3GR37.look);
      }
      else if ((playerChoice.Contains("TAKE") || playerChoice.Contains("FLASHLIGHT")) && !playerInventory.Contains("Flashlight"))
      {
        Console.WriteLine(Script.decisionSeparator);
        Console.WriteLine("\nYou pick up the flashlight.");
        playerInventory.Add("Flashlight");

      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }


  /*
  This is the PRIDE room. The only meaningful thing in this room is a mirror which could kill the player
  */
  private static void roomPR1D3(bool exitMirror = false)
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (!exitMirror)
    {
      if (roomsExplored["PR1D3"])
      {
        Console.WriteLine(Script.roomPR1D3.previous);
      }
      else
      {
        Console.WriteLine(Script.roomPR1D3.initial);
        roomsExplored["PR1D3"] = true;
      }
    }
    Console.WriteLine(Script.roomPR1D3.navigation);

    //gets input from the player to determine what they want to do
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("LOOK") || playerChoice.Contains("GAZE") || playerChoice.Contains("MIRROR"))
      {
        Console.WriteLine(Script.decisionSeparator);
        mirrorDialogue(); //subfunction to handle the mirror choices
      }
      else if (playerChoice.Contains("R3GR37") || playerChoice.Contains("SOUTH"))
      {
        roomR3GR37();
      }
      else if (playerChoice.Contains("LU57") || playerChoice.Contains("EAST"))
      {
        roomLU57();
      }
      else if (playerChoice.Contains("3NV7") || playerChoice.Contains("NORTH"))
      {
        room3NV7();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }


  /*
  Helper function to handle the dialogue for when the player looks into the mirror
  */
  private static void mirrorDialogue()
  {
    //first time looking into the mirror
    Console.WriteLine(Script.roomPR1D3.lookAtMirror1);

    //second time looking into the mirror
    while (true)
    {
      playerChoice = getChoice("Continue looking at the mirror?");

      if (playerChoice.Contains("NO") || playerChoice.Contains("NOT"))
      {
        Console.WriteLine("\nYou stop looking at the mirror, deciding it wasn't helpful in escaping this dungeon.");
        roomPR1D3(true);
      }
      else if (playerChoice.Contains("YES") || playerChoice.Contains("CONTINUE"))
      {
        Console.WriteLine(Script.roomPR1D3.lookAtMirror2);

        //third and final time looking into the mirror
        while (true)
        {
          playerChoice = getChoice("Continue looking at the mirror?");

          if (playerChoice.Contains("NO") || playerChoice.Contains("NOT"))
          {
            Console.WriteLine("\nYou stop looking at the mirror, deciding it wasn't helpful in escaping this dungeon.");
            roomPR1D3(true);
          }
          else if (playerChoice.Contains("YES") || playerChoice.Contains("CONTINUE"))
          {
            //the player looked at the mirror for too long and got murdered
            Console.WriteLine(Script.roomPR1D3.lookAtMirror3);
            conclusion(false);
          }
          else if (playerChoice.Contains("INVENTORY"))
          {
            printInventory();
          }
          else
          {
            Console.WriteLine(Script.inputError);
          }
        }
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }


  /*
  This is the GREED room. This room forces the player to choose between to valuable items; they must choose the lower value item, which is the golden glasses.
  */
  private static void room6R33D()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (roomsExplored["6R33D"])
    {
      Console.WriteLine(Script.room6R33D.previous);
    }
    else
    {
      Console.WriteLine(Script.room6R33D.initial);
      roomsExplored["6R33D"] = true;

      //first time in the room, require the player to pick between the items
      while (true)
      {
        playerChoice = getChoice("Will you take the Ruby Necklace or Golden Glasses?");

        //the golden glasses is the correct choice because it is less valuable than a ruby necklace
        if (playerChoice.Contains("GOLD"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room6R33D.goldenGlasses);
          playerInventory.Add("Golden Glasses");
          break; //break out of the input loop to move on to next choice
        }
        //the ruby necklace is the INcorrect choice because it is more valuable than gold glasses
        else if (playerChoice.Contains("RUBY"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room6R33D.rubyNecklace);
          conclusion(false);
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }
    }

    //get input for navigation of the player
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("R3GR37") || playerChoice.Contains("WEST"))
      {
        roomR3GR37();
      }
      else if (playerChoice.Contains("LU57") || playerChoice.Contains("NORTH"))
      {
        roomLU57();
      }
      else if (playerChoice.Contains("5107H") || playerChoice.Contains("EAST"))
      {
        room5107H();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the ENVY room. This is where the player is offered a GUN, a DAGGER, and a KEY. 
  They MUST take the key, and should try to take either the dagger or the gun, but neither is guaranteed to be given to them.
  */
  private static void room3NV7()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (roomsExplored["3NV7"])
    {
      Console.WriteLine(Script.room3NV7.previous);
    }
    else
    {
      //randomly determine whether a player can or cannot get the gun/dagger
      Random rand = new Random();
      Console.WriteLine(Script.room3NV7.initial);
      roomsExplored["3NV7"] = true;
      Console.WriteLine(Script.room3NV7.offerGun);

      while (true)
      {
        playerChoice = getChoice("Do you take the gun?");

        if (playerChoice.Contains("YES"))
        {
          //player has a 1/3 chance of being able to get the gun
          if (rand.Next(0, 3) == 2)
          {
            Console.WriteLine(Script.decisionSeparator);
            Console.WriteLine(Script.room3NV7.acceptGunAlive);
            playerInventory.Add("Gun");
            break;
          }
          else
          {
            Console.WriteLine(Script.decisionSeparator);
            Console.WriteLine(Script.room3NV7.acceptGunDead);
            conclusion(false);
          }
        }
        //player can ALWAYS reject the gun with no penalty
        else if (playerChoice.Contains("NO"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room3NV7.rejectGun);
          break;
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }

      Console.WriteLine(Script.room3NV7.offerDagger);
      while (true)
      {
        playerChoice = getChoice("Do you take the dagger?");

        if (playerChoice.Contains("YES"))
        {
          //player has a 1/2 chance of getting the dagger
          if (rand.Next(0, 2) == 1)
          {
            Console.WriteLine(Script.decisionSeparator);
            Console.WriteLine(Script.room3NV7.acceptDaggerAlive);
            playerInventory.Add("Dagger");
            break;
          }
          else
          {
            Console.WriteLine(Script.decisionSeparator);
            Console.WriteLine(Script.room3NV7.acceptDaggerDead);
            conclusion(false);
          }
        }
        //player can ALWAYS reject the offer of the dagger with no penalty
        else if (playerChoice.Contains("NO"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room3NV7.rejectDagger);
          break;
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }

      Console.WriteLine(Script.room3NV7.offerKey);
      while (true)
      {
        playerChoice = getChoice("Do you take the silver key?");

        //player MUST take the silver key. If they reject it the game is not completable
        if (playerChoice.Contains("YES"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room3NV7.acceptKey);
          playerInventory.Add("Silver Key");
          break;
        }
        //if the player rejects the key they are KILLED
        else if (playerChoice.Contains("NO"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room3NV7.rejectKey);
          conclusion(false);
          Console.WriteLine(Script.decisionSeparator);
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }
    }

    //three offers have taken place, now get navigation from the player
    Console.WriteLine(Script.room3NV7.navigation);
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("PR1D3") || playerChoice.Contains("SOUTH"))
      {
        roomPR1D3();
      }
      else if (playerChoice.Contains("61U770N7") || playerChoice.Contains("EAST"))
      {
        room61U770N7();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }


  /*
  This is the LUST room. This room has a woman which offers the player to get a vial.
  The interaction is mostly meaningless, and just filler for more immersion.
  */
  private static void roomLU57()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (roomsExplored["LU57"])
    {
      Console.WriteLine(Script.roomLU57.previous);
      if (acceptedVial) { Console.WriteLine(Script.roomLU57.acceptedVial); }
    }
    else
    {
      Console.WriteLine(Script.roomLU57.initial);
      roomsExplored["LU57"] = true;

      while (true)
      {
        //the player can accept or reject the vial, with no consequence on the game
        playerChoice = getChoice("Do you accept the vial?");

        if (playerChoice.Contains("YES"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.roomLU57.acceptVial);
          acceptedVial = true;
          break;
        }
        else if (playerChoice.Contains("NO"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.roomLU57.rejectVial);
          break;
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }
    }
    Console.WriteLine(Script.roomLU57.navigation);

    //get the navigation from the player, this room is the CENTRAL room for the dungeon, so many doors
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("PR1D3") || playerChoice.Contains("WEST"))
      {
        roomPR1D3();
      }
      else if (playerChoice.Contains("61U770N7") || playerChoice.Contains("NORTH"))
      {
        room61U770N7();
      }
      else if (playerChoice.Contains("6R33D") || playerChoice.Contains("SOUTH"))
      {
        room6R33D();
      }
      else if (playerChoice.Contains("4C3D14") || playerChoice.Contains("EAST"))
      {
        room4C3D14();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the SLOTH room. This is the location of the bronze key, which is required to get in order to complete the game.
  The player SHOULD, but doesn't have to, sit in the chair. They could always leave and then come back and sit.
  */
  private static void room5107H(bool exitChair = false)
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (roomsExplored["5107H"] && satInChair && !exitChair)
    {
      Console.WriteLine(Script.room5107H.previousSat);
    }
    else if (roomsExplored["5107H"] && !satInChair & !exitChair)
    {
      Console.WriteLine(Script.room5107H.previousNoSat);
    }
    else if (!exitChair)
    {
      Console.WriteLine(Script.room5107H.initial);
      roomsExplored["5107H"] = true;
    }
    Console.WriteLine(Script.room5107H.navigation);

    //get navigation / decision for if the player wants to sit in the chair.
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      //the player can only sit in the chair once, in order to get the key.
      if (!satInChair && (playerChoice.Contains("SIT") || playerChoice.Contains("CHAIR")))
      {
        Console.WriteLine(Script.decisionSeparator);
        satInChair = true;
        chairDialogue(); //goes to a helper function for the chair dialogue.
      }
      else if (playerChoice.Contains("6R33D") || playerChoice.Contains("WEST"))
      {
        room6R33D();
      }
      else if (playerChoice.Contains("4C3D14") || playerChoice.Contains("NORTH"))
      {
        room4C3D14();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  Helper function for the chair dialogue which happens when the player sits in the chair in the SLOTH room.
  */
  private static void chairDialogue()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.room5107H.sitChair);

    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      //the player CANNOT do anything until they escape the chair. (aside from looking at their inventory)
      if (playerChoice.Contains("REACH") || playerChoice.Contains("TRY"))
      {
        Console.WriteLine(Script.decisionSeparator);
        Console.WriteLine(Script.room5107H.reachObject);
        playerInventory.Add("Bronze Key");
        room5107H(true);
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the GLUTTONY room. This room contains food which is poisonous and SHOULD NOT be eaten, lest the player simply DIE
  */
  private static void room61U770N7()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    Console.WriteLine(Script.room61U770N7.entrance);
    roomsExplored["61U770N7"] = true;

    while (true)
    {
      //the player can, but does not have to, eat the room in the room. They could also just leave the room
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("3NV7") || playerChoice.Contains("WEST"))
      {
        room3NV7();
      }
      else if (playerChoice.Contains("LU57") || playerChoice.Contains("SOUTH"))
      {
        roomLU57();
      }
      else if (playerChoice.Contains("WR47H") || playerChoice.Contains("EAST"))
      {
        roomWR47H();
      }
      else if (playerChoice.Contains("EAT") || playerChoice.Contains("DRINK"))
      {
        //the player ate the room and died.
        Console.WriteLine(Script.decisionSeparator);
        Console.WriteLine(Script.room61U770N7.ateFood);
        conclusion(false);
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the ACEDIA room. This is the escape room, but it requires that the player have the gold, silver, and bronze key in order to escape.
  */
  private static void room4C3D14()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    Console.WriteLine(Script.room4C3D14.entrance);

    while (true)
    {
      //determines what the player want to do, and if they have the keys required to complete the game.
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("HATCH") || playerChoice.Contains("KEY"))
      {
        if (playerInventory.Contains("Silver Key") && playerInventory.Contains("Bronze Key") && playerInventory.Contains("Golden Key"))
        {
          Console.WriteLine(Script.decisionSeparator);
          Console.WriteLine(Script.room4C3D14.threeKeys1);
          Console.WriteLine(Script.room4C3D14.foundYou(playerName));
          Console.WriteLine(Script.room4C3D14.threeKeys2);

          conclusion(true);
        }
        else
        {
          //very specific error for when the player tries to open the hatch without having the three keys
          Console.WriteLine(Script.keyError);
        }
      }
      //these are all navigation choices for the player to go to a different room
      else if (playerChoice.Contains("WR47H") || playerChoice.Contains("NORTH"))
      {
        roomWR47H();
      }
      else if (playerChoice.Contains("LU57") || playerChoice.Contains("WEST"))
      {
        roomLU57();
      }
      else if (playerChoice.Contains("5107H") || playerChoice.Contains("SOUTH"))
      {
        room5107H();
      }
      //inventory and error options
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the WRATH room. This is an important room, because the player MUST eventually fight the wolf in order to win the game.
  It is recommended that the player fight the wolf with either a GUN or a DAGGER, because beating the wolf with fists is extremely hard.
  */
  private static void roomWR47H()
  {
    //prints the contextualized introduction into the room
    Console.WriteLine(Script.decisionSeparator);
    if (wolfDead && roomsExplored["WR47H"])
    {
      Console.WriteLine(Script.roomWR47H.previousFight);
    }
    else if (roomsExplored["WR47H"])
    {
      Console.WriteLine(Script.roomWR47H.previousFlee);
    }
    else
    {
      Console.WriteLine(Script.roomWR47H.initial);
      roomsExplored["WR47H"] = true;
    }

    //The wolf has not been fought yet
    if (!wolfDead)
    {
      while (true)
      {
        playerChoice = getChoice(Script.roomWR47H.fightOrFlee + "\nWhat would you like to do?");

        //the player decides to fight the wolf
        if (playerChoice.Contains("FIGHT"))
        {
          Console.WriteLine(Script.decisionSeparator);
          if (playerInventory.Contains("Gun")) wolfFight("gun");
          else if (playerInventory.Contains("Dagger")) wolfFight("dagger");
          else wolfFight("fist");
          break; //after wolf fight is completed (this implies the player won to break;), go to navigation
        }

        //the player decides to flee to another room, likely to better prepare themselves for the fight
        else if (playerChoice.Contains("FLEE"))
        {
          roomWR47H_navigation();
        }
        else if (playerChoice.Contains("INVENTORY"))
        {
          printInventory();
        }
        else
        {
          Console.WriteLine(Script.inputError);
        }
      }
    }

    //specialized helper function for the navigation of the WRATH room, used to minimize code repetition
    roomWR47H_navigation();
  }

  /*
  Helper function which gets the navigation from the WRATH room. Used to minimize code repetition.
  */
  private static void roomWR47H_navigation()
  {
    //prompt the player for their choice of navigation
    Console.WriteLine(Script.roomWR47H.navigation);
    while (true)
    {
      playerChoice = getChoice("What would you like to do?");

      if (playerChoice.Contains("61U770N7") || playerChoice.Contains("WEST"))
      {
        room61U770N7();
      }
      else if (playerChoice.Contains("4C3D14") || playerChoice.Contains("SOUTH"))
      {
        room4C3D14();
      }
      else if (playerChoice.Contains("INVENTORY"))
      {
        printInventory();
      }
      else
      {
        Console.WriteLine(Script.inputError);
      }
    }
  }

  /*
  This is the fight between the player and the wolf. This is required to BEAT in order to complete the game.
  */
  public static void wolfFight(string weapon)
  {
    Random rand = new Random();
    int damage;

    while (true)
    {
      //player's attack
      Console.WriteLine($"{playerName}'s attack:\n==============\n");
      damage = rand.Next(0, weaponDamage[weapon]); //determine possible damage based off of lookup dictionary
      wolfHealth -= damage; //the wolf got hit this much

      Console.WriteLine(getDamageText(weapon, damage)); //get the corresponding event which happened based on how much damage was done
      Console.WriteLine($"\n[ You did {damage} damage to the wolf ]");
      if (wolfHealth > 0)
      {
        Console.WriteLine($"[ Wolf's health: {wolfHealth} ]");
        Console.WriteLine($"[ {playerName}'s health: {playerHealth} ]");
      }

      //the wolf has died if this is true, the player has WON the battle
      if (wolfHealth < 1)
      {
        Console.WriteLine(Script.roomWR47H.wolfDeath);
        playerInventory.Add("Golden Key");
        wolfDead = true;
        break;
      }

      //the player should choose when the information progresses
      Console.WriteLine("[ PRESS ENTER TO CONTINUE ]");
      Console.ReadLine();

      //wolf's attack
      Console.WriteLine("Wolf's attack:\n==============\n");
      damage = rand.Next(0, wolfDamage); //determine possible damage the wolf will do
      playerHealth -= damage; //the player got hit this much

      Console.WriteLine(getWolfText(damage)); //get the corresponding event which happened based on how much damage was done
      Console.WriteLine($"\n[ The wolf did {damage} damage to you ]");
      if (playerHealth > 0)
      {
        Console.WriteLine($"[ Wolf's health: {wolfHealth} ]");
        Console.WriteLine($"[ {playerName}'s health: {playerHealth} ]");
      }

      //the player has died if this is true, the player has LOST the battle, GAME OVER
      if (playerHealth < 1)
      {
        Console.WriteLine(Script.roomWR47H.playerDeath);
        conclusion(false);
      }

      //the player should choose when the information progresses
      Console.WriteLine("[ PRESS ENTER TO CONTINUE ]");
      Console.ReadLine();
    }
  }

  /*
  Helper function, acts as a lookup table for the script event that happens based off of damage and the kind of weapon used.
  */
  public static string getDamageText(string weapon, int damage)
  {
    switch (weapon)
    {
      case "gun":
        if (damage > (2 * weaponDamage["gun"] / 3)) return (Script.roomWR47H.gunAttacks.heavy);
        if (damage > (weaponDamage["gun"] / 3)) return (Script.roomWR47H.gunAttacks.medium);
        if (damage > 0) return (Script.roomWR47H.gunAttacks.weak);
        else return (Script.roomWR47H.gunAttacks.miss);
      case "dagger":
        if (damage > (2 * weaponDamage["dagger"] / 3)) return (Script.roomWR47H.daggerAttacks.heavy);
        if (damage > (weaponDamage["dagger"] / 3)) return (Script.roomWR47H.daggerAttacks.medium);
        if (damage > 0) return (Script.roomWR47H.daggerAttacks.weak);
        else return (Script.roomWR47H.daggerAttacks.miss);
      case "fist":
        if (damage > (weaponDamage["fist"] / 2)) return (Script.roomWR47H.fistAttacks.medium);
        if (damage > 0) return (Script.roomWR47H.fistAttacks.weak);
        else return (Script.roomWR47H.daggerAttacks.miss);
      default:
        return ("[ ERROR IN DAMAGE LOOKUP TABLE]");
    }
  }

  /*
  Helper function, gets the corresponding script event that happens based off of the damage the wolf has done.
  */
  public static string getWolfText(int damage)
  {
    if (damage > (2 * wolfDamage / 3)) return (Script.roomWR47H.wolfAttacks.heavy);
    if (damage > (wolfDamage / 3)) return (Script.roomWR47H.wolfAttacks.medium);
    if (damage > (0)) return (Script.roomWR47H.wolfAttacks.weak);
    else return (Script.roomWR47H.wolfAttacks.miss);
  }

  /*
  This is a game ending state. If true is passed, the player has won the game. If false, the player has lost the game
  */
  private static void conclusion(bool win)
  {
    if (win)
    {
      Console.WriteLine(Script.winMsg);
    }
    else
    {
      Console.WriteLine(Script.deathMsg);
    }

    while (true)
    {
      //prompt the user to player again, whether they won or lost
      playerChoice = getChoice("Would you like to play again?");

      if (playerChoice.Contains("YES"))
      {
        setGameData();
        roomR3GR37();
      }
      //no more game to be played, display credits and exit the program
      else if (playerChoice.Contains("NO"))
      {
        credits();
      }
    }
  }

  /*
  Helper function, just prints the credits and exists the game safely
  */
  public static void credits()
  {
    Console.WriteLine(Script.decisionSeparator);
    Console.WriteLine(Script.credits);

    Environment.Exit(1);
  }
}