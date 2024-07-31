# Basic
def basic():
    return


# Annotation
def annotated_func(param: int) -> int:
    return param


# Doc String
def doc_string(param: int, ret: bool) -> int:
    """
    One-liner function description.

    Parameters:
    param_name (param_type): Param Description.
    ...

    Returns:
    return_type: return_description
        - tuple_or_class_description
        - ...

    Examples:
    >>> result = function_call(...)
    >>> result
    output
    ...
    """
    return param if ret else 0


# Multiple return values
def multi_return(name: str, age: int) -> tuple[str, int]:
    """
    Docstring of the function

    Parameters:
    name (str): Name.
    age (age) : Age.

    Returns:
    str: Name.
    int: Age.
    """
    return name, age


# Default arguments
def default_args(name: str='Name') -> str:
    return name
assert default_args('CustomName') == 'CustomName'
assert default_args() == 'Name'


# Pass by reference: Mutable types
# Pass by value: Immutable types


# Pass as function parameters (callbacks)
# To do: add type signatures
def param(a: int) -> int:
    return a

def func_param(func: int, val: int) -> int:
    return func(val)+val


# Recursive functions
def recursive_func(n):
    if n == 0:
        return 1
    else:
        return n * recursive_func(n - 1)
    

# Nested functions
z = 4
def nested_outer(param: str):
    x, y, z = 1, 2, 3
    def nested_inner():
        nonlocal x  # nonlocal to modify non-global enclosing vars 
        x = 2
        # print(param, y) # can access
        global z
        z = 3   # change global z
    nested_inner()


# Private functions
def _private_function():
    pass


# Decorators (access control, etc)
def decorator_func(func):
    def wrapper():
        # print("Something is happening before the function is called.")
        func()
        # print("Something is happening after the function is called.")
    return wrapper

@decorator_func
def actual_func():
    # print("Hello!")
    return

actual_func()   # Something b4 -> Hello -> Something after


# First class objects  (all functions)
def first_class_func():
    pass
first_class_func.name = 'First Class Object'


# Variable arguments
def variable_args(*args, **kwargs):
    # print(args)   unpack using *args
    # print(kwargs) unpack using **kwargs
    pass
variable_args(1, 2, 3, a=4, b=5) # Outputs (1, 2, 3), {'a': 4, 'b': 5}


# Co-routines
def coroutine_func():
    # print("Starting coroutine")
    while True:
        value = yield
        # print(f"Received value: {value}")

coroutine = coroutine_func()
next(coroutine_func)  # Start the coroutine
coroutine_func.send(10)  # Outputs "Received value: 10"
coroutine_func.send(20)  # Outputs "Received value: 20"


# Async
async def async_func():
     pass

async def another_async_func():
     await async_func()


# Keyword only (all args after *)
def keyword_only_func(name, *, age):
    return f"Hello, {name}. You are {age} years old."

keyword_only_func("Alice", age=30)  # Works
# keyword_only_func("Alice", 30)  # Raises TypeError


# Positinal only (all args after /)
def keyword_only_func(name, /, age):
    return f"Hello, {name}. You are {age} years old."

keyword_only_func("Alice", 30)  # Works
# keyword_only_func("Alice", age=30)  # Raises TypeError
