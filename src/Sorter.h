#ifndef _SORTER_H
#define _SORTER_H


#include "SortError.h"
#include "SortTechFactory.h"
#include <mutex>
using namespace std;
#include <list>
using namespace std;

template<class T, template<typename...> class Container> class SortData;
class SortDataBase;

#include <memory>

#ifdef _WIN32
#ifdef BUILDING_CLIENT_DLL
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif
#else
// -fvisibility=hidden
#define CLIENT_API __attribute__((visibility("default")))
#endif

//This class serves as the main access point to the library's interface. All sorting requests should be processed in a multithreaded manner to ensure efficiency and performance.
class CLIENT_API Sorter {
  public:
    template<class T, template<typename...> class Container>
    inline SortError sort(SortData<T, Container> & data);


  private:
    mutex m_queue_mutex;

    list<shared_ptr<SortDataBase>> m_queue;

};
template<class T, template<typename...> class Container>
inline SortError Sorter::sort(SortData<T, Container> & data) {
  return SE_SUCCESS;
}

#endif
