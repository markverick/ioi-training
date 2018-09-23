#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <vector>

using namespace std;

//Define sides     (The back should be orange. Alas, I could not make orange, so it is purple instead.)
char sTop[10] = {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', '\0'};
char sLeft[10] = {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', '\0'};
char sFront[10] = {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', '\0'};
char sRight[10] = {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', '\0'};
char sBottom[10] = {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', '\0'};
char sBack[10] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '\0'};

//The title to use on every 'page'
string title = "                              --Console Cube--";

//Get Cube Status (Used during the game to tell the user if the cube is solved)
string getStatus()
{
   for (int sqr = 0; sqr < 8; sqr++)
   {
      if (sTop[sqr] != 'R' ||
          sLeft[sqr] != 'B' ||
          sFront[sqr] != 'W' ||
          sRight[sqr] != 'Y' ||
          sBottom[sqr] != 'G' ||
          sBack[sqr] != 'P')
      {
         return "Unsolved";
      }
   }
   return "**Complete**";
}

//Show the help text (Used with playHelpKeyControl below)
void helpText()
{
   system("CLS");

   cout << title;
   cout << "\n\n\nHelp:\n\n"
        << "Controls: First select the side you wish to choose (t, l, f, r, bo, ba), then\nthe"
        << " direction you want to turn it (c = clockwise, cc = counterclockwise).\nSide and "
        << "direction should be seperated by a space. So, if you would like to\nrotate the top of "
        << "the cube clockwise, you would type 't c (ENTER)'.\n\nI did the best I could to make"
        << " a 2D representation of a 3D object, so the cube\nthe game shows will be folded out "
        << "(It looks kind of like a cross), but its\nrotations will work exactly the same as a 3D"
        << " cube (meaning that the back, which is the very bottom square on the 2D cube, will be "
        << "flipped upside-down).\n\nYou can type 'exit' to stop playing. You can type 'reset' to "
        << "reset the cube.\n\nYou can type 'scramble' and a number to scramble the cube "
        << "('scramble', then a\nspace, then an integer. Random sides will be turned the amount of"
        << " times of the\nnumber). You can type 'alg' to enter algorithms.\n\n";
}

//Show the key (Used with playHelpKeyControl below)
void keyText()
{
   HANDLE color;
   color = GetStdHandle(STD_OUTPUT_HANDLE);

   system("CLS");

   cout << title;
   cout << "\n\n\nKey:\n\n";
   SetConsoleTextAttribute(color, 12);
   cout << "                                    TOP\n\n";
   SetConsoleTextAttribute(color, 9);
   cout << "                              LEFT ";
   SetConsoleTextAttribute(color, 15);
   cout << "FRONT ";
   SetConsoleTextAttribute(color, 14);
   cout << "RIGHT\n\n";
   SetConsoleTextAttribute(color, 10);
   cout << "                                  BOTTOM\n\n";
   SetConsoleTextAttribute(color, 13);
   cout << "                                   BACK\n\n\n";
   SetConsoleTextAttribute(color, 7);
}

//Ask if the user wants to play, get help, or view the key ("play" = continue to next step in Main)
void playHelpKeyControl()
{
   bool continueToGame = false;

   do
   {
      string playHelpKey;

      cout << title << "\n\n";
      cout << "Type 'play,' 'help,' or 'key': ";
      cin >> playHelpKey;

      system("CLS");
      if (playHelpKey == "play")
      {
         system("CLS");
         continueToGame = true;
      }

      else if (playHelpKey == "help")
      {
         helpText();
      }

      else if (playHelpKey == "key")
      {
         keyText();
      }
   }
   while (continueToGame == false);
}

//----------Show 2D representation of the cube in its current state-----------//
//          (Draw the cube in the beginning, and redraw after turns)
void showCube()
{
   HANDLE color;
   color = GetStdHandle(STD_OUTPUT_HANDLE);

   system("CLS");

   cout << "\n\n\n" << title << "             Status: ";

   //Show the cube's status at the top at all times ("Complete" or "Unsolved")
   if (getStatus() == "**Complete**")
      {SetConsoleTextAttribute(color, 12);}
   cout << getStatus() << "\n\n";

//Load each individual square into a string, with spaces for padding.
   string cube = "";
   //top
   cube = cube + "                                     " + sTop[0] + sTop[1] + sTop[2] + "\n";
   cube = cube + "                                     " + sTop[3] + sTop[4] + sTop[5] + "\n";
   cube = cube + "                                     " + sTop[6] + sTop[7] + sTop[8] + "\n\n";

   //left, front, right
   cube = cube + "                                 " + sLeft[0] + sLeft[1] + sLeft[2];
   cube = cube + " " + sFront[0] + sFront[1] + sFront[2];
   cube = cube + " " + sRight[0] + sRight[1] + sRight[2] + "\n";

   cube = cube + "                                 " + sLeft[3] + sLeft[4] + sLeft[5];
   cube = cube + " " + sFront[3] + sFront[4] + sFront[5];
   cube = cube + " " + sRight[3] + sRight[4] + sRight[5] + "\n";

   cube = cube + "                                 " + sLeft[6] + sLeft[7] + sLeft[8];
   cube = cube + " " + sFront[6] + sFront[7] + sFront[8];
   cube = cube + " " + sRight[6] + sRight[7] + sRight[8] + "\n\n";

   //bottom
   cube = cube + "                                     " + sBottom[0] + sBottom[1] + sBottom[2] + "\n";
   cube = cube + "                                     " + sBottom[3] + sBottom[4] + sBottom[5] + "\n";
   cube = cube + "                                     " + sBottom[6] + sBottom[7] + sBottom[8] + "\n\n";

   //back        (Show it flipped upside-down)
   cube = cube + "                                     " + sBack[6] + sBack[7] + sBack[8] + "\n";
   cube = cube + "                                     " + sBack[3] + sBack[4] + sBack[5] + "\n";
   cube = cube + "                                     " + sBack[0] + sBack[1] + sBack[2] + "\n\n";
//---------------------End of cube filling

   //Print with color
   for (int charIndex = 0; charIndex < cube.length(); charIndex++)
   {
      if (cube[charIndex] == 'R')
         {SetConsoleTextAttribute(color, 12);}
      else if (cube[charIndex] == 'B')
         {SetConsoleTextAttribute(color, 9);}
      else if (cube[charIndex] == 'W')
         {SetConsoleTextAttribute(color, 15);}
      else if (cube[charIndex] == 'Y')
         {SetConsoleTextAttribute(color, 14);}
      else if (cube[charIndex] == 'G')
         {SetConsoleTextAttribute(color, 10);}
      else if (cube[charIndex] == 'P')
         {SetConsoleTextAttribute(color, 13);}

      cout << cube[charIndex];
   }
   SetConsoleTextAttribute(color, 7);
}

//  | |---------------------------------------------| |
//  | |---------------------------------------------| |
//  | |      I have this guide written on a         | |
//  | |            notecard next to me              | |
//  | |                  _______                    | |
//  | |                  |0|1|2|                    | |
//  | |                  |3|#|5|                    | |
//  | |                  |6|7|8|                    | |
//  | |                  ```````                    | |
//  | |---------------------------------------------| |
//  | |---------------------------------------------| |

//                                                               Side note: The following
//                                                               function was more difficult
//                                                               and took more time than
//                                                               anything else in the program.

//Side rotation (Put the value [or color] of one single square into the index of another, repeat)
bool rotateSide(string chosenSide, string direction)
{
   //Temporary spots so the first squares moved don't get erased.
   char cornerSave, sideSave;
   char spotSave0, spotSave1, spotSave2;

   //Top (First choose side...)
   if (chosenSide == "t")
   {
      //Clockwise (...then direction.)
      if (direction == "c")
      {
         //First switch the squares on the face that is being rotated (Corner squares first...)
         cornerSave = sTop[0];
         sTop[0] = sTop[6];
         sTop[6] = sTop[8];
         sTop[8] = sTop[2];
         sTop[2] = cornerSave;

         //(...then sides.)
         sideSave = sTop[1];
         sTop[1] = sTop[3];
         sTop[3] = sTop[7];
         sTop[7] = sTop[5];
         sTop[5] = sideSave;

         //We then switch the squares of all other rows that are affected by the rotation.

         //(There are a few very tedious systems to follow while doing this, but I'm not going
         //to explain it. You'd understand if you were to refer to my code and the guide above
         //while screwing with an actual Rubik's Cube.)

         spotSave0 = sFront[0];
         spotSave1 = sFront[1];
         spotSave2 = sFront[2];
         sFront[0] = sRight[0];
         sFront[1] = sRight[1];
         sFront[2] = sRight[2];
         sRight[0] = sBack[2];
         sRight[1] = sBack[1];
         sRight[2] = sBack[0];
         sBack[2] = sLeft[0];
         sBack[1] = sLeft[1];
         sBack[0] = sLeft[2];
         sLeft[0] = spotSave0;
         sLeft[1] = spotSave1;
         sLeft[2] = spotSave2;
      }
      //Counterclockwise (now do the same stuff for the other direction)
      else if (direction == "cc")
      {
         cornerSave = sTop[0];
         sTop[0] = sTop[2];
         sTop[2] = sTop[8];
         sTop[8] = sTop[6];
         sTop[6] = cornerSave;

         sideSave = sTop[1];
         sTop[1] = sTop[5];
         sTop[5] = sTop[7];
         sTop[7] = sTop[3];
         sTop[3] = sideSave;

         spotSave0 = sFront[0];
         spotSave1 = sFront[1];
         spotSave2 = sFront[2];
         sFront[0] = sLeft[0];
         sFront[1] = sLeft[1];
         sFront[2] = sLeft[2];
         sLeft[0] = sBack[2];
         sLeft[1] = sBack[1];
         sLeft[2] = sBack[0];
         sBack[2] = sRight[0];
         sBack[1] = sRight[1];
         sBack[0] = sRight[2];
         sRight[0] = spotSave0;
         sRight[1] = spotSave1;
         sRight[2] = spotSave2;
      }
   }

   //Front (and repeat)
   else if (chosenSide == "f")
   {
      //Clockwise
      if (direction == "c")
      {
         cornerSave = sFront[0];
         sFront[0] = sFront[6];
         sFront[6] = sFront[8];
         sFront[8] = sFront[2];
         sFront[2] = cornerSave;

         sideSave = sFront[1];
         sFront[1] = sFront[3];
         sFront[3] = sFront[7];
         sFront[7] = sFront[5];
         sFront[5] = sideSave;

         spotSave0 = sBottom[0];
         spotSave1 = sBottom[1];
         spotSave2 = sBottom[2];
         sBottom[0] = sRight[6];
         sBottom[1] = sRight[3];
         sBottom[2] = sRight[0];
         sRight[6] = sTop[8];
         sRight[3] = sTop[7];
         sRight[0] = sTop[6];
         sTop[8] = sLeft[2];
         sTop[7] = sLeft[5];
         sTop[6] = sLeft[8];
         sLeft[2] = spotSave0;
         sLeft[5] = spotSave1;
         sLeft[8] = spotSave2;
      }
      //Counterclockwise
      else if (direction == "cc")
      {
         cornerSave = sFront[0];
         sFront[0] = sFront[2];
         sFront[2] = sFront[8];
         sFront[8] = sFront[6];
         sFront[6] = cornerSave;

         sideSave = sFront[1];
         sFront[1] = sFront[5];
         sFront[5] = sFront[7];
         sFront[7] = sFront[3];
         sFront[3] = sideSave;

         spotSave0 = sBottom[0];
         spotSave1 = sBottom[1];
         spotSave2 = sBottom[2];
         sBottom[0] = sLeft[2];
         sBottom[1] = sLeft[5];
         sBottom[2] = sLeft[8];
         sLeft[2] = sTop[8];
         sLeft[5] = sTop[7];
         sLeft[8] = sTop[6];
         sTop[8] = sRight[6];
         sTop[7] = sRight[3];
         sTop[6] = sRight[0];
         sRight[6] = spotSave0;
         sRight[3] = spotSave1;
         sRight[0] = spotSave2;
      }
   }

   //Bottom
   else if (chosenSide == "bo")
   {
      //Clockwise
      if (direction == "c")
      {
         cornerSave = sBottom[0];
         sBottom[0] = sBottom[6];
         sBottom[6] = sBottom[8];
         sBottom[8] = sBottom[2];
         sBottom[2] = cornerSave;

         sideSave = sBottom[1];
         sBottom[1] = sBottom[3];
         sBottom[3] = sBottom[7];
         sBottom[7] = sBottom[5];
         sBottom[5] = sideSave;

         spotSave0 = sFront[6];
         spotSave1 = sFront[7];
         spotSave2 = sFront[8];
         sFront[6] = sLeft[6];
         sFront[7] = sLeft[7];
         sFront[8] = sLeft[8];
         sLeft[6] = sBack[8];
         sLeft[7] = sBack[7];
         sLeft[8] = sBack[6];
         sBack[8] = sRight[6];
         sBack[7] = sRight[7];
         sBack[6] = sRight[8];
         sRight[6] = spotSave0;
         sRight[7] = spotSave1;
         sRight[8] = spotSave2;
      }
      //Counterclockwise
      else if (direction == "cc")
      {
         cornerSave = sBottom[0];
         sBottom[0] = sBottom[2];
         sBottom[2] = sBottom[8];
         sBottom[8] = sBottom[6];
         sBottom[6] = cornerSave;

         sideSave = sBottom[1];
         sBottom[1] = sBottom[5];
         sBottom[5] = sBottom[7];
         sBottom[7] = sBottom[3];
         sBottom[3] = sideSave;

         spotSave0 = sFront[6];
         spotSave1 = sFront[7];
         spotSave2 = sFront[8];
         sFront[6] = sRight[6];
         sFront[7] = sRight[7];
         sFront[8] = sRight[8];
         sRight[6] = sBack[8];
         sRight[7] = sBack[7];
         sRight[8] = sBack[6];
         sBack[8] = sLeft[6];
         sBack[7] = sLeft[7];
         sBack[6] = sLeft[8];
         sLeft[6] = spotSave0;
         sLeft[7] = spotSave1;
         sLeft[8] = spotSave2;
      }
   }

   //Left
   else if (chosenSide == "l")
   {
      //Clockwise
      if (direction == "c")
      {
         cornerSave = sLeft[0];
         sLeft[0] = sLeft[6];
         sLeft[6] = sLeft[8];
         sLeft[8] = sLeft[2];
         sLeft[2] = cornerSave;

         sideSave = sLeft[1];
         sLeft[1] = sLeft[3];
         sLeft[3] = sLeft[7];
         sLeft[7] = sLeft[5];
         sLeft[5] = sideSave;

         spotSave0 = sBack[6];
         spotSave1 = sBack[3];
         spotSave2 = sBack[0];
         sBack[6] = sBottom[0];
         sBack[3] = sBottom[3];
         sBack[0] = sBottom[6];
         sBottom[0] = sFront[0];
         sBottom[3] = sFront[3];
         sBottom[6] = sFront[6];
         sFront[0] = sTop[0];
         sFront[3] = sTop[3];
         sFront[6] = sTop[6];
         sTop[0] = spotSave0;
         sTop[3] = spotSave1;
         sTop[6] = spotSave2;
      }
      //Counterclockwise
      else if (direction == "cc")
      {
         cornerSave = sLeft[0];
         sLeft[0] = sLeft[2];
         sLeft[2] = sLeft[8];
         sLeft[8] = sLeft[6];
         sLeft[6] = cornerSave;

         sideSave = sLeft[1];
         sLeft[1] = sLeft[5];
         sLeft[5] = sLeft[7];
         sLeft[7] = sLeft[3];
         sLeft[3] = sideSave;

         spotSave0 = sBack[6];
         spotSave1 = sBack[3];
         spotSave2 = sBack[0];
         sBack[6] = sTop[0];
         sBack[3] = sTop[3];
         sBack[0] = sTop[6];
         sTop[0] = sFront[0];
         sTop[3] = sFront[3];
         sTop[6] = sFront[6];
         sFront[0] = sBottom[0];
         sFront[3] = sBottom[3];
         sFront[6] = sBottom[6];
         sBottom[0] = spotSave0;
         sBottom[3] = spotSave1;
         sBottom[6] = spotSave2;
      }
   }

   //Right
   else if (chosenSide == "r")
   {
      //Clockwise
      if (direction == "c")
      {
         cornerSave = sRight[0];
         sRight[0] = sRight[6];
         sRight[6] = sRight[8];
         sRight[8] = sRight[2];
         sRight[2] = cornerSave;

         sideSave = sRight[1];
         sRight[1] = sRight[3];
         sRight[3] = sRight[7];
         sRight[7] = sRight[5];
         sRight[5] = sideSave;

         spotSave0 = sBack[8];
         spotSave1 = sBack[5];
         spotSave2 = sBack[2];
         sBack[8] = sTop[2];
         sBack[5] = sTop[5];
         sBack[2] = sTop[8];
         sTop[2] = sFront[2];
         sTop[5] = sFront[5];
         sTop[8] = sFront[8];
         sFront[2] = sBottom[2];
         sFront[5] = sBottom[5];
         sFront[8] = sBottom[8];
         sBottom[2] = spotSave0;
         sBottom[5] = spotSave1;
         sBottom[8] = spotSave2;
      }
      //Counterclockwise
      else if (direction == "cc")
      {
         cornerSave = sRight[0];
         sRight[0] = sRight[2];
         sRight[2] = sRight[8];
         sRight[8] = sRight[6];
         sRight[6] = cornerSave;

         sideSave = sRight[1];
         sRight[1] = sRight[5];
         sRight[5] = sRight[7];
         sRight[7] = sRight[3];
         sRight[3] = sideSave;

         spotSave0 = sBack[8];
         spotSave1 = sBack[5];
         spotSave2 = sBack[2];
         sBack[8] = sBottom[2];
         sBack[5] = sBottom[5];
         sBack[2] = sBottom[8];
         sBottom[2] = sFront[2];
         sBottom[5] = sFront[5];
         sBottom[8] = sFront[8];
         sFront[2] = sTop[2];
         sFront[5] = sTop[5];
         sFront[8] = sTop[8];
         sTop[2] = spotSave0;
         sTop[5] = spotSave1;
         sTop[8] = spotSave2;
      }
   }

   //Back

   //(The worst part of the whole thing. To compensate for the cube being 2D, this side has
   //to be flipped upside-down)

   else if (chosenSide == "ba")
   {
      //Clockwise
      if (direction == "c")
      {
         cornerSave = sBack[0];
         sBack[0] = sBack[2];
         sBack[2] = sBack[8];
         sBack[8] = sBack[6];
         sBack[6] = cornerSave;

         sideSave = sBack[1];
         sBack[1] = sBack[5];
         sBack[5] = sBack[7];
         sBack[7] = sBack[3];
         sBack[3] = sideSave;

         spotSave0 = sBottom[6];
         spotSave1 = sBottom[7];
         spotSave2 = sBottom[8];
         sBottom[6] = sLeft[0];
         sBottom[7] = sLeft[3];
         sBottom[8] = sLeft[6];
         sLeft[0] = sTop[2];
         sLeft[3] = sTop[1];
         sLeft[6] = sTop[0];
         sTop[2] = sRight[8];
         sTop[1] = sRight[5];
         sTop[0] = sRight[2];
         sRight[8] = spotSave0;
         sRight[5] = spotSave1;
         sRight[2] = spotSave2;
      }
      //Counterclockwise
      else if (direction == "cc")
      {
         cornerSave = sBack[0];
         sBack[0] = sBack[6];
         sBack[6] = sBack[8];
         sBack[8] = sBack[2];
         sBack[2] = cornerSave;

         sideSave = sBack[1];
         sBack[1] = sBack[3];
         sBack[3] = sBack[7];
         sBack[7] = sBack[5];
         sBack[5] = sideSave;

         spotSave0 = sBottom[6];
         spotSave1 = sBottom[7];
         spotSave2 = sBottom[8];
         sBottom[6] = sRight[8];
         sBottom[7] = sRight[5];
         sBottom[8] = sRight[2];
         sRight[8] = sTop[2];
         sRight[5] = sTop[1];
         sRight[2] = sTop[0];
         sTop[2] = sLeft[0];
         sTop[1] = sLeft[3];
         sTop[0] = sLeft[6];
         sLeft[0] = spotSave0;
         sLeft[3] = spotSave1;
         sLeft[6] = spotSave2;
      }
   }
   return true;
}

//---------------Other commands (Other commands that may be put in "Imput command: ")

//Scramble the cube

//(turn a random side in a random direction) however many times the user wants.
//The cube will be redrawn after every rotation because it looks cool. Entering "100000000000" will
//last for over an hour. That's your fault for being a smartass.

bool scramble(string numTurns)
{
   //Do random turns any number of times
   int turns = atoi(numTurns.c_str());
   string chosenSide, direction;

   for (int remTurns = turns; remTurns > 0; remTurns--)
   {
      int randSide = rand() % 6;
      int randDirection = rand() % 2;

      //Pick a side
      if (randSide == 0)
      {
         chosenSide = "t";
      }
      else if (randSide == 1)
      {
         chosenSide = "f";
      }
      else if (randSide == 2)
      {
         chosenSide = "bo";
      }
      else if (randSide == 3)
      {
         chosenSide = "l";
      }
      else if (randSide == 4)
      {
         chosenSide = "r";
      }
      else if (randSide == 5)
      {
         chosenSide = "ba";
      }

      //Pick a direction
      if (randDirection == 0)
      {
         direction = "c";
      }
      else if (randDirection == 1)
      {
         direction = "cc";
      }

      rotateSide(chosenSide, direction);
      showCube();
   }

   return true;
}

//Exit the game or reset the cube
bool end(string type)
{
   //Exit (to the main menu)
   if (type == "exit")
   {
      system("CLS");
      return false;
   }

   //Reset (set the cube to default settings)
   else if (type == "reset")
   {
      for (int sqr = 0; sqr < 9; sqr++)
      {
         sTop[sqr] = 'R';
         sFront[sqr] = 'W';
         sBottom[sqr] = 'G';
         sLeft[sqr] = 'B';
         sRight[sqr] = 'Y';
         sBack[sqr] = 'P';
      }
      return true;
   }
}

//---------------------Algorithm-related Functions---------------------//
//      (Functions for entering algorithms. All used in algMain)

//Enter algorithms
bool algInput()
{
   HANDLE color;
   color = GetStdHandle(STD_OUTPUT_HANDLE);

   string param1, chosenSide, direction;

   SetConsoleTextAttribute(color, 7);
   showCube();
   SetConsoleTextAttribute(color, 11);

   cout << "       ((number/'-1'/'end') + (side + direction) *repeat) *repeat \n";
   //                    1               2        3
   cout << "Input: ";

   //I've never been as stuck on how to do this program as I am at this point.

   //The plan: Do  multiple rotations as many times as the user wants.
   //Repeat that^ until the user types 'end.' I've got some idea of how to do
   //some of it, but I'm going to have to perform all of the rotations one after another,
   //in between the ends of iterations or recursions or whatever. How the hell...
   //Update: Some of that^ is incorrect. Whatever. I have an idea.

   do
   {
      //Create vectors to store sides and directions in for the rotations we will do in a minute.
      //And a variable to allow me to easily change the vector length I will use for the loop.

      vector<string> tilDoneSides(1), tilDoneDirs(1);
      int vectLength;

      //Get first paramater. This could be a -1 (to loop until completed), a number (to loop
      //the specified amount of times), or end (to end).

      cin >> param1;

      //When the user wants to loop infinitely until the cube is solved
      while ((param1 == "-1") && (getStatus() != "**Complete**"))
      {
         //Gather all the sides and directions into the vectors, making the vectors the
         //appropriate size as more are collected, until something other than a side is detected
         //by the 'cin >> chosenSide;'
         do
         {
            cin >> chosenSide;

            if ((chosenSide == "t") || (chosenSide == "f") || (chosenSide == "r") ||
                (chosenSide == "l") || (chosenSide == "bo") || (chosenSide == "ba"))
            {
               cin >> direction;

               vectLength++;

               tilDoneSides.push_back(chosenSide);
               tilDoneDirs.push_back(direction);
            }
         }
         while ((chosenSide == "t") || (chosenSide == "f") || (chosenSide == "r") ||
                (chosenSide == "l") || (chosenSide == "bo") || (chosenSide == "ba"));

         //Until the cube is complete, loop through the side/direction vector, update the
         //chosen side and direction, then rotate the cube accordingly.
         while (getStatus() != "**Complete**")
         {
            showCube();
            for (int index = 0; index < tilDoneSides.size(); index++)
            {
               if (getStatus() != "**Complete**")
               {
                  chosenSide = tilDoneSides.at(index);
                  direction = tilDoneDirs.at(index);

                  rotateSide(chosenSide, direction);

                  SetConsoleTextAttribute(color, 7);
                  showCube();
                  SetConsoleTextAttribute(color, 11);
               }
            }
         }
         return true;
      }
      //Done with 'loop until complete'

      //If the user wants to loop through some commands a certain number of times.
      //(If param1 is not 'end' or '-1', it is a number.) Structure is similar to before.
      if ((param1 != "end") && (param1 != "-1") && (chosenSide != "end") && (getStatus() != "**Complete**"))
      {
         int algRuns = atoi(param1.c_str());

         //Gather all the sides and directions into the vectors, making the vectors the
         //appropriate size as more are collected, until something other than a side is detected
         //by the 'cin >> chosenSide;'
         do
         {
            cin >> chosenSide;

            if ((chosenSide == "t") || (chosenSide == "f") || (chosenSide == "r") ||
                (chosenSide == "l") || (chosenSide == "bo") || (chosenSide == "ba"))
            {
               cin >> direction;

               vectLength++;

               tilDoneSides.push_back(chosenSide);
               tilDoneDirs.push_back(direction);
            }
         }
         while ((chosenSide == "t") || (chosenSide == "f") || (chosenSide == "r") ||
                (chosenSide == "l") || (chosenSide == "bo") || (chosenSide == "ba"));

         //Until the cube is complete or done looping, loop through the side/direction vector,
         //update the chosen side and direction, then rotate the cube accordingly.
         for (int run = 0; run < algRuns; run ++)
         {
            if (getStatus() != "**Complete**")
            {
               showCube();
               for (int index = 0; index < tilDoneSides.size(); index++)
               {
                  if (getStatus() != "**Complete**")
                  {
                     chosenSide = tilDoneSides.at(index);
                     direction = tilDoneDirs.at(index);

                     rotateSide(chosenSide, direction);

                     SetConsoleTextAttribute(color, 7);
                     showCube();
                     SetConsoleTextAttribute(color, 11);
                  }
               }
            }
         }
         return true;
      }
   }
   while ((chosenSide != "end") && (param1 != "end"));

   return true;
}

//Show algorithm-input help text
bool algHelp()
{
   cout << title << "\n\n";
   cout << "Algorithms are used to solve the cube faster. You can do this by performing \ncommands "
        << "infinitely until the cube is solved, or by performing commands a \ncertain number of times"
        << ", automatically. To loop until the cube is solved, after you enter 'start', enter a '-1'"
        << ", followed by the commands you want to perform \n(t c ba cc bo c, etc), and then 'end' "
        << "to tell the program when you're done \nentering the algorithm. To loop a specific amount "
        << "of times, simply replace the \n'-1' with the number of times you want to loop. Type 'exit'"
        << " to leave the \nalgorithm enterer.\n\nType 'c' to continue: ";

   string cont = "";
   while (cont != "c")
   {cin >> cont;}

   return true;
}

//Algorithm Main
bool algMain()
{
   HANDLE color;
   color = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(color, 11);

   string param1;
   bool enterAlgs = true;

   do
   {
      SetConsoleTextAttribute(color, 7);
      showCube();
      SetConsoleTextAttribute(color, 11);

      cout << "                      'help,' 'exit,' or 'start': ";
      cin >> param1;

      if (param1 == "start")
      {
         system("CLS");
         enterAlgs = algInput();
      }
      else if (param1 == "help")
      {
         system("CLS");
         enterAlgs = algHelp();
      }
      else if (param1 == "exit")
      {
         system("CLS");
         SetConsoleTextAttribute(color, 7);
         return true;
      }
   }
   while (enterAlgs == true);

   return true;
}

//-------------------------End of Algorithm-related Functions-----------------//


//----------------------------------------------------------------------------//
//------------------------------------Main------------------------------------//
//----------------------------------------------------------------------------//
int main()
{
   string param1, param2;
   bool keepPlaying = true;

   //Ask to play, see the help text, or see the key text
   playHelpKeyControl();

   do
   {
      showCube();

      //Ask for a command
      cout << "                               Input command: ";
      cin >> param1;

      //If they enter the name of a side, take a direction then rotate and redraw the cube.
      if ((param1 == "t") || (param1 == "f") || (param1 == "r") ||
          (param1 == "l") || (param1 == "bo") || (param1 == "ba"))
      {
         cin >> param2;
         keepPlaying = rotateSide(param1, param2);
      }
      //If "scramble" is entered, take a number and scramble the cube that many times.
      else if (param1 == "scramble")
      {
         cin >> param2;
         keepPlaying = scramble(param2);
      }
      //If "exit" is entered, return to the Play/Help/Key menu. If "reset," restart the cube.
      else if ((param1 == "exit") || (param1 == "reset"))
      {
         keepPlaying = end(param1);
      }
      //If "alg" is entered, allow the user to enter algorithms to solve the cube faster.
      else if (param1 == "alg")
      {
         keepPlaying = algMain();
      }

      //Note: Making all of the functions used by Main booleans was my clever way of continuing
      //      the game after each was performed (except for End ---> Exit, which ends the game).
   }
   while (keepPlaying == true);
   main();

   return 0;
}
//Damn, that was a lot of work.
//The funny thing is that nobody is probably ever going to play this game.
