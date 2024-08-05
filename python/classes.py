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
class Vehicle:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year

    def display_info(self):
        return f"{self.year} {self.make} {self.model}"

class Car(Vehicle):
    def __init__(self, make, model, year, num_doors):
        super().__init__(make, model, year)
        self.num_doors = num_doors

    def display_info(self):
        return f"{super().display_info()}, {self.num_doors}-door"

car = Car("Toyota", "Camry", 2020, 4)
car.display_info() # Overrides super().display_info()


# Multiple Inheritance
class Device:
    def power_on(self):
        return "Device powered on"

class Charger:
    def charge(self):
        return "Charging device"

class Phone(Device, Charger):
    def make_call(self):
        return "Making a call"

phone = Phone()
phone.power_on()
phone.charge()
phone.make_call()


# Polymorphism
# Allows methods to do different things based on the object it is acting upon
class Payment:
    def process_payment(self, amount):
        raise NotImplementedError("Subclass must implement abstract method")

class CreditCardPayment(Payment):
    def process_payment(self, amount):
        return f"Processing credit card payment of {amount}"

class PayPalPayment(Payment):
    def process_payment(self, amount):
        return f"Processing PayPal payment of {amount}"

def process(payment, amount):
    return payment.process_payment(amount)

credit_card_payment = CreditCardPayment()
paypal_payment = PayPalPayment()

process(credit_card_payment, 100)
process(paypal_payment, 200)    # uses paypal payment


# Abstraction
# Provide only essential information and hiding the implementation details
from abc import ABC, abstractmethod

class Storage(ABC):
    @abstractmethod
    def save(self, data):
        pass

    @abstractmethod
    def load(self):
        pass

class FileStorage(Storage):
    def save(self, data):
        # with open("data.txt", "w") as file:
        #     # file.write(data)
        #     pass
        return "Data saved to file"

    def load(self):
        # with open("data.txt", "r") as file:
        #     pass
        return

storage = FileStorage()
storage.save("Example data")
storage.load()


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
class Date:
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    @classmethod
    def from_string(cls, date_string):
        year, month, day = map(int, date_string.split('-'))
        return cls(year, month, day)

    @staticmethod
    def is_valid_date(date_string):
        year, month, day = map(int, date_string.split('-'))
        return 1 <= month <= 12 and 1 <= day <= 31

date = Date.from_string("2024-08-04")
# date.year, date.month, date.day
Date.is_valid_date("2024-08-04")


# Property Decorators
class Temperature:
    def __init__(self, celsius):
        self._celsius = celsius

    @property
    def celsius(self):
        return self._celsius

    @celsius.setter
    def celsius(self, value):
        self._celsius = value

    @property
    def fahrenheit(self):
        return self._celsius * 9/5 + 32

temp = Temperature(25)
# temp.celsius) calls celsius(self
# temp.fahrenheit) calls fahrenheit(self
temp.celsius = 30   # calls @celsius.setter


# Encapsulation
class BankAccount:
    def __init__(self, owner, balance):
        self.owner = owner
        self.__balance = balance

    def deposit(self, amount):
        self.__balance += amount
        return self.__balance

    def withdraw(self, amount):
        if amount > self.__balance:
            return "Insufficient funds"
        self.__balance -= amount
        return self.__balance

    def get_balance(self):
        return self.__balance

account = BankAccount("Bob", 1000)
account.deposit(500)
account.withdraw(200)
account.get_balance()


# Dunder methods
class SpeicalClass:
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return f"MyClass with value {self.value}"

    def __add__(self, other):
        return SpeicalClass(self.value + other.value)

obj1 = SpeicalClass(10)
obj2 = SpeicalClass(20)
obj3 = obj1 + obj2


# Mixins (can't just use class methods or static methods?)
class LogMixin:
    def log(self, message):
        return f"Log: {message}"

class Application(LogMixin):
    def run(self):
        self.log("Application is running")

app = Application()
app.run()


# Descriptors
# Validating attributes (can just __set__ but cleaner code)
class Positive:
    def __init__(self, name):
        self.name = name

    def __get__(self, instance, owner):
        return instance.__dict__[self.name]

    def __set__(self, instance, value):
        if value < 0:
            raise ValueError("Value must be positive")
        instance.__dict__[self.name] = value

class Account:
    balance = Positive('balance')

    def __init__(self, balance):
        self.balance = balance

account = Account(100)
account.balance = 200
# account.balance = -50  # This will raise a ValueError


# Context Managers
class DatabaseConnection:
    def __enter__(self):
        self.conn = self.connect_to_database()
        return self.conn

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.close_connection(self.conn)

    def connect_to_database(self):
        # print("Connecting to database")
        return "Database Connection"

    def close_connection(self, conn):
        return "Closing database connection"

with DatabaseConnection() as conn:
    # Output:
    # Connecting to database
    # Database connection
    # Closing database connection
    pass

