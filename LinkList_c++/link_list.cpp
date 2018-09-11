#include <iostream>
#include <string>
#include "List"


struct product
{
	int id;
	std::string name;
	float price;
};


int show(product& data)
{
	std::cout << data.id << ' ' << data.name << ' ' << data.price << std::endl;
	return 1;
}


int main()
{
	List<int> scores;
	List<double> salary;
	List<product> pros;

	scores.push_back(98);
	scores.push_back(86);
	scores.push_front(59);
	scores.insert(0, 73);

	std::cout << scores.size() << std::endl;


	product p1 = {1001, "辣条", 0.50};
	pros.push_back(p1);	

	product p2 = {1002, "冰激凌", 5.00};
	pros.push_back(p2);	

	product p3 = {1003, "鼠标", 30.50};
	pros.push_back(p3);	

	pros.traverse(show);

	return 0;
}
