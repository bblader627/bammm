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
		_maximumGold = 15;
	}
	MineState::MineState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		_maximumGold = 15;
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
		_maximumGold = 100;
	}

	void MineState::setAmount(int amountToMine)
	{
		_amountToMine = amountToMine;
	}

	void MineState::setOreType(string oreType)
	{
		_oreType = oreType;
	}

	void MineState::breakdown()
	{
	}

	void MineState::tick(float deltaTime)
	{
		if (_actor->getGold() > _maximumGold || _amountToMine <= 0)
		{

			cout << _actor->getName() << " is finished mining!" << "\n";
			_amountToMine = 0;
			switchState("null");
			return;
		}

		if (_actor->getBAC() > 0.4)
		{
			cout << _actor->getName()
					<< " drunkenly swings the pickaxe, hits himself in the foot, and decides not to do that anymore."
					<< "\n";
			switchState("null"); //Ends this state;
			return;
		}

		_actor->reduceStamina(1);
		_actor->addGold(1);

		cout << _actor->getName()
				<< " lifts his pickaxe, and swings it at the rock. " << "\n";
		cout << _actor->getGold() << "\n";

	}

	void MineState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string MineState::toString()
	{
		return "mine";
	}
}
