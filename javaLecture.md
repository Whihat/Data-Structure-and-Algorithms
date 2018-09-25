# Lecture 9 Inheritance

Why we need inheritance?（if we dont use inheritance）
1. Repeated code/functionality, hard to debug
2. Doesn't represent the similarity/relationship between objects
3. A lot of work required to implement
4. Difficult to extend

Inheritance: A form of abstraction that permits "generalisation" of similar attributes/methods of classes, analogous to passsing genetics on your children

⭐️*Superclass*: The "parent" or "base" class in the inheritance relationship, provide general information to its "child" classes.

⭐️*Subclass*: The "child" or "derived" class in the inheritance relationship, inherits common attributes and methods from the "parent" class.

extends: Indicates one class **inherits** from another.

⭐️*Is A*: 
    1. Inherutance defines an "**Is A**" relationship.
    2. Only use inheritance when this relationship **make sense**.
    3. A subclass can only be **one thing**(inherits one superclass.

super: Invokes a constructor in the **parent** class.
    - Note: Must be the **first** statement in the subclass constructor.

Q: What level of privact should superclass intstance variable have?
A: **Private!**

⭐️*Overloading*: Declaring multiple methods with the same name, but **differing method signature**. Superclass methods **can** be overloaded in subclasses.

⭐️*Overrding*: Declaring a method that exits in a superclass **again** in a subclass, with the **same** signature. Methods can **only** be overriden by subclass.

Q: Why Overriding?
A: - Subclasses can **extend** functionality from a parent.
   - Subclasses can **override/change** functionality from a parent.
   -  Makes the subclass behaviour **available** when using variables of a superclass.
   -  Defines a general "interface" in a superclass, with specific behaviour implemented in the subclass.

super: A reference to an object's parent class; just like *this* is a reference to itself, *super* refers to the attributes and methods of the parent.

<span style="color:red">Pitfall: Method Overriding</span>
1. Overriding can't change return type.
2. Overriding cna't make methods **more** private(but **less** private is okay).

(Restricting Inheritance)**final**:
- *final* indicate s that a variable, **method**, or **class** can be assigned, declared or defined once.
- *Final Methods* may not be overriden by subclasses.
- *Final classes* may not be inherited.


# Lecture 10 Polymorphism and Abstract Classes

⭐️*instanceof*: Results in true if an object A is an instance of teh same class as object B, or a class that inherits from B.

⭐️*Upcasting*: When an object of a child class is assigned to a variable of an ancestor class.
`Robot robot = new AerialRobot()`

⭐️*Downcasting*: When an object of an ancestor class is assigned to a variable of a child class. Only make sense if the underlying object is **actually** of that class.

⭐️*Polymorphism*: The ability to use objects or methods in many different ways; roughly means "multiple forms"(Overloading, Overriding, Substitution, Generics).

## Abstract Class
Some classes aren't meant to be instantiated because they aren't **well defined**.

*Abstract Method*: Defines a superclass method that is common to **all** subclasses, but has no implementation. Each subclass then provides it's own implementation through **overriding**.

⭐️*Abstract Class*: A class that represents common attributes and methods of its subclasses, but that is **missing** some information specific to its subclasses. **Cannot** be instantiated.

*Concrete Class*: Any class that is not abstract, and has well-defined, specific implementation for all actions it can take.


# Lecture 11 Polymorphism and Interfaces

