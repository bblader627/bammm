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
 * MeleeCombat cpp file.
 *
 */

#include "MeleeCombat.h"

namespace bammm
{
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
