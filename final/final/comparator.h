#ifndef COMPARATOR_H
#define COMPARATOR_H

template <typename Type> class Comparator
{
public:
    virtual ~Comparator()
    {}
    /**
      * Method compares two objects.
      * @return 1 if first grater than second, -1 if second grater, 0 if objects are equal.
      */
    virtual int compare(Type obj1, Type obj2) = 0;
};

#endif // COMPARATOR_H
