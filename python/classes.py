"""
A blueprint for creating objects. 
An object is an instance of a class. 
Classes encapsulate data for the object and methods to manipulate that data.
"""

# Basic class
class BasicClass:
    def __init__(self, attribute1, attribute2):
        self.attribute1 = attribute1
        self.attribute2 = attribute2

    def method1(self):
        return self.attribute1

my_object = BasicClass("value1", "value2")
my_object.method1()


# Inheritance 
# Inherits attributes and methods
class ParentClass:
    def __init__(self, parent_attribute):
        self.parent_attribute = parent_attribute

    def parent_method(self):
        return self.parent_attribute

class ChildClass(ParentClass):
    def __init__(self, parent_attribute, child_attribute):
        super().__init__(parent_attribute)
        self.child_attribute = child_attribute

    def child_method(self):
        return self.child_attribute

child_object = ChildClass("parent_value", "child_value")
child_object.parent_method()
child_object.child_method()


# Multiple Inheritance
class Base1:
    def method_base1(self):
        return "Base1"

class Base2:
    def method_base2(self):
        return "Base2"

class Derived(Base1, Base2):
    def method_derived(self):
        return "Derived"

derived = Derived()
derived.method_base1()
derived.method_base2()
derived.method_derived()


# Polymorphism
# Allows methods to do different things based on the object it is acting upon
class Animal:
    def sound(self):
        raise NotImplementedError("Subclass must implement abstract method")

class Dog(Animal):
    def sound(self):
        return "Bark"

class Cat(Animal):
    def sound(self):
        return "Meow"

def make_sound(animal):
    return animal.sound()

dog = Dog()
cat = Cat()
make_sound(dog) # Bark
make_sound(cat) # Meow


# Abstraction
# Provide only essential information and hiding the implementation details
from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def sound(self):
        pass

class Dog(Animal):
    def sound(self):
        return "Bark"

class Cat(Animal):
    def sound(self):
        return "Meow"

dog = Dog()
cat = Cat()

dog.sound()
cat.sound()


# Data classes
# Provide a decorator and functions for automatically adding special methods to user-defined classes
from dataclasses import dataclass

@dataclass
class DataClass:
    x: int
    y: int

point = DataClass(1, 2)
x, y = point.x, point.y


# Class Method and Static Methods
# Class methods are methods that are bound to the class and not the instance of the class
# Static methods do not have access to the class or instance
class MyClass:
    class_attribute = "class attribute"

    @classmethod
    def class_method(cls):
        return cls.class_attribute

    @staticmethod
    def static_method():
        return "static method"

MyClass.class_method()
MyClass.static_method()


# Property Decorators
class DecoratedClass:
    def __init__(self, value):
        self._value = value

    @property
    def value(self):
        return self._value

    @value.setter
    def value(self, new_value):
        self._value = new_value

obj = DecoratedClass(10)
obj.value = 20      # @value.setter gets called


# Encapsulation
class EncapsulationClass:
    def __init__(self, value):
        self.__value = value  # private variable

    def get_value(self):
        return self.__value

    def set_value(self, new_value):
        self.__value = new_value

obj = EncapsulationClass(10)
obj.get_value()
obj.set_value(20)


# Dunder methods
class SpeicalClass:
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return f"MyClass with value {self.value}"

    def __add__(self, other):
        return MyClass(self.value + other.value)

obj1 = MyClass(10)
obj2 = MyClass(20)
obj3 = obj1 + obj2


# Context Managers
class MyContextManager:
    def __enter__(self):
        # print("Entering the context")
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        # print("Exiting the context")
        pass

with MyContextManager():
    # print("Inside the context")
    pass

# Output:
# Entering the context
# Inside the context
# Exiting the context

