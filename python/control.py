# if
x = 10
if x > 5:
    print(f"{x} is greater than 5")

# if-else
y = 3
if y > 5:
    print(f"{y} is greater than 5")
else:
    print(f"{y} is less than or equal to 5")

# elif
z = 8
if z > 10:
    print(f"{z} is greater than 10")
elif z == 8:
    print(f"{z} is equal to 8")
else:
    print(f"{z} is less than 8")

# nested ifs
age = 20
if age >= 18:
    if age >= 21:
        print("you can vote and drink alcohol (depending on the country).")
    else:
        print("you can vote, but not drink alcohol.")
else:
    print("you cannot vote or drink alcohol.")

# ternary operator (conditional expression)
a = 15
result = "even" if a % 2 == 0 else "odd"
print(f"{a} is {result}")

# match (python 3.10+)
status_code = 404
match status_code:
    case 200:
        print("ok")
    case 404:
        print("not found")
    case 500:
        print("internal server error")
    case _:
        print("unknown status code")

# `and`, `or`, `not` in conditions
b = 10
c = 15
if b > 5 and c > 10:
    print("both conditions are true")
if b > 5 or c > 20:
    print("at least one condition is true")
if not b < 5:
    print(f"{b} is not less than 5")
