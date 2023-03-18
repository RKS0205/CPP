#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	private:
		unsigned int _size;
		T *ptr;

	public:
		Array(void) {	
			this->_size = 0;
		}

		Array(unsigned int size) {
			this->_size = size;
			if (size) {
				this->ptr = new T[this->_size];
			}
		}

		Array(const Array &src) {
			this->_size = src._size;
			if (this->_size) {
      			this->ptr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++) {
        			this->ptr[i] = src[i];
      			}
    		}
		}

		~Array(void) {
			if (this->_size) {
				delete[] this->ptr;
			}
		}

		Array &operator=(const Array &src) {
			if (this->_size) {
        		delete[] this->ptr;
      		}
			this->_size = src._size;
			if (this->_size) {
      			this->ptr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++) {
        			this->ptr[i] = src[i];
      			}
    		}
			return (*this);
		}

		T &operator[](unsigned int i) {
			if (i < 0 || i >= this->_size) {
      			throw InvalidIndex();
    		}
			else {
				return (this->ptr[i]);
			}
		}

		const T &operator[](unsigned int i) const {
			if (i < 0 || i >= this->_size) {
      			throw InvalidIndex();
    		}
			else {
				return (this->ptr[i]);
			}
		}

		unsigned int size(void) {
			return (this->_size);
		}


		class InvalidIndex : public std::exception {
			public:
				const char* what(void) const throw() {
					return ("Index is out of range");
				}
  		};

};

#endif
