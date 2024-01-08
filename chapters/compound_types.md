# Compound Types

A **compound type** is a type that is defined in terms of another type. In this chapter, we’ll cover two of them-*references* and *pointers*.

## References
A reference defines an alternative name for an object. We define a reference type by writing a declarator of the form
`&d`, where `d` is the name being declared.

```C++
    int val = 1;
    int &refVal = val;
```

When we define a reference, instead of copying the initializer's value, we bind the reference to its initializer. There is no way to rebind a reference to refer to a different object.

## Pointers
A pointer is a compound type that points to another type. A pointer is an object in its own right. Pointers can be assigned and copied. A pointer need not to be initialzed at the time it is defined, and it will have undefined value if it is defined at block scope and not initialized.

A pointer holds the address of another object. We get the address of an object by using the **address-of operator**.

```C++
    int ival = 1;
    int *p = &ival;
```

When a pointer points to  an object, we can use the dereference operator to access the object.

```Cpp
    int ival = 1;
    int *p = &ival;
    cout << *p;
```

## Null Pointers
A **null pointer** doesn't point to any object. There are several ways to obtain a null pointer:

```Cpp
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;
```

The most direct approach is to initialize the pointer using the literal **nullptr**. 

## Assignment and Pointers

Both pointers and references give indirect access to other objects. Once we have defined a reference, there is no way to make that reference refer to a different object. When we assign to a pointerm we give the pointer itself a new value. Assignment makes the pointer point to a different object.

```cpp
    int i = 42;
    // pi is initialized but addresses no object.
    int *pi = 0;
    // pi2 is initialized to hold the address of i.
    int *pi2 = &i;
    // if pi3 is defined inside a block, pi3 is uninitialized.
    int *pi3;
    // pi3 and pi2 address the same object.
    pi3 = pi2;
    // value in pi is changedm pi now points to ival.
    pi = &ival;
    // value in ival is changed, pi is unchanged.
    *pi = 0;
```

##