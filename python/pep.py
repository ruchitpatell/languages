# PEP 8 Python Style Guide

# Variable names
# variable_name, descriptive, avoid single character (except for counters or iterators)
total_sum = 0
user_age = 25

# Function Names
# function_name, use verbs to describe what function does
def calculate_total(price, tax_rate):
    return price * (1 + tax_rate)


# Class Names
# CapitalizedWords (CamelCase), be descriptive and avoid abbreviations
class DataProcessor:
    pass

# Constant Names
# All uppercase, separated by underscores, CONSTANT_NAME
PI = 3.14159
MAX_CONNECTIONS = 100


# Module and Package Names
# Lowercase separated by underscores, module_name
# import my_module

# Private Variables and Methods
# leading underscore, _private_var or _private_method
class MyClass:
    def __init__(self):
        self._internal_data = 0

    def _private_method(self):
        pass


# Special Methods
# double leading and trailing underscores, __special_method__
class MyClass:
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return str(self.value)


# Other

# Indentation
#    Use 4 spaces per indentation level.
#    No tabs for indentation.

# Line Length
#    Limit all lines to a maximum of 79 characters.
#    For docstrings and comments, limit lines to 72 characters.

# Blank Lines
#    Two blank lines before top-level function and class definitions.
#    One blank line between method definitions inside a class.

# Imports
#    Import standard libraries first, then third-party libraries, and then local application-specific libraries.
#    Use absolute imports rather than relative imports.

# Comments
#    Use comments to explain code where necessary, but avoid redundant comments.
#    Inline comments should be separated by at least two spaces from the statement.

# Docstrings
#    Use triple double quotes for docstrings.
#    Include a description of the module, class, or method.
#    Docstrings for functions should include a description of parameters and return values.
def calculate_area(radius: float) -> float:
    """
    Calculate the area of a circle given its radius.

    Parameters:
    radius (float): The radius of the circle.

    Returns:
    float: The area of the circle.
    """
    return 3.14159 * (radius ** 2)


# Use of `self` and `cls`
#    Use `self` for instance methods to refer to the instance itself.
#    Use `cls` for class methods to refer to the class itself.

# Avoid Using `from module import *`
#    Explicit imports are preferred to avoid polluting the namespace and to make the code clearer.

# Type Hints
#    Use type hints for function arguments and return types where applicable.
def add_numbers(a: int, b: int) -> int:
    return a + b


# Avoid Using Magic Numbers
#     Define constants for magic numbers to make the code more readable and maintainable.
MAX_RETRIES = 5
for _ in range(MAX_RETRIES):
    pass


# Context Managers
#    Use context managers (`with` statement) for resource management to ensure that resources are properly cleaned up.
with open('file.txt', 'r') as file:
    content = file.read()
   
# Avoid Using Mutable Default Arguments
#   use `None` and initialize inside the function.
def append_to_list(element, my_list=None):
    if my_list is None:
        my_list = []
    my_list.append(element)
    return my_list
   

# Use `is` for Singletons
#   for comparisons with singletons like `None`, `True`, and `False`.
value = True
if value is None:
    pass
   

# Code Organization
#    place imports at the top, followed by constants, then class definitions, and finally functions. Group related code together to improve readability.


# Avoid Overusing `lambda`
#   only use for simple / one-line functions
def add(x, y):
       return x + y
add = lambda x, y: x + y
   

# Use List Comprehensions and Generator Expressions
squares = [x * x for x in range(10)]
    

# Document Your Code
#   write clear docstrings for all public modules, classes, and functions

# Use `__name__ == "__main__"`
#   to allow code to be run as a script or imported as a module.
def main():
    pass

if __name__ == "__main__":
    main()
    

# Avoid Global Variables
#   Minimize the use of global variables to avoid potential conflicts and to make the code easier to maintain.

# Lint and format
#   Flake8 and Black
