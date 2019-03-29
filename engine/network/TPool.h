#pragma once
#include <list>

namespace wls
{

	template <typename T> class TPool
	{
	public:
		T* malloc()
		{
			T* ret = new T();
			return ret;
		}


		void free(T* t)
		{
			delete t;
		}

	private:
		std::list<T> mObjects;
	};
};
