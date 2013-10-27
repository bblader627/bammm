
class Stein : public IWeaponType
{
	private:
		WeaponData weaponData;

	public:
		Stein();
		~Stein();
		void attack();
		bool canAttack();
		void reload();
}
