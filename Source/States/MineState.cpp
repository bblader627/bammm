/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * MineState cpp file.
 *
 */

#include "MineState.h"

namespace bammm
{
	MineState::MineState(Actor& actor)
	{
		_actor = &actor;
	}
	MineState::MineState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	/*void MineState::setup(DynamicArray<string>* args)
	{
		_successChance = 30;
		_maximumGold = 100;
		_amountToMine = atoi(args->get(1).c_str());
		_oreType = args->get(2);
	}*/

	void MineState::setup()
	{
		_successChance = 30;
	}

	void MineState::setAmount(int amountToMine)
	{
		_amountToMine = amountToMine;
	}

	void MineState::setOre(Actor& ore)
	{
		_ore = &ore;
	}

	void MineState::breakdown()
	{
	}

	void MineState::tick(float deltaTime)
	{
		if (canMine())
		{
			if (_actor->getBAC() > .4)
			{
				cout << _actor->getName()
						<< " drunkenly swings the pickaxe, hits himself in the foot, and decides not to do that anymore."
						<< "\n";
				switchState("null"); //Ends this state;
			}
			else
			{
				string oreName = _ore->getName();
				if (_ore->getName() == "Gold")
				{
					_actor->setGold(_actor->getGold() + 1);
					_ore->setGold(_ore->getGold() - 1);
				}
				else if (_ore->getName() == "Iron")
				{
					_actor->setIron(_actor->getIron() + 1);
					_ore->setIron(_ore->getIron() - 1);
				}
				else if (_ore->getName() == "Coal")
				{
					_actor->setCoal(_actor->getCoal() + 1);
					_ore->setCoal(_ore->getCoal() - 1);
				}
				_actor->reduceStamina(1);

				cout << _actor->getName()
						<< " lifts his pickaxe, and swings it at the rock. " << "\n";
				cout << _actor->getName() 
						<< " successfully mines a piece of " << _ore->getName() << "\n";
				_amountToMine--;
			}
		}
		else
		{
			cout << _actor->getName() << " is finished mining!" << "\n";
			_amountToMine = 0;
			switchState("null");
		}
	}

	void MineState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string MineState::toString()
	{
		return "mine";
	}

	bool MineState::canMine()
	{
		int canMine = 0;
		
		if(_amountToMine > 0)
		{
			if(_ore->getGold() > 0)
			{
				canMine++;
			}
			
			if(_ore->getIron() > 0)
			{
				canMine++;
			}
			
			if(_ore->getCoal() > 0)
			{
				canMine++;
			}
		}

		return !!canMine;
	}
}
