//Viking Chest 3.0 - Dmitry Tsarapkine

#include <iostream>                     //A preprocessor directive
#include <Windows.h>                    //Allows use of Sleep()
using namespace std;                    //Makes definitions visible

string placeHolder;                     //Creates string
string rules;                           //Whether the user wants to select rules

string square[11][11];                  //Creates string 2d array for the purpose of the board's squares

string ux;                              //String for the user's input of coordinates
string uy;

int xBoard1;                            //Creates integers
int yBoard1;

int turn = 1;                           //Creates integer and sets value to 1

int wins1 = 0;                          //Amount of wins for player 1
int wins2 = 0;                          //Amount of wins for player 2
int defendCounter = 0;                  //Amount of defenders on the board
int winner = 0;                         //Which player is the winner

int directionInterval1;

string direction1;
string directionAmount1;

string type1;
string type2;

int player = 1;                         //Creates integer and sets value to 1

bool finished = 0;                      //Creates bool and sets value to 0
bool ended = 0;

void theRules()                         //The rules of the game
{
     cout << "\nTwo players may participate. One player plays the king's\n";                        //Outputs new line, text and new creates line
     cout << "side, with a king and his defenders, and the other player\n";
     cout << "plays the attackers. There are nine defenders and 16-\n";
     cout << "four attackers. Attackers go first and are player 1\n\n";
     
     Sleep(500);                                                                                   //Pauses for .5 seconds
     
     cout << "The game is played on a board with 9 by 9 squares and with the below\n";
     cout << "initial set-up.\n\n";
     
     Sleep(500);
     
     cout << "The central square, called the throne, and the four squares in the\n";
     cout << "corners are restricted and may only be occupied by the king. The king\n";
     cout << "is able to re-enter the throne, and all pieces may pass the throne when it\n";
     cout << "is empty. The four corner squares are hostile to all pieces, which means\n";
     cout << "that they can replace one of the two pieces taking part in a capture. The\n";
     cout << "throne is always hostile to the attackers, but only hostile to the\n";
     cout << "defenders when it is empty.\n\n";
     
     Sleep(500);
     
     cout << "The objective for the king's side is to move the king to any of the four\n";
     cout << "corner squares. In that case, the king has escaped and his side wins. \n";
     cout << "The attackers win if they can capture the king before he escapes \n\n";
          
     Sleep(500);     
          
     cout << "The attackers' side moves first, and the game then proceeds by\n";
     cout << "alternate moves. All pieces move any number of vacant squares along a \n";
     cout << "row or a column, like a rook in chess.\n\n";
           
     Sleep(500);      
           
     cout << "All pieces except the king are captured if they are sandwiched between \n";
     cout << "two enemy pieces, or between an enemy piece and a hostile square,\n";
     cout << "along a column or a row. The two enemy pieces should either be on the\n";
     cout << "square above and below or on the square to the left and to the right of\n";
     cout << "the attacked piece. A piece is only captured if the trap is closed by a\n";
     cout << "move of the opponent, and it is, therefore, allowed to move in between \n";
     cout << "two enemy pieces. A captured piece is removed from the board and\n";
     cout << "is no longer active in the play. The king may take part in captures.\n\n";
  
     Sleep(500);
  
     cout << "The king himself is captured when the attackers surround him in all four \n";
     cout << "cardinal points. When he is on a square next to the throne, the attackers \n";
     cout << "must occupy all surrounding squares in the four points of the compass \n";
     cout << "except the throne.\n\n";

     cout << "The king cannot be captured on the edge, UNLESS he is the only white \n";
     cout << "piece remaining on the board and is completely surrounded by black. \n\n";
     
     Sleep(500);
     
     cout << "Type something here when you are done reading: ";
     
    cin >>  placeHolder;                                                                //Allows user to type whatever they want to continue
     }
     
     void introduction()                                                                //The introduction                 
{
     system("cls");                                                                     //Clears screen
     cout << "HNEFATAFL - Dmitry Tsarapkine\n\n";                                       
     cout << "Pronounced: Nef-a-taff-ull\n\n";
     cout << "Would you like to hear the rules of the game?: ";
     
     cin >> rules;                                                                      //user inputs whether they want to read the rules
     
     
     if(rules != "y" && rules != "n" && rules != "yes" && rules != "no")                //If user doesn't type that, it calls function
     {
                 cout << "\nThat is an invalid choice! Please type yes or no!\n\n";
                 Sleep(800);
                 introduction();                                                        //Calls introduction function
                 }
                 
     if(rules == "y" || rules == "yes")
     {
              theRules();                                                               //Shows rules
              system("cls");
              rules = "n";                                                              //Sets rules to no
              }
     }
     
     ///////////////////Board Function
     void board()
{
    system("cls");                                                                     //Clears screen
    system("COLOR F0");

  cout << "     1     2     3     4     5     6     7     8     9\n";                  //Outputs top of board and new line               
  cout << "   _____________________________________________________       TURN " << turn << endl;
  
  for(int i = 9; i>= 1; i-- )                                                          //Loop starts at 9 and ends at 1
  {

  cout << "  |     |     |     |     |     |     |     |     |     | " << endl;   
  cout << i << " |  " << square[1][i] << "  |  " << square[2][i] << "  |  " << square[3][i]; //Outputs Each square value
  cout << "  |  " << square[4][i] << "  |  " << square[5][i] << "  |  " << square[6][i] ;
  cout << "  |  " << square[7][i] << "  |  " << square[8][i] << "  |  " << square[9][i] << "  | " << i;
  
  if(i == 9)
  cout << "  Player 1 - " << wins1 << " wins";                                         //Outputs player 1's win amount on desired part of screen
  
  if(i == 8)
  cout << "  Player 2 - " << wins2 << " wins";
  
  if(i == 6)
  cout << "  Player 1 = '#'";
  
  if(i == 5) 
  cout << "  Player 2 = 'O' & 'M'";
  
  
  cout << endl;                                                            
  cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|_____| " << endl;
     }
  cout << "\n     1     2     3     4     5     6     7     8     9\n\n";

}
///////////////////////////////Reset Board
void boardReset()																	   //Start location of each piece (beginning)
{
    for(int i = 1; i <= 9; i++)                                                        //This nested loop sets all the squares to spaces                           
   {
           for(int j = 1; j <= 9; j++)
           {
                   square[i][j] = " ";
                   }
                  
           } 
   
   for(int i = 0; i <= 10; i++)                                                        //Sets boundary that you cannot see so that you cannot escape board
   square[0][i] = "P";
   
   for(int i = 0; i <= 10; i++)
   square[10][i] = "P";
   
   for(int i = 0; i <= 10; i++)
   square[i][0] = "P";
   
   for(int i = 1; i <= 10; i++)
   square[i][10] = "P";
   
   square[1][1] = "X";                                                                //Sets these coordinates to be set to X
   square[1][9] = "X";
   square[9][1] = "X";
   square[9][9] = "X";
   
   square[3][5] = "O";                                                                //Sets the squares in these coordinates to be set to O's
   square[4][5] = "O";
   square[6][5] = "O";
   square[7][5] = "O";
   square[5][3] = "O";
   square[5][4] = "O";
   square[5][6] = "O";
   square[5][7] = "O";
   
   square[1][4] = "#";                                                                //Sets the squares in these coordinates to be set to #'s
   square[1][5] = "#";
   square[1][6] = "#";
   square[2][5] = "#";
   square[4][1] = "#";
   square[5][1] = "#";
   square[6][1] = "#";
   square[5][2] = "#";
   square[5][9] = "#";
   square[4][9] = "#";
   square[6][9] = "#";
   square[5][8] = "#";
   square[9][4] = "#";
   square[9][5] = "#";
   square[9][6] = "#";
   square[8][5] = "#";
   
   square[5][5] = "M";                                                                //Sets king's location
}
   //////////////////Player 1 x y input
   void xyPut()                                                                       //Creates function that allows the selection of a coordinate
   {
  
    cout << "P" << player << " - X-axis: ";
     cin >> ux;
     while(ux != "1" && ux != "2" && ux != "3" && ux != "4" && ux != "5" && ux != "6" && ux != "7" && ux != "8" && ux != "9")  //While the user does not type in
     {                                                                                                                         //a valid number/word, this happens
              cout << "Invalid choice (1-9 please)\n";                                                                         //Outputs text and new line
              cout << "P" << player << " - X-axis: ";                                                                          //Outputs text and variable
              cin >> ux;                                                                                                       //User types in these values again
              } 
       cout << "P" << player << "- Y-axis: ";
     cin >> uy;
     while(uy != "1" && uy != "2" && uy != "3" && uy != "4" && uy != "5" && uy != "6" && uy != "7" && uy != "8" && uy != "9")  
     {
              cout << "Invalid choice (1-9 please)\n";
              cout << "P1 - Y-axis: ";
              cin >> uy;
              }          
     
           
  if(ux == "1")													                      //The number the user types is then converted to an integer
  xBoard1 = 1; 																			
  
  else if(ux == "2")																  //If user types 2, xBoard1 is set to 2
  xBoard1 = 2; 
  
  else if(ux == "3")
  xBoard1 = 3;
  
  else if(ux == "4")
  xBoard1 = 4;
  
  else if(ux == "5")
  xBoard1 = 5;
  
  else if(ux == "6")
  xBoard1 = 6;
  
  else if(ux == "7")
  xBoard1 = 7;
  
  else if(ux == "8")
  xBoard1 = 8;
  
  else if(ux == "9")
  xBoard1 = 9;
  
  else
  {
      cout << "That is not a valid number!";
      xyPut();																		 //Calls function to start this process over again
      }
  ////////////y
    if(uy == "1")
  {yBoard1 = 1; 
  }
  
  else if(uy == "2")
  {yBoard1 = 2; 
  }
  
  else if(uy == "3")
  {yBoard1 = 3; 
 }
  
  else if(uy == "4")
  {yBoard1 = 4; 
 }
  
  else if(uy == "5")
  {yBoard1 = 5; 
  }
  
 else  if(uy == "6")
  {yBoard1 = 6;
  }
  
 else  if(uy == "7")
  {yBoard1 = 7;
  }
  
  else if(uy == "8")
  {yBoard1 = 8; 
  }
  
  else if(uy == "9")
  {yBoard1 = 9; 
 }
     else
     {
          cout << "That is not a valid number!";
      xyPut();
         }
        
        }
 
///////////////////Direction
void directionPlayer1()															                  //Function for choosing direction of piece
{
  cout << "Direction: ";
  cin >> direction1;																			  //User types in direction	
  
  while(direction1 != "u" && direction1 != "up" && direction1 != "d" && direction1 != "down" &&   //While their asnwer is not valid...
     direction1 != "l" && direction1 != "left" && direction1 != "r" && direction1 != "right"
     )
     {
               board(); 																		  //Clears screen and puts board
               cout << "INVALID DIRECTION!\n";													  //States that direction is invalid	
               cout << "Direction: ";
               cin >> direction1;																  //user sets value for direction again			
               }      
               
               
     /////////For the king
     
          if(direction1 == "up" && square[xBoard1][yBoard1 + 1] != " " && square[xBoard1][yBoard1] == "M" && square[xBoard1][yBoard1 + 1] != "X" 
           )                                                                                      //if the piece is a king and the direction is up  
     {																							  //and there is not one space/X/throne to move that way...
     board();																					  //The board is updated	
     cout << "INVALID DIRECTION!\n";															  //States that the direction is invalid
     directionPlayer1();														                  //Does function over again
     }
     
                
     if(direction1 == "u" && square[xBoard1][yBoard1 + 1] != " " && square[xBoard1][yBoard1] == "M"  && square[xBoard1][yBoard1 + 1] != "X"
       )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "down" && square[xBoard1][yBoard1 - 1] != " " && square[xBoard1][yBoard1] == "M"  && square[xBoard1][yBoard1 - 1] != "X"
        )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "d" && square[xBoard1][yBoard1 - 1] != " " && square[xBoard1][yBoard1] == "M"  && square[xBoard1][yBoard1 - 1] != "X"
         )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "left" && square[xBoard1 - 1][yBoard1] != " " && square[xBoard1][yBoard1] == "M" && square[xBoard1 - 1][yBoard1] != "X"
        )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "l" && square[xBoard1 - 1][yBoard1] != " " && square[xBoard1][yBoard1] == "M" && square[xBoard1 - 1][yBoard1] != "X"
         )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "right" && square[xBoard1 + 1][yBoard1] != " " && square[xBoard1][yBoard1] == "M" && square[xBoard1 + 1][yBoard1] != "X"
        )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "r" && square[xBoard1 + 1][yBoard1] != " " && square[xBoard1][yBoard1] == "M" && square[xBoard1 + 1][yBoard1] != "X"
         )
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
     ////////Not the king          
               
     if(direction1 == "up" && square[xBoard1][yBoard1 + 1] != " " && square[xBoard1][yBoard1] != "M")
     {                                                                                    //If the piece is not a king and there is no open space that way
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
                
     if(direction1 == "u" && square[xBoard1][yBoard1 + 1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "down" && square[xBoard1][yBoard1 - 1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "d" && square[xBoard1][yBoard1 - 1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "left" && square[xBoard1 - 1][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "l" && square[xBoard1 - 1][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
      if(direction1 == "right" && square[xBoard1 + 1][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
       if(direction1 == "r" && square[xBoard1 + 1][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
     {
     board();
     cout << "INVALID DIRECTION!\n";
     directionPlayer1();
     }
     
     }
     
     ////////////Landlock check1
     void player1Landlock()									                //Function that checks landlock
{
    
    if(square[xBoard1-1][yBoard1] != " " && square[xBoard1+1][yBoard1] != " " && 
  square[xBoard1][yBoard1-1] != " " && square[xBoard1][yBoard1+1] != " ") 
  {                                                                         //If there are no spaces around the piece then...
  
  system("cls");															//Screen is cleared
  board();																	//Calls board function
  cout << "That is a landlocked piece!\n";
  if(square[xBoard1][yBoard1] != type1 && square[xBoard1][yBoard1] != type2)//If the pieces are not the player's	
  cout << "Also, that place on the board is not something you can select!\n";
  Sleep(750);
 xyPut();														            //Player chooses coordinates
 player1Landlock();															//Same function is called again
           }
   else if(square[xBoard1][yBoard1] != type1 && square[xBoard1][yBoard1] != type2) //If the piece is not the player's
   {
        
          system("cls");
          board();
          cout << "That is not something you can select!\n";
          Sleep(750);
          board();																
          xyPut();
          player1Landlock();												
          
        }
  

     }
     ///////////////Direction Interval
     void directionValue1()												    //Function for direction amount			
     {
                      
   cout << "How many places would like to move that way?: ";				
   cin >> directionAmount1;													//User types how many spaces they want to move
  
   

    if(directionAmount1 == "1")												//Converts what the user types to an integer
    {
     directionInterval1 = 1;								
                         
                        }
    
    else if(directionAmount1 == "2")									    //If the user typed 2		
    {
     directionInterval1 = 2;  											    //This variable is set to 2			
        
                        }
    
    else if(directionAmount1 == "3")
      directionInterval1 = 3;
       
                        
    
    else if(directionAmount1 == "4")
      directionInterval1 = 4;
       
                        
    
    else if(directionAmount1 == "5")
      directionInterval1 = 5;
       
                        
    
    else if(directionAmount1 == "6")
       directionInterval1 = 6;
        
                        
                        
    else if(directionAmount1 == "7")
    {
       directionInterval1 = 7;
       
                        }
                         
    else if(directionAmount1 == "8")
    {
       directionInterval1 = 8;
       
                        }
                            
    else if(directionAmount1 == "9")
    {
       directionInterval1 = 9;
       
                        }
                        
     else                                                                                     //If none of these applied, it is not a valid number
     {
         cout << "That is not a valid number";
         Sleep(750);
         board();
         directionValue1();																	  //Same function is called again	
         }
         
     if(direction1 == "u" || direction1 == "up")											  				
     {
     for(int i = yBoard1 + 1; i <= (directionInterval1 + yBoard1); i++)
     {
             if(square[xBoard1][yBoard1] == "M" && square[xBoard1][i] != " "
             && square[xBoard1][yBoard1] == "M" && square[xBoard1][i] != "X")
             {
                                   cout << "That is not a valid number";
                                   Sleep(750);
                                   board();
                                   i = directionInterval1 + yBoard1;
                                   directionValue1();
                                         
                                         } 
             
             else if(square[xBoard1][i] != " " && square[xBoard1][yBoard1] != "M")
             {
                                   cout << "That is not a valid number";
                                   Sleep(750);
                                   board();
                                   i = directionInterval1 + yBoard1;
                                   directionValue1();
                                   
                                   } 
                                   }            
             }
             
             
       if(direction1 == "d" || direction1 == "down")
     {
     for(int i = yBoard1 - 1; i >= (yBoard1 - directionInterval1); i--)
     {
               if(square[xBoard1][yBoard1] == "M" && square[xBoard1][i] != " "
             && square[xBoard1][yBoard1] == "M" && square[xBoard1][i] != "X")
             {
                                   cout << "That is not a valid number";
                                   Sleep(750);
                                   board();
                                   i = directionInterval1 + yBoard1;
                                   directionValue1();
                                         
                                         } 
             
             else if(square[xBoard1][i] != " " && square[xBoard1][yBoard1] != "M")
             { 
                                    cout << "That is not a valid number";
                                    Sleep(750);
                                    board();
                                   i = yBoard1 - directionInterval1;
                                   directionValue1();
                                   
                                   } 
                                   }            
             }
     
     if(direction1 == "left" || direction1 == "l")
     {
     for(int i = xBoard1 - 1; i >= (xBoard1 - directionInterval1); i--)
     {
             if(square[xBoard1][yBoard1] == "M" && square[i][yBoard1] != " "
             && square[xBoard1][yBoard1] == "M" && square[i][yBoard1] != "X")
              {
                                    cout << "That is not a valid number";
                                    Sleep(750);
                                    board();
                                   i = xBoard1 - directionInterval1;
                                   directionValue1();
                                   
                                   } 
             
             else if(square[i][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
             {
                                    cout << "That is not a valid number";
                                    Sleep(750);
                                    board();
                                   i = xBoard1 - directionInterval1;
                                   directionValue1();
                                   
                                   } 
                                   }            
             }
             
       if(direction1 == "right" || direction1 == "r")
     {
     for(int i = xBoard1 + 1; i <= (directionInterval1 + xBoard1); i++)
     {
             
              if(square[xBoard1][yBoard1] == "M" && square[i][yBoard1] != " "
             && square[xBoard1][yBoard1] == "M" && square[i][yBoard1] != "X")
              {
                                    cout << "That is not a valid number";
                                    Sleep(750);
                                    board();
                                   i = xBoard1 - directionInterval1;
                                   directionValue1();
                                   
                                   } 
             
             else if(square[i][yBoard1] != " " && square[xBoard1][yBoard1] != "M")
             {
                                    cout << "That is not a valid number";
                                    Sleep(750);
                                    board();
                                   i = directionInterval1 + xBoard1;
                                   directionValue1();
                                   
                                   } 
                                   }            
             }
   
                      }
                      
   void player1Move()
   {
          
          if(direction1 == "d" && square[xBoard1][yBoard1] != "M" || direction1 == "down" && square[xBoard1][yBoard1] != "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1][yBoard1 - directionInterval1] = type1;
                        board();
                        }
          if(direction1 == "u" && square[xBoard1][yBoard1] != "M" || direction1 == "up" && square[xBoard1][yBoard1] != "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1][yBoard1 + directionInterval1] = type1;
                        }
        
           if(direction1 == "l" && square[xBoard1][yBoard1] != "M" || direction1 == "left" && square[xBoard1][yBoard1] != "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1 - directionInterval1][yBoard1] = type1;
                        board();
                        }
          if(direction1 == "r" && square[xBoard1][yBoard1] != "M" || direction1 == "right" && square[xBoard1][yBoard1] != "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1 + directionInterval1][yBoard1] = type1;
                        }
        
        /////////////////For the king
        
            if(direction1 == "d" && square[xBoard1][yBoard1] == "M"|| direction1 == "down" && square[xBoard1][yBoard1] == "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1][yBoard1 - directionInterval1] = "M";
                        board();
                        }
          if(direction1 == "u" && square[xBoard1][yBoard1] == "M"|| direction1 == "up" && square[xBoard1][yBoard1] == "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1][yBoard1 + directionInterval1] = "M";
                        }
        
           if(direction1 == "l" && square[xBoard1][yBoard1] == "M"|| direction1 == "left" && square[xBoard1][yBoard1] == "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1 - directionInterval1][yBoard1] = "M";
                        board();
                        }
          if(direction1 == "r" && square[xBoard1][yBoard1] == "M" || direction1 == "right" && square[xBoard1][yBoard1] == "M")
          {
                        square[xBoard1][yBoard1] = " ";
                        square[xBoard1 + directionInterval1][yBoard1] = "M";
                        }
        
        if(square[5][5] != "X" && square[5][5] != "M")
        square[5][5] = "X";
        
        
        }
        
   void capture()
   {
          //After a piece moves, it checks whether there is an enemy piece, up, down, left, right of the moved space and then checks if there is a 
          //friendly piece behind that enemy piece. If there is a friendly piece and an enemy piece in the same direction, the enemy peice is captured
          
          //Attacker's turn (#)
          
          /////////////////LEFT
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1 - 1][yBoard1] == "O"
          && square[xBoard1 - directionInterval1 - 2][yBoard1] == "#" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1 - 1][yBoard1] == "O" && square[xBoard1 - directionInterval1 - 2][yBoard1] == "#")
          square[xBoard1 - directionInterval1 - 1][yBoard1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1][yBoard1 - 1] == "O"
          && square[xBoard1 - directionInterval1][yBoard1 - 2] == "#" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1][yBoard1 - 1] == "O" && square[xBoard1 - directionInterval1][yBoard1 - 2] == "#")
          square[xBoard1 - directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1][yBoard1 + 1] == "O"
          && square[xBoard1 - directionInterval1][yBoard1 + 2] == "#" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1][yBoard1 + 1] == "O" && square[xBoard1 - directionInterval1][yBoard1 + 2] == "#")
          square[xBoard1 - directionInterval1][yBoard1 + 1] = " ";
          
          //////////////////RIGHT
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1 + 1][yBoard1] == "O"
          && square[xBoard1 + directionInterval1 + 2][yBoard1] == "#" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1 + 1][yBoard1] == "O" && square[xBoard1 + directionInterval1 + 2][yBoard1] == "#")
          square[xBoard1 + directionInterval1 + 1][yBoard1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1][yBoard1 - 1] == "O"
          && square[xBoard1 + directionInterval1][yBoard1 - 2] == "#" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 - 1] == "O" && square[xBoard1 + directionInterval1][yBoard1 - 2] == "#")
          square[xBoard1 + directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1][yBoard1 + 1] == "O"
          && square[xBoard1 + directionInterval1][yBoard1 + 2] == "#" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 + 1] == "O" && square[xBoard1 + directionInterval1][yBoard1 + 2] == "#")
          square[xBoard1 + directionInterval1][yBoard1 + 1] = " ";
          
          ///////////////////DOWN
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1][yBoard1 - directionInterval1 - 1] == "O"
          && square[xBoard1][yBoard1 - directionInterval1 - 2] == "#" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1][yBoard1 - directionInterval1 - 1] == "O" && square[xBoard1][yBoard1 - directionInterval1 - 2] == "#")
          square[xBoard1][yBoard1 - directionInterval1 - 1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1 - 1][yBoard1 - directionInterval1] == "O"
          && square[xBoard1 - 2][yBoard1 - directionInterval1] == "#" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1 - 1][yBoard1 - directionInterval1] == "O" && square[xBoard1 - 2][yBoard1 - directionInterval1] == "#")
          square[xBoard1 - 1][yBoard1 - directionInterval1] = " ";
          
          if(direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1 + 1][yBoard1 - directionInterval1] == "O"
          && square[xBoard1 + 2][yBoard1 - directionInterval1] == "#" ||direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1 + 1][yBoard1 - directionInterval1] == "O" && square[xBoard1 + 2][yBoard1 - directionInterval1] == "#")
          square[xBoard1 + 1][yBoard1 - directionInterval1] = " ";
          
          ///////////////////UP
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1 - 1][yBoard1 + directionInterval1] == "O"
          && square[xBoard1 - 2][yBoard1 + directionInterval1] == "#" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1 - 1][yBoard1 + directionInterval1] == "O" && square[xBoard1 - 2][yBoard1 + directionInterval1] == "#")
          square[xBoard1 - 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1 + 1][yBoard1 + directionInterval1] == "O"
          && square[xBoard1 + 2][yBoard1 + directionInterval1] == "#" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1 + 1][yBoard1 + directionInterval1] == "O" && square[xBoard1 + 2][yBoard1 + directionInterval1] == "#")
          square[xBoard1 + 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1][yBoard1 + directionInterval1 + 1] == "O"
          && square[xBoard1][yBoard1 + directionInterval1 + 2] == "#" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1][yBoard1 + directionInterval1 + 1] == "O" && square[xBoard1][yBoard1 + directionInterval1 + 2] == "#")
          square[xBoard1][yBoard1 + directionInterval1 + 1] = " ";

          //Defender's Turn (O)
          
          /////////////////LEFT
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1 - 1][yBoard1] == "#"
          && square[xBoard1 - directionInterval1 - 2][yBoard1] == "O" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1 - 1][yBoard1] == "#" && square[xBoard1 - directionInterval1 - 2][yBoard1] == "O")
          square[xBoard1 - directionInterval1 - 1][yBoard1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1][yBoard1 - 1] == "#"
          && square[xBoard1 - directionInterval1][yBoard1 - 2] == "O" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1][yBoard1 - 1] == "#" && square[xBoard1 - directionInterval1][yBoard1 - 2] == "O")
          square[xBoard1 - directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1][yBoard1 + 1] == "#"
          && square[xBoard1 - directionInterval1][yBoard1 + 2] == "O" ||direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1][yBoard1 + 1] == "#" && square[xBoard1 - directionInterval1][yBoard1 + 2] == "O")
          square[xBoard1 - directionInterval1][yBoard1 + 1] = " ";
          
          //////////////////RIGHT
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1 + 1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1 + 2][yBoard1] == "O" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1 + 1][yBoard1] == "#" && square[xBoard1 + directionInterval1 + 2][yBoard1] == "O")
          square[xBoard1 + directionInterval1 + 1][yBoard1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1][yBoard1 - 1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 - 2] == "O" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1][yBoard1 - 1] == "#" && square[xBoard1 + directionInterval1][yBoard1 - 2] == "O")
          square[xBoard1 + directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1][yBoard1 + 1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 + 2] == "O" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1][yBoard1 + 1] == "#" && square[xBoard1 + directionInterval1][yBoard1 + 2] == "O")
          square[xBoard1 + directionInterval1][yBoard1 + 1] = " ";
          
          ///////////////////DOWN
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1][yBoard1 - directionInterval1 - 1] == "#"
          && square[xBoard1][yBoard1 - directionInterval1 - 2] == "O" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1][yBoard1 - directionInterval1 - 1] == "#" && square[xBoard1][yBoard1 - directionInterval1 - 2] == "O")
          square[xBoard1][yBoard1 - directionInterval1 - 1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1 - 1][yBoard1 - directionInterval1] == "#"
          && square[xBoard1 - 2][yBoard1 - directionInterval1] == "O" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1 - 1][yBoard1 - directionInterval1] == "#" && square[xBoard1 - 2][yBoard1 - directionInterval1] == "O")
          square[xBoard1 - 1][yBoard1 - directionInterval1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1 + 1][yBoard1 - directionInterval1] == "#"
          && square[xBoard1 + 2][yBoard1 - directionInterval1] == "O" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1 + 1][yBoard1 - directionInterval1] == "#" && square[xBoard1 + 2][yBoard1 - directionInterval1] == "O")
          square[xBoard1 + 1][yBoard1 - directionInterval1] = " ";
          
          ///////////////////UP
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1 - 1][yBoard1 + directionInterval1] == "#"
          && square[xBoard1 - 2][yBoard1 + directionInterval1] == "O" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1 - 1][yBoard1 + directionInterval1] == "#" && square[xBoard1 - 2][yBoard1 + directionInterval1] == "O")
          square[xBoard1 - 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1  == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1 + 1][yBoard1 + directionInterval1] == "#"
          && square[xBoard1 + 2][yBoard1 + directionInterval1] == "O" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1 + 1][yBoard1 + directionInterval1] == "#" && square[xBoard1 + 2][yBoard1 + directionInterval1] == "O")
          square[xBoard1 + 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1][yBoard1 + directionInterval1 + 1] == "#"
          && square[xBoard1][yBoard1 + directionInterval1 + 2] == "O" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1][yBoard1 + directionInterval1 + 1] == "#" && square[xBoard1][yBoard1 + directionInterval1 + 2] == "O")
          square[xBoard1][yBoard1 + directionInterval1 + 1] = " ";
 
          /////////////////X's
          //////////////////
          
          /////////////////LEFT
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1 - 1][yBoard1] == "O"
          && square[xBoard1 - directionInterval1 - 2][yBoard1] == "X" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1 - 1][yBoard1] == "O" && square[xBoard1 - directionInterval1 - 2][yBoard1] == "X")
          square[xBoard1 - directionInterval1 - 1][yBoard1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1][yBoard1 - 1] == "O"
          && square[xBoard1 - directionInterval1][yBoard1 - 2] == "X" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1][yBoard1 - 1] == "O" && square[xBoard1 - directionInterval1][yBoard1 - 2] == "X")
          square[xBoard1 - directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "#" && square[xBoard1 - directionInterval1][yBoard1 + 1] == "O"
          && square[xBoard1 - directionInterval1][yBoard1 + 2] == "X" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "#" 
          && square[xBoard1 - directionInterval1][yBoard1 + 1] == "O" && square[xBoard1 - directionInterval1][yBoard1 + 2] == "X")
          square[xBoard1 - directionInterval1][yBoard1 + 1] = " ";
          
          //////////////////RIGHT
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1 + 1][yBoard1] == "O"
          && square[xBoard1 + directionInterval1 + 2][yBoard1] == "X" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1 + 1][yBoard1] == "O" && square[xBoard1 + directionInterval1 + 2][yBoard1] == "X")
          square[xBoard1 + directionInterval1 + 1][yBoard1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1][yBoard1 - 1] == "O"
          && square[xBoard1 + directionInterval1][yBoard1 - 2] == "X" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 - 1] == "O" && square[xBoard1 + directionInterval1][yBoard1 - 2] == "X")
          square[xBoard1 + directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "#" && square[xBoard1 + directionInterval1][yBoard1 + 1] == "O"
          && square[xBoard1 + directionInterval1][yBoard1 + 2] == "X" || direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 + 1] == "O" && square[xBoard1 + directionInterval1][yBoard1 + 2] == "X")
          square[xBoard1 + directionInterval1][yBoard1 + 1] = " ";
          
          ///////////////////DOWN
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1][yBoard1 - directionInterval1 - 1] == "O"
          && square[xBoard1][yBoard1 - directionInterval1 - 2] == "X" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1][yBoard1 - directionInterval1 - 1] == "O" && square[xBoard1][yBoard1 - directionInterval1 - 2] == "X")
          square[xBoard1][yBoard1 - directionInterval1 - 1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1 - 1][yBoard1 - directionInterval1] == "O"
          && square[xBoard1 - 2][yBoard1 - directionInterval1] == "X" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1 - 1][yBoard1 - directionInterval1] == "O" && square[xBoard1 - 2][yBoard1 - directionInterval1] == "X")
          square[xBoard1 - 1][yBoard1 - directionInterval1] = " ";
          
          if(direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "#" && square[xBoard1 + 1][yBoard1 - directionInterval1] == "O"
          && square[xBoard1 + 2][yBoard1 - directionInterval1] == "X" ||direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "#" 
          && square[xBoard1 + 1][yBoard1 - directionInterval1] == "O" && square[xBoard1 + 2][yBoard1 - directionInterval1] == "X")
          square[xBoard1 + 1][yBoard1 - directionInterval1] = " ";
          
          ///////////////////UP
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1 - 1][yBoard1 + directionInterval1] == "O"
          && square[xBoard1 - 2][yBoard1 + directionInterval1] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1 - 1][yBoard1 + directionInterval1] == "O" && square[xBoard1 - 2][yBoard1 + directionInterval1] == "X")
          square[xBoard1 - 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1 + 1][yBoard1 + directionInterval1] == "O"
          && square[xBoard1 + 2][yBoard1 + directionInterval1] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1 + 1][yBoard1 + directionInterval1] == "O" && square[xBoard1 + 2][yBoard1 + directionInterval1] == "X")
          square[xBoard1 + 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "#" && square[xBoard1][yBoard1 + directionInterval1 + 1] == "O"
          && square[xBoard1][yBoard1 + directionInterval1 + 2] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "#" 
          && square[xBoard1][yBoard1 + directionInterval1 + 1] == "O" && square[xBoard1][yBoard1 + directionInterval1 + 2] == "X")
          square[xBoard1][yBoard1 + directionInterval1 + 1] = " ";

          //Defender's Turn (O)
          
          /////////////////LEFT
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1 - 1][yBoard1] == "#"
          && square[xBoard1 - directionInterval1 - 2][yBoard1] == "X" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1 - 1][yBoard1] == "#" && square[xBoard1 - directionInterval1 - 2][yBoard1] == "X")
          square[xBoard1 - directionInterval1 - 1][yBoard1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1][yBoard1 - 1] == "#"
          && square[xBoard1 - directionInterval1][yBoard1 - 2] == "X" || direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1][yBoard1 - 1] == "#" && square[xBoard1 - directionInterval1][yBoard1 - 2] == "X")
          square[xBoard1 - directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "left" && square[xBoard1 - directionInterval1][yBoard1] == "O" && square[xBoard1 - directionInterval1][yBoard1 + 1] == "#"
          && square[xBoard1 - directionInterval1][yBoard1 + 2] == "X" ||direction1 == "l" && square[xBoard1 - directionInterval1][yBoard1] == "O" 
          && square[xBoard1 - directionInterval1][yBoard1 + 1] == "#" && square[xBoard1 - directionInterval1][yBoard1 + 2] == "X")
          square[xBoard1 - directionInterval1][yBoard1 + 1] = " ";
          
          //////////////////RIGHT
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1 + 1][yBoard1] == "#"
          && square[xBoard1 + directionInterval1 + 2][yBoard1] == "X" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1 + 1][yBoard1] == "#" && square[xBoard1 + directionInterval1 + 2][yBoard1] == "X")
          square[xBoard1 + directionInterval1 + 1][yBoard1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1][yBoard1 - 1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 - 2] == "X" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1][yBoard1 - 1] == "#" && square[xBoard1 + directionInterval1][yBoard1 - 2] == "X")
          square[xBoard1 + directionInterval1][yBoard1 - 1] = " ";
          
          if(direction1 == "right" && square[xBoard1 + directionInterval1][yBoard1] == "O" && square[xBoard1 + directionInterval1][yBoard1 + 1] == "#"
          && square[xBoard1 + directionInterval1][yBoard1 + 2] == "X" ||direction1 == "r" && square[xBoard1 + directionInterval1][yBoard1] == "O" 
          && square[xBoard1 + directionInterval1][yBoard1 + 1] == "#" && square[xBoard1 + directionInterval1][yBoard1 + 2] == "X")
          square[xBoard1 + directionInterval1][yBoard1 + 1] = " ";
          
          ///////////////////DOWN
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1][yBoard1 - directionInterval1 - 1] == "#"
          && square[xBoard1][yBoard1 - directionInterval1 - 2] == "X" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1][yBoard1 - directionInterval1 - 1] == "#" && square[xBoard1][yBoard1 - directionInterval1 - 2] == "X")
          square[xBoard1][yBoard1 - directionInterval1 - 1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1 - 1][yBoard1 - directionInterval1] == "#"
          && square[xBoard1 - 2][yBoard1 - directionInterval1] == "X" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1 - 1][yBoard1 - directionInterval1] == "#" && square[xBoard1 - 2][yBoard1 - directionInterval1] == "X")
          square[xBoard1 - 1][yBoard1 - directionInterval1] = " ";
          
          if(direction1 == "down" && square[xBoard1][yBoard1 - directionInterval1] == "O" && square[xBoard1 + 1][yBoard1 - directionInterval1] == "#"
          && square[xBoard1 + 2][yBoard1 - directionInterval1] == "X" ||direction1 == "d" && square[xBoard1][yBoard1 - directionInterval1] == "O" 
          && square[xBoard1 + 1][yBoard1 - directionInterval1] == "#" && square[xBoard1 + 2][yBoard1 - directionInterval1] == "X")
          square[xBoard1 + 1][yBoard1 - directionInterval1] = " ";
          
          ///////////////////UP
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1 - 1][yBoard1 + directionInterval1] == "#"
          && square[xBoard1 - 2][yBoard1 + directionInterval1] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1 - 1][yBoard1 + directionInterval1] == "#" && square[xBoard1 - 2][yBoard1 + directionInterval1] == "X")
          square[xBoard1 - 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1  == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1 + 1][yBoard1 + directionInterval1] == "#"
          && square[xBoard1 + 2][yBoard1 + directionInterval1] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1 + 1][yBoard1 + directionInterval1] == "#" && square[xBoard1 + 2][yBoard1 + directionInterval1] == "X")
          square[xBoard1 + 1][yBoard1 + directionInterval1] = " ";
          
          if(direction1 == "up" && square[xBoard1][yBoard1 + directionInterval1] == "O" && square[xBoard1][yBoard1 + directionInterval1 + 1] == "#"
          && square[xBoard1][yBoard1 + directionInterval1 + 2] == "X" || direction1 == "u" && square[xBoard1][yBoard1 + directionInterval1] == "O" 
          && square[xBoard1][yBoard1 + directionInterval1 + 1] == "#" && square[xBoard1][yBoard1 + directionInterval1 + 2] == "X")
          square[xBoard1][yBoard1 + directionInterval1 + 1] = " ";
              
        
          board();                
                 }
        
        void checkWin()
        {
        
        if(square[9][1] == "M")
        {
        winner = 2;
        wins2 = wins2 + 1;
        finished = 1; 
        }
        if(square[9][9] == "M")
        {
        winner = 2;
        wins2 = wins2 + 1;
        finished = 1; 
        }
        
        if(square[1][1] == "M")
        {
        winner = 2;
        wins2 = wins2 + 1;
        finished = 1; 
        }
        
        if(square[1][9] == "M")
        {
        winner = 2;
        wins2 = wins2 + 1;
        finished = 1; 
        }    
        
        //////////King's capture
        
        for(int i = 1; i <= 9; i ++)
        {
                
                for(int j = 1; j <= 9; j++)
                {
                        if(square[j][i] == "M" && square[j - 1][i] == "#" && square[j + 1][i] == "#" && square[j][i + 1] == "#" && square[j][i - 1] == "#")
                        {
                                        winner = 1;
                                        wins1 = wins1 + 1;
                                        finished = 1; 
                                        }
                                        
                        if(square[j][i] == "M" && square[j - 1][i] == "X" && square[j + 1][i] == "#" && square[j][i + 1] == "#" && square[j][i - 1] == "#")
                        {
                                        winner = 1;
                                        wins1 = wins1 + 1;
                                        finished = 1; 
                                        }
                                        
                        if(square[j][i] == "M" && square[j - 1][i] == "#" && square[j + 1][i] == "X" && square[j][i + 1] == "#" && square[j][i - 1] == "#")
                        {
                                        winner = 1;
                                        wins1 = wins1 + 1;
                                        finished = 1; 
                                        }
                        
                        if(square[j][i] == "M" && square[j - 1][i] == "#" && square[j + 1][i] == "#" && square[j][i + 1] == "X" && square[j][i - 1] == "#")
                        {
                                        winner = 1;
                                        wins1 = wins1 + 1;
                                        finished = 1; 
                                        }
                        
                        if(square[j][i] == "M" && square[j - 1][i] == "X" && square[j + 1][i] == "#" && square[j][i + 1] == "#" && square[j][i - 1] == "X")
                        {
                                        winner = 1;
                                        wins1 = wins1 + 1;
                                        finished = 1; 
                                        }
                                        
                        if(square[j][i] == "O")
                        {
                                        defendCounter = defendCounter + 1;
                                        }                        
                                        
                        if(defendCounter == 0 && j == 9 && i == 9)
                        {
                                         for(int i = 1; i <= 9; i ++)
                                         {
                                                 if(square[j][i] == "M" && square[j + 1][i] == "P" && square[j - 1][i] == "#"
                                                 && square[j][i - 1] == "#" && square[j][i + 1] == "#" ||
                                                    square[j][i] == "M" && square[j + 1][i] == "#" && square[j - 1][i] == "P"
                                                 && square[j][i - 1] == "#" && square[j][i + 1] == "#" ||
                                                    square[j][i] == "M" && square[j + 1][i] == "#" && square[j - 1][i] == "#"
                                                 && square[j][i - 1] == "P" && square[j][i + 1] == "#" ||
                                                    square[j][i] == "M" && square[j + 1][i] == "#" && square[j - 1][i] == "#"
                                                 && square[j][i - 1] == "#" && square[j][i + 1] == "P"
                                                 )
                                                 {
                                                                winner = 1;
                                                                wins1 = wins1 + 1;
                                                                finished = 1;
                                                                } 
                                                 
                                                 
                                                 
                                                 }
                                         
                                         }
                        }
                }
             
           
             
             }

     
        

     int main()
     {
         system("COLOR F0");										//Sets background to white and text to black
         introduction();											//Calls introduction function
         boardReset();												//Resets board
         board();													//Updates board
         while(ended == 0)											//While the user has not decided to exit
         {
         while(finished == 0)										//While the game is not finished
         {
                       
                        if(finished != 1)							//If the game is not finished
                      { //player 1
                        type1 = "#";							    //Sets the type of piece to #
                        type2 = "#";								//Sets secondary type of piece to #
                        defendCounter = 0;
                        player = 1;									//Sets player #
                        board();									//Updates board	
                        xyPut();									//User can choose piece
                        player1Landlock();							//Checks if the piece is landlocked
                        directionPlayer1();							//player can choose direction
                        directionValue1();							//Distance the player wants to move
                        player1Move();							    //Moves piecies
                        capture();									//Captures pieces that are needed to be captured 
                        
                        checkWin();									//Checks if anything resulting in a win for either player occurs
                         
                        turn = turn + 1;							//Adds one to the turn
                        }
                        if(finished != 1)												
                      { //player 2									//Same thing except for player 2
                        type1 = "O";
                        type2 = "M";
                        defendCounter = 0;
                        player = 2;
                        board();
                        xyPut();
                        player1Landlock();
                        directionPlayer1();
                        directionValue1();
                        player1Move();
                        capture();
                        
                        checkWin();
                        
                        turn = turn + 1;
                        }
                        }
                        
                        Sleep(1000);								//Delay for 1 second
                        
                        system("cls");								//Clears screen
                        
                        cout << "Player " << winner << " is the winner!\n";                                             //States winner
                        
                        do{																								//Does this...	
                        cout << "Would you like to play again?: ";														//Outputs text	
                        cin >> placeHolder;																				//User can type their choice
                        }
                        while(placeHolder != "yes" && placeHolder != "y" && placeHolder != "n" && placeHolder != "no");	//While their answer is not valid
                        
                        if(placeHolder == "y" || placeHolder == "yes")													//If the user chooses yes		
                        {
                                       cout << "Let's play again!";														
                                       Sleep(1000);
                                       turn = 1;
                                       finished = 0;																	//The game is no longer finished
                                       boardReset();														            //resets board
                                       board(); 																		//Updates board
                                       }
                        else																							//Otherwise...
                        {
                            cout << "Goodbye!";																			
                            Sleep(1000);
                            ended = 1;																				    //Loop ends and so does the game		
                            }
                        
                        }
         
         system("pause");                                       //Pauses system for user to see the screen
         return 0;												//Terminates function
         
         }
     
     
