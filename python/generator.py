"""
https://www.youtube.com/watch?v=D1twn9kLmYg

Generators: Behind the Scenes
A special kind of iterator. 

When a generator function is called, it doesn't actually run the function. 
Instead, it returns a generator object, which can be iterated over. 

When you start iterating over this generator, 
Python runs the function until it hits the yield statement. 
At this point, the function's state is "frozen," and the yielded value is returned to the caller. 

When next() is called again on the generator, it resumes execution right after the yield statement.

Initial Call: a generator object is created but the function body is not executed immediately.
First next() call: function executes until it hits a yield statement, which returns the value and pauses the function's execution. 
                   functions state, including local variables and the current instruction pointer, is saved.
Subsequent next() Calls: function resumes from the exact point it was paused, just after the yield statement, continuing until it either reaches another yield or the end of the function.

Termination:
If the function exits without a yield (or explicitly raises StopIteration), the generator is considered exhausted. Any further calls to next() will raise StopIteration.
This mechanism allows generators to be highly efficient in terms of both memory and performance.
"""
import time

large_dataset = range(1, 100)

# simple generator: lazy load data
def fetch_records(query):
    for i in large_dataset:
        yield {"id": i, "name": f"Record {i}"}

def process_records(query):
    for record in fetch_records(query):
        print(f"Processing {record['name']}")


# generator expression lazy square
squared_numbers = (x * x for x in large_dataset)

def process_transformed_data(data_gen):
    for num in data_gen:
        if num > 1000:
            print(f"Large number: {num}")
            break

# event streaming
def event_stream():
    event_id = 0
    while True:
        yield {"event_id": event_id, "timestamp": time.time()}
        event_id += 1
        time.sleep(1)

def process_event_stream():
    for event in event_stream():
        print(f"Processing event: {event}")
        if event["event_id"] >= 10:
            break

# large file reading
def read_large_log(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            yield line.strip()

def analyze_logs(log_file):
    error_count = 0
    for line in read_large_log(log_file):
        if "ERROR" in line:
            print(f"Error found: {line}")
            error_count += 1
    print(f"Total errors found: {error_count}")

# generator delegation
def fetch_data():
    return [
        {"name": "Batch 1", "data": [1, 2, 3]},
        {"name": "Batch 2", "data": [4, 5]},
        {"name": "Batch 3", "data": [6, 7, 8]}
    ]

def process_batch(batch):
    print(f"Processing {batch['name']}")
    yield from batch['data']  # Delegate to the nested list (sub-generator)

def process_all_data():
    data_batches = fetch_data()
    for batch in data_batches:
        yield from process_batch(batch)

# stateful generator
def connection_pool(max_connections=5):
    current_connections = 0
    while current_connections < max_connections:
        yield f"Connection {current_connections}"
        current_connections += 1
    while True:
        yield "No connections available"

def request_handler():
    pool = connection_pool()
    for _ in range(7):
        connection = next(pool)
        print(f"Handling request with {connection}")

# send to generator
# send() method is used to send a value into the generator
# it resumes the generator’s execution and sends a value to the point 
# where the generator was paused (just after the last yield).
def accumulator():
    total = 0
    while True:
        value = yield total
        if value is None:
            break
        total += value

# close
def resource_manager():
    print("Opening resource")
    try:
        while True:
            yield "Resource in use"
    except GeneratorExit:
        print("Closing resource")

# throw
# used to raise an exception at the point where the generator was paused. 
# can be used to handle errors in generators or to force a generator to terminate early.
def controlled_generator():
    try:
        yield "Start"
        yield "Middle"
    except ValueError:
        yield "Handled ValueError"
    yield "End"

if __name__ == "__main__":
    process_records("SELECT * FROM large_table")
    process_transformed_data(squared_numbers)
    process_event_stream()
    analyze_logs("generator.py")

    for item in process_all_data():
        print(f"Processed item: {item}")

    request_handler()
    
    gen = accumulator()
    print(next(gen)) # nothing send, yield 0
    print(gen.send(10))  # send 10, yield 10
    print(gen.send(20))  # send 20, yield 30
    gen.close()

    gen = resource_manager()
    print(next(gen))
    gen.close() # raises GeneratorExit

    gen = controlled_generator()
    print(next(gen))  # "Start"
    print(gen.throw(ValueError))  # raises ValueError, caught in generator, "Handled ValueError"
    print(next(gen))  # "End"
