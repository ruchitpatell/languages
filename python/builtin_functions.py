# Built-in Functions

# Absolute / abs(x)
# Returns the absolute value of a number.
assert abs(-7) == 7

# All / all(iterable)
# Returns True if all elements of the iterable are true (or if the iterable is empty).
assert all([1, 2, 3]) == True

# Any / any(iterable)
# Returns True if any element of the iterable is true. If the iterable is empty, returns False
assert any([0, 1, 2]) == True

# Binary / bin(x)
# Converts an integer number to a binary string prefixed with "0b".
# Time & Space O(log n)
assert bin(3) == '0b11'

# Bool bool([x])
# Converts a object to a Boolean, using the standard truth testing procedure.
assert bool([]) == False
assert bool({1: 1}) == True

# Char / chr(i)
# Returns the string representing a character whose Unicode code point is the integer i
assert chr(97) == 'a'

# Divmod / divmod(a, b)
# Returns a pair of numbers (a tuple) consisting of their quotient and remainder.
assert divmod(7, 3) == (2, 1)

# Enumerate / enumerate(iterable, start=0)
# Adds a counter to an iterable and returns it in a form of an enumerate object.
assert list(enumerate(['a', 'b', 'c'])) == [(0, 'a'), (1, 'b'), (2, 'c')]

# Filter / filter(function, iterable)
# Constructs an iterator from elements of iterable for which function returns true.
assert list(filter(lambda x: x % 2 == 0, [1, 2, 3, 4])) == [2, 4]

# Float / float([x])
# Converts a string or a number to a floating point number.
assert float('3.14') == 3.14

# Int / int([x], [base])
assert int('10', 2) == 2

# Len / len(s)
# Returns the length (the number of items) of an object.
assert len('abc') == 3

# List / list([iterable])
# Creates a list from an iterable.
assert list('abc') == ['a', 'b', 'c']

# Map / map(function, iterable, ...)
# Applies function to every item of iterable, yielding the results.
assert list(map(lambda x: x * 2, [1, 2, 3])) == [2, 4, 6]

# Max / max(iterable, *[, key, default])
# Returns the largest item in an iterable or the largest of two or more arguments.
assert max([1, 2, 3]) == 3

# Min / min(iterable, *[, key, default])
# Returns the smallest item in an iterable or the smallest of two or more arguments.
assert min([1, 2, 3]) == 1

# Power / pow(x, y[, z])
# Returns x to the power y; if z is present, returns x to the power y, modulo z
# Time O(log y)
assert pow(2, 3) == 8

# Print / print()

# range(start, stop[, step])
# Returns an immutable sequence of numbers from start to stop by step
assert list(range(1, 5)) == [1, 2, 3, 4]

# Reversed / reversed(seq)
# Returns a reverse iterator.
assert list(reversed([1, 2, 3])) == [3, 2, 1]

# Round / round(number[, ndigits])
# Rounds a number to a given precision in decimal digits.
assert round(3.14159, 2) == 3.14

# Sorted / sorted(iterable, *, key=None, reverse=False)
# Returns a new sorted list from the items in iterable
# Time O(nlogn), Space O(n)
assert sorted([3, 1, 2]) == [1, 2, 3]

# String / str(object='')
# Returns a string version of object
# Time & Space O(n)
assert str(123) == '123'

# Sum / sum(iterable, /, start=0)
# Sums the items of an iterable from left to right and returns the total.
assert sum([1, 2, 3]) == 6

# Zip / zip(*iterables)
# Returns an iterator of tuples, where the i-th tuple contains the i-th element from each of the argument sequences or iterables.
assert list(zip([1, 2, 3], ['a', 'b', 'c'])) == [(1, 'a'), (2, 'b'), (3, 'c')]

# Callable / callable(object)
# Returns True if the object appears callable (i.e., some function or method)
assert callable(print) == True

# Hash / hash(object)
# Returns the hash value of the object
hash('hash')

# ID / id(object)
# Returns the identity of an object. Different every run.
id((1, 2, 3))

# Is Instance / isinstance(object, classinfo)
# Returns True if the object is an instance of the classinfo argument.
assert isinstance(3, int) == True

# Is subclass issubclass(class, classinfo)
# Returns True if the class is a subclass of classinfo.
class A:
    pass
class B(A):
    pass
assert issubclass(B, A) == True

# Iter / iter(object[, sentinel])
# Returns an iterator object.
list_iter = iter([1, 2, 3])
assert next(list_iter) == 1

# Object / object()
# Returns a new featureless object
objectt = object()

# Ord / ord(c)
# Returns the Unicode code point for a one-character string.
assert ord('a') == 97

# Vars / vars([object])
# Returns the __dict__ attribute of the given object. 
# If no object is provided, returns a dictionary containing the local symbol table.
class MyClass:
    def __init__(self):
        self.a = 1
        self.b = 2
assert vars(MyClass()) == {'a': 1, 'b': 2}

# Slice / slice(start, stop[, step])
# Returns a slice object representing the set of indices specified by start, stop, and step.
lst = [0, 1, 2, 3, 4, 5]
assert lst[slice(1, 5, 2)] == [1, 3]


# Magic Methods (Dunder Methods)
# Allow the use of built-in operations and functions with custom objects
# Operator overloading, etc.

class MyClass:
     # Called when a class instance is created
     def __init__(self, value):
          self.value = value
          self.items = {}

     # Called by str() and print() to get the string representation of the object
     def __str__(self):
          return f"MyClass with value {self.value}"
     
     # Called by repr() to get the string representation of the object
     def __repr__(self):
          return f"MyClass(value={self.value})"

     # Called by len() to get the length of the object
     def __len__(self):
          return len(self.value)
     
     # Called to get an item using the subscript notation (e.g., obj[key]).
     def __getitem__(self, key):
          return self.value[key]
     
     # Called to set an item using the subscript notation (e.g., obj[key] = value).
     def __setitem__(self, key, value):
          self.value[key] = value
     
     # Called to delete an item using the subscript notation (e.g., del obj[key]).
     def __delitem__(self, key):
          del self.value[key]
     
     # Called to get an iterator for the object.
     def __iter__(self):
          return iter(self.value)
     
     # Called to get the next item from the iterator.
     def __next__(self):
          return next(self.value)
     
     # Called when the object is called as a function.
     def __call__(self, *args, kwargs):
          return f"Called with {args} and {kwargs}"
     
     # Called by the in operator to check if item is in the container.
     def __contains__(self, item):
          return item in self.items

     # Called by the == operator to compare two objects for equality.
     # same with < __lt__ and > __gt__
     def __eq__(self, other):
          return self.value == other.value


# Lambda Functions
# Lambda functions are small anonymous functions defined using the lambda keyword.
# They can have any number of arguments but only one expression.
# Syntax: lambda arguments: expression
add = lambda x, y: x + y
assert add(2, 3) == 5

nums = [1, 2, 3, 4]
assert list(map(lambda x: x**2, nums)) == [1, 4, 9, 16]
assert list(filter(lambda x: x % 2 == 0, nums))  == [2, 4]

pairs = [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]
sorted(pairs, key=lambda pair: pair[1])


# Keywords

# True, False, None, and, or, class, def, if, elif, else, try, except, finally
# for, while, import, in, is, lambda, not, return

# As / as
# Used to create an alias while importing a module.
# import math as m

# Assert / assert
# Used for debugging purposes. Tests if a condition is true, and if not, raises an AssertionError.
x = 5
assert x > 0, "x should be positive"

# Async / async
# Defines an asynchronous function.
async def my_coroutine():
     pass

# Await / await
# Waits for the completion of an async function.
async def another_coroutine():
     await my_coroutine()

# Break / break
# Terminates the nearest enclosing loop.
for i in range(10):
     if i == 5:
          break

# Continue / continue
# Skips the rest of the code inside the loop for the current iteration and moves to the next iteration.

for i in range(10):
     if i % 2 == 0:
          continue

# Delete / del
# Deletes an object.
x = [1, 2, 3]
del x[1]
assert x == [1, 3]

# From / from
# Imports specific parts of a module.
# from math import sqrt

# Global / global
# Declares a global variable.
x = 5
def set_global():
     global x
     x = 10
     set_global()

# Nonlocal nonlocal
# Declares a non-local variable.
def outer():
     x = 5
     def inner():
          nonlocal x
          x = 10
     inner()
outer()

# Pass / pass
# A null statement used as a placeholder.
def my_function():
     pass

# raise
# Raises an exception.
# raise ValueError("An error occurred")

# With / with
# Simplifies exception handling by encapsulating common preparation and cleanup tasks.
# with open('file.txt', 'r') as f:
#      contents = f.read()

# Yield / yield
# Pauses a generator function and returns a value. Can be resumed later.
def generator():
     yield 1
     yield 2
for value in generator():
     pass
