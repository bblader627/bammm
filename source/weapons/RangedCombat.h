/*
 * RangedCombat.h
 *
 *  Created on: Oct 28, 2013
 *      Author: michael
 */

#ifndef RANGEDCOMBAT_H_
#define RANGEDCOMBAT_H_

#include "../resources/grid3d.h"

namespace bammm
{

	class RangedCombat
	{

		private:
			Actor* actor1;
			Actor* actor2;
			Actor* _winner;
			Actor* _loser;
			bool playerTurn;

			void giveLoot();
			void victory();
			bool hit();
			bool inRange();

		public:
			RangedCombat(Actor* a1, Actor* a2);
			bool canFight();
			void useTurn();
			Actor* getWinner();
			Actor* getLoser();
			Actor* getOpponent();
			~RangedCombat();
	};

	RangedCombat::RangedCombat(Actor* a1, Actor* a2)
	{
		actor1 = a1;
		actor2 = a2;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
	}

	bool RangedCombat::canFight()
	{
		if (actor1->getHealth() <= 0 || actor2->getHealth() <= 0)
		{
			return false;
		}

		return true;
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
		if (playerTurn)
		{
			if (actor2->getLocation()
					<= actor1->getLocation()
							+ actor1->getRangedWeapon()->getRange()
					&& actor2->getLocation()
							>= actor1->getRangedWeapon()->getRange())
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
			if (actor1->getLocation()
					<= actor2->getLocation()
							+ actor2->getRangedWeapon()->getRange()
					&& actor1->getLocation()
							>= actor2->getRangedWeapon()->getRange())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	void RangedCombat::useTurn()
	{
		if (canFight())
		{
			if (hit())
			{
				int damage;

				if (playerTurn)
				{
					damage = actor1->getRangedWeapon()->attack();
					actor2->reduceHealth(damage);
					cout << actor2->getName() << " has taken " << damage << " damage!" << endl;
				}
				else
				{
					damage = actor2->getRangedWeapon()->attack();
					actor1->reduceHealth(damage);
					cout << actor1->getName() << " has taken " << damage << " damage!" << endl;
				}
			}
		}

		playerTurn = !playerTurn;

		if (actor1->getHealth() <= 0)
		{
			_winner = actor2;
			_loser = actor1;
			cout << _loser->getName() << " has been slain!" << endl;
			victory();
		}
		else if (actor2->getHealth() <= 0)
		{
			_winner = actor1;
			_loser = actor2;
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

	void RangedCombat::victory()
	{
		//Play victory sound
		giveLoot();
		cout << _winner->getName() << " has slain " << _loser->getName()
				<< ".\n";
	}

	void RangedCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}

}

#endif /* RANGEDCOMBAT_H_ */
