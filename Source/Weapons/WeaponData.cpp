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
 * WeaponData cpp file.
 *
 */

#include "WeaponData.h"

namespace bammm
{
	WeaponData::WeaponData()
	{
	}

	WeaponData::WeaponData(int damage, uint fireRate, string model, string type)
	{
		_range = 0;
		_damage = damage;
		_fireRate = fireRate;
		_model = model;
		_type = type;
	}

	WeaponData::WeaponData(int range, int clipCapacity, int damage,
			float reloadSpeed, uint fireRate, string model, string type)
	{
		_range = range;
		_clipCapacity = clipCapacity;
		_reloadSpeed = reloadSpeed;
		_damage = damage;
		_fireRate = fireRate;
		_model = model;
		_type = type;
	}

	string WeaponData::getType()
	{
		return _type;
	}

	int WeaponData::getRange()
	{
		return _range;
	}

	int WeaponData::getClipCapacity()
	{
		return _clipCapacity;
	}

	int WeaponData::getDamage()
	{
		return _damage;
	}

	float WeaponData::getReloadSpeed()
	{
		return _reloadSpeed;
	}

	int WeaponData::getAmmoCount()
	{
		return _ammoCount;
	}

	uint WeaponData::getFireRate()
	{
		return _fireRate;
	}

	string WeaponData::getModel()
	{
		return _model;
	}
}
