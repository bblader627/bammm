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

	MeleeCombat::MeleeCombat()
	{
		_actor1 = NULL;
		_actor2 = NULL;
		_winner = NULL;
		_loser = NULL;
		_playerTurn = true;
		_fightHappening = false;
	}

	MeleeCombat::~MeleeCombat()
	{
	}

	void MeleeCombat::setup(Actor& actor1, Actor& actor2)
	{

		_actor1 = &actor1;
		_actor2 = &actor2;
		_winner = NULL;
		_loser = NULL;
		_playerTurn = true;
		_fightHappening = true;
	}

	void MeleeCombat::useTurn()
	{
		Actor* attacker;
		Actor* attacked;

		if (canFight())
		{
			if (_playerTurn)
			{
				attacker = _actor1;
				attacked = _actor2;
			}
			else
			{
				attacker = _actor2;
				attacked = _actor1;
			}

			//Check to see if hit or miss
			if (inRange())
			{
				if (attacker->getMeleeWeapon()->canAttack())
				{
					int damage = attacker->getMeleeWeapon()->attack();
					attacked->reduceHealth(damage);
					cout << attacker->getName() << " hit "
							<< attacked->getName() << " for " << damage
							<< " damage.";
				}
				else
				{
					cout << attacker->getName() << " can't attack yet!\n";
				}
			}
			else
			{
				cout << attacker->getName() << " missed " << attacked->getName()
						<< ".";
			}

			cout << attacked->getName() << " has " << attacked->getHealth()
					<< " hp left.\n";

			//Change turns
			_playerTurn = !_playerTurn;

			//Check for end of fight
			if (attacked->getHealth() <= 0)
			{
				_winner = attacker;
				_loser = attacked;
				victory();
			}
		}
	}

	bool MeleeCombat::fightHappening()
	{
		return _fightHappening;
	}

	Actor& MeleeCombat::getWinner()
	{
		return *(_winner);
	}

	Actor& MeleeCombat::getLoser()
	{
		return *(_loser);
	}

	void MeleeCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}

	void MeleeCombat::victory()
	{
		//Play victory sound
		giveLoot();
		cout << _winner->getName() << " has slain " << _loser->getName()
				<< ".\n";

		_actor1 = NULL;
		_actor2 = NULL;
		_winner = NULL;
		_loser = NULL;
		_playerTurn = true;
		_fightHappening = false;
	}

	bool MeleeCombat::inRange()
	{
		if (!(*(_actor1->getLocation()) == *(_actor2->getLocation())))
		{
			return false;
		}
		return true;
	}

	bool MeleeCombat::canFight()
	{
		if (_actor1->getHealth() <= 0 || _actor2->getHealth() <= 0)
		{
			return false;
		}

		return true;
	}
}

#endif
