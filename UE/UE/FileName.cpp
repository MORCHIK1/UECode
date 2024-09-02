#include <iostream>

int main() {
	float health; 

	std::cin >> health; 

	std::cout << "Input distance first and impact second: \n"; 

	while (health > 0) { 
		float item_distance, item_impact; 

		std::cin >> item_distance >> item_impact;  

		float result_impact = item_distance > 100.0f ? 0.0f : item_impact * (1 - item_distance / 100.0f); 

		health += result_impact; 
		if (health < 1 && health > 0) health = 1; 

		std::cout << "Current health: " << health << "\n"; 
	}
	std::cout << "\nYou died!"; 
}