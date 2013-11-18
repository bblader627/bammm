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
			RangedCombat(Actor* actor1, Actor* actor2 /*,Grid3d<Actor> grid*/);
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
			Actor* getWinner();

			/**
			 getLoser
			 @Pre-Condition- No input
			 @Post-Condition- Returns the loser of the fight
			 */
			Actor* getLoser();

			/**
			 getOpponent
			 @Pre-Condition- No input
			 @Post-Condition- Returns the opponent being fought
			 */
			//TODO: This function is not implemented right now
			Actor* getOpponent();
	};

	RangedCombat::RangedCombat()
	{
		_actor1 = NULL;
		_actor2 = NULL;
		_winner = NULL;
		_loser = NULL;
		_playerTurn = true;
	}

	RangedCombat::RangedCombat(Actor* actor1, Actor* actor2/*, Grid3d<Actor> grid*/)
	{
		_actor1 = actor1;
		_actor2 = actor2;
		_winner = NULL;
		_loser = NULL;
		_playerTurn = true;
	}

	RangedCombat::~RangedCombat()
	{
	}

	bool RangedCombat::canFight()
	{
		if (_actor1->getHealth() <= 0 || _actor2->getHealth() <= 0)
		{
			return false;
		}

		return true;
	}

	void RangedCombat::useTurn()
	{
		if (canFight())
		{
			if (hit())
			{
				int damage;

				if (_playerTurn)
				{
					damage = _actor1->getRangedWeapon()->attack();
					_actor2->reduceHealth(damage);
					cout << _actor2->getName() << " has taken " << damage
							<< " damage!" << endl;
				}
				else
				{
					damage = _actor2->getRangedWeapon()->attack();
					_actor1->reduceHealth(damage);
					cout << _actor1->getName() << " has taken " << damage
							<< " damage!" << endl;
				}
			}
		}

		_playerTurn = !_playerTurn;

		if (_actor1->getHealth() <= 0)
		{
			_winner = _actor2;
			_loser = _actor1;
			cout << _loser->getName() << " has been slain!" << endl;
			victory();
		}
		else if (_actor2->getHealth() <= 0)
		{
			_winner = _actor1;
			_loser = _actor2;
			cout << _winner->getName() << " has been slain!" << endl;
			victory();
		}
	}

	Actor* RangedCombat::getWinner()
	{
		return _winner;
	}

	Actor* RangedCombat::getLoser()
	{
		return _loser;
	}

	void RangedCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}

	void RangedCombat::victory()
	{
		//Play victory sound
		giveLoot();
		cout << _winner->getName() << " has slain " << _loser->getName()
				<< ".\n";
	}

	bool RangedCombat::hit()
	{
		if (inRange())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool RangedCombat::inRange()
	{

		int playerX, playerY, playerZ;
		int opponentX, opponentY, opponentZ;

		playerX = _actor1->getX();
		playerY = _actor1->getY();
		playerZ = 0;

		opponentX = _actor2->getX();
		opponentY = _actor2->getY();
		opponentZ = 0;

		if (_playerTurn)
		{
			int weaponRange = _actor1->getRangedWeapon()->getRange();

			if (opponentX <= playerX + weaponRange
					&& opponentX >= playerX - weaponRange
					&& opponentY <= playerY + weaponRange
					&& opponentY >= playerY - weaponRange
					&& opponentZ == playerZ)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			int weaponRange = _actor2->getRangedWeapon()->getRange();

			if (playerX <= opponentX + weaponRange
					&& playerX >= opponentX - weaponRange
					&& playerY <= opponentY + weaponRange
					&& playerY >= opponentY - weaponRange
					&& opponentZ == playerZ)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

#endif
