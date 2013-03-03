/* Copyright (c) 2012-2013 LevelDOWN contributors
 * See list at <https://github.com/rvagg/node-leveldown#contributing>
 * MIT +no-false-attribs License <https://github.com/rvagg/node-leveldown/blob/master/LICENSE>
 */

#ifndef LD_ITERATOR_ASYNC_H
#define LD_ITERATOR_ASYNC_H

#include <node.h>

#include "async.h"
#include "iterator.h"

namespace leveldown {

class NextWorker : public AsyncWorker {
public:
  NextWorker (
      Iterator* iterator
    , v8::Persistent<v8::Function> callback
    , void (*localCallback)(Iterator*)
  );

  virtual ~NextWorker ();
  virtual void Execute ();
  virtual void HandleOKCallback ();

private:
  Iterator* iterator;
  void (*localCallback)(Iterator*);
  std::string key;
  std::string value;
  bool ok;
};

class EndWorker : public AsyncWorker {
public:
  EndWorker (
      Iterator* iterator
    , v8::Persistent<v8::Function> callback
  );

  virtual ~EndWorker ();
  virtual void Execute ();

private:
  Iterator* iterator;
};

} // namespace leveldown

#endif
