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
 * LevelingSystem cpp file.
 *
 */

#include "LevelingSystem.h"

namespace bammm
{
	LevelingSystem::LevelingSystem()
	{

	}

	LevelingSystem::~LevelingSystem()
	{

	}

	Actor* LevelingSystem::levelUP(Actor* actor)
	{

		cout << "actor is leveling up" << endl;

		actor->setExperience(0);
		actor->setTotalExperienceThisLevel(
				actor->getTotalExperienceThisLevel() * 2);
		actor->setMaximumHealth(actor->getMaximumHealth() + 10);
		actor->setHealth(actor->getMaximumHealth());
		actor->setAttack(actor->getAttack() + 10);
		actor->setDefense(actor->getDefense() + 10);
		actor->setLevel(actor->getLevel() + 1);

		cout << "DING! " << actor->getName() << " has reached level "
				<< actor->getLevel() << "!" << endl;
		cout << "His powers have improved: " << actor->getHealth() << " "
				<< actor->getAttack() << " " << actor->getDefense() << endl;
		cout << actor->getTotalExperienceThisLevel()
				<< " more kills till next level." << endl;

		return actor;
	}

	Actor* LevelingSystem::gainExperience(Actor* actor)
	{
		cout << "in gainExperience" << endl;

		actor->setExperience(actor->getExperience() + 1);
		cout << "experience was set to " << actor->getExperience() << endl;

		cout << "total experience for this level is " << actor->getTotalExperienceThisLevel() << endl;

		if (actor->getExperience() == actor->getTotalExperienceThisLevel())
		{
			actor = levelUP(actor);
			return actor;
		}

		return actor;
	}
}
