# basic
try:
    result = 10 / 0
except ZeroDivisionError as e:
    print(f"error: {e}\n\n")

# multiple exceptions
try:
    number = int("abc\n")
except (ValueError, TypeError) as e:
    print(f"error: {e}\n")

# all exceptions
try:
    print(undefined_variable)
except Exception as e:
    print(f"caught an exception: {e}\n")

# finally
# always executed, regardless of whether an exception was raised
try:
    with open("somefile.txt", "r") as file:
        content = file.read()
except FileNotFoundError as e:
    print(f"error: {e}\n")
finally:
    print("execution of the try-except block is complete.\n")

# else block executes if no exceptions are raised in the try block
try:
    result = 10 / 2
except ZeroDivisionError as e:
    print(f"error: {e}\n")
else:
    print(f"no Exceptions Raised\n")

# custom
class NegativeNumberError(Exception):
    def __init__(self, number, message="negative number not allowed\n"):
        self.number = number
        self.message = message
        super().__init__(self.message)

def check_positive(number):
    if number < 0:
        raise NegativeNumberError(number)

try:
    check_positive(-5)
except NegativeNumberError as e:
    print(f"error: {e}\n")

# raie
def divide_numbers(a, b):
    if b == 0:
        raise ZeroDivisionError("division by zero is not allowed\n")
    return a / b

try:
    result = divide_numbers(10, 0)
except ZeroDivisionError as e:
    print(f"error: {e}\n")

# reraise
# try:
#     result = divide_numbers(10, 0)
# except ZeroDivisionError as e:
#     print(f"logging the error: {e}\n")
#     # raise  # re-raises the caught exception

# chaining
def chaining():
    try:
        1 / 0
    except ZeroDivisionError as e:
        raise ValueError("custom message for the next exception\n") from e

def meta():
    try:
        undefined_variable += 1
    except Exception as e:
        print(f"error type: {type(e).__name__}\n")
        print(f"error arguments: {e.args}\n")
        print(f"error message: {e}\n")

# assert
def validate_age(age):
    assert age >= 0, "age cannot be negative"
    return age

try:
    validate_age(-1)
except AssertionError as e:
    print(f"assertion error: {e}\n")

# # ctx managers
# from contextlib import contextmanager

# @contextmanager
# def open_file(file, mode):
#     try:
#         f = open(file, mode)
#         yield f
#     except IOError as e:
#         print(f"error: {e}\n")
#     finally:
#         f.close()

# with open_file('nonexistent_file.txt', 'r') as f:
#     content = f.read()
