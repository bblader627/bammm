/*
 * RangedCombat.h
 *
 *  Created on: Oct 28, 2013
 *      Author: michael
 */

#ifndef RANGEDCOMBAT_H_
#define RANGEDCOMBAT_H_

#include "../SceneManager/Grid3D.h"

namespace bammm
{

	class RangedCombat
	{

		private:
			Actor* actor1;
			Actor* actor2;
			Actor* _winner;
			Actor* _loser;
//			Grid3d<Actor> GRID;
			bool playerTurn;

			void giveLoot();
			void victory();
			bool hit();
			bool inRange();

		public:
			RangedCombat(Actor* a1, Actor* a2 /*,Grid3d<Actor> grid*/);
			bool canFight();
			void useTurn();
			Actor* getWinner();
			Actor* getLoser();
			Actor* getOpponent();
			~RangedCombat();
	};

	RangedCombat::RangedCombat(Actor* a1, Actor* a2/*, Grid3d<Actor> grid*/)
	{
		actor1 = a1;
		actor2 = a2;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
		//GRID = grid;
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

		int playerX, playerY, playerZ;
		int opponentX, opponentY, opponentZ;

		playerX = actor1->getX();
		playerY = actor1->getY();
		playerZ = 0;

		opponentX = actor2->getX();
		opponentY = actor2->getY();
		opponentZ = 0;

		if (playerTurn)
		{
			int weaponRange = actor1->getRangedWeapon()->getRange();

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
			int weaponRange = actor2->getRangedWeapon()->getRange();

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
					cout << actor2->getName() << " has taken " << damage
							<< " damage!" << endl;
				}
				else
				{
					damage = actor2->getRangedWeapon()->attack();
					actor1->reduceHealth(damage);
					cout << actor1->getName() << " has taken " << damage
							<< " damage!" << endl;
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
