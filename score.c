// ----------------------------------------------------------------------
// File: score.c
//
// Name: Al Shaffer & Marshall Liu 
//
// Description: This is the implementation of the SCORE module of the
//     YAHTZEE game. It keeps track of the score card, enters new
//     scores as requested, and displays the score as requested.
// ----------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "score.h"
#include "screen.h"

#define NUMBER_OF_ENTRIES 13  // Does not count the subtotals and totals


// **************************************************************************
// ****************************  DEFINED TYPES   ****************************
// **************************************************************************

// An entry in a scorecard
struct entry_t {
    unsigned int value;
    bool         used;
};


// **************************************************************************
// **************************** GLOBAL VARIABLES ****************************
// **************************************************************************

// The Scorecard
static struct entry_t Score[NUMBER_OF_ENTRIES+1]; // row 0 is not used

// The Entry Names in a scorecard
static char *Entry_names[] = {
    "******** NOT USED *********",
    "Aces     (total of all 1's)",   // Keep these col's all the same widths
    "Twos     (total of all 2's)",
    "Threes   (total of all 3's)",
    "Fours    (total of all 4's)",
    "Fives    (total of all 5's)",
    "Sixes    (total of all 6's)",
    "3 of a Kind  (add all dice)",
    "4 of a Kind  (add all dice)",
    "Full House   (score 25)    ",
    "Sm. Straight (score 30)    ",
    "Lg. Straight (score 40)    ",
    "YAHTZEE      (score 50)    ",
    "Chance       (add all dice)"
};

    int tot_score;
    int bonus = 0;
    int total_left;
    int total_right;
    int grand_total;

// **************************************************************************
// *************************** EXTERNAL FUNCTIONS ***************************
// **************************************************************************

// ---------------------------------------------------------------------
// Function
//     score_reset
// Inputs
//     none
// Outputs
//     none
// Description
//     Initializes all the scorecard entries to zero and unused.
// ---------------------------------------------------------------------
void score_reset(void)
{
   for(int i = 1; i < (NUMBER_OF_ENTRIES + 1); i++)
   {
        Score[i].value= 0;
        Score[i].used = false;
   }
}//end score_reset


// ---------------------------------------------------------------------
// Function
//     score_display
// Inputs
//     none
// Outputs
//     none
// Description
//     Displays the current scorecard using the entire screen.
// ---------------------------------------------------------------------
void score_display(void)
{  

    tot_score = Score[1].value + Score[2].value + Score[3].value + Score[4].value 
    + Score[5].value + Score[6].value;

    //account for bonus
    if (tot_score >= 63)
    {
        bonus = 35;
    }

    // total score of left side
    total_left = tot_score + bonus;

    //score of right section
    total_right = Score[7].value + Score[8].value + Score[9].value + Score[10].value 
    + Score[11].value + Score[12].value + Score[13].value;

    // grand total
    grand_total = total_left + total_right;

 //print initial line
    printf("           LEFT SECTION            YAHTZEE             RIGHT SECTION         \n\n");

    printf("%46i %49s %80i \n", 7, Entry_names[7], Score[7].value);
    printf(" %i %s %34i %47i %76s %80i \n", 1, Entry_names[1], Score[1].value, 8,  Entry_names[8], Score[8].value);
    printf(" %i %s %34i %47i %76s %80i \n", 2, Entry_names[2], Score[2].value, 9,  Entry_names[9], Score[9].value);
    printf(" %i %s %34i %47i %76s %80i \n", 3, Entry_names[3], Score[3].value, 10,  Entry_names[10], Score[10].value);
    printf(" %i %s %34i %47i %76s %80i \n", 4, Entry_names[4], Score[4].value, 11,  Entry_names[11], Score[11].value);
    printf(" %i %s %34i %47i %76s %80i \n", 5, Entry_names[5], Score[5].value, 12,  Entry_names[12], Score[12].value);
    printf(" %i %s %34i %47i %76s %80i \n", 6, Entry_names[6], Score[6].value, 13,  Entry_names[13], Score[13].value);  

/*    for (int i = 0; i < ( NUMBER_OF_ENTRIES + 1); i++){
        if ( Score[i].value == 0 )
        {
            printf ("  %i %s %34i %47i %76s %80i \n", i, Entry_names[i], Score[i].value, i+7,  Entry_names[i+7], Score[i+7].value);
            //printf (" %i ", i, "%s", Entry_names[i], "%34i", Score[i].value, "%47i", i+7, "%76s", Entry_names[i+7], "%80i\n", Score[i+7].value);
        }
        else{ //need to print with blanks in mind
            printf( "   %s %34i %76s %80i \n", Entry_names[i], Score[i].value, Entry_names[i+7], Score[i+7].value);
            //printf( "   %s", Entry_names[i], "%34i", Score[i].value, "%76s", Entry_names[i+7], "%80i\n", Score[i+7].value);
        }
    }*/
/*    printf("%0s", Entry_names[0], "%80s \n", Entry_names[7]);
   printf("%0s", Entry_names[1], "%4i", Score[1].value, "%80s ", Entry_names[8], "%80i \n ", Score[8].value);
    printf("%0s", Entry_names[2], "%4i", Score[2].value, "%80s \n", Entry_names[9]);
    printf("%0s", Entry_names[3], "%4i", Score[3].value, "%80s \n", Entry_names[10]);
    printf("%0s", Entry_names[4], "%4i", Score[4].value, "%80s \n", Entry_names[11]);
    printf("%0s", Entry_names[5], "%4i", Score[5].value, "%80s \n", Entry_names[12]);
    printf("%0s", Entry_names[6], "%4i", Score[6].value, "%80s \n", Entry_names[13]);
    printf("3  =======27===========30 ===/34          46,47   49====================76/4 ===\n") */

    printf("   =========================== ===             =========================== ===\n");
/*
    //score of left section
    tot_score = Score[1].value + Score[2].value + Score[3].value + Score[4].value 
    + Score[5].value + Score[6].value;

    //account for bonus
    if (tot_score >= 63)
    {
        bonus = 35;
    }

    // total score of left side
    total_left = tot_score + bonus;

    //score of right section
    total_right = Score[7].value + Score[8].value + Score[9].value + Score[10].value 
    + Score[11].value + Score[12].value + Score[13].value;

    // grand total
    grand_total = total_left + total_right;
*/
    printf("   TOTAL SCORE %34i %50s %80i \n" , tot_score, "TOTAL LEFT", total_left);
    printf("   BONUS %34i %50s %80i \n ", bonus, "TOTAL_RIGHT", total_right);
    printf("   TOTAL_LEFT %34i %50s %80i \n",total_left, "GRAND_TOTAL", grand_total );

}//end score_display


// ---------------------------------------------------------------------
// Function
//     score_display_final
// Inputs
//     none
// Outputs
//     none
// Description
//     Displays the final scorecard in a simple format.
// ---------------------------------------------------------------------
void score_display_final(void)
{   //prints upper section
    printf("UPPER SECTION\n");
    for (int i = 1;i<7;i++)
    {
        printf("   %s %34i", Entry_names[i], Score[i].value);
    }
    printf("   =========================== ===\n");

    printf("   TOTAL SCORE %34i", tot_score);
    printf("   BONUS %34i", bonus);
    printf("   TOTAL UPPER %34i", total_left);

    //prints lower section
    printf("LOWER SECTION \n");
    for (int i = 7; i < (NUMBER_OF_ENTRIES+ 1); i++)
    {
        printf("   %s %34i", Entry_names[i], Score[i].value);
    }
    printf("   =========================== ===\n");
    printf("   TOTAL UPPER %34i", total_left);
    printf("   TOTAL LOWER %34i", total_right);
    printf("   GRAND TOTAL %34i", grand_total);   
}//end score_display_final


// ---------------------------------------------------------------------
// Function
//     score_set
// Inputs
//     item
//         This is the line in the scorecard to put the score.
//     score
//         This is the score to be put on the selected line.
// Outputs
//     function result
// Description
//     This function updates the line on the scorecard with the given
//     score. The item must not already be used by a previous entry, or
//     the function returns a non-SUCCESS and no change to the card
//     happens. The given item must also exist, or the function returns
//     a non-SUCCESS and no change to the card happens. Otherwise, the
//     requested change occurs, and a SUCCESS is returned.
// ---------------------------------------------------------------------
int score_set(const int item, const int score)
{
    if ( item < 1 || item > 14)
    {
        return !SUCCESS;
    }
    if ( score < 0)
    {
        return !SUCCESS;
    }
    if (Score[item].used == true )
    {
        return !SUCCESS;
    }
    else
    {
        Score[item].value = score;
        Score[item].used = true;

        return SUCCESS;
    }
}//end score_set
