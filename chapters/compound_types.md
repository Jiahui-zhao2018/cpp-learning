# Compound Types

A **compound type** is a type that is defined in terms of another type. In this chapter, we’ll cover two of them-_references_ and _pointers_.

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

When a pointer points to an object, we can use the dereference operator to access the object.

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

## Void Pointers

The type **void\*** is a special pointer type that can hold the address of any object.

We can compare a void pointer to another pointer, we can pass it to or return it from a function, and we can assign it to another void pointer. We cannot use a void pointer to operate on the object it addresses because we don't know that object's type, and the type determines what operations we can perform on the object.

## Pointers to Pointers

In general, there are no limits to how many type modifiers can be applied to a declarator.

We indicate each pointer level by its own `*`.

```cpp
    int  ival = 1024;
    int  *pi = &ival;
    int* *ppi = &pi;
```

## References to Pointers

A reference is not an object. Hence, we may not have a pointer to a reference. However, because a pointer is an object, we can define a reference to a pointer.

## const Qualifier

### Local to a File

When a const object is initialized from a compile-time constant, the compiler will usually replace uses of the variable with its corresponding value during compilation.

To substitute the value for the variable, the compiler has to see the variable’s initializer. When we split a program into multiple files, every file that uses the const must have access to its initializer. In order to see the initializer, the variable must be defined in every file that wants to use the variable’s value.

### Reference to const

As with any other object, we can bind a reference to an object of a const type.
To do so we use a **reference to const**.

```c++
    const int ci = 1024;
    const int &r1 = ci; //ok: both reference and underlying object are const.
    r1 = 42;            //error
    int &r2 = ci        //error: nonconst reference to a const object.
```

There are two exceptions to the rule that the type of a reference must match the type of the object to which it refers.

1. We can initialize a reference to const from any expression that can be converted to the type of the reference. In particular, we can bind a reference to const to a nonconst object, a literal, or a more general expression.
   ```c++
       int i = 42;
       const int &r1 = i;          //ok: we can bind a const int& to a plain int object.
       const int &r2 = 42;         //ok: r1 is a reference to const.
       const int &r3 = r1 * 2;     //ok: r3 is a reference to const.
       int &r4 = r1;               //error: : r4 is a plain, nonconst reference.
   ```
1. When we bind a reference to an object of a different type:
   ```c++
       double dval = 2.71;
       const int &ri = dval;
   ```
   the compiler creates an unnamed(temporary) object and binds `ri` to it.
   ```c++
       const int temp = dval;
       const int &ri = temp;
   ```

### const Pointers

Pointers are objects, hence, as with any other object type, we can have a pointer that is itself const. A const pointer must be initialized, and once initialized, its value may not be changed.

We indicate that the pointer is const by putting the const after the `*`. This placement indicates that it is the pointer, not the pointed-to type, that is const:

```C++
    int errNum = 0;
    int * const curErr = &errNum;   // curErr will always point to errNum.
    const double pi = 3.14;
    const double * const pip = &pi; // pip is a const pointer to a const object.
```

The fact that a pointer is itself const says nothing about whether we can use
the pointer to change the underlying object. Whether we can change that object depends entirely on the type to which the pointer points.

### Top-level Pointer

We use the term **top-level const** to indicate that the pointer itself is a const. When a pointer can point to a const object, we refer to that const as a **low-level const**.

More generally, top-level const indicates that an object itself is const. Top-level const can appear in any object type. Low-level const appears in the base type of compound types such as pointers or references.

```Cpp
    int i = 0;
    int const *p1 = i; // we can't change the value of p1; const is top-level.
    const int ci = 42; // we can't change the value of ci; const is top-level.
    const int *p2 = &ci; // we can change the value of p2; const is low-level.
    const int *const p3 = p2; // right-most const is top-level, left-most is not.
    const int &r = ci; // const in reference is always low-level.
```

The distinction between top-level and low-level matters when we copy an object. When we copy an object, top-level consts are ignored.

On the other hand, low-level const is never ignored. When we copy an object, both objects must have the same low-level const qualification or there must be a conversion between the types of the two objects.
