#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>

class Convert {
	private:
		std::string input;
		char c;
		int i;
		float f;
		double d;
		std::string c_out;
		std::string i_out;
		std::string d_out;
		std::string f_out;

	public:
		Convert(void);
		~Convert(void);
  		Convert(const std::string input);
 		Convert(const Convert &c);

		Convert &operator=(const Convert &c);

		char checkInputType(void);
		void useDataFromChar(void);
		void useDataFromInt(void);
		void useDataFromFloat(void);
		void useDataFromDouble(void);
		void useDataFromNothing(void);
		void insertIntoString(void);
		void printResult(void);
};


#endif
