#pragma once

namespace ly
{
	class HealthComponent
	{
	public:
		HealthComponent(float health, float maxHealth);
		void ChangeHealth(float amt);
		float GetHealth() const { return mHealth; }
		float GetMaxHealth() const { return mMaxHealth; }
	private:
		void TakenDamage(float amt);
		void HealthEmpty();
		void HealthRegen(float amt);
		float mHealth;
		float mMaxHealth;
	};
}