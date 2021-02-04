# Get the input
n =int(input())
elements = [int(i) for i in input().split()]

# Dictionary to store the element and its count
element_counts = {}

# Iterate the elements list and add the count into the dictionary
for i in elements:
    #print("{} \n".format(element_counts))
    if i in element_counts:
        element_counts[i] += 1
    else:
        element_counts[i] = 1

def findOutTheElement(element_counts):
    # Iterate the element_counts dictionary and find out element count that it atleast n/2
    count = 0
    for key, value in element_counts.items():
        if value > n/2:
            count += 1
    return count

print(findOutTheElement(element_counts))