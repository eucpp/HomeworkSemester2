#pragma once

/**
  * This class define the java-style interface of iterator.
  */
template <typename Type> class Iterator
{
public:
    virtual ~Iterator() {}
    /**
      * Return current element and move iterator to the next.
      */
    virtual Type next() = 0;
    /**
      * Check whether the current element is last.
      */
    virtual bool hasNext() = 0;
    /**
      * Add new element to the container (but not to the iterator).
      */
    virtual void add(Type elem) = 0;
    /**
      * Remove current element both from container and iterator.
      * Iterator is moved to the next after removed.
      */
    virtual void remove() = 0;
};
