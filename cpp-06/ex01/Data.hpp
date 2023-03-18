#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	private:
		std::string input;

	public:
		Data(void);
		~Data(void);
  		Data(const std::string input);
 		Data(const Data &d);

		Data &operator=(const Data &d);

		std::string getInput(void);
};


#endif
