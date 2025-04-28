import time
start_time = time.time()
test_list = []

for i in range(3, 156):
    append_start_time = time.time()
    test_list.append(i)
    append_duration = time.time() - append_start_time 
    print(f"Appended {i} in {append_duration:.10f} seconds.")

end_time = time.time() - start_time
print(f"Total time taken to append all integers: {end_time:.10f} seconds.")
