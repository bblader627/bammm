/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * RangedCombat header file.
 *
 */

#ifndef RANGEDCOMBAT_H_
#define RANGEDCOMBAT_H_

namespace bammm
{
	class RangedCombat
	{
		private:
			Actor* _actor1;
			Actor* _actor2;
			Actor* _winner;
			Actor* _loser;
			bool _playerTurn;

			/**
			 giveLoot
			 @Pre-Condition- No input
			 @Post-Condition- Defeated enemy is looted
			 */
			void giveLoot();

			/**
			 victory
			 @Pre-Condition- No input
			 @Post-Condition- Victory declared and giveLoot called
			 */
			void victory();

			/**
			 hit
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if enemy is hit, false otherwise
			 */
			bool hit();

			/**
			 inRange
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if enemy is in range, false otherwise
			 */
			bool inRange();

		public:
			RangedCombat();
			RangedCombat(Actor& actor1, Actor& actor2 /*,Grid3d<Actor> grid*/);
			~RangedCombat();

			/**
			 canFight
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if you can engage your opponent in combat, false otherwise
			 */
			bool canFight();

			/**
			 useTurn
			 @Pre-Condition- No input
			 @Post-Condition- Executes a turn of combat
			 */
			void useTurn();

			/**
			 getWinner
			 @Pre-Condition- No input
			 @Post-Condition- Returns the winner of the fight
			 */
			Actor& getWinner();

			/**
			 getLoser
			 @Pre-Condition- No input
			 @Post-Condition- Returns the loser of the fight
			 */
			Actor& getLoser();

			//TODO: This function is not implemented right now
			/**
			 getOpponent
			 @Pre-Condition- No input
			 @Post-Condition- Returns the opponent being fought
			 */
			Actor* getOpponent();
	};
}

#endif
