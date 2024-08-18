# for
numbers = [1, 2, 3, 4, 5]
for number in numbers:
    print(f"number: {number}")

# while
count = 0
while count < 5:
    print(f"count: {count}")
    count += 1

# unzip / for each
person = {'name': 'alice', 'age': 30, 'city': 'new york'}
for key, value in person.items():
    print(f"{key}: {value}")

# nested
for i in range(3):
    for j in range(2):
        print(f"i: {i}, j: {j}")

# break
for number in range(10):
    if number == 5:
        break
    print(f"number before break: {number}")

# continue
for number in range(10):
    if number % 2 == 0:
        continue
    print(f"odd number: {number}")

# else with loops
for number in range(5):
    print(f"number: {number}")
else:
    print(f"loop exited successfully w/o break(s)")

# iterating with enumerate()
fruits = ['apple', 'banana', 'cherry']
for index, fruit in enumerate(fruits):
    print(f"index: {index}, fruit: {fruit}")

# iterating with zip()
names = ['alice', 'bob', 'charlie']
ages = [25, 30, 35]
heights = [1, 2, 3]
for name, age, height in zip(names, ages, heights):
    print(f"{name} is {age} years old and {height} ft tall")

# list comprehension
squares = [x**2 for x in range(6)]
print(f"squares: {squares}")
