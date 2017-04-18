//! Copyright [2017] <relldaXY>

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

/**
 * @brief - This is describe an array list. 
 *	It does functions like pop, push, get size and some like that
 *
 * @param - contents - reference to array list.
 * @param - size_ - the last position of array
 * @param - max_size_ - the max size of array list.
 */

template<typename T>
class ArrayList {
 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;

 public:
    /**
	 * @brief - Constructor.
	 *
	 * @details - Create the array list with size equal 10u.
	 */
    ArrayList() {
        std::size_t ArrayList(DEFAULT_MAX);
    }
    /**
	 * @brief - Construtor da classe lista.
	 *
	 * @param - max_size - Create the array list with size by parameter.
	 */
    explicit ArrayList(std::size_t max_size) {
        max_size_ = max_size;
        contents = new T[max_size_];
	size_ = -1;
    }

    //! @brief - Destructor.
    ~ArrayList() {
        delete[] contents;
    }

    //! @brief - To clear the array.
    void clear() {
        delete[] contents;
        size_ = -1;
        contents = new T[max_size_];
    }
    /**
	 * @brief - push back into array list.
	 *
	 */
    void push_back(T data) {
        insert(data, size_+1);
    }
    /**
	 * @brief - push front into array list.
	 *
	 */
    void push_front(T data) {
        insert(data, 0);
    }
    /**
	 * @brief - Insert element.
	 *
	 */
    void insert(T data, std::size_t index) {
       if (full()) {
			throw std::out_of_range("Array list full");
		} else {
			if(index > size_ + 1 || index < 0) {
				throw std::out_of_range("Invalid Index");
			}
		}
		size_++;
		std::size_t i = size_;
		while(i > index) {
		contents[i] = contents[i-1];
			i--;
		}
		contents[index] = data;
    }
    /**
	 * @brief - Insert and sort elements.
	 *
	 */
    void insert_sorted(T data) {
      if (full()) {
			throw std::out_of_range("Array list full");
		} else {
			std::size_t i = 0;
			while(i < size_+1 && data > contents[i]) {
				i++;
			}
			insert(data, i);
		}
    }
    /**
	 * @brief - pop elements by index.
	 *
	 */
    T pop(std::size_t index) {
        if (index > size_ || index < 0) {
			throw std::out_of_range("Invalid index");
		} else {
			if(empty()) {
				throw std::out_of_range("Array list empty");
			} else {
				size_--;
				T data_aux = contents[index];
				std::size_t i = index;
				while(i < size_+1) {
					contents[i] = contents[i+1];
					i++;
				}
				return data_aux;
			}
		}
    }

    //! @brief - pop the last element from array list.
    T pop_back() {
        return pop(size_);
    }

    //! @brief - pop the first element from array list.
    T pop_front() {
        return pop(0);
    }
    /**
	 * @brief - remove by data.
	 *
	 */
    void remove(T data) {
        std::size_t index = find(data);
        if (index < size_) {
        pop(index);
        }
    }
    /**
	 * @brief - Is the array list full?
	 *
	 */
    bool full() const {
        return size_ == max_size_-1;
    }
    /**
	 * @brief - Is the array list empty?
	 *
	 */
    bool empty() const {
        return size_ == -1;
    }
    /**
	 * @brief - verify if contains the element.
	 *
	 */
    bool contains(const T& data) const {
        return find (data) != size_+1;
    }
    /**
	 * @brief - verify de position of an element by data.
	 *
	 */
    std::size_t find(const T& data) const {
        for (std::size_t i = 0; i <= size_; i++) {
            if (data == contents[i]) {
                return i;
            }
        }
        return size_+1;
    }
    /**
	 * @brief - return the size.
	 *
	 */
    std::size_t size() const {
        return size_+1;
    }
    /**
	 * @brief - return the max size.
	 *
	 */
    std::size_t max_size() const {
        return max_size_;
    }
    /**
	 * @brief - return index.
	 *
	 */
    T& at(std::size_t index) {
        if (index <= size_) {
                return contents[index];
        }
        throw std::out_of_range("Invalid index");
    }
    /**
	 * @brief - return index.
	 *
	 */
    T& operator[](std::size_t index) {
        return contents[index];
    }
    /**
	 * @brief - return index.
	 * 
	 */
    const T& at(std::size_t index) const {
        return at(index);
    }
    /**
	 * @brief - return index.
	 * 
	 */
    const T& operator[](std::size_t index) const {
        return contents[index];
    }
};
}  //  namespace structures

#endif
