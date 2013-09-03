#ifndef MAT_ALG_HPP
#define MAT_ALG_HPP


#include  "struct.hpp"

namespace velalg {

	class mat_alg {
	public:
		virtual short get_power() const = 0; 
		virtual short get_unit() const = 0; 

	};



	template <typename T>
	class dec_alg : public mat_alg {
	public:
		dec_alg(const T value){
		
		};


		virtual short get_power() const {

			return 0;
		}; 

		virtual short get_unit() const {
			return 0;
		}; 
		virtual ~dec_alg() {};
	private:
		T value;
	
	};


	template <typename T>
	class oct_alg : public mat_alg {

	public:
		oct_alg (const T value) {
		
		};

		virtual short get_power() const {

			return 0;
		}; 

		virtual short get_unit() const {
			return 0;
		}; 

		virtual ~oct_alg() {};

	private:
		T value;
	
	};


}



#endif//MAT_ALG_HPP
