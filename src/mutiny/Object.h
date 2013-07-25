#ifndef MUTINY_ENGINE_OBJECT_H
#define MUTINY_ENGINE_OBJECT_H

#include <string>

namespace mutiny
{

namespace engine
{

class Application;

class Object
{
  friend class Application;

public:
  static void dontDestroyOnLoad(Object* object);

  Object();
  virtual ~Object();

  void setName(std::string name);
  std::string getName();

private:
  std::string name;
  bool destroyOnLoad;

};

}

}

#endif
