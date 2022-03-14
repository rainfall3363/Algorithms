import itertools

numbers = [7, 11, 17]
result = []

for i in range(1, 15):
    tmp = list(itertools.combinations_with_replacement(lst, i))
    for j in range(len(tmp)):
        result.append(sum(tmp[j]))
        
result.sort()

print(set(result))
