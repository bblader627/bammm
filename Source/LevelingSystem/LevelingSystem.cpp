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

	static Actor* LevelingSystem::levelUP(Actor* actor)
	{
		actor->setExperience = 0;
		actor->setTotalExperienceThisLevel(
				actor->getTotalExperienceThisLevel() * 2);

		actor->_stats->_maximumHealth += 10;
		actor->_stats->_health = actor->_stats->_maximumHealth;
		actor->_stats->_attack += 10;
		actor->_stats->_defense += 10;
		actor->_stats->_level++;

		cout
				<< "DING! " + actor->_stats->_name + " has reached level "
						+ actor->_stats->_level + "!" << endl;
		cout
				<< "His powers have improved: " + actor->_stats->_health + " "
						+ actor->_stats->_attack + " " + actor->_stats->_defense
				<< endl;
		cout
				<< actor->_stats->_totalExperienceThisLevel
						+ " more kills till next level." << endl;

		return actor;
	}

	static Actor* LevelingSystem::gainExperience(Actor* actor)
	{
		actor->_stats->_experience++;

		if (actor->_stats->_experience
				== actor->_stats->_totalExperienceThisLevel)
		{
			actor = levelUP(actor);
			return actor;
		}

		return actor;
	}
}
