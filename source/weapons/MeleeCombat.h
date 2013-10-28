#ifndef MELEECOMBAT_H_
#define MELEECOMBAT_H_

#include "../actors/actor.h"

namespace bammm
{
	class MeleeCombat
	{
		private:
			Actor* actor1;
			Actor* actor2;
			Actor* _winner;
			Actor* _loser;
			bool playerTurn;
			bool inRange();
			void giveLoot();
			void victory();
			bool canFight();

		public:
			MeleeCombat(Actor* a1, Actor* a2);
			void useTurn();
			Actor* getWinner();
			Actor* getLoser();
			~MeleeCombat();
	};

	MeleeCombat::MeleeCombat(Actor* a1, Actor* a2)
	{
		actor1 = a1;
		actor2 = a2;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
	}

	bool MeleeCombat::canFight()
	{
		if (actor1->getHealth() <= 0 || actor2->getHealth() <= 0)
		{
			return false;
		}

		return true;
	}

	bool MeleeCombat::inRange()
	{
		if (!(actor1->getLocation() == actor2->getLocation()))
		{
			return false;
		}
		return true;
	}

	void MeleeCombat::useTurn()
	{
		Actor* attacker;
		Actor* attacked;
		//Damage
		if(canFight())
		{
			if (playerTurn)
			{
				attacker = actor1;
				attacked = actor2;
			}
			else
			{
				attacker = actor2;
				attacked = actor1;
			}

			//Check to see if hit or miss
			if(inRange())
			{
				int damage = attacker->getWeapon()->attack();
				attacked->reduceHealth(damage);
				cout << attacker->getName() << " hit " << attacked->getName() << " for " << damage << " damage.";
			}
			else
			{
				cout << attacker->getName() << " missed " << attacked->getName() << ".";
			}

			//Change turns
			playerTurn = !playerTurn;

			//Check for end of fight
			if (attacked->getHealth() <= 0)
			{
				_winner = attacker;
				_loser = attacked;
				victory();
			}
		}
	}

	Actor* MeleeCombat::getWinner()
	{
		return _winner;
	}

	Actor* MeleeCombat::getLoser()
	{
		return _loser;
	}

	void MeleeCombat::victory()
	{
		//Play victory sound
		giveLoot();
		cout << _winner->getName() << " has slain " << _loser->getName()
				<< ".\n";
	}

	void MeleeCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}

}

#endif
