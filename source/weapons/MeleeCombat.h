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
			~MeleeCombat();
	};

	MeleeCombat::MeleeCombat(Actor* a1, Actor* at2)
	{
		actor1 = a1;
		actor2 = a2;
		_winner = NULL;
		_loser = NULL;
		playerTurn = true;
	}

	bool MeleeCombat::canFight()
	{
		if(a1->getHealth() <= 0 || a2->getHealth() <= 0)
		{
			return false;
		}

		return true;
	}

	void MeleeCombat::useTurn()
	{
		//Damage
		if(playerTurn)
		{
			actor1->getWeapon()->doDamage(actor2);
		}
		else
		{
			actor2->getWeapon()->doDamage(actor1);
		}

		//Change turns
		playerTurn = !playerTurn;

		//Check for end of fight
		if(actor1->getHealth() <= 0)
		{
			_winner = actor2;
			_loser = actor1;
			victory();
		}
		else if(actor2->getHealth() <= 0)
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
		cout << actor1->getName() << " has slain " << actor2->getName() << ".\n";
	}

	void MeleeCombat::giveLoot()
	{
		_winner->addGold(_loser->getGold());
		_loser->spendGold(_loser->getGold());
	}


}

#endif
