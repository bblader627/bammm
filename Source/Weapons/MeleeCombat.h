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
 * MeleeCombat header file.
 *
 */

#ifndef MELEECOMBAT_H_
#define MELEECOMBAT_H_

#include "../Actors/Actor.h"
#include "../Resources/Constant.h"

namespace bammm
{
	class MeleeCombat
	{
		private:
			Actor* _actor1;
			Actor* _actor2;
			Actor* _winner;
			Actor* _loser;
			bool _playerTurn;
			bool _fightHappening;

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
			 inRange
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if enemy is in range, false otherwise
			 */
			bool inRange();

			/**
			 canFight
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if you can engage your opponent in combat, false otherwise
			 */
			//TODO: Why is this private here but public in RangedCombat? This is inconsistent
			bool canFight();

		public:
			MeleeCombat();
			~MeleeCombat();

			/**
			 setup
			 @Pre-Condition- Two Actor*, actor1 and actor2
			 @Post-Condition- The actors will be setup to engage in combat
			 */
			//TODO:Why does MeleeCombat use setup and RangedCombat use a constructor for the same purpose? This is inconsistent
			void setup(Actor& actor1, Actor& actor2);

			/**
			 useTurn
			 @Pre-Condition- No input
			 @Post-Condition- Executes a turn of combat
			 */
			void useTurn();

			/**
			 fightHappening
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if a fight is happening
			 */
			bool fightHappening();

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
	};
}

#endif
