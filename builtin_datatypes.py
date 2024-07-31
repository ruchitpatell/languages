# Basic
intt: int = 10          
floatt: float = 10.5                 
stringg: str = "Hello, World!"
booll: bool = True

# Containers
listt: list = [1, "2", 3, 4.0, 5]
tuplee: tuple = (1, 2, "3", 4, 5)
sett: set = {1, 2, 3, .01, 5}
dictt: dict = {'name': 'John', 1: 30}

# Operators
# + - * / // % **
# & | << >> ^ ~
# == != < > is/is not in/not in and or not

'''
Lists / list() / bytearray()

1. Append / .append(x) / +[x]: Time & Space O(1)

2. Clear / .clear(): Time O(n)

3. Copy / .copy() / =list() / = [:] [shallow copies]

4. Count / .count(x)
    - [1, 1, 1, 2].count(1) -> 3
    - Time O(n)

5. Extend / .extend(iterable): Time & Space O(k)

6. Index / .index(x) [first found index or error]

7. Insert / .insert(index, x): Time O(n)

8. Pop / .pop(**x) [default -1]: Time O(n)

9. Remove / .remove(x): Time O(n)

10. Reverse / .reverse() [in place]: Time O(n)

11. Sort / .sort(**reverse=True|False, **key=func)
    - Time O(nlogn)
    - In place

'''

'''
Tuples: Immutable/Hashable, Ordered, tuple()

1. Count / .count(x)

2. Index / .index(x) [first found index or error]
    - Time O(n)

3. Can Concat, Slice, Unpack, Iterate
'''

'''
Sets: Mutable, Unordered, Unique Elements, set(), frozenset()

1. Add / .add(x): O(1)

2. Clear / .clear(): Time O(n)

3. Copy / .copy()

4. Difference / .difference() / -
    - {1, 2, 3}.difference(2, 3, 4) = {1}
    - Time: O(m+n), Space O(m)

5. Diff update / .difference_update() [in place]

6. Discard / .discard(x): Remove if present

7. Intersection / .intersection()
    - {1, 2, 3}.intersect({2, 3, 4}) = {2, 3}
    - Time & Space O(min(m, n))

8. Intersectino update / .intersection_update() [in place]

9. Is Disjoint / .isdisjoint(): Time(O(min(m, n)))

10. Is Subset / .issubset(): Time(O(m))

11. Is Superset / .issuperset(): Time(O(n))

12. Pop / .pop(): Remove random element or KeyError if empty

13. Remove / .remove(x): Remove if present else KeyError

14. Symmetric Difference / .symmetric_difference()
    - {1, 2, 3}.intersect({2, 3, 4}) = {1, 4}
    - Time & Space O(m, n))

15. Symmetric difference / .symmetric_difference() [in place]

16. Union / .union(): Time & Space O(m+n)

17. Update / .update(): Union in place
'''

'''
Dictionaries: Unordered

1. Delete: O(1)

2. Get / .get(key, **default): O(1)

3. Pop / .pop(key, **default)

4. Pop Item / .popitem() : Return key-value

5. Keys / .keys(): O(1)

6. Values / .values(): O(1)

7. Items / .items(): O(1)

8. Update / .update(dict): Time O(n), dict key-values take preference

9. Clear / .clear(): O(n)

10. Copy / .copy(): Time & Space O(n)

11. Fromkeys / .fromkeys(keys, default): Time & Space O(n)

12. Setdefault / .setdefault(key, default)
'''


'''
Strings: Immutable

1. Concat

2. Repeat: 'str'*n

3. Find / .find(substr): Time O(m*n) m->substr length

4. Index / .index(substr): Time O(m*n)

5. Count / .count(substr): Time O(m*n)

6. Lower / .lower(): Time O(n)

7. Upper / .upper(): Time O(n)

8. Replace / .replace(substr, replace): Time O(m*n) Space O(n)

9. Strip / .strip()

10. Split / .split(delim)

11. Join / .join(delim)

12. Format / .format(**kwargs)

'''

# Enums
from enum import Enum

class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3
