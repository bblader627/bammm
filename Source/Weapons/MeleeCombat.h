#ifndef MELEECOMBAT_H_
#define MELEECOMBAT_H_

#include "../Actors/Actor.h"

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
			bool fightHappening;
			bool inRange();
			void giveLoot();
			void victory();
			bool canFight();

		public:
			void setup(Actor* a1, Actor* a2);
			MeleeCombat();
			void useTurn();
			bool getFightHappening();
			Actor* getWinner();
			Actor* getLoser();
			~MeleeCombat();
	};

	MeleeCombat::MeleeCombat()
	{
		actor1 = NULL;
		actor2 = NULL;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
		fightHappening = false;
	}

	void MeleeCombat::setup(Actor* a1, Actor* a2)
	{
		if(a1 == NULL || a2 == NULL)
			return;

		actor1 = a1;
		actor2 = a2;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
		fightHappening = true;
	}

	bool MeleeCombat::getFightHappening()
	{
		return fightHappening;
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
		if (!(*(actor1->getLocation()) == *(actor2->getLocation())))
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
				if(attacker->getMeleeWeapon()->canAttack())
				{
					int damage = attacker->getMeleeWeapon()->attack();
					attacked->reduceHealth(damage);
					cout << attacker->getName() << " hit " << attacked->getName() << " for " << damage << " damage.";
				}
				else
				{
					cout << attacker->getName() << " can't attack yet!\n";
				}
			}
			else
			{
				cout << attacker->getName() << " missed " << attacked->getName() << ".";
			}

			cout << attacked->getName() << " has " << attacked->getHealth() << " hp left.\n";

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
		
		actor1 = NULL;
		actor2 = NULL;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
		fightHappening = false;
	}

	void MeleeCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}

}

#endif
