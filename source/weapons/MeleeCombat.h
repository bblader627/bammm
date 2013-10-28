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
			void giveLoot();
			void victory();

		public:
			MeleeCombat(Actor* a1, Actor* a2);
			bool canFight();
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

	void MeleeCombat::useTurn()
	{
		//Damage
		if (canFight() && actor1->getLocation() == actor2->getLocation())
		{
			if (playerTurn)
			{
				actor1->getMeleeWeapon()->attack(actor2);
			}
			else
			{
				actor1->getMeleeWeapon()->attack(actor2);
			}
		}
		//Change turns
		playerTurn = !playerTurn;

		//Check for end of fight
		if (actor1->getHealth() <= 0)
		{
			_winner = actor2;
			_loser = actor1;
			victory();
		}
		else if (actor2->getHealth() <= 0)
		{
			_winner = actor1;
			_loser = actor2;
			victory();
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
